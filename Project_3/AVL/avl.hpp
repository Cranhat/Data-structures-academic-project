#ifndef AVL_HPP
#define AVL_HPP

class AVLNode {
public:
    int key;
    int value;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k, int v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
    
};

class AVLTree {
private:
    AVLNode* root;
    AVLNode* insert(AVLNode* node, int key, int value);
    AVLNode* remove(AVLNode* node, int key);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
    AVLNode* findMin(AVLNode* node);
    AVLNode* removeMin(AVLNode* node);
    void destroyTree(AVLNode* node);
    int height(AVLNode* node);
    void updateHeight(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* searchNode(AVLNode* node, int key);

public:
    AVLTree();
    ~AVLTree();

    void insert(int key, int value);
    void remove(int key);
    int search (int key);

};

#endif
