#include "Posts_Tree.hpp"
#include <algorithm>
#include <iostream>

int Posts_Tree::height(PostNode* N) { return N ? N->height : -1; }

PostNode* Posts_Tree::rightRotate(PostNode* y) {
    PostNode* x = y->left;
    PostNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

PostNode* Posts_Tree::leftRotate(PostNode* x) {
    PostNode* y = x->right;
    PostNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

int Posts_Tree::getBalance(PostNode* N) {
    if (!N) return 0;
    return height(N->left) - height(N->right);
}

PostNode* Posts_Tree::insertHelper(PostNode* node, long long key, const std::string& content) {
    if (!node) return new PostNode(key, content);
    if (key <= node->key)
        node->left = insertHelper(node->left, key, content);
    else
        node->right = insertHelper(node->right, key, content);

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) return rightRotate(node);
    if (balance < -1 && key > node->right->key) return leftRotate(node);
    if (balance > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (balance < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}

void Posts_Tree::insert(long long key, const std::string& content) {
    root = insertHelper(root, key, content);
    size++;
}

void Posts_Tree::deleteTree(PostNode* node) {
    if (node) { deleteTree(node->left); deleteTree(node->right); delete node; }
}

void Posts_Tree::inorder(PostNode* root, int &k) {
    if (k == -1) k = size;
    if (!root || k <= 0) return;
    inorder(root->right, k);
    if (k > 0) { std::cout << root->content << std::endl; k--; }
    inorder(root->left, k);
}

Posts_Tree::Posts_Tree() : root(nullptr), size(0) {}
Posts_Tree::~Posts_Tree() { deleteTree(root); }
int Posts_Tree::getRootBalanceFactor() { return root ? getBalance(root) : 10; }
void Posts_Tree::inorder_helper(int k) { inorder(root, k); }
