/* You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 */

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *last = NULL;

struct ListNode* createNode(struct ListNode *head, int data) {
    struct ListNode *temp  = NULL, *new_node = NULL;
    if(head == NULL) {
        head = (struct ListNode*)malloc(sizeof(struct ListNode));
        head->val = data;
        head->next = NULL;
        return head;
    }

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = data;
    new_node->next = NULL;

    temp->next = new_node;
    return head;
}   

struct ListNode* addNode(struct ListNode *head) {
    int size, data, i = 1;
    printf("Enter the number of nodes for list: \n");
    scanf("%d", &size);
    while(size) {
        printf("Enter the data for node %d: \n",i);
        scanf("%d", &data);
        head = createNode(head, data);
        i++;
        size--;
    }
    return head;
}

int furtherAdd(struct ListNode *l, int carry) {
    struct ListNode *node = NULL;
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = l->val + carry;
    if(node->val > 9) {
	carry = 1;
	node->val -= 10;
    }
    else {
	carry = 0;
    }
    last->next = node;
    last = node;
    return carry;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *new_list = NULL, *node = NULL;
    int carry = 0;

    if(new_list == NULL) {
        new_list = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_list->next = NULL;
        new_list->val = l1->val + l2->val + carry;
        if(new_list->val > 9) {
            carry = 1;
            new_list->val -= 10;
        }
        else {
            carry = 0;
        }
    }

    last = new_list;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 && l2) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next  = NULL;
        node->val = l1->val +l2->val + carry;
        if(node->val > 9) {
            carry = 1;
            node->val -= 10;
        }
        else {
            carry = 0;
        }
        last->next = node;
        last = node;
	l1 = l1->next;
	l2 = l2->next;
    }

    while(l1) {
	carry = furtherAdd(l1, carry);
	l1 = l1->next;
    }
    while(l2) {
	carry = furtherAdd(l2, carry);
	l2 = l2->next;
    }

    if(carry == 1) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->val = 1;
	last->next = node;
	last = node;
    }

    return new_list;
}

int main(void) {
    struct ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
    printf("++++++++ For first list\n");
    l1 = addNode(l1);
    printf("\n");
    printf("++++++++ For second list\n");
    l2 = addNode(l2);
    l3 = addTwoNumbers(l1, l2);
    printf("++++++++ Print final list values\n");

    while(l3) {
        printf("%d->", l3->val);
        l3 = l3->next;
    }
    printf("Null\n");

    return 0;
}
