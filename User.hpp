#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Posts_Tree.hpp"
#include "Friends_Tree.hpp"

class User {
public:
    std::string username;
private:
    Posts_Tree postsTree;
    Friends_Tree friends;
    std::vector<User*> friendList;
    int totalposts;

public:
    User();
    User(const std::string& name);
    void add_friend(const std::string& friendName, User* friendUser);
    std::string getname();
    void list_friends();
    void suggest_friends(int n);
    int getDistance(const std::string& friendName);
    void add_post(const std::string& content);
    void view_posts(int k);
    // friend accessors for main if needed
    std::vector<User*>& getFriendList() { return friendList; }
    Friends_Tree& getFriendsTree() { return friends; }
};

#endif
