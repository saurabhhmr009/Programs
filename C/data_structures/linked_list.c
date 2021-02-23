#include <stdio.h>
#include <stdlib.h>

// A linked list node. Contains a data and pointer to the next node.
typedef struct Node {
    int data;
    struct Node *next;
}node;


node* create_node(node *head) {
    int value;
    printf("Enter the data to be inserted into the head node:\n");
    scanf("%d", &value);
    head  = (node*)malloc(sizeof(node));
    head->data = value;
    head->next = NULL;
    return head;
}

node* insert_node(node *head){
    node *last;
    node *temp;
    int value;
    
    printf("Enter the node data value: \n");
    scanf("%d", &value);
    last = (node*)malloc(sizeof(node));
    last->data = value;
    
    if(head->next == NULL) {
        head->next = last;
        last->next = NULL;
        printf("test\n");
    }
    else {
        temp = head;
        while(temp->next != NULL) {
            printf("Inside\n");
            temp = temp->next;
        }
	printf("haha\n");
        temp->next = last;
        last->next = NULL;
    }
    return head;
}
        
    
void print_list(node *head) {
    node *p = NULL;
    if(head == NULL) {
        printf("Linked list is empty!!!\n");
        return;
    }
    else {
        p = head;
        while(p != NULL) {
            printf("%d->", p->data);
            p = p->next;
        }
        printf("NULL");
        printf("\n");
    }
}

int list_menu() {
    int choice;
    printf("Choose the option:\n");
    printf("1. Create a Linked List.\n");
    printf("2. Insert a node.\n");
    printf("3. Delete the linked list.\n");
    printf("4. Print Linked List.\n");
    printf("5. Quit.\n");
    scanf("%d", &choice);
    printf("\n");
    
    return choice;
}
    
int main(void) {
    node *head = NULL;
    int choice;
    
    while(1) {
        choice = list_menu();
        switch(choice) {
            case 1: {
                head = create_node(head);
                printf("Head Node created!!\n");
                printf("\n");
                break;
            }
            case 2: {
                head = insert_node(head);
                printf("Node is inserted!!\n");
                printf("\n");
                break;
            }
            case 3: {
                printf("Linklist is deleted!!!\n");
                printf("\n");
                break;
            }
            case 4: {
                print_list(head);
                printf("\n");
                break;
            }            
            case 5: {
                printf("Quitting!!!\n");
                return 0;
            }
            default: {
                printf("Wrong input!!!\n");
                return 1;
            }
        }
    }
    //printf("Enter the value for the head node: \n");
    //scanf("%d", &value);
    
    //head = create_node(head, value);
    //printf("The head is created successfully!!!\n");
    //printf("Data in head is %d\n", head->data);
    
    //size = traverse_list(head);
    //printf("The size of the linked list is %d\n", size);
    return 0;
}
