#include "bst.h"
using std::runtime_error;

class Node;

BST::Node::Node(int value, Node* left, Node* right): value(value), left(left), right(right){
    // return this;
}

BST::Node::Node(){
    this->left = nullptr;
    this->right = nullptr;
    this->value = 0;
    // return this;
}

BST::Node::Node(const Node& node){
    this->value = node.value;
    this->left = node.left;
    this->right = node.right;
    // return this;
}

ostream& operator<<(ostream& os, BST::Node node){
    os<<"node: "<< &node <<endl<<"value: "<<node.value<<endl<<"left: "<<node.left<<endl<<"right: "<<node.right<<endl;
    return os;
}

// ==, <, <=, >, >= operators
bool operator==(const BST::Node node, const int num){return node.value==num;}
bool operator==(const int num,const BST::Node node){return node.value==num;}

bool operator<(const BST::Node node, const int num){return node.value<num;}
bool operator<(const int num, const BST::Node node){return num<node.value;}

bool operator<=(const BST::Node node,const int num){return node.value<=num;}
bool operator<=(const int num, const BST::Node node){return num<=node.value;}

bool operator>(const BST::Node node, const int num){return node.value>num;}
bool operator>(const int num, const BST::Node node){return num>node.value;}

bool operator>=(const BST::Node node,const int num){return node.value>=num;}
bool operator>=(const int num, const BST::Node node){return num>=node.value;}

BST::BST(){
    this->root = nullptr;
}

BST::Node* copyTree(BST::Node* root){
    if (root == nullptr)
        return nullptr;
    BST::Node* newRoot = new BST::Node(root->value, nullptr, nullptr);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

BST::BST(const BST& b){
    if(b.root ==nullptr){
        this->root = nullptr;
    }
    else{
        this->root = copyTree(b.root);
        // BST::Node* newRoot = new BST::Node(b->root->value,b->root->left,b->root->right);
        // newRoot->left = BST(b->root->left);
        // newRoot->right = BST(b->root->right);
        // this->root = newRoot;
    }
    // return this;
    // this->root = b->root;
}

BST::BST(BST&& b){
    this->root = b.root;
    b.root = nullptr;
}

void BST::deleteNode(Node* node) {
    if (node) {
        deleteNode(node->left);   // 递归删除左子树
        deleteNode(node->right);  // 递归删除右子树
        delete node;              // 删除当前节点
    }
}

BST::~BST(){
    deleteNode(this->root);
}

BST& BST::operator=(BST& b){
    this->root = copyTree(b.root);
    return *this;
}

BST& BST::operator=(BST&& b){
    this->root = b.root;
    b.root = nullptr;
    return *this;
}

// Node*& BST::get_root()
BST::Node*& BST::get_root(){
    return this->root;
}

// void BST::bfs(std::function<void(Node*& node)> func){

// }

// size_t BST::length(){
//     size_t node_cnt = 0;
// }

bool BST::add_node(int value){
    // Node* newNode = new Node(value,nullptr,nullptr);
    // cout << newNode<<endl;
    // cout<< "create node value = "<<newNode->value<<endl;
    if(this->root==nullptr){
        this->root = new Node(value,nullptr,nullptr);
        cout << "root is null"<<endl;
        return true;
    }
    Node* nodeRef = this->root;
    cout << nodeRef <<endl;
    cout << "root value = "<<nodeRef->value<<endl;
    while(true){
        cout <<"--->current node value = "<< nodeRef->value<<endl;
        if(value>nodeRef->value){
            if(nodeRef->right==nullptr) break;
            nodeRef = nodeRef->right;
        }
        else if(value<nodeRef->value){
            if(nodeRef->left==nullptr) break;
            nodeRef = nodeRef->left;
        }
        else{
            throw runtime_error("node is already exist!");
            return false;
        }


        // if(value>nodeRef->value){
        //     if(nodeRef->right!=nullptr){
        //         nodeRef = nodeRef->right;
        //         continue;
        //     }
        //     else{
        //         nodeRef->right = new Node(value,nullptr,nullptr);
        //         break;
        //     }
        // }
        // else if(value<nodeRef->value){
        //     if(nodeRef->left!=nullptr){
        //         nodeRef = nodeRef->left;
        //         cout<< "move to left"<<endl;
        //         continue;
        //     }
        //     else{
        //         nodeRef->left = new Node(value,nullptr,nullptr);
        //         cout << "insert value "<< value;
        //         cout << ", new root = "<<this->get_root()->value<<endl;
        //         break;
        //     }
        // }
        // else{
        //     throw runtime_error("node is already exist!");
        //     return false;
        // }
    }
    if(value>nodeRef->value){
        nodeRef->right = new Node(value,nullptr,nullptr);
        cout << "insert value "<< value;
        cout << ", new root = "<<this->get_root()->value<<endl;
    }
    else if(value<nodeRef->value){
        nodeRef->left = new Node(value,nullptr,nullptr);
        cout << "insert value "<< value;
        cout << ", new root = "<<this->get_root()->value<<endl;
    }
    else{
        throw runtime_error("node is already exist!");
        return false;
    }
    cout << endl;
    return true;
}
// Node** BST::find_node(int value){

// }
// Node** BST::find_parrent(int value){

// }
// Node** BST::find_successor(int value){

// }
// bool BST::delete_node(int value){
    
// }