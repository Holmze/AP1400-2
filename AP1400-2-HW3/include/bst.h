#ifndef BST_H
#define BST_H
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <initializer_list>



using std::cout;
using std::endl;
using std::ostream;
using std::queue;
using std::vector;
// using std::runtime_error;
class BST
{
public:
    class Node
    {
    public:
        Node(int value, Node* left, Node* right);
        Node();
        Node(const Node& node);

        int value;
        Node* left;
        Node* right;
    };
    BST();              // default constructor
    BST(const BST& b);  // copy constructor
    BST(BST&& b);       // move constructor
    ~BST();             // destructor
    BST(std::initializer_list<int> list);
    void deleteNode(Node* node);
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

    friend ostream& operator<<(ostream& os, BST b);
    BST& operator++();//op++
    BST operator++(int);//++op

    BST& operator=(BST& b);
    BST& operator=(BST&& b);
    Node* insertRecursive(Node* node, int value);
    void insert(int value);

private:
    
    Node* root;
    
};

ostream& operator<<(ostream& os, BST::Node node);

bool operator==(const BST::Node& node, const int& num);
bool operator==(const int& num, const BST::Node& node);

bool operator<(const int& num, const BST::Node& node);
bool operator<(const BST::Node& node, const int& num);

bool operator<=(const int& num, const BST::Node& node);
bool operator<=(const BST::Node& node, const int& num);

bool operator>(const int& num, const BST::Node& node);
bool operator>(const BST::Node& node, const int& num);

bool operator>=(const int& num, const BST::Node& node);
bool operator>=(const BST::Node& node, const int& num);
void printNodeValue(BST::Node*& node);
#endif //BST_H