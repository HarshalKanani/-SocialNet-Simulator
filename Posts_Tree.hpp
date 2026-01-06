#ifndef POSTS_TREE_HPP
#define POSTS_TREE_HPP

#include "PostNode.hpp"
#include <string>

class Posts_Tree {
private:
    PostNode* root;
    int size;

    int height(PostNode* N);
    PostNode* rightRotate(PostNode* y);
    PostNode* leftRotate(PostNode* x);
    int getBalance(PostNode* N);
    PostNode* insertHelper(PostNode* node, long long key, const std::string& content);
    void deleteTree(PostNode* node);
    void inorder(PostNode* root, int &k);

public:
    Posts_Tree();
    ~Posts_Tree();
    void insert(long long key, const std::string& content);
    int getRootBalanceFactor();
    void inorder_helper(int k);
};

#endif
