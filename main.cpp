#include <iostream>
#include <unordered_map>
#include <sstream>
#include "User.hpp"
#include "utils.hpp"

int main() {
    std::unordered_map<std::string, User*> userMap;
    while (true) {
        std::string line;
        std::cout << "Enter command: ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "ADD_USER") {
            std::string username;
            getline(ss, username);
            if (!username.empty() && username[0] == ' ') username = username.substr(1);
            std::string key = toLowerStr(username);
            if (userMap.find(key) != userMap.end()) { std::cout << "User already exists!" << std::endl; continue; }
            userMap[key] = new User(username);
        } else if (command == "ADD_FRIEND") {
            std::string friend1name, friend2name;
            ss >> std::ws;
            getline(ss, friend1name, ' ');
            getline(ss, friend2name);
            if (!friend1name.empty() && friend1name[0] == ' ') friend1name = friend1name.substr(1);
            if (!friend2name.empty() && friend2name[0] == ' ') friend2name = friend2name.substr(1);
            friend1name = toLowerStr(friend1name);
            friend2name = toLowerStr(friend2name);
            if (userMap.find(friend1name) == userMap.end() || userMap.find(friend2name) == userMap.end()) {
                std::cout << "One or both users not found!" << std::endl;
                continue;
            } else if(friend1name==friend2name){
                std::cout<<"A user cannot befriend themselves!"<<std::endl;
                continue;
            } else {
                userMap[friend1name]->add_friend(userMap[friend2name]->getname(), userMap[friend2name]);
                userMap[friend2name]->add_friend(userMap[friend1name]->getname(), userMap[friend1name]);
            }
        } else if (command == "LIST_FRIENDS") {
            std::string username;
            ss >> std::ws;
            getline(ss, username);
            username = toLowerStr(username);
            if (userMap.find(username) == userMap.end()) {
                std::cout << "User not found!" << std::endl;
                continue;
            }
            userMap[username]->list_friends();
        } else if (command == "SUGGEST_FRIENDS") {
            std::string friend1name;
            int n=-100;
            ss >> std::ws;
            getline(ss, friend1name, ' ');
            ss >> n;
            if (!friend1name.empty() && friend1name[0] == ' ') friend1name = friend1name.substr(1);
            friend1name = toLowerStr(friend1name);
            if (userMap.find(friend1name) == userMap.end()) {
                std::cout << "User not found!" << std::endl;
                continue;
            }
            userMap[friend1name]->suggest_friends(n);
        } else if (command == "DEGREES_OF_SEPARATION") {
            std::string friend1name, friend2name;
            ss >> std::ws;
            getline(ss, friend1name, ' ');
            getline(ss, friend2name);
            if (!friend1name.empty() && friend1name[0] == ' ') friend1name = friend1name.substr(1);
            if (!friend2name.empty() && friend2name[0] == ' ') friend2name = friend2name.substr(1);
            friend1name = toLowerStr(friend1name);
            friend2name = toLowerStr(friend2name);
            if (userMap.find(friend1name) == userMap.end() || userMap.find(friend2name) == userMap.end()) {
                std::cout << "One or both users not found!" << std::endl;
                continue;
            }
            int distance = userMap[friend1name]->getDistance(friend2name);
            std::cout << "Degrees of separation: " << distance << std::endl;
        } else if (command == "ADD_POST") {
            std::string username, content;
            ss >> std::ws;
            getline(ss, username, ' ');
            getline(ss, content);
            if (!username.empty() && username[0] == ' ') username = username.substr(1);
            if (!content.empty() && content[0] == ' ') content = content.substr(1);
            std::string key = toLowerStr(username);
            if (userMap.find(key) == userMap.end()) {
                std::cout << "User not found!" << std::endl;
                continue;
            }
            userMap[key]->add_post(content);
        } else if (command == "OUTPUT_POSTS") {
            int k;
            std::string username;
            ss >> std::ws;
            getline(ss, username, ' ');
            ss >> k;
            if (!username.empty() && username[0] == ' ') username = username.substr(1);
            std::string key = toLowerStr(username);
            if (userMap.find(key) == userMap.end()) {
                std::cout << "User not found!" << std::endl;
                continue;
            }
            if (k < -1) {
                std::cout << "Invalid number of posts!" << std::endl;
                continue;
            }else if (k == -1) {
                k = 1000000000;
            }
            userMap[key]->view_posts(k);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}
