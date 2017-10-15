#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct LinkedList
{
    int size;
    Node* head;
}LinkedList;

typedef struct Stack
{
    LinkedList* l;
} Stack;

void init(LinkedList* l)
{
    l->size = 0;
    Node* sentintal = malloc(sizeof(Node));
    sentintal->prev = sentintal;
    sentintal->next = sentintal;
    l->head = sentintal;
}

void add_to_empty_list(LinkedList *l, int val)
{
    Node* sentinal = l->head;
    Node* node = malloc(sizeof(Node));
    node->value = val;
    sentinal->next = node;
    sentinal->prev = node;
    node->prev = sentinal;
    node->next = sentinal;
    l->size++;
}

void add_front(LinkedList *l, int val)
{
    if (l->size == 0) {
        add_to_empty_list(l, val);
    }
    else {
        Node* sentinal = l->head;
        Node* node = malloc(sizeof(Node));
        node->value = val;
        node->next = sentinal->next;
        node->prev = sentinal;
        sentinal->next->prev = node;
        sentinal->next = node;
        l->size++;
    }
}

void add_end(LinkedList *l, int val)
{
    if (l->size == 0) {
        add_to_empty_list(l, val);
    }
    else {
        Node* sentinal = l->head;
        Node* node = malloc(sizeof(Node));
        node->value = val;
        node->next = sentinal;
        node->prev = sentinal->prev;
        sentinal->prev->next = node;
        sentinal->prev = node;
        l->size++;
    }
}

void delete_single_element(LinkedList *l)
{
    if (l->size == 0) {
        return;
    }

    Node* sentinal = l->head;
    Node* delete = sentinal->next;
    sentinal->prev = sentinal;
    sentinal->next = sentinal;
    free(delete);
    l->size--;
}

void remove_front(LinkedList *l)
{
    if (l->size == 0) {
        return;
    }

    if (l->size == 1) {
        delete_single_element(l);
    } else {
        Node* sentinal = l->head;
        Node* delete = sentinal->next;
        sentinal->next = sentinal->next->next;
        sentinal->next->prev = sentinal;
        free(delete);
        l->size--;
    }
}

void remove_end(LinkedList *l)
{
    if (l->size == 0) {
        return;
    }

    if (l->size == 1) {
        delete_single_element(l);
    } else {
        Node* sentinal = l->head;
        Node* delete = sentinal->prev;
        sentinal->prev = sentinal->prev->prev;
        sentinal->prev->next = sentinal;
        free(delete);
        l->size--;
    }
}

void print(LinkedList *l)
{
    if (l->size == 0){
        printf("size:%d\n", l->size);
        return;
    } else {
        Node* sentinal = l->head;
        Node* node = sentinal->next;
        while (node != sentinal)
        {
            printf("%i ", node->value);
            node = node->next;
        }
        printf("size:%d\n", l->size);
    }
}

void test_linkedlist()
{
    LinkedList l;
    init(&l);
    add_front(&l, 2);
    add_front(&l, 1);
    add_end(&l, 3);
    add_end(&l, 4);
    print(&l);

    remove_front(&l);
    remove_front(&l);
    remove_end(&l);
    remove_end(&l);
    print(&l);

    add_end(&l, 1);
    print(&l);

    remove_front(&l);
}

void initS(Stack* s)
{
    LinkedList* l = malloc(sizeof(LinkedList));
    init(l);
    s->l = l;
}

int isEmptyS(Stack* s)
{
    if (s->l->size == 0){
        return 1;
    } else {
        return 0;
    }
}

void push(Stack* s, int val)
{
    add_front(s->l, val);
}

int pop(Stack* s, int* res)
{
    if (isEmptyS(s)){
        return 1;
    }

    *res = s->l->head->next->value;
    remove_front(s->l);

    return 0;
}

void printS(Stack *s)
{
    print(s->l);
}

void test_stack()
{
    Stack s;
    initS(&s);
    int res;

    push(&s, 13);
    push(&s, 14);
    push(&s, 15);
    printS(&s);

    pop(&s, &res);
    pop(&s, &res);
    pop(&s, &res);
    pop(&s, &res);
    printS(&s);
}

int main()
{
    /* test_stack(); */
    /* test_linkedlist(); */
}
