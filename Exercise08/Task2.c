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

struct TreeNode *mirror_image(struct TreeNode *root){
    if(root == NULL){
        return NULL;
    }
    struct TreeNode *temp = root ->left;
    root ->left = root ->right;
    root ->right = temp;

    mirror_image(root ->left);
    mirror_image(root ->right);
    return root;
}

int main(){
    struct TreeNode *root = NULL;

    printf("Inserting: 8, 5, 9, 3, 7, 11, 4 sequentially\n");
   insert(&root, 8);
   insert(&root, 5);
   insert(&root, 9);
   insert(&root, 3);
   insert(&root, 7);
   insert(&root, 11);
   insert(&root, 4);
   printTree(root);
   printf("traverse: \n");
   traverseTree(root);
   printf("\n");
   mirror_image(root);
   printTree(root);
   printf("traverse: \n");
   traverseTree(root);
   return 0;
}