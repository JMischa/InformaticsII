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

struct TreeNode *insert(struct TreeNode **root, int val){
    struct TreeNode *new = malloc(sizeof(TreeNode));
    new ->val = val;
    new ->left = NULL;
    new ->right = NULL;

    struct TreeNode* parent = NULL;
    struct TreeNode* curr = *root;
    while(curr != NULL){
        parent = curr;
        if(curr ->val < val){
            curr = curr ->right;
        }
        else{
            curr = curr -> left;
        }
    }
    if(parent == NULL){
        *root = new;
    }
    else if(parent ->val < new -> val){
        parent ->right = new;
    }
    else if(parent ->val > new ->val){
        parent ->left = new;
    }
    return *root;
}

int main() {
    struct TreeNode *root1 = NULL;
    struct TreeNode *root2 = NULL;
    printf("Inserting: 8, 5, 9, 3, 7, 11, 4 sequentially\n");
    insert(&root1, 8);
    insert(&root1, 5);
    insert(&root1, 9);
    insert(&root1, 3);
    insert(&root1, 7);
    insert(&root1, 11);
    insert(&root1, 4);

    insert(&root2, 8);
    insert(&root2, 5);
    insert(&root2, 9);
    insert(&root2, 3);
    insert(&root2, 7);
    insert(&root2, 11);
    insert(&root2, 4);

    bool result = are_identical(root1, root2);
    printf("Are the trees identical? %s\n", result ? "Yes" : "No");

    free(root1);
    free(root2);
    
    return 0;
}
