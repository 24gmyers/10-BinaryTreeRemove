Add a find(), contains() and remove() method to the binary tree class.  You may use the BinaryTreeDeleteTest.cpp Download BinaryTreeDeleteTest.cppfile to test to see that it passes all the test cases.

//The find method will be given a value and it will return the node that contains that particular value
//You might need an extra method to help with the recursion on this one much like the traversals
shared_ptr<Node<T>> find(const T& item);
//findRightMostNode() is a helper method used in the remove() function.  It should normally be a private method,
//but leave it public for testing purposes.
//Given a tree and a node, it will find the right most node of the branch from the given node
shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr);
//findParent() is a helper method used in the remove() function. It should normally be a private method,
//but leave it public for testing purposes.
//Given a tree and a node, it will find the right the parent of the given node
shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr);
//The remove will remove the given node from the list.  Remember there are four situations, no children, left child
//right child, and two children. 
void remove(const T& item);
The three above method descriptions are helper methods.  They will need to call a recursive method which will have a pointer to the node.  If you need some additional help with the remove method, I have added some pseudocode below
Delete Pseudocode 
If the current node is nullptr you may exit the method as there is nothing to delete (base case)

If the item to be removed has a greater value then the current node, recursive case to remove the node from the branch to the right 

If the item to be removed has a smaller value then the current node, recursive case to remove the node from the branch to the left

If you have found the item to be removed, there are three cases...

If the left pointer is null, replace the node with the right branch (base case)
else If the right pointer is null, replace the node with the left branch (base case)
Otherwise, replace the node's value with the value in the rightmost node of the left branch and remove the node that contains that value. (recursive case again)