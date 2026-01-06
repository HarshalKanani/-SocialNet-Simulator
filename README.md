COL106 LONG ASSIGNMENT 2: SocialNet Simulator
==========================================

------------------------------------------
1. **INTRODUCTION**
------------------------------------------
This project implements a command-line social network simulator called **SocialNet**.
The simulator allows users to create accounts, add friends, make posts, view posts, 
and find mutual friend suggestions — all using custom AVL Tree and Graph implementations.

The system models:
- Each user as a vertex in a graph.
- Friendships as undirected edges.
- User posts stored in a self-balanced AVL tree.

------------------------------------------
2. **FILE STRUCTURE**
------------------------------------------
The provided project is modular and divided as follows:

```
social_network
│
├── utils.hpp        -> Case-insensitive helpers and string utilities.
├── utils.cpp
│
├── PostNode.hpp     -> Definition of a node in the Posts AVL Tree.
├── Posts_Tree.hpp   -> Header for Posts_Tree class.
├── Posts_Tree.cpp   -> Implementation of AVL tree storing user posts.
│
├── Friends_Tree.hpp -> Header for Friends AVL tree (alphabetically sorted friend list).
├── Friends_Tree.cpp -> Implementation of friend AVL operations.
│
├── User.hpp         -> User class managing friendships, posts, and BFS-based graph logic.
├── User.cpp         -> Implementation of User class methods.
│
└── main.cpp         -> Main driver handling all user commands.
```
------------------------------------------
3. **COMPILATION INSTRUCTIONS**
------------------------------------------
Make sure you have g++ (C++17 or later) installed.

To compile the full program, open a terminal in the `social_network` folder and run:

    g++ main.cpp User.cpp Posts_Tree.cpp Friends_Tree.cpp utils.cpp -o socialnet

This will produce an executable file named **socialnet**.

------------------------------------------
4. **RUNNING THE PROGRAM**
------------------------------------------
To run the compiled program:

    ./socialnet

The program will then prompt you with:
    Enter command:

You can now type commands as described below.

------------------------------------------
5. **COMMAND REFERENCE**
------------------------------------------

All usernames and post contents are **case-insensitive**.

1️⃣  ADD_USER <username>
    - Adds a new user with no friends or posts.

2️⃣  ADD_FRIEND <username1> <username2>
    - Creates a bidirectional friendship between the two users.

3️⃣  LIST_FRIENDS <username>
    - Prints all friends of <username> in alphabetical order.

4️⃣  SUGGEST_FRIENDS <username> <N>
    - Suggests up to N users who are "friends of friends" (not already friends).
    - Sorted by number of mutual friends (descending), then alphabetically.

5️⃣  DEGREES_OF_SEPARATION <username1> <username2>
    - Prints the minimum number of friendships (edges) connecting two users.
    - Prints -1 if no connection exists.

6️⃣  ADD_POST <username> <post content>
    - Adds a new post for the user.
    - Example: ADD_POST Alice "My first post!"

7️⃣  OUTPUT_POSTS <username> <N>
    - Displays the most recent N posts by the user in reverse chronological order.
    - If N = -1, displays all posts.

8️⃣  EXIT
    - Exits the simulator.

------------------------------------------
7. **NOTES**
------------------------------------------
- All usernames are case-insensitive (Alice == alice == ALICE).
- Posts are stored in an AVL tree with insertion timestamps to preserve order.
- Friend suggestions are computed using the "friends of friends" heuristic.
- All tree balancing operations (rotations, balance factors) follow AVL logic.
