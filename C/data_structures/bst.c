#include <stdio.h>
#include <stdlib.h>

// Structure having elements data and two pointers, one points to left and another to right. 
typedef struct Node {
    int data;
    struct Node *leftchild, *rightchild;
}node;

// Function to print nodes in the Breadth level manner.
void breadth_level(node* root, int level) {
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        printf("%d\n", root->data);
    }
    else if(level > 1) {
        breadth_level(root->leftchild, level -1);
        breadth_level(root->rightchild, level - 1);
    }
}

// Calculate the depth of a BST.
int calculate_depth(node *root) {
    int left_height, right_height;
    int depth;
    if(root == NULL) {
        return -1;
    }
    else {
        left_height = calculate_depth(root->leftchild);
        right_height = calculate_depth(root->rightchild);

        if(left_height > right_height) {
            depth = left_height + 1;
            //printf("Left %d\n", depth);
        }
        else {
            depth = right_height + 1;
            //printf("Right %d\n", depth);
        }
    }
    return depth;
}

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
        return temp;
    }
    else {
        if(key < insert->data) {
            insert->leftchild = insert_node(insert->leftchild, key);
        }
        else {
            insert->rightchild = insert_node(insert->rightchild, key);
        }
    }
    return insert;
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

// BST menu to be displayed.
int bst_menu() {
    int choice;
    printf("1. Create the root of the BST.\n");
    printf("2. Insert the node in the BST.\n");
    printf("3. Calculate the Depth of the BST.\n");
    printf("4. Print the nodes in Breadth/ Level search manner.\n");
    printf("5: Quit.\n");
    printf("Enter the operation to be perfomed on the BST: \n");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main(void) {
    node* root = NULL;
    int choice, data, i, depth = 0;
    
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
                depth = calculate_depth(root);
                printf("Depth of the BST is %d\n", depth);
                break;
            }
            case 4: {
                depth = calculate_depth(root);
                for(i=1; i<=depth+1; i++) {
                    //printf("%d\n", depth);
                    breadth_level(root, i);
                }
                break;
            }
            case 5: {
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
