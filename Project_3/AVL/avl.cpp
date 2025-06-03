#include "avl.hpp"
#include <stdexcept>
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

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

AVLNode* AVLTree::insert(AVLNode* node, int key, int value) {
    if (!node) return new AVLNode(key, value);
    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->value = value;
    return balance(node);
}

void AVLTree::insert(int key, int value) {
    root = insert(root, key, value);
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

AVLNode* AVLTree::remove(AVLNode* node, int key) {
    if (!node) return nullptr;
    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        AVLNode* left = node->left;
        AVLNode* right = node->right;
        delete node;
        if (!right) return left;
        AVLNode* min = findMin(right);
        min->right = removeMin(right);
        min->left = left;
        return balance(min);
    }
    return balance(node);
}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

AVLNode* AVLTree::searchNode(AvlNode* node, int key) {
    if (!node) return nullptr;
    if (key == node ->key) return node;
    if (key < node->key) return searchNode(node->left, key);
    return searchNode(node->right, key);
}

int AVLTree::search(int key){
        AVLNode* result = searchNode(root,key);
    return result ? result->value : -1;
}
