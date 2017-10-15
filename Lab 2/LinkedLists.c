
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
    int size;
}LinkedList;

int isEmpty(LinkedList *l){
    if(l->head)
        return 0;
    return 1;
}

void init(LinkedList *l){
    l->head = NULL;
    l->size = 0;
}

void addFront(LinkedList* l,int x){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = x;
    
    newNode->next = l->head;
    l->head = newNode;
    l->size++;
}

void addEnd(LinkedList* l,int x){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;
    l->size++;

    Node* ptr = l->head;
    if(ptr == NULL)
    {
        l->head = newNode;
        return;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}
void removeFront(LinkedList* l){
    if(l->head == NULL)
        return;
    l->size--;
    
    Node* ptr = l->head;
    l->head = l->head->next;

    free(ptr);
}
void removeEnd(LinkedList* l){
    if(l->head == NULL)
        return;
    if(l->size==1){
        removeFront(l);
        return;
    }
    
    Node* ptr = l->head;
    
    while(ptr->next->next){
        ptr = ptr->next;
    }
    Node* delPtr = ptr->next;
    ptr->next = NULL;
    free(delPtr);
    l->size--;
}
void destroy(LinkedList* l){
    while(!isEmpty(l)){
        removeFront(l);
    }
    
}

void removeValue(LinkedList* l, int x){
    if (l->size == 0) {
        return;
    }

    while (l->head != NULL && l->head->value == x){ // remove initial nodes
        removeFront(l);
    }

    Node* node = l->head;
    Node* delete;
    while (node != NULL && node->next != NULL)
    {
        if (node->next->value == x) {
            delete = node->next;
            node->next = node->next->next;
            l->size--;
            free(delete);
        }
        node = node->next;
    }

}

void print(LinkedList *l){
    Node* ptr = l->head;
    if(!ptr)
    {
        printf("List is empty!!\n");
        return;
    }
    printf("(");
    while(ptr->next){
        printf("%d -> ",ptr->value);
        ptr = ptr->next;
    }
    printf("%d ) %d\n",ptr->value,l->size);
}
void update(LinkedList* l){
    if (l->size == 0) {
        return;
    }

    int i;
    Node* ptr = l->head;
    int smallest = ptr->value;
    ptr = ptr->next;

    for (i = 1; i < l->size; i++) {
        if (smallest > ptr->value){
            smallest = ptr->value;
        }
        ptr = ptr->next;
    }

    ptr = l->head;
    for (i = 0; i < l->size; i++) {
        ptr->value -= smallest;
        ptr = ptr->next;
    }
}

int main (){
    /* Array LL */ 
    /* AddFront       O(n)  O(1) */
    /* AddEnd         O(1)  O(n) */
    /* RemoveFront    O(n)  O(1) */
    /* RemoveEnd      O(1)  O(n) */
    LinkedList ll;
    init(&ll);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    update(&ll);
    print(&ll);
    
    removeValue(&ll,0);
    print(&ll);

    removeValue(&ll,2);
    //removeFront(&ll);
    //removeEnd(&ll);
    print(&ll);

    //removeFront(&ll);
    removeValue(&ll,3);
    print(&ll);

    removeValue(&ll,1);
    print(&ll);
    return 0;
}    

