#ifndef POSTNODE_HPP
#define POSTNODE_HPP

#include <string>

// 64-bit key to store timestamps safely
struct PostNode {
    long long key;
    PostNode* left;
    PostNode* right;
    int height;
    std::string content;

    PostNode(long long k, const std::string& cont) : key(k), left(nullptr), right(nullptr), height(0), content(cont) {}
};

#endif
