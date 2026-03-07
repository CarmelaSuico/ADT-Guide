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
    int top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, Person value);
Person pop(Stack* s);
Person peek(Stack* s);
Person top(Stack *s);
void display(Stack* s);

int main(){
    Stack *S;
    S = initialize(S);
    
    int choose; Person data;
    
    do{
        printf("Choose a number:\n1.Push a name\n2.Pop a name\n3.Top of the stack\n4.Display names\n0.Exit\n");
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
                printf("\nPopping a name\n");
                if(isEmpty(S)){
                    printf("Stack is empty\n");
                }else{
                    data = pop(S);
                    printf("Popping %s %s\n", data.FName, data.LName);
                }
                
                printf("\n");
            break;
            case 3:
                printf("\nChecking the top of the stack\n");
                data = top(S);
                printf("Top of the stack: %s %s\n", data.FName, data.LName);
                printf("\n");
            break;
            case 4:
                printf("\nDisplaying names\n");
                display(S);
                printf("\n");
            break;
            case 0:
                printf("\nExiting...\n");
            break;
            default:
                printf("Invaild choose\n");
        }
      
        
    }while(choose != 0);
}

Stack *initialize(){
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    return S;
}

bool isFull(Stack* s){
    return (s->top == MAX - 1) ? true : false;
}

bool isEmpty(Stack* s){
    return (s->top == -1) ? true : false;
}

void push(Stack* s, Person value){
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
        s->top++;
        s->p[s->top] = value;
    }
}

Person pop(Stack* s){
    Person temp;
    temp = s->p[s->top];
    s->top--;
    
    return temp;
}

Person peek(Stack* s){
    return (isEmpty(s)) ? printf("Stack is empty\n"), (Person){"", ""} : s->p[s->top];
}

Person top(Stack* s){
    return peek(s);
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        for(int i = s->top; i >= 0; i--){
            printf("%d. %s %s\n", i, s->p[i].FName, s->p[i].LName);
        }
    }
}
