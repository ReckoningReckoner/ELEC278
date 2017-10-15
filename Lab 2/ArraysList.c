
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList{
    int end;
    int* a;
}ArrayList;


void init(ArrayList *l,int size){
    l->a = malloc(sizeof(int)*size);
    l->end = -1;
}

void addFront(ArrayList* l,int x){
    if (l->end == -1) {
        l->a[0] = x;
    }

    int i;
    for (i = l->end; i >= 0; i--){
        l->a[i+1]  = l->a[i];
    }

    l->a[0] = x;
    l->end++;
}
void addEnd(ArrayList* l,int x){
    l->end++;
    l->a[l->end] = x;
}

void removeEnd(ArrayList* l){
    if(l->end==-1)
        return;
    l->a[l->end]=0;
    l->end--;
}
void removeFront(ArrayList* l){
    if (l->end == -1)
        return;

    int i;
    for (i = 0; i < l->end; i++){
        l->a[i] = l->a[i+1];
    }
    l->end--;
}


void print(ArrayList *l){
    int i;
    if(l->end == -1)
    {
        printf("List is empty!!\n");
        return;
    }
    printf("(");
    for( i=0;i<=l->end-1;i++){
        printf("%d - ",l->a[i]);
    }
    printf("%d) \n",l->a[l->end]);
}

int main (){
    ArrayList ll;
    init(&ll,10);
    
    addFront(&ll,5);
    addFront(&ll,2);
    addEnd(&ll,4);
    addEnd(&ll,3);
    
    print(&ll);
    
    removeFront(&ll);
    removeEnd(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);
    print(&ll);

    removeFront(&ll);

    
    addFront(&ll,10);
    
    print(&ll);
    
    
    return 0;
}
