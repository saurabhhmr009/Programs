/* Program to make a linked list with basic linked list options.
 */

#include <stdio.h>
#include <stdlib.h>

// A linked list node. Contains a data and pointer to the next node.
typedef struct Node {
    int data;
    struct Node *next;
}node;

// Function to create the head node of the Linked List.
node* create_node(node *head) {
    int value;
    printf("Enter the data to be inserted into the head node:\n");
    scanf("%d", &value);
    head  = (node*)malloc(sizeof(node));
    head->data = value;
    head->next = NULL;
    return head;
}

// Function to add the node at the end of the Linked list.
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

node* add_node(node *head) {
    int point, count;
    int node_data;
    node *new_node;
    node *temp, *next;
    
    printf("Enter the node number after which you want to add the node: \n");
    scanf("%d", &point);
    count = point;
    
    printf("Enter the node data value: \n");
    scanf("%d", &node_data);
    
    new_node = (node*)malloc(sizeof(node));
    new_node->data = node_data;
    
    temp = head;
    while(count != 1) {
        temp = temp->next;
        count--;
    }
    next = temp->next;
    temp->next = new_node;
    new_node->next = next;
    
    return head;
}

// Function to print the whole Linked List.
void print_list(node *head) {
    node *p = NULL;
    int count = 0;
    if(head == NULL) {
        printf("Linked list is empty!!!\n");
        return;
    }
    else {
        p = head;
        while(p != NULL) {
            count++;
            printf("%d->", p->data);
            p = p->next;
        }
        printf("NULL\n");
        printf("%d\n",count);
        printf("\n");
    }
}

// Function to delete the whole linked list(Still in progress!!).
void delete_list(node* head) {
    node *next  = NULL;
    node *current = head;
    
    while(current->next != NULL) {
        next = current->next;
        free(current);
        current->next = NULL;
        current = next;
    }
    head = NULL;
}

node* delete_node(node *head) {
    node *prev, *next, *temp;
    int point, count;
    
    printf("Enter the node which you want to delete: \n");
    scanf("%d", &point);
    count = point;
    
    temp = head;
    while(count != 1) {
        prev = temp;
        temp = temp->next;
        count--;
    }
    printf("Test\n");
    next = temp->next;
    prev->next = next;
    temp->next = NULL;
    free(temp);
    
    return head;
}

node* reverse_list(node* head) {
    node *prev = NULL;
    node* current = head;
    node* next = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to print the value stored at a particular node.
void print_node(node* head) {
    int count = 0;
    int node_choice;
    node *temp;
    temp = head;
    printf("Enter the node whose value you want to print: \n");
    scanf("%d", &node_choice);
    count=node_choice;
    
    while(node_choice != 1) {
        temp=temp->next;
        node_choice--;
    }
    printf("Value at node %d is %d\n", count, temp->data);
}

// Function to display the Linked list menu.
int list_menu() {
    int choice;
    printf("Choose the option:\n");
    printf("1. Create a Linked List.\n");
    printf("2. Insert a node(at the end).\n");
    printf("3. Insert a node(after any node).\n");
    printf("4. Delete the linked list.\n");
    printf("5. Delete a particular node\n");
    printf("6. Print Linked List.\n");
    printf("7. Print a node in the list.\n");
    printf("8. Reverse a Linked List.\n"); 
    printf("9. Quit.\n");
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
                printf("Node is added!!\n");
                printf("\n");
                break;
            }
            case 3: {
                head = add_node(head);
                printf("Node is inserted!!\n");
                printf("\n");
                break;
            }
            case 4: {
                delete_list(head);
                printf("Linklist is deleted!!!\n");
                printf("\n");
                break;
            }
            case 5: {
                head = delete_node(head);
                printf("Node is deleted!!\n");
                printf("\n");
                break;
            }
            case 6: {
                print_list(head);
                printf("\n");
                break;
            }
            case 7: {
                print_node(head);
                printf("\n");
                break;
            }
            case 8: {
                head = reverse_list(head);
                printf("\n");
                break;
            }
            case 9: {
                printf("Quitting!!!\n");
                return 0;
            }
            default: {
                printf("Wrong input!!!\n");
                return 1;
            }
        }
    }
    
    return 0;
}
