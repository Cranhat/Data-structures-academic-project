#pragma once

#include "../../DataStructures/DataStructure/DataStructure.hpp"
#include "../../DataStructures/Dynamic_array/DynamicArray.hpp"

class AVLNode : public NodeBase{
public:
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode() : height(1), left(nullptr), right(nullptr) {}

    ~AVLNode() {}
    
};

class AVLTree : public DataStructure{
    protected:
    int size;
    AVLNode* root;
    AVLNode* insertNode(AVLNode* node, int key, int value);
    // AVLNode* remove(AVLNode* node, int key);
    AVLNode* remove(AVLNode* node, int key, int value);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
    AVLNode* findMin(AVLNode* node);
    AVLNode* removeMin(AVLNode* node);
    void destroyTree(AVLNode* node);
    int height(AVLNode* node);
    void updateHeight(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* searchNode(AVLNode* node, int key, int value);

    public:
    AVLTree();
    ~AVLTree();

    void printInOrder(AVLNode* node);
    
    bool search (int key, int value);

    void printElements(); //
    
    int getSize(); // 

    void clear(); //

    void addHash(int key, int value);

    void insert(int key, int value);

    void deleteBack(); //

    void collectNodesInOrder(AVLNode* node, DynamicArray& nodesArr);
    
    void deleteHash(int key, int value); //

    void remove(int key, int value);

    void deleteElement(int key, int value); //

    NodeBase* getRandom();

    void allocate_from_csv(std::string dataFilePath, int elements_allocated, int new_capacity); //

};
