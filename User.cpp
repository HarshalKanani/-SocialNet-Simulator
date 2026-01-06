#include "User.hpp"
#include "utils.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <ctime>
#include <algorithm>

User::User() : totalposts(0) {}
User::User(const std::string& name) : username(name), totalposts(0) {}

void User::add_friend(const std::string& friendName, User* friendUser) {
    friends.insert(friendName);
    friendList.push_back(friendUser);
}

std::string User::getname() { return username; }
void User::list_friends() { friends.inorder(); }

void User::suggest_friends(int n) {
    std::unordered_map<std::string, int> suggestions;
    for (auto friendUser : friendList) {
        for (auto fof : friendUser->friendList) {
            if (!friends.present(fof->username) && fof->username != this->username) {
                suggestions[fof->username]++;
            }
        }
    }
    std::vector<std::pair<std::string, int>> suggVec(suggestions.begin(), suggestions.end());
    std::sort(suggVec.begin(), suggVec.end(), comparePairs<int>);
    for (int i = 0; i < std::min(n, (int)suggVec.size()); i++) {
        std::cout << suggVec[i].first << " (" << suggVec[i].second << " mutual friends)" << std::endl;
    }
}

int User::getDistance(const std::string& friendName) {
    std::queue<std::pair<User*, int>> q;
    std::unordered_map<User*, bool> visited;
    q.push({this, 0});
    visited[this] = true;
    std::string lowerFriendName = toLowerStr(friendName);
    while (!q.empty()) {
        auto currentUser = q.front().first;
        auto distance = q.front().second;
        q.pop();
        if (toLowerStr(currentUser->username) == lowerFriendName) {
            return distance;
        }
        for (auto friendUser : currentUser->friendList) {
            if (!visited[friendUser]) {
                visited[friendUser] = true;
                q.push({friendUser, distance + 1});
            }
        }
    }
    return -1;
}

void User::add_post(const std::string& content) {
    long long key = static_cast<long long>(time(0));
    key = key * 1000LL + totalposts;
    postsTree.insert(key, content);
    totalposts++;
}

void User::view_posts(int k) { postsTree.inorder_helper(k); }
