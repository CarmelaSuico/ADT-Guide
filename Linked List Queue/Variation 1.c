#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct Node{
    Person p;
    struct Node *next;
}Node;

typedef struct List{
    Node *front;
    Node *rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, Person value);
Person dequeue(Queue* q);
Person front(Queue* q);
void display(Queue* q);

int main(){
    Queue *Q = initialize();
    int choose; Person data;
    
    do{
        printf("Choose a number:\n1.Enqueue a name\n2.Dequeue a name\n3.Checking the current front\n4.Display names\n0.Exit\n");
        printf("Enter a number: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nEnqueuing a name\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                enqueue(Q, data);
                printf("\n");
            break;
            case 2:
                printf("\nDequeuing a name\n");
                dequeue(Q);
                printf("\n");
            break;
            case 3:
                printf("\nCurrent top names\n");
                data = front(Q);
                printf("%s %s\n", data.FName, data.LName);
                printf("\n");
            break;
            case 4:
                printf("\nDisplaying names\n");
                display(Q);
                printf("\n");
            break;
            case 0:
                printf("Exiting...\n");            
            break;
        }
        
    }while(choose != 0);
}

Queue* initialize(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL){
        printf("Memory Allocation failed");
    }else{
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

bool isFull(Queue* q){
    return false;//linked list is never full
}
bool isEmpty(Queue* q){
    return(q->front == NULL) ? true : false;
}

void enqueue(Queue* q, Person value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation falied");
    }else{
        newNode->p = value;
        newNode->next = NULL;
        if(isEmpty(q)){//if the Queue is Empty
            q->front = newNode;
            q->rear = newNode;
        }else{//if its not
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

Person dequeue(Queue* q){
    Person result = (Person){"",""};
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        Node *temp = q->front;
        temp->p = q->front->p;
        q->front = q->front->next;
        result = temp->p;
        if(isEmpty(q)){
            q->rear = NULL;
        }
        free(temp);
    }
    
    return result;
}

Person front(Queue* q){
    Person result = (Person){"", ""};
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        result = q->front->p;
    }
    
    return result;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        int i = 0;
        for(Node *trav = q->front; trav != NULL; trav = trav->next){
            printf("%d. %s %s\n", i++,trav->p.FName, trav->p.LName);
        }
    }
    printf("\n");
}
