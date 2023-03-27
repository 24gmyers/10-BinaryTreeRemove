#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
class BTree{
    private:
        shared_ptr<Node<T>> find(const T& item){
        //The find method will be given a value and it will return the node that contains that particular value. You might need an extra method to help with the recursion on this one much like the traversals

        }

        shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr){
        //findRightMostNode() is a helper method used in the remove() function.  It should normally be a private method, but leave it public for testing purposes. Given a tree and a node, it will find the right most node of the branch from the given node

        }

        shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr){
        //findParent() is a helper method used in the remove() function. It should normally be a private method, but leave it public for testing purposes. Given a tree and a node, it will find the right the parent of the given node

        }

        void remove(const T& item){
        //The remove will remove the given node from the list.  Remember there are four situations, no children, left child right child, and two children. 

        }
    public:
    
};