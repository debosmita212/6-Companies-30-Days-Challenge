//Leetcode 2265
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int &sum,int &count){
        //base case
        if(root==NULL){
            sum=0,count=0;
            return 0;
        }

        int sum1=0,count1=0,sum2=0,count2=0;
        //left subtree
        int ans1=dfs(root->left,sum1,count1);
        //right subtree
        int ans2=dfs(root->right,sum2,count2);

        int ans=ans1+ans2;
        sum=sum1+sum2+root->val;
        count=count1+count2+1; //1 for root
        int avg=(sum/(double)count); //calculate the average

        if(avg==root->val) ans++;
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum,count;
        return dfs(root,sum,count);
    }
};
