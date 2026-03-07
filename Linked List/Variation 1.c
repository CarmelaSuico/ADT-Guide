#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char FName[25];
    char LName[25];
}Person;

typedef struct node{
    Person p;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List initialize();
List empty(List list);
List insertFirst(List list, Person data);
List insertLast(List list, Person data);
List insertPos(List list, Person data, int index);
List deleteStart(List list);
List deleteLast(List list);
List deletePos(List list, int index);
Person retrieve(List list, int index);
int locate(List list, Person data);
void display(List list);

int main(){
    List L;
    L = initialize();
    
    L = empty(L);
    
    int choose, index; Person data;
    
    do{
        printf("Choose a number:\n1.Insert name at the first position\n2.Insert name at the last position\n3.Insert at specific position\n4.Delete a name at this start\n5.Delete a name at the last\n6.Delete in a specific position\n7.Retrieving a name at a position\n8.Retrieve position using name\n10.Display the List\n11.Empty the List\n0.Exit\n");
        printf("Enter a number: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                printf("\nInserting name at the first position\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                L = insertFirst(L, data);
                printf("\n");
            break;
            case 2:
                printf("\nInserting name at the last position\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                L = insertLast(L, data);
                printf("\n");
            break;
            case 3:
                printf("\nInserting name at specific position\n");
                printf("Enter the name(First name Last name): ");
                scanf("%s %s", data.FName, data.LName);
                printf("Enter the position: ");
                scanf("%d", &index);
                L = insertPos(L, data, index);
                printf("\n");
            break;
            case 4:
                printf("\nDeleting a name at the start\n");
                if(L.head == NULL){
                    printf("List is empty\n");
                }else{
                    L = deleteStart(L);
                }
                printf("\n");
            break;
            case 5:
                printf("\nDeleting a name at the last\n");
                if(L.head == NULL){
                    printf("List is empty\n");
                }else{
                    L = deleteLast(L);
                }
                printf("\n");
            break;
            case 6:
                printf("\nDeleting a name at a position\n");
                if(L.head == NULL){
                    printf("List is empty\n");
                }else{
                    printf("Enter the position: ");
                    scanf("%d", &index);
                    L = deletePos(L, index);
                }
                printf("\n");
            break;
            case 7:
                printf("\nRetrieving a name at a position\n");
                if(L.head == NULL){
                    printf("List is empty\n");
                }else{
                    printf("Enter the position: ");
                    scanf("%d", &index);
                    data = retrieve(L, index);
                    
                    printf("Position %d: %s %s\n", index, data.FName, data.LName);
                }
                printf("\n");
            break;
            case 8:
                printf("\nRetrieving position using the name\n");
                if(L.head == NULL){
                    printf("List is empty\n");
                }else{
                    printf("Enter the name(First name Last name): ");
                    scanf("%s %s", data.FName, data.LName);
                    index = locate(L, data);
                    
                    if(index != -1){
                        printf("%s %s is at %d\n", data.FName, data.LName, index);
                    }else{
                        printf("%s %s does not exist\n", data.FName, data.LName);
                    }
                }
                printf("\n");
            break;
            case 10:
                printf("\nDisplaying the List\n");
                display(L);
                printf("\n");
            break;
            case 11:
                printf("\nEmptying the List\n");
                L = empty(L);
                printf("\n");
            break;
            case 0:
                printf("Exiting...");            
            break;
            default:
                printf("Invaid Number\n\n");
        }
    }while(choose != 0);
}

List initialize(){
    List L;
    L.head = NULL;
    L.count = 0;
    
    return L;
}

List empty(List list){
    Node *temp;
    for(Node *current = list.head; current != NULL; current = temp){
        temp = current->next;
        free(current);
    }
    
    list.head = NULL;
    list.count = 0;
    
    return list;
}

List insertFirst(List list, Person data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation Failed\n");
    }else{
        newNode->p = data;
        newNode->next = list.head;
        list.head = newNode;
        list.count++;
    }
    
    return list;
}

List insertLast(List list, Person data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Allocation failed!\n");
    }else if(list.head == NULL){
        list = insertFirst(list, data);
    }else{
        newNode->p = data;
        newNode->next = NULL;
        Node *trav;
        for(trav = list.head; trav->next != NULL; trav = trav->next){}
        trav->next = newNode;
        list.count++;
    }
    
    return list;
}

List insertPos(List list, Person data, int index){
    printf("Inserting %s %s at position %d\n", data.FName, data.LName, index);
    if(index > list.count){
        printf("Invalid position\n");
    }else if(index == 0){
        list = insertFirst(list, data);
    }else if(index == list.count){
        list = insertLast(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){
            printf("Memory Allocation Failed!\n");
        }else{
            newNode->p = data;
            Node *trav = list.head;
            for(int i = 0; i < index - 1; i++){
                trav = trav->next;
            }
            newNode->next = trav->next;
            trav->next = newNode;
            list.count++;
        }
    }
    
    return list;
}

List deleteStart(List list){
    Node *temp = list.head;
    list.head = temp->next;
    free(temp);
    list.count--;
    return list;
}

List deleteLast(List list){
    if(list.count == 1){
        list = deleteStart(list);
    }else{
        Node *trav, *temp;
        for(trav = list.head; trav->next->next != NULL; trav = trav->next){}
        temp = trav->next->next;
        trav->next = NULL;
        free(temp);
    }
    
    return list;
}

List deletePos(List list, int index){
    if(index < list.count){
        printf("Invalid position\n");
    }else if(index == 0){
        list = deleteStart(list);
    }else if(index == list.count){
        list = deleteLast(list);
    }else{
        Node *trav = list.head, *temp;
        for(int i = 0; i < index - 1; i++){
            trav = trav->next;
        }
        temp = trav->next;
        trav->next = temp->next;
        free(temp);
        list.count--;
    }
    
    return list;
}

Person retrieve(List list, int index){
    Person result;
    if(index > list.count){
        printf("Invalid position\n");
    }else{
        Node *trav = list.head; int i;
        for(i = 0; i < index; i++){
            trav = trav->next;
        }
        result = trav->p;
    }
    
    return result;
}

int locate(List list, Person data){
    int result = -1;
    if(list.head == NULL){
        printf("List is empty\n");
    }else{
        Node *trav = list.head; int i;
        for(i = 0; trav != NULL && (strcmp(trav->p.LName, data.LName) != 0 || strcmp(trav->p.FName, data.FName) != 0); i++){ trav = trav->next; }
        if(trav != NULL){
            result = i; 
        }else{
            result = -1;
        }
    }
    
    return result;
}

void display(List list){
    if(list.head == NULL){
        printf("List is empty\n");
    }else{
        int i = 0;
        for(Node *current = list.head; current != NULL; current = current->next){
            printf("%d. %s %s\n", i++, current->p.FName, current->p.LName);
        }
    }
}
