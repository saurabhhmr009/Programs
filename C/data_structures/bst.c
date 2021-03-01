#include <stdio.h>
#include <stdlib.h>

// Structure having elements data and two pointers, one points to left and another to right. 
typedef struct Node {
    int data;
    struct Node *leftchild, *rightchild;
}node;

// Function to insert the node in BST
node* insert_node(node *create) {
    int data;
    printf("Enter the node data: \n");
    scanf("%d", &data);
    create = (node*)malloc(sizeof(node));
    create->data = data;
    create->leftchild = NULL;
    create->rightchild = NULL;
    return create;
}

// Function to create the root node of the BST.
node* root_node(node *top) {
    node *temp = NULL;
    if(top !=  NULL) {
        printf("The root node is already created.\n");
    }
    else {
        temp = insert_node(top);
    }
    return temp;
}
        

int bst_menu() {
    int choice;
    printf("1. Create the root of the Tree.\n");
    printf("2. Insert the node in the Tree.\n");
    printf("3: Quit.\n");
    printf("Enter the operation to be perfomed on the BST: \n");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main(void) {
    node* root = NULL;
    int choice;
    
    choice = bst_menu();
    switch(choice) {
        case 1: {
            root = root_node(root);
            printf("Root node created successfully!!!\n");
            break;
        }
        case 2: {
            root = insert_node(root);
            printf("Node is inserted successfully!!!\n");
            break;
        }
        case 3: {
            printf("Quitting\n");
            return 0;
        }
        default: {
            printf("Wrong input!!!!\n");
            return 1;
        }
    }
    return 0;
}
