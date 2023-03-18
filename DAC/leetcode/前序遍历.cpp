//
// Created by 刘日亮 on 2023/3/18.
//
/**
 *注意helper 里面 必须是引用
 * 层序遍历
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/submissions/
 */
#include  "leetcode.h"
class Solution {
public:

    void helper(TreeNode* root, vector<int> &res){
        if(!root) return;
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};