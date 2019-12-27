#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    node *left, *right;
};

node *create_node(int item)
{
    node *newNode = new node;
    newNode -> data = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
void preorder(node *parent)
{
    printf("%d ", parent -> data);
    if (parent -> left != NULL) {
        preorder(parent -> left);
    }
    if (parent -> right != NULL) {
        preorder(parent -> right);
    }
}

void inorder(node *parent)
{
    if (parent -> left != NULL) {
        inorder(parent -> left);
    }
    printf("%d ", parent -> data);
    if (parent -> right != NULL) {
        inorder(parent -> right);
    }
}

void postorder(node *parent)
{
    if (parent -> left != NULL) {
        postorder(parent -> left);
    }
    if (parent -> right != NULL) {
        postorder(parent -> right);
    }
    printf("%d ", parent -> data);
}

node *insert(node *root, int item) 
{
    if(root == NULL) {
        return create_node(item);
    }
    if (root -> data > item) { // ถ้าข้อมูลซ้ำกันไปขวา
        root -> left = insert(root -> left, item);
    } else {
        root -> right = insert(root -> right, item);
    }
    return root;
}


int main()
{
    node *root = NULL;
    int max_input, num_input;
    scanf("%d", &max_input);
    for (int i = 0; i < max_input; i++) {
        scanf("%d", &num_input);

        root = insert(root, num_input);
    }

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}

