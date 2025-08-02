/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans ;
        if (root == nullptr) return ans ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for (int i =0;i<size;i++)
            {
                Node* node = q.front();
                q.pop();
                if (i==0)
                {
                    ans.push_back(node->data);
                }
                if(node-> left) q.push(node-> left);
                              if(node-> right) q.push(node-> right);
                              
            }
        }
        return ans ;
    }
};