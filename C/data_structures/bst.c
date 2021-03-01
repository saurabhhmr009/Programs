#include <stdio.h>
#include <stdlib.h>

// Structure having elements data and two pointers, one points to left and another to right. 
typedef struct Node {
    int data;
    struct Node *leftchild, *rightchild;
}node;

// Function to create the node in BST
node* create_node(int key) {
    node* temp = NULL;
    
    temp = (node*)malloc(sizeof(node));
    temp->data = key;
    temp->leftchild = NULL;
    temp->rightchild = NULL;
    return temp;
}

// Function to insert the node in the BST.
node* insert_node(node* insert, int key) {
    node* temp = NULL;

    if(insert == NULL) {
        temp = create_node(key);
    }
    else {
        if(key < insert->data) {
            insert->leftchild = insert_node(insert->leftchild, key);
        }
        else {
            insert->rightchild = insert_node(insert->rightchild, key);
        }
    }
    return temp;
} 

// Function to create the root node of the BST.
node* root_node(node *temp) {
    int data;
    if(temp !=  NULL) {
        printf("The root node is already created.\n");
    }
    else {
        printf("Enter the node data: \n");
        scanf("%d", &data);
        temp = create_node(data);
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
    int choice, data;
    
    while(1) {
        choice = bst_menu();
        switch(choice) {
            case 1: {
                root = root_node(root);
                printf("Root node created successfully!!!\n");
                printf("\n");
                break;
            }
            case 2: {
                printf("Enter the data to be inserted in the node: \n");
                scanf("%d", &data);
                root = insert_node(root, data);
                printf("Node is inserted successfully!!!\n");
                printf("\n");
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
    }
    return 0;
}
