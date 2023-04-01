//
// Created by 刘日亮 on 2023/3/20.
//
#include "leetcode.h"
class Solution{
public:
/*
我们可以使用深度优先搜索的方式遍历整棵树，用哈希表记录遍历过的节点的值。
*///DFS
    unordered_set<int> hashTable;
    bool findTarget1(TreeNode* root, int k){
        if(root == nullptr) return false;
        if(hashTable.count(k-root->val)){
            return true;
        }
        hashTable.insert(root->val);//如果没有，那么插入
        return findTarget(root->left, k) || findTarget(root->right,k);
    }
    //BFS

    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> hashTable;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            while(size--){
                TreeNode* node = queue.front(); queue.pop();
                if(hashTable.count(k- node->val)) return true;
                hashTable.insert(node->val);
                if(node->left != nullptr) queue.push(node->left);
                if(node->right != nullptr) queue.push(node->right);
            }
        }
        return false;
    }
};
