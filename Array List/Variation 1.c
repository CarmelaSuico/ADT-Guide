#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct{
    Person elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, Person data, int position);
List deletePos(List L, int position);
int locate(List L, Person data);
List insertSorted(List L, Person data);
void display(List L);

int main(){
    List L;
    L = initialize(L);
    
    int choose, position; Person data;
    
    do{
        
        printf("Enter the choose:\n1.Insert a name in position\n2.Delete a name in a position\n3.Locate a name\n4.Insert a name order\n5.Display names\n0.Exit\n");
        printf("Enter your choose: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nInserting a name in a position\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                printf("Enter the position: ");
                scanf("%d", &position);
                
                L = insertPos(L, data, position);
                printf("\n");
            break;
            case 2:
                printf("\nDeleting a name in a position\n");
                printf("Enter the position: ");
                scanf("%d", &position);
                L = deletePos(L, position);
                printf("\n");
            break;
            case 3:
                printf("\nLocating a name\n");
                printf("Enter a name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                position = locate(L, data); 
                
                if(position == 0){
                    printf("Name %s %s does not exist\n", data.FName, data.LName);
                }else{
                    printf("Name %s %s is in position %d\n", data.FName, data.LName, position);
                }
                printf("\n");
            break;
            case 4:
                printf("\nInserting a name in order\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                L = insertSorted(L, data);
                
                printf("\n");
            break;
            case 5:
                printf("\nDisplaying names\n");
                display(L);
                printf("\n");
            break;
            case 0:
                printf("Exiting...\n");
            break;
            default:
                printf("Invlid input\n");
        }
        
    }while(choose != 0);
    
    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, Person data, int position){
    if(position > L.count){
        printf("Invalid position\n");
    }else if(L.count == MAX){
        printf("List is full\n");
    }else{  
        for(int i = L.count - 1; i >= position; i--){
            L.elem[i + 1] = L.elem[i];
        }
        
        L.elem[position] = data;
        L.count++;
    }
    
    return L;
}

List deletePos(List L, int position){
    if(position > L.count){
        printf("Invalid position\n");
    }else if(L.count == 0){
        printf("List is empty\n");
    }else{
        for(int i = position; i < L.count; i++){
            L.elem[i] = L.elem[i + 1];
        }
        
        L.count--;
    }
    
    return L;
}

int locate(List L, Person data){
    int result = 0;
    if(L.count == 0){
        printf("List is empty\n");
    }else{
        int i;
        for(i = 0; i < L.count && (strcmp(data.FName, L.elem[i].FName) || strcmp(data.LName, L.elem[i].LName)) != 0; i++){}
        result = i;
    }
    
    return result;
}

List insertSorted(List L, Person data){
    if(L.count == MAX){
        printf("List is full\n");
    }else{
        int i;
        for(i = L.count - 1; i >= 0 && (strcmp(data.LName, L.elem[i].LName) < 0 || (strcmp(data.LName, L.elem[i].LName) == 0 && strcmp(data.FName, L.elem[i].FName) < 0)); i--){
            L.elem[i + 1] = L.elem[i];
        }
    
        L.elem[i + 1] = data;
        L.count++;
    }
    
    return L;
}

void display(List L){
    if(L.count == 0){
        printf("List is empty\n");
    }else{
        for(int i = 0; i < L.count; i++){
            printf("%d. %s %s\n", i, L.elem[i].FName, L.elem[i].LName);
        }
    }
    
}
