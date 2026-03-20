#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 3

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct{
    Person elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, Person data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, Person data);
Person retrieve(EPtr L, int position);
void insertSorted(EPtr L, Person data);
void display(EPtr L);
void makeNULL(EPtr L);

int main(){
    Etype L;
    initialize(&L);
    
    int choose, position; Person data;
    
    do{
        
        printf("Choose a number:\n1.Insert a name in a position\n2.Delete a name\n3.Locate a name\n4.Retrieve a name\n5.Insert a name by order\n6.Display names\n7.Empty all\n0.Exit\n");
        printf("Enter a number: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nInserting a name in a position\n");
                printf("Enter a name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertPos(&L, data, position);
                printf("\n");
            break;
            case 2:
                printf("\nDeleting a name in a position\n");
                printf("Enter the position: ");
                scanf("%d", &position);
                deletePos(&L, position);
                printf("\n");
            break;
            case 3:
                printf("\nLocating a name\n");
                printf("Enter a name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                position = locate(&L, data);
                
                if(position == -1 && L.count == 0){
                    printf("Name %s %s does not exist\n", data.FName, data.LName);
                }else{
                    printf("%s %s is at position %d\n", data.FName, data.LName, position);
                }
                
                printf("\n");
            break;
            case 4:
                printf("\nRetrieving a name\n");
                printf("Enter the position: ");
                scanf("%d", &position);
                data = retrieve(&L, position);
                printf("\n");
            break;
            case 5:
                printf("\nInserting a name by order\n");
                printf("Enter a name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                insertSorted(&L, data);
                printf("\n");
            break;
            case 6:
                printf("\nDisplaying names:\n");
                display(&L);
                printf("\n");
            break;
            case 7:
                printf("\nEmptying everything...\n\n");
                makeNULL(&L);
            break;
            case 0:
                printf("Exiting...");
            break;
            default:
                printf("Invaild input\n");
        }
        
    }while(choose != 0);
    
    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, Person data, int position){
    if(position > L->count){
        printf("Invalid position\n");
    }else if(L->count == MAX){
        printf("List is full\n");
    }else{
        for(int i = L->count - 1; i >= position; i--){
            L->elem[i + 1] = L->elem[i];
        }
        
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){
    if(position > L->count){
        printf("Invalid position\n");
    }else if(L->count == 0){
        printf("List is empty\n");
    }else{
        for(int i = position; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        
        L->count--;
    }
}

int locate(EPtr L, Person data){
    int i = 0;
    if(L->count == 0){
        printf("List is empty\n");
    }else{
        for(i = 0; i < L->count && (strcmp(data.LName, L->elem[i].LName) != 0 || strcmp(data.FName, L->elem[i].FName) != 0); i++){}
    }
    return (i == L->count) ? -1 : i;
}

Person retrieve(EPtr L, int position){
    Person result;
    if(position > L->count){
        printf("Invalid position\n");
    }else{
        result = L->elem[position];
        printf("Position %d. %s %s\n", position, result.FName, result.LName);
    }
    return result;
}

void insertSorted(EPtr L, Person data){
    if(L->count == MAX){
        printf("List is full\n");
    }else{
        int i;
        for(i = L->count - 1; i >= 0 && (strcmp(data.LName, L->elem[i].LName) < 0 || (strcmp(data.LName, L->elem[i].LName) == 0 && strcmp(data.FName, L->elem[i].FName) < 0)); i--){
            L->elem[i + 1] = L->elem[i];
        }
        
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(EPtr L){
    if(L->count == 0){
        printf("List is empty\n");
    }else{
        for(int i = 0; i < L->count; i++){
            printf("%d. %s %s\n", i, L->elem[i].FName, L->elem[i].LName);
        }
    }
}

void makeNULL(EPtr L){
    L->count = 0;
}

