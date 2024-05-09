#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

// a)
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

// b)

struct TreeNode *delete(struct TreeNode **root, int val){
    struct TreeNode *parent = NULL;
    struct TreeNode *curr = *root;

    while(curr != NULL && curr ->val != val){
        parent = curr;
        if(val < curr -> val){
            curr = curr ->left;
        }
        else{
            curr = curr ->right;
        }
    }
    if(curr == NULL){
        return NULL;
    }
    if(curr ->left == NULL && curr -> right == NULL){
        if(curr == *root){
            *root = NULL;
        }
        else{
            if(parent ->left == curr){
                parent ->left = NULL;
            }
            else{
                parent ->right = NULL;
            }
            free(curr);
        }
    }
    else if(curr ->right == NULL){
        if(parent == NULL){
            *root = curr ->left;
        }
        else if(parent ->left == curr){
            parent -> left = curr ->left;
        }
        else{
            parent ->right = curr ->left;
        }
        free(curr);
    }
    else if(curr ->left == NULL){
        if(parent == NULL){
            *root = curr ->left;
        }
        else if(parent -> left == curr){
            parent ->left = curr ->right;
        }
        else{
            parent ->right = curr ->right;
        }
        free(curr);
    }
    else{
        TreeNode *largest_left = curr ->left;
        TreeNode * LLparent = curr;
        while(largest_left ->right != NULL){
            LLparent = largest_left;
            largest_left = largest_left ->right;
        }
        curr ->val = largest_left ->val;
        if(LLparent ->right == largest_left){
            LLparent ->right = largest_left ->left;
        }
        else{
            LLparent ->left = largest_left -> left;
        }
        free(largest_left);
    }
    return *root;
}

void printTreeRecursive(struct TreeNode *root, int lvl){
    if(root == NULL){
        return;
    }
    if(root ->left != NULL){
        printf(" %d -- %d : %d\n", root ->val, root ->left->val, lvl);
        printTreeRecursive(root ->left, lvl + 1);
    }
    if(root ->right != NULL){
        printf(" %d -- %d : %d\n", root ->val, root ->right->val, lvl);
        printTreeRecursive(root ->right, lvl + 1);
    }
}

void printTree(struct TreeNode *root){
    printf("graph g {\n");
    printTreeRecursive(root, 1);
    printf("\n");
}


void pretraversal(struct TreeNode *root){
    printf("%d", root ->val);
    if(root ->left != NULL){
        pretraversal(root ->left);
    }
    if(root->right != NULL){
        pretraversal(root ->right);
    }
}

void intraversal(struct TreeNode *root){
    if(root ->left != NULL){
        intraversal(root ->left);
    }
    printf("%d", root ->val);
    if(root ->right != NULL){
        intraversal(root ->right);
    }
}

void posttraversal(struct TreeNode *root){
    if(root ->left != NULL){
        posttraversal(root ->left);
    }
    if(root ->right != NULL){
        posttraversal(root ->right);
    }
    printf("%d", root ->val);
}

void traverseTree(struct TreeNode *root){
    printf("Pretraversal:\n");
    pretraversal(root);
    printf("\n");
    printf("Intraversal:\n");
    intraversal(root);
    printf("\n");
    printf("Posttraversal:\n");
    posttraversal(root);
    printf("\n");
}

int main() {
   struct TreeNode* root = NULL;
   printf("Inserting: 9, 3, 10, 6, 12, 1, 8 sequentially\n");
   insert(&root, 9);
   insert(&root, 3);
   insert(&root, 10);
   insert(&root, 6);
   insert(&root, 12);
   insert(&root, 1);
   insert(&root, 8);
   printTree(root);
   printf("traverse: \n");
   traverseTree(root);
   printf("Deleting: 23, 1, 3, 9\n");
   delete (&root, 23);   // Case 0: node does not exist
   delete (&root, 1);   // Case 1: node has 0 children
   delete (&root, 3);  // Case 2: node has 1 child
   delete (&root, 9);   // Case 3: node has 2 children
   printTree(root);
   return 0;
}