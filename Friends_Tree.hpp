#ifndef FRIENDS_TREE_HPP
#define FRIENDS_TREE_HPP

#include <string>
#include "utils.hpp"

struct Node {
    std::string key;
    Node* left;
    Node* right;
    int height;
    Node(const std::string& k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

class Friends_Tree {
private:
    Node* root;
    int height(Node* N);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    int getBalance(Node* N);
    Node* insertHelper(Node* node, const std::string& key);
    void deleteTree(Node* node);
    void inorder(Node* root);

public:
    Friends_Tree();
    ~Friends_Tree();
    void insert(const std::string& key);
    int getRootBalanceFactor();
    void inorder();
    bool present(std::string st);
};

#endif
