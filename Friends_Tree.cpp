#include "Friends_Tree.hpp"
#include <iostream>
#include <algorithm>

int Friends_Tree::height(Node* N) { return N ? N->height : -1; }

Node* Friends_Tree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* Friends_Tree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

int Friends_Tree::getBalance(Node* N) { return N ? height(N->left) - height(N->right) : 0; }

Node* Friends_Tree::insertHelper(Node* node, const std::string& key) {
    if (!node) return new Node(key);
    if (ci_less(key, node->key)) node->left = insertHelper(node->left, key);
    else if (ci_less(node->key, key)) node->right = insertHelper(node->right, key);
    else return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && ci_less(key, node->left->key)) return rightRotate(node);
    if (balance < -1 && ci_less(node->right->key, key)) return leftRotate(node);
    if (balance > 1 && ci_less(node->left->key, key)) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (balance < -1 && ci_less(key, node->right->key)) { node->right = rightRotate(node->right); return leftRotate(node); }
    return node;
}

bool Friends_Tree::present(std::string st) {
    Node* curr = root;
    while (curr) {
        if (ci_less(st, curr->key)) curr = curr->left;
        else if (ci_less(curr->key, st)) curr = curr->right;
        else return true;
    }
    return false;
}

void Friends_Tree::deleteTree(Node* node) { if (node) { deleteTree(node->left); deleteTree(node->right); delete node; } }
void Friends_Tree::inorder(Node* root) { if (root) { inorder(root->left); std::cout << root->key << std::endl; inorder(root->right); } }
Friends_Tree::Friends_Tree() : root(nullptr) {}
Friends_Tree::~Friends_Tree() { deleteTree(root); }
void Friends_Tree::insert(const std::string& key) { root = insertHelper(root, key); }
int Friends_Tree::getRootBalanceFactor() { return root ? getBalance(root) : 10; }
void Friends_Tree::inorder() { inorder(root); }
