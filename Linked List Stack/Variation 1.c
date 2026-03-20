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

typedef struct Stack{
    Node *top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, Person value);
Person pop(Stack* s);
Person peek(Stack* s);
void display(Stack* s);

int main(){
    Stack *S = initialize();
    int choose; Person data;
    
    do{
        printf("Choose a number:\n1.Push a name\n2.Pop a name\n3.Checking the current top\n4.Display names\n0.Exit\n");
        printf("Enter a number: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nPushing a name\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                push(S, data);
                printf("\n");
            break;
            case 2:
                printf("\nPoping a name\n");
                pop(S);
                printf("\n");
            break;
            case 3:
                printf("\nCurrent top names\n");
                data = peek(S);
                printf("%s %s\n", data.FName, data.LName);
                printf("\n");
            break;
            case 4:
                printf("\nDisplaying names\n");
                display(S);
                printf("\n");
            break;
            case 0:
                printf("Exiting...\n");            
            break;
        }
        
    }while(choose != 0);
    
    
    return 0;
}

Stack *initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
    return false;//linked list can never be full
}
bool isEmpty(Stack* s){
    return(s->top == NULL) ? true : false;
}

void push(Stack* s, Person value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->p = value;//add the value
    newNode->next = s->top;//setting to the next NULL
    s->top = newNode;//linking the first node to the head
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        int i = 0;
        for(Node *trav = s->top;trav != NULL; trav = trav->next){
            printf("%d. %s %s\n", i++, trav->p.FName, trav->p.LName);
        }
    }
}

Person pop(Stack* s){
    Person result = (Person){"",""};
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        Node *temp = s->top;
        s->top = temp->next;
        result = temp->p;
        free(temp);
    }
    
    return result;
}

Person peek(Stack* s){
    Person result = (Person){"",""};
    if(isEmpty(s)){
        printf("Stack is empty");
    }else{
        result = s->top->p;
    }
    
    return result;
}
