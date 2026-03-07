#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 10

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct{
    Person p[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, Person value);
Person dequeue(Queue* q);
Person front(Queue* q);
void display(Queue* q);

int main(){
    Queue *Q = initialize(Q);
    
    int choose; Person data;
    
    do{
        printf("Choose a number:\n1.Enqueue a name\n2.Dequeue a name\n3.Front Queue\n4.Display Queue\n0.Exit\n");
        printf("Enter a number: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nEnqueuing a name\n");
                printf("Enter a name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                enqueue(Q, data);
                printf("\n");
            break;
            case 2:
                printf("\nDequeuing a name\n");
                if(isEmpty(Q)){
                    printf("Queue is empty\n");
                }else{
                    data = dequeue(Q);
                    printf("Dequeuing %s %s\n", data.FName, data.LName);
                }
                printf("\n");
            break;
            case 3:
                printf("\nChecking the front of the queue\n");
                if(isEmpty(Q)){
                    printf("Queue is empty\n");
                }else{
                    data = front(Q);
                    printf("Current front of the Queue %s %s\n", data.FName, data.LName);
                }
                printf("\n");
            break;
            case 4:
                printf("\nDisplaying a queue\n");
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
    Queue *Q = (Queue *)malloc(sizeof(Queue) * MAX);
    Q->list.count = 0;
    Q->front = 1;
    Q->rear = 0;
    return Q;
}

bool isFull(Queue* q){
    return (q->list.count == MAX) ? true : false;
}

bool isEmpty(Queue* q){
    return (q->list.count == 0) ? true : false;
}

void enqueue(Queue* q, Person value){
    if(isFull(q)){
        printf("Queue is full\n");
    }else{
        q->rear = (q->rear + 1) % MAX;
        q->list.p[q->rear] = value;
        q->list.count++;
    }
}

Person dequeue(Queue* q){
    Person temp = q->list.p[q->front];
    if(q->front == q->rear){
        q->list.count = 0;
        q->front = 1;
        q->rear = 0;
    }else{
        q->front = (q->front + 1) % MAX;
        q->list.count--;
    }
    
    return temp;
}

Person front(Queue* q){
    return q->list.p[q->front];
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }else{
        for(int i = q->front; i <= q->rear; i++){
            printf("%d. %s %s\n", i, q->list.p[i].FName, q->list.p[i].LName);
        }
    }
}
