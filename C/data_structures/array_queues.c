/* Implementation of queues in C.
 */

#include <stdio.h>
#include <stdlib.h>

// Frond and end keep the track of the front and end index of array.
// Size keeps the track of current size of the array.
// Capacity is the actual size of the array. arr is the int type array. 
typedef struct Queue {
    int front, end, size;
    unsigned int capacity;
    int *arr;
}queue;

// Function initialize the queue. 
queue* createQueue(int length) {
    queue *create = NULL;
    create = (queue*)malloc(sizeof(queue));
    create->front = 0;
    create->end = length-1;
    create->size = 0;
    create->capacity = length;
    create->arr = (int*)malloc(create->capacity*sizeof(int));
    return create;
}

//Fucntion to check if Queue is Full
int check_full(queue *start) {
    return(start->size == start->capacity);
}

// Function to check if Queue is full
int check_empty(queue *start) {
    return (start->size == 0);
}

// Function to Enqueue the element in the queue:
queue* enqueue(queue *start, int data) {
    //check if queue is full
    if(check_full(start)) {
        printf("Queue is full!!!\n");
        return start;
    }
    start->end = (start->end +1)%start->capacity;
    start->arr[start->end] = data;
    start->size += 1;
    printf("End %d size %d\n", start->end, start->size);
    return start;
}

//Function to dequeue the elements from the queue.
queue* dequeue(queue *start) {
    if(check_empty(start)) {
        printf("Queue is already empty!!!\n");
        return 0;
    }
    start->front = (start->front+1)%start->capacity;
    start->size -= 1;
    printf("Front %d size %d\n", start->front, start->size);
    return start;
}

//Function to display the front and rare element
void front_end(queue *start) {
    printf("Front element is %d\n", start->arr[start->front]);
    printf("End element is %d\n", start->arr[start->end]);
}

// Function to display the queue menu.
int queue_menu() {
    int choice;
    printf("Arrays  Queues main menu: \n");
    printf("1. Create a Queue.\n");
    printf("2. Enqueue.\n");
    printf("3. Dequeue.\n");
    printf("4. Check Queue is empty or full.\n");
    printf("5. Display front and rear queue elements.\n");
    printf("6. Quit.\n");
    scanf("%d", &choice);
    return choice;
}

// Main Function.
int main(void) {
    int length, choice, data;
    queue *start = NULL;
    
    while(1) {
        choice = queue_menu();
        switch(choice) {
            case 1: {
                printf("\n");
                printf("Enter the length of the queue: \n");
                scanf("%d", &length); 
                start = createQueue(length);
                printf("Queue is created!!!\n");
                printf("\n");
                break;
            }
            case 2: {
                printf("\n");
                printf("Enter the data to be inserted: \n");
                scanf("%d", &data);
                start = enqueue(start, data);
                printf("Data enqueued!!!\n");
                printf("\n");
                break;
            }
            case 3: {
                printf("\n");
                start = dequeue(start);
                printf("Data dequeued!!!\n");
                printf("\n");
                break;
            }
            case 4: {
                printf("\n");
                if(check_full(start)) {
                    printf("Queue is full!!!\n");
                }
                else {
                    printf("Queue is empty!!!\n");
                }
                printf("\n");
                break;
            }
            case 5: {
                printf("\n");
                front_end(start);
                printf("\n");
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                printf("Wrong Input Entered!!!\n");
                return 1;
            }
        }
    }
    return 0;
}
