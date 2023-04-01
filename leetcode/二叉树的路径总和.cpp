// 可行性判断问题
// Created by 刘日亮 on 2023/3/20.
//
#include "leetcode.h"
class Solution{
public:
    //BFS
    bool hasPathSum(TreeNode* root, int targetSum){
        if(!root) return false;
        queue<int> values;
        queue<TreeNode*> nodes;
        values.push(root->val);
        nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            while (size--){
                TreeNode* node = nodes.front();nodes.pop();
                int temp = values.front();values.pop();
                if(node->left== nullptr&&node->right== nullptr){
                    if(temp == targetSum) return true;
                    continue;//到了叶子节点就不用push了
                }
                if(node->left!= nullptr){
                    nodes.push(node->left);
                    values.push(temp+node->val);
                }
                if(node->right!= nullptr){
                    nodes.push(node->right);
                    values.push(temp+node->val);
                }
            }
        }
        return false;
    }

    //DFS
    bool DFS_hasPathSum(TreeNode* root, int targetSum){
        if(root== nullptr)return false;
        if(root->val==targetSum&&root->left== nullptr&&root->right== nullptr) return true;
        //只要一个能成就是成了
        return DFS_hasPathSum(root->left,targetSum-root->val)||DFS_hasPathSum(root->right,targetSum-root->val);
    }


};