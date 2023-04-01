// Created by 刘日亮 on 2023/3/20.
//给定二叉搜索树（BST）的根节点root和一个整数值val。
//你需要在 BST 中找到节点值等于val的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
#include "leetcode.h"
class solution{
public:
    //递归
    TreeNode* BSTSearch(TreeNode* root, int val){
        if(root== nullptr) return nullptr;
        if(root->val == val) return root;
        //在 符合 条件的子树当中继续寻找
        return BSTSearch(root->val>val?root->left:root->right,val);

    }
    //迭代
    TreeNode* IBSTSearch(TreeNode* root, int val){
        if(root == nullptr) return nullptr;
        while(root){
            if(root->val == val) return root;
            root = root->val > val ? root->left:root->right;
        }
        return nullptr;
    }
};
