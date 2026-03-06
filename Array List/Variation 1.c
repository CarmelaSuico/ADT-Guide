#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct{
    Person p[MAX];
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
        printf("Choose a number:\n1.Insert a name in position\n2.Delete a name in position\n3.Locate a name\n4.Insert a name by order\n5.Display the names\n0.Exit\n");
        printf("Enter a number: ");
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
                if(L.count == 0){
                    printf("List is empty\n");
                }else{
                    printf("\nDeleting a name in a position\n");
                    printf("Enter the position: ");
                    scanf("%d", &position);
                    L = deletePos(L, position);
                }
                
                printf("\n");
            break;
            case 3:
                if(L.count == 0){
                    printf("List is empty\n");
                }else{
                    printf("\nLocating a name\n");
                    printf("Enter the name(First name Last name): ");
                    scanf("%s %s", data.FName, data.LName);
                    position = locate(L, data);
                    
                    if(position != -1){
                        printf("%s %s is in position %d\n", data.FName, data.LName, position);
                    }else{
                        printf("%s %s does not exist in the data\n", data.FName, data.LName);
                    }
                }
                
                printf("\n");
            break;
            case 4:
                printf("\nInserting a name by order\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                L = insertSorted(L, data);
                printf("\n");
            break;
            case 5:
                if(L.count == 0){
                    printf("List is empty\n");
                }else{
                    printf("\nDisplaying the names:\n");
                    display(L);
                    printf("\n");
                }
            break;
            case 0:
                printf("Exiting...");            
            break;
            default:
                printf("Invaid Number\n\n");
        }
    }while(choose != 0);
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, Person data, int position){
    if(position > L.count){
        printf("Invalid Position\n");
    }else if(L.count == MAX){
        printf("List is full\n");
    }else{
        printf("Inserting %s %s in %d\n", data.FName, data.LName, position);
        for(int i = L.count - 1; i >= position; i--){
            L.p[i + 1] = L.p[i];
        }
        
        L.p[position] = data;
        L.count++;
    }
    
    return L;
}

List deletePos(List L, int position){
    if(position > L.count){
        printf("Invalid position\n");
    }else{
        printf("Deleting in %d\n",position);
        for(int i = position; i < L.count - 1; i++){
            L.p[i] = L.p[i + 1];
        }
        
        L.count--;
    }
    
    return L;
}

int locate(List L, Person data){
    int i, result;
    for(i = 0; i < L.count && (strcmp(data.LName, L.p[i].LName) != 0 || strcmp(data.FName, L.p[i].FName) != 0); i++){}
    
    if(strcmp(data.LName, L.p[i].LName) == 0 && strcmp(data.FName, L.p[i].FName) == 0){
        result = i;
    }else{
        result = -1;
    }
    
    return result;
}

List insertSorted(List L, Person data){
    if(L.count == MAX){
        printf("List is full\n");
    }else{
        int i;
        for(i = 0; i < L.count && (strcmp(data.LName, L.p[i].LName) > 0 || (strcmp(data.LName, L.p[i].LName) == 0 && strcmp(data.FName, L.p[i].FName) > 0)); i++){}
        
        L = insertPos(L, data, i);
    }
    
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d. %s %s\n", i, L.p[i].FName, L.p[i].LName);
    }
}
