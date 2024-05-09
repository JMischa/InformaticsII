#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;


bool are_identical(struct TreeNode *root1, struct TreeNode *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1 ->val == root2 ->val){
        return (are_identical(root1 ->left, root2 ->left) && are_identical(root1 ->right, root2 ->right));
    }
    return false;
}

int main() {
    struct TreeNode *root1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *root2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    root1->val = 1;
    root1->left = NULL;
    root1->right = NULL;

    root2->val = 1;
    root2->left = NULL;
    root2->right = NULL;

    bool result = are_identical(root1, root2);
    printf("Are the trees identical? %s\n", result ? "Yes" : "No");

    free(root1);
    free(root2);
    
    return 0;
}
