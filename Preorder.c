
#include <stdio.h>

/*
 * Definition for a binary tree node
 * struct TreeNode {
 *     int val;
 *     struct TreeNode* left
 *     struct TreeNode* right
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

#include <stdlib.h>
// typedef struct TreeNode tnode;

struct TreeNode*
TreeNodeNew(int val)
{
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if(node) {
        // printf("node(%d)\n",pre[start]);
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    }
    return(node);
}

struct TreeNode*
TreeBuild(int* pre, int start, int end)
{
    struct TreeNode* root = NULL;
    if(start >= end) return NULL;
    if( !(root = TreeNodeNew(pre[start])) ) return(root);
    // printf("node(%d)\n",pre[start]);
    int split;
    // printf("start %d, end %d\n", start, end);
    for( split=start+1; split < end; ++split) {
        if( pre[split] > pre[start] ) {
            break;
        }
    }
    // printf("split %d\n", split);
    // printf("left[%d,%d]\n", start+1, split);
    root->left = TreeBuild(pre, start+1, split);
    // printf("right[%d,%d]\n", split, end);
    root->right = TreeBuild(pre, split, end);
    return (root);
}

struct TreeNode*
bstFromPreorder(int* preorder, int preorderSize)
{
    // printf("size:%d\n",preorderSize);
    // for( int ix=0; ix<preorderSize; ++ix) {
    //     printf("  %d\n",preorder[ix]);
    // }
    struct TreeNode* root = TreeBuild(preorder, 0, preorderSize);
    return(root);
}

int
main()
{
    int pre[] = {8,5,1,7,10,12};
    int size = 6;
    bstFromPreorder(pre, size);
}


