#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
struct Node {
    Node(T data) : data(data), left(nullptr), right(nullptr), parent(nullptr) {};
    Node(){};
    T data;
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;
    shared_ptr<Node<T>> parent;
};

template <typename T>
class BTree{
    public:
        BTree():root(nullptr){}
        void insert(const T& item){
            if (root == nullptr){
                root = make_shared<Node<T>>(item);
            }else {
                insert(item, root);
            }
        }
        
        void insert(const T& item, shared_ptr<Node<T>> ptr){
            if(item < ptr->data){//Check if it goes to the left
                //If there is no node to the left, insert new node here
                if(ptr->left == nullptr){
                    auto newNode = make_shared<Node<T>>();
                    newNode->data = item;
                    newNode->parent = ptr;
                    ptr->left = move(newNode);
                }else {//Otherwise keep going to the left
                    insert(item, ptr->left);
                }
            }else{//Goes to the right
                //If there is no node to the right, insert new node here
                if(ptr->right == nullptr){
                    auto newNode = make_shared<Node<T>>();
                    newNode->data = item;
                    newNode->parent = ptr;
                    ptr->right = move(newNode);
                }else{//Otherwise keep going to the left
                    insert(item, ptr->right);
                }
            }
        }

        void inOrder(){
            inOrder(root);
        }

        void inOrder(shared_ptr<Node<T>> ptr){
            //Until all nodes are traversed −
            if (ptr){
                cout << ptr->data << " ";
                // Step 1 − Recursively traverse left subtree.
                inOrder(ptr->left);
                // Step 2 − Visit root node.
                cout << root->data << " ";
                // Step 3 − Recursively traverse right subtree.
                inOrder(ptr->right);
            }
        }

        shared_ptr<Node<T>> find(const T& item){
        //The find method will be given a value and it will return the node that contains that particular value. You might need an extra method to help with the recursion on this one much like the traversals
            return find(item, root);
        }
        
        shared_ptr<Node<T>> find(const T& item, shared_ptr<Node<T>> ptr){
            if(item < ptr->data){
                find(item, ptr->left);
            }else if (item > ptr->data){
                find(item, ptr->right);
            }else{
                return ptr;
            }
        }

        shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr){
        //findRightMostNode() is a helper method used in the remove() function.  It should normally be a private method, but leave it public for testing purposes. Given a tree and a node, it will find the right most node of the branch from the given node
            if (ptr->right){
                findRightMostNode(ptr->right);
            }else{
                return ptr;
            }
        }

        shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr){
        //findParent() is a helper method used in the remove() function. It should normally be a private method, but leave it public for testing purposes. Given a tree and a node, it will find the right the parent of the given node
            return ptr->parent;
        }

        void remove(const T& item){
        //The remove will remove the given node from the list.  Remember there are four situations: no children, left child, right child, and two children. 
            auto curr = find(item);

            if(curr->parent->left->data == item){ //am the left child
                if(curr->left && curr->right){ //has two children
                    
                }else if(curr->left && !curr->right){ //has left child only
                    
                }else if(curr->right && !curr->left){ //has right child only

                }else{ // has no children

                }
            }else{ //am the right child
                if(curr->left && curr->right){ //has two children
                
                }else if(curr->left && !curr->right){ //has left child only
                    
                }else if(curr->right && !curr->left){ //has right child only

                }else{ // has no children

                }
            }

            


            // auto curr = root;
            // if(curr){
            //     if (item > curr->data){
            //         remove(curr->right);
            //     }else if (item < curr->data){
            //         remove(curr->left);
            //     }else{
            //         if(curr->left == nullptr){
            //             curr = curr->right;
            //         }else if(curr->right == nullptr){
            //             curr = curr->left;
            //         }else{
            //             curr = findRightMostNode(curr->left);
            //             remove(curr->right);
            //         }
            //     }
                
            // }else{
            //     return;
            // }
        }
        
    private:
        shared_ptr<Node<T>> root;
};