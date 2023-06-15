/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string solve(TreeNode* root)
    {
         if(!root)
            return "";
        return to_string(root->val)+"#"+solve(root->left)+solve(root->right);
    }
    string serialize(TreeNode* root) {
       string x=solve(root);
        // cout<<x<<" ";
        return x;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=NULL;
        string s="";
        for(int i=0;i<data.size();i++)
        {
            if(data[i]=='#')
            {
                int num=stoi(s);
                root=build(root,num);
                s="";
                
            }
            else
            {
                s+=data[i];
            }
        }
        return root;
    }
    TreeNode *build(TreeNode *root,int num)
    {
        if(root==NULL) {
            return new TreeNode(num);
        }
        if(num>root->val)
        {
            root->right=build(root->right,num);
        }
        if(num<root->val)
        {
            root->left=build(root->left,num);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;