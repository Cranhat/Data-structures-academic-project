#include "avl.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <random>


AVLTree::AVLTree() : root(nullptr) {
}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

void AVLTree::updateHeight(AVLNode* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
}

int AVLTree::balanceFactor(AVLNode* node) {
    return height(node->right) - height(node->left);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    updateHeight(node);
    int bf = balanceFactor(node);
    if (bf == 2) {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if (bf == -2) {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

AVLNode* AVLTree::insertNode(AVLNode* node, int key, int value) {
    if (!node){
        AVLNode* newNode = new AVLNode();
        newNode -> key = key;
        newNode -> value = value;
        return newNode;
    }
    if (key < node->key)
        node->left = insertNode(node->left, key, value);
    else if (key > node->key)
        node->right = insertNode(node->right, key, value);
    else
        node->value = value;
    return balance(node);
}

void AVLTree::insert(int key, int value) {
    root = insertNode(root, key, value);
    size++;
}

AVLNode* AVLTree::findMin(AVLNode* node) {
    return node->left ? findMin(node->left) : node;
}

AVLNode* AVLTree::removeMin(AVLNode* node) {
    if (!node->left)
        return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

// AVLNode* AVLTree::remove(AVLNode* node, int key) {
//     if (!node) return nullptr;
//     if (key < node->key) {
//         node->left = remove(node->left, key);
//     }
//     else if (key > node->key) {
//         node->right = remove(node->right, key);
//     }
//     else {
//         AVLNode* left = node->left;
//         AVLNode* right = node->right;
//         delete node;
//         if (!right) return left;
//         AVLNode* min = findMin(right);
//         min->right = removeMin(right);
//         min->left = left;
//         return balance(min);
//     }
//     return balance(node);
// }

AVLNode* AVLTree::remove(AVLNode* node, int key, int value) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key, value);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key, value);
    }
    else {
        if (value == node->value) {
            AVLNode* left = node->left;
            AVLNode* right = node->right;
            delete node;
            if (!right) return left;
            AVLNode* min = findMin(right);
            min->right = removeMin(right);
            min->left = left;
            return balance(min);
        } else {
            node->left = remove(node->left, key, value);
            node->right = remove(node->right, key, value);
        }
    }

    return balance(node);
}


void AVLTree::remove(int key, int value) {
    root = remove(root, key, value);
    size--;
}

AVLNode* AVLTree::searchNode(AVLNode* node, int key, int value) {
    if (!node) return nullptr;
    if (key == node->key && value == node->value) return node;
    AVLNode* leftResult = searchNode(node->left, key, value);
    if (leftResult) return leftResult;
    return searchNode(node->right, key, value);
}

bool AVLTree::search(int key, int value) {
    AVLNode* result = searchNode(root, key, value);
    return result != nullptr;
}


void AVLTree::printElements(){
    printInOrder(root);
} 

void AVLTree::printInOrder(AVLNode* node) {
    if (!node) return;
    printInOrder(node->left);
    std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
    printInOrder(node->right);
}


int AVLTree::getSize(){return size;} 

void AVLTree::clear(){
    destroyTree(root);
    root = nullptr;
    size = 0;
}

void AVLTree::addHash(int key, int value){
    insert(key, value);
}

void AVLTree::deleteBack(){ // instead of last deletes radom, needed only for testing purposes
    NodeBase* rand_ptr = getRandom();
    deleteHash(rand_ptr -> key, rand_ptr -> value);
}


void AVLTree::collectNodesInOrder(AVLNode* node, DynamicArray& nodesArr) {
    if (!node) return;
    collectNodesInOrder(node->left, nodesArr);
    nodesArr.insert(node -> key, node -> value);
    collectNodesInOrder(node->right, nodesArr);
}

NodeBase* AVLTree::getRandom(){
    DynamicArray nodesArr;
    collectNodesInOrder(root, nodesArr);
    NodeBase* rand_node = nodesArr.getRandom();
    return searchNode(root, rand_node -> key, rand_node -> value);
}

void AVLTree::deleteHash(int key, int value){
    remove(key, value);
}

void AVLTree::deleteElement(int key, int value){} // empty


void AVLTree::allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity){
    clear();

    std::ifstream myFile(dataFilePath.c_str(), std::ios::in);

    int number, key, location, count = 0;
    std::string line;

    while (std::getline(myFile, line) && elements_allocated > count){

        location = line.find(';');

        number = stoi(line.substr(0, location));
        key = stoi(line.substr(location + 1));
        
        addHash(number, key);
        count++;
    }    
    myFile.close();
}