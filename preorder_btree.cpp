/**
 * @file preorder_btree.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-29
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * 
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){} 
};


void traversal_binary_tree(TreeNode* root ,vector<int> &result){
    if(root == nullptr){
        return;
    }

    result.push_back(root->val);

    traversal_binary_tree(root->left , result);
    traversal_binary_tree(root->right , result);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    traversal_binary_tree(root , result);
    return result;
}

int main(){
    return 0;
}



