class Solution {
public:
    vector<vector<int>> v;
    void r(TreeNode* root,int target,vector<int> temp){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            if(target-root->val==0){
                temp.push_back(root->val);
                v.push_back(temp);
            }
            return ;
        }
        temp.push_back(root->val);
        r(root->left,target-root->val,temp);
        r(root->right,target-root->val,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        r(root,targetSum,temp);
        return v;
    }
};
