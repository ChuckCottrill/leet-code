

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(std::nullptr), right(std::nullptr) {}
 *     TreeNode(int x) : val(x), left(std::nullptr), right(std::nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include <cstdio>

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stdlib.h>
// typedef struct TreeNode tnode;

class Solution {

private:

    TreeNode*
    TreeNodeNew(int val)
    {
        TreeNode* node = new TreeNode(val);
        if(!node) return(node);
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        return(node);
    }

public:

    TreeNode*
    TreeBuild(std::vector<int> pre, int start, int end)
    {
        TreeNode* root = nullptr;
        if(start >= end) return nullptr;
        // root = new TreeNode(pre[start]);
        if( (root = new TreeNode(pre[start])) == nullptr ) return(root);
        printf("node(%d)\n",pre[start]);
        int split;
        // printf("start %d, end %d\n", start, end);
        for( split=start+1; split < end; ++split) {
            if( pre[split] > pre[start] ) {
                break;
            }
        }
        // printf("split %d\n", split);
        printf("left[%d,%d]\n", start+1, split);
        root->left = TreeBuild(pre, start+1, split);
        printf("right[%d,%d]\n", split, end);
        root->right = TreeBuild(pre, split, end);
        return (root);
    }

    TreeNode*
    bstFromPreorder(std::vector<int>& preorder) // preorderSize
    {
        // printf("size:%d\n",preorder.size());
        // for( int ix=0; ix<preorder.size(); ++ix) {
        //     printf("  %d\n",preorder[ix]);
        // }
        TreeNode* root = TreeBuild(preorder, 0, preorder.size());
        return(root);
    }
};

int
main()
{
    // int pre[] = {8,5,1,7,10,12};
    int ray[] = {8,5,1,7,10,12};
    int n = sizeof(ray) / sizeof(ray[0]);
    std::vector<int> pre(ray, ray+n);
    Solution solution = Solution();
    solution.bstFromPreorder(pre);
}

