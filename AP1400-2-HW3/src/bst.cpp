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

ostream& operator<<(ostream& os, const BST::Node node){
    os<<"node: "<< &node
      <<"\nvalue: "<<node.value
      <<"\nleft: "<<node.left
      <<"\nright: "<<node.right;
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
    // this->root = new BST::Node{};
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
    auto pre = find_parrent(node->value);
    // cout << **pre<<endl;
    if((*pre)->left!=nullptr&&(*pre)->left==node){
        (*pre)->left = nullptr;
    }
    // cout << "1"<<endl;
    // else if((*pre)->left==node){
    //     (*pre)->left = nullptr;
    // }
    if((*pre)->right != nullptr&&(*pre)->right==node){
        (*pre)->right = nullptr;
    }
    // cout << "2"<<endl;
    
    // else if((*pre)->right == node){
    //     (*pre)->right = nullptr;
    // }
    if (node) {
        // cout << "3"<<endl;
        if(node->left!=nullptr) deleteNode(node->left);   // 递归删除左子树
        // cout << "4"<<endl;
        if(node->right!=nullptr) deleteNode(node->right);  // 递归删除右子树
        // cout << "5"<<endl;
        delete node;              // 删除当前节点
        // cout << "6"<<endl;
    }
}

// BST::~BST(){
//     deleteNode(this->root);
// }

 BST::~BST()
 {
 	std::vector<Node*> nodes;
 	bfs([&nodes](BST::Node*& node){nodes.push_back(node);});
 	for(auto& node: nodes)
 		delete node;
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

BST::Node*& BST::get_root(){
    return this->root;
}

void printNodeValue(BST::Node*& node) {
    std::cout << "Node value: " << node->value << std::endl;
}

void BST::bfs(std::function<void(Node*& node)> func){
    std::queue<Node*> bfsQueue;
    if(this->root!=nullptr){
        bfsQueue.push(this->root);
    }

    while(!bfsQueue.empty()){
        Node* current = bfsQueue.front();
        bfsQueue.pop();

        func(current);

        if(current->left!=nullptr){
            bfsQueue.push(current->left);
        }
        if(current->right!=nullptr){
            bfsQueue.push(current->right);
        }
    }
}

int cnt_node(BST::Node* node){
    if(node==nullptr){
        return 0;
    }
    else{
        return 1+cnt_node(node->left)+cnt_node(node->right);
    }
}

size_t BST::length(){
    return (size_t)cnt_node(this->root);
}

bool BST::add_node(int value){
    // Node* newNode = new Node(value,nullptr,nullptr);
    // cout << newNode<<endl;
    // cout<< "create node value = "<<newNode->value<<endl;
    if(this->root==nullptr){
        this->root = new Node(value,nullptr,nullptr);
        // cout << "root is null"<<endl;
        return true;
    }
    Node* nodeRef = this->root;
    // cout << nodeRef <<endl;
    // cout << "root value = "<<nodeRef->value<<endl;
    while(true){
        // cout <<"--->current node value = "<< nodeRef->value<<endl;
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
        // cout << "insert value "<< value;
        // cout << ", new root = "<<this->root->value<<endl;
    }
    else if(value<nodeRef->value){
        nodeRef->left = new Node(value,nullptr,nullptr);
        // cout << "insert value "<< value;
        // cout << ", new root = "<<this->root->value<<endl;
    }
    else{
        throw runtime_error("node is already exist!");
        return false;
    }
    cout << endl;
    return true;
}
BST::Node** BST::find_node(int value){
    Node** current = &this->root;
    while(*current!=nullptr){
        if((*current)->value == value){
            // cout<<"Find node, value = "<<(*current)->value<<endl;
            return current;
        }
        else if(value > (*current)->value){
            current = &((*current)->right);
        }
        else{
            current = &((*current)->left);
        }
    }
    throw runtime_error("404 Not FOUND");
    return nullptr;
}
BST::Node** BST::find_parrent(int value){
    //前驱parent node
    Node* current = get_root();
    Node* pre = nullptr;
    while (current != nullptr) {
        if (value > current->value) {
            pre = current;
            current = current->right;
        } else if (value < current->value) {
            pre = current;
            current = current->left;
        } else {
            break;
        }
    }
    if (current == nullptr)
        return nullptr;
    else {
        Node** result{new Node* {pre}};
        return result;
    }

    ///以下代码误解为要寻找对称节点
    // if(find_node(value)==nullptr){
    //     throw runtime_error("404 Not FOUND");
    //     return nullptr;
    // }
    // vector<int> trace = {};
    // //false->0->left
    // //ture->1->right
    // Node** current = &this->root;
    // while(*current!=nullptr){
    //     if((*current)->value == value){
    //         // cout<<"Find node, value = "<<(*current)->value<<endl;
    //         break;
    //         // return current;
    //     }
    //     else if(value > (*current)->value){
    //         trace.push_back(true);
    //         current = &((*current)->right);
    //     }
    //     else{
    //         trace.push_back(false);
    //         current = &((*current)->left);
    //     }
    // }
    // current = &this->root;
    // for(int i=0;i<trace.size();i++){
    //     cout << **current <<endl;
    //     if(*current==nullptr){
    //         // cout << "NULLPTR"<<endl;
    //         throw runtime_error("No pattern node");
    //         return nullptr;
    //     }
    //     else if(trace[i]){
    //         //=1, thrn left
    //         current = &((*current)->left);
    //     }
    //     else{
    //         //=0, turn right
    //         current = &((*current)->right);
    //     }
    // }
    // return current;
}
BST::Node** BST::find_successor(int value){
    // auto current = find_node(value);
    Node** current = nullptr;
    try{
        current = find_node(value);    
    }
    catch(runtime_error){
        throw runtime_error("Not EXIST, NO successor! ");
        return nullptr;
    }
    // if(current == nullptr){
    //     throw runtime_error("Not EXIST, NO successor! ");
    //     return nullptr;
    // }
    if((*current)->left == nullptr&&(*current)->right==nullptr){
        // cout << "end of tree"<<endl;
        return nullptr;
    }
    else if((*current)->left == nullptr){
        return &((*current)->right);
    }
    else if((*current)->right == nullptr){
        return &((*current)->left);
    }
    else{
        //select min value of right subtree
        current = &((*current)->right);
        while((*current)->left!=nullptr){
            current = &((*current)->left);
        }
        return current;
    }
}
bool BST::delete_node(int value){
    if(find_node(value)==nullptr){
        throw runtime_error("Value not exist");
        return false;
    }
    if(find_successor(value)==nullptr){
        // auto pre = find_parrent(value);
        // if((*pre)->left==nullptr){
        //     (*pre)->right= nullptr;
        // }
        // // else if((*pre)->right==nullptr){
        // else{
        //     (*pre)->left=nullptr;
        // }
        // else{
        //     if((*pre)->left==*find_node(value)){
        //         (*pre)->left = nullptr;
        //     }
        //     else{
        //         (*pre)->right = nullptr;
        //     }
        // }
        deleteNode(*find_node(value));
        return true;
    }
    else{
        auto current = find_node(value);
        auto successor = find_successor(value);
        // int tmp = (*current)->value;
        // auto pre = find_parrent((*successor)->value);
        // cout <<"current is "<< **current <<endl;
        // cout <<"succ is "<< **successor <<endl;
        // cout <<"pre is "<< **pre <<endl;
        int tmp_value = (*successor)->value;
        delete_node(tmp_value);
        (*current)->value = tmp_value;
        // if((*pre)->right == nullptr){
        //     (*pre)->left = nullptr;
        // }
        // else if((*pre)->right==*successor){
        //     (*pre)->right = nullptr;
        // }
        // if((*pre)->left == nullptr){
        //     (*pre)->right = nullptr;
        // }
        // else if((*pre)->left==*successor){
        //     (*pre)->left = nullptr;
        // }
        // (*current)->value = (*successor)->value;
        // (*successor)->value = tmp;
        // deleteNode(find_node(value));
        
        // delete *successor;
    }
}