#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
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

bool search(struct node* root, int key)
{
    if (root == NULL) {
        return false;
    }
    if (root -> data == key)
        return true;

    if (root -> data < key)
        return search(root -> right, key);

    return search(root -> left, key);
}

node *insert(node *root, int item)
{
    if (root == NULL) {
        return create_node(item);
    }
    if (root -> data > item) { // ถ้าข้อมูลน้อยกว่ากว่าไปซ้ายและถ้าข้อมูลซ้ำกันไปขวา
        root -> left = insert(root -> left, item);
    } else {
        root -> right = insert(root -> right, item);
    }
    return root;
}

void printRootToMin(node *parent)
{
    if (parent == NULL)
        return;
    else {
        printf("%d ", parent -> data);
    }
    printRootToMin(parent -> left);
}

void printRootToMax(node *parent)
{
    if (parent == NULL) {
        return;
    } else {
        printf("%d ", parent -> data);
    }
    printRootToMax(parent -> right);
}

void printLeafNode(node *parent)
{
    if (parent -> left != NULL) {
        printLeafNode(parent -> left);
    }
    if (parent -> left == NULL and parent -> right == NULL) {
        printf("%d ", parent -> data);
    }
    if (parent -> right != NULL) {
        printLeafNode(parent -> right);
    }
}

node *deleteNode(node *root, int item)
{
    node *temp, *replacement;
    int replacement_value;

    if (root == NULL) {
        return root;
    }
    // วนหาทุกตัว
    if (root -> data > item) {
        root -> left = deleteNode(root -> left, item);
    } else if (root -> data < item) {
        root -> right = deleteNode(root -> right, item);
    } else {
        // กรณีไม่มีลูก
        if (root -> left == NULL and root -> right == NULL) {
            free(root);
            root = NULL;
        }
        // มีลูกตัวเดียวทางขวา
        else if (root -> left == NULL) {
            temp = root -> right;
            free(root);
            root = temp;
        }
        // มีลูกตัวเดียวทางซ้าย
        else if (root -> right == NULL) {
            temp = root -> left;
            free(root);
            root = temp;
        } else {
            // กรณีมีลูก 2 ตัว
            replacement = root -> right;
            while (replacement -> left != NULL) {
                replacement = replacement -> left;
            }
            replacement_value = replacement -> data;
            root = deleteNode(root, replacement_value);
            root -> data = replacement_value;
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    int choice, value;
    while (choice != 4) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            root = insert(root, value);
        } else if (choice == 2) {
            scanf("%d", &value);
            if (search(root, value) == true) { // ถ้ามีข้อมูลที่เรารับ = ข้อมูลใน tree แปลว่าลบได้
                printf("yes\n");
            } else {
                printf("no\n");
            }
            root = deleteNode(root, value);
        } else if (choice == 3) {
            printRootToMin(root);
            printf("\n");
            printRootToMax(root);
            printf("\n");
            if (root == 0) {
                printf("\n");
                continue;
            } else {
                printLeafNode(root);
                printf("\n");
            }
        }
    }
    return 0;
}