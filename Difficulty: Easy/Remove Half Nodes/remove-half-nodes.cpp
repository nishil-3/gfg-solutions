/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root ==nullptr) return nullptr;
        root -> left = RemoveHalfNodes(root-> left);
        root -> right = RemoveHalfNodes(root-> right);
        
        if(root -> left == nullptr && root -> right != nullptr)
        {
            Node * newRoot = root-> right ;
            delete root;
            return newRoot;
        }
        if(root -> left != nullptr && root -> right == nullptr)
        {
            Node * newRoot = root-> left ;
            delete root;
            return newRoot;
        }
        
        return root ;
    }
};