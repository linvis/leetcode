/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * This is a solution based on C, but I think C++ can also use it.
 * For leetcode office, it use vector rather than array, and I think array is easier for this question
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int j = 0;
    
    if (preorderSize == 0 && inorderSize ==0)
        return NULL;
    
    struct TreeNode *binaryTree = malloc(sizeof(struct TreeNode));
    
    binaryTree->val = preorder[0];
    if (preorderSize <= 1) {
        binaryTree->left = NULL;
        binaryTree->right = NULL;
        return binaryTree;
    }   
    
    for ( ; j < inorderSize; j++) {
        if (preorder[0] == inorder[j]) {
            if (j == 0) {
                binaryTree->left = NULL;
            } else 
                binaryTree->left = buildTree(preorder + 1, j, inorder, j);
            if (j + 1 < inorderSize) {
                binaryTree->right = buildTree(preorder + j + 1, preorderSize - j - 1, inorder + j + 1, inorderSize - j - 1);
            } else {
                binaryTree->right = NULL;
            }
        } 
    }
    
    return binaryTree;
}
