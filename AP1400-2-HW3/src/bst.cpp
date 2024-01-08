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

ostream& operator<<(ostream& os, BST bst){
    os<<"********************************************************************************\n";
    ///////////////////////////////////
    std::queue<BST::Node*> bfsQueue;
    if(bst.get_root()!=nullptr){
        bfsQueue.push(bst.get_root());
    }

    while(!bfsQueue.empty()){
        BST::Node* current = bfsQueue.front();
        bfsQueue.pop();

        // func(current);
        // os << current <<"   ==> value:" << current->value << "    left:"<< current->left << "  right:"<< current->right<<"\n";
        os<< std::setw(10) << current << "   ==> value: " << current->value
              << "    left: " << std::setw(16) << current->left
              << "  right: " << std::setw(16) << current->right << "\n";

        if(current->left!=nullptr){
            bfsQueue.push(current->left);
        }
        if(current->right!=nullptr){
            bfsQueue.push(current->right);
        }
    }
    ///////////////////////////////////
    os<<"binary search tree size: "<<bst.length()<<"\n";
    os<<"********************************************************************************\n";
    return os;
}

// ==, <, <=, >, >= operators
bool operator==(const BST::Node& node, const int& num){return node.value==num;}
bool operator==(const int& num,const BST::Node& node){return node.value==num;}

bool operator<(const BST::Node& node, const int& num){return node.value<num;}
bool operator<(const int& num, const BST::Node& node){return num<node.value;}

bool operator<=(const BST::Node& node,const int& num){return node.value<=num;}
bool operator<=(const int& num, const BST::Node& node){return num<=node.value;}

bool operator>(const BST::Node& node, const int& num){return node.value>num;}
bool operator>(const int& num, const BST::Node& node){return num>node.value;}

bool operator>=(const BST::Node& node,const int& num){return node.value>=num;}
bool operator>=(const int& num, const BST::Node& node){return num>=node.value;}

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
    // cout << "BST1"<<endl;
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
    // cout << "BST2"<<endl;
    this->root = b.root;
    b.root = nullptr;
}

void BST::deleteNode(Node* node) {
    // auto pre = find_parrent(node->value);
    // if((*pre)->left!=nullptr&&(*pre)->left==node){
    //     (*pre)->left = nullptr;
    // }
    // if((*pre)->right != nullptr&&(*pre)->right==node){
    //     (*pre)->right = nullptr;
    // }
    
    if (node) {
        // if(node->left!=nullptr) 
        deleteNode(node->left);   // 递归删除左子树
        // if(node->right!=nullptr) 
        deleteNode(node->right);  // 递归删除右子树
        delete node;              // 删除当前节点
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

void printNode(BST::Node*& node) {
    std::cout << "Node: " << node << "Node value: " << node->value << std::endl;
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
            // throw runtime_error("node is already exist!");
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
        // throw runtime_error("node is already exist!");
        return false;
    }
    // cout << endl;
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
    // throw runtime_error("404 Not FOUND");
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
    Node** current = find_node(value);
    if(current==nullptr) return nullptr;
    // nullptr;
    // try{
    //     current = find_node(value);    
    // }
    // catch(runtime_error){
        // throw runtime_error("Not EXIST, NO successor! ");
    //     return nullptr;
    // }
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
        current = &((*current)->left);
        while((*current)->right!=nullptr){
            current = &((*current)->right);
        }
        return current;
    }
}
bool BST::delete_node(int value){
    //NOTE: 删除操作节点地址不能做修改，只能改变指针！
    if(find_node(value)==nullptr){
        // throw runtime_error("Value not exist");
        return false;
    }
    if(find_successor(value)==nullptr){
        cout << "delete leaf"<<endl;
        auto current = *find_node(value);
        auto curr_pre = *find_parrent(value);
        if(curr_pre->left!=nullptr){
            // cout << "left leaf"<<endl;
            if(curr_pre->left->value == value){
                curr_pre->left = nullptr;
            }
        }
        if(curr_pre->right!=nullptr){
            // cout << "right leaf"<<endl;
            if(curr_pre->right->value == value){
                // cout << "delete it"<<endl;
                curr_pre->right = nullptr;
            }
        }
        delete current;
        // deleteNode(*find_node(value));
        return true;
    }
    else{
        /*old version: 修改节点的值，递归实现，释放掉最后一个叶子结点*/
        // auto current = find_node(value);
        // auto successor = find_successor(value);
        // int tmp_value = (*successor)->value;
        // delete_node(tmp_value);
        // (*current)->value = tmp_value;

        /*new version: 只操作ptr*/
        //case1 left or right = nullptr
        auto current = *find_node(value);
        // cout << *current <<endl;
        if(current->left==nullptr){
            auto pre = *find_parrent(value);
            if(pre->left!=nullptr&&pre->left==current){
                pre->left = *find_successor(value);
            }
            if(pre->right!=nullptr&&pre->right==current){
                pre->right = *find_successor(value);
            }
        }
        else if(current->right==nullptr){
            // cout << "right is null"<<endl;
            auto pre = *find_parrent(value);
            // cout << *pre<<endl;
            if(pre->left!=nullptr&&pre->left==current){
                pre->left = *find_successor(value);
            }
            if(pre->right!=nullptr&&pre->right==current){
                pre->right = *find_successor(value);
            }
        }
        //case2 left and right != nullptr
        else{
            auto successor = *find_successor(value);
            // cout << "successor: " << endl;
            // cout<<*successor<<endl;
            // cout<<**find_successor(value)<<endl;
            auto succ_pre = *find_parrent(successor->value);
            // cout << "succ_pre: " << endl;
            // cout <<*succ_pre <<endl;
            auto curr_pre = *find_parrent(value);
            // cout <<*curr_pre <<endl;
            // cout << "brfore delete: " << endl;
            // cout << *this << endl;
            // step2 succ_pre->nullptr
            // cout <<  << endl;
            if(succ_pre->left!=nullptr){
                // cout << succ_pre->left->value <<"=?"<<successor->value<< endl;
                if(succ_pre->left->value==successor->value)
                // succ_pre->left == nullptr;//FUCK!!!
                succ_pre->left = nullptr;
            }
            if(succ_pre->right!=nullptr){
                cout << succ_pre->right->value <<"=?"<<successor->value<<endl;
                if(succ_pre->right->value==successor->value){
                    // succ_pre->right == nullptr; //FUCK!!!
                    succ_pre->right = nullptr;
                    // cout << *succ_pre <<endl<<endl;
                    // cout << **find_parrent(successor->value)<<endl;
                }
            }
            // cout << "step2, succ_pre->nullptr " << endl;
            // cout << *this << endl;
            // step1 curr_pre->succ
            // cout << current->value<<"=?"<<this->root->value<<endl;
            if(current->value!=this->root->value){
                //delete no-root
                if(curr_pre->left!=nullptr&&curr_pre->left->value==current->value){
                    curr_pre->left = successor;
                }
                if(curr_pre->right!=nullptr&&curr_pre->right->value==current->value){
                    curr_pre->right = successor;
                }
                // cout << *this << endl;
            }
            else{
                this->root = successor;
            }
            
            // step3 ? succ_pre->succ_succ
            if(successor->left!=nullptr){
                cout << "succ has left subtree"<<endl;
                // auto succ_succssor = successor->left;
                // succ_pre->right = succ_succssor;
                succ_pre->right = successor->left;
                successor->left = nullptr;
            }
            // cout << *this<<endl;
            // cout << *this <<endl;
            //step4 & 5 fix succ->left&right
            
            successor->left = current->left;
            successor->right = current->right;
            // cout << *this <<endl;
            current->left = nullptr;
            current->right = nullptr;
            delete current;
        }
    }
    return true;
}

void xpplus(BST::Node*& node) {
    node->value++;
}

void pplusx(BST::Node*& node){
    ++node->value;
}

BST& BST::operator++(){
    //++i
    bfs(pplusx);
    return *this;
}
BST BST::operator++(int){
    //i++
    BST newBst = BST(*this);
    bfs(xpplus);
    return newBst;
}

BST::BST(std::initializer_list<int> values) : root(nullptr) {
    for (int value : values) {
        insert(value);
    }
}

void BST::insert(int value) {
    root = insertRecursive(root, value);
}

BST::Node* BST::insertRecursive(BST::Node* node, int value) {
    if (node == nullptr) {
        return new Node(value,nullptr,nullptr);
    }

    if (value < node->value) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->value) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}