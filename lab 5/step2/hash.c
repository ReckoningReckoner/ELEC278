/*
 * hash.c
 *
 *  Created on: Nov 6, 2016
 *      Author: hisham
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DLL.h"

typedef struct HashTable {
	LinkedList** a;
	int size;
	int collisions;
} HashTable;

HashTable * initHashTable(int s) {
	HashTable* h = malloc(sizeof(HashTable));
	h->size = s;
	h->a = malloc(sizeof(LinkedList) * s);
	int i;
	for(i=0;i<s;i++)
		h->a[i]= init();
	h->collisions = 0;
	return h;
}

long h(char* x){
	long sum=0;
    int n = (int)strlen(x);

    int i;
    for (i = 0; i < n; i++) {
        sum += x[i] * (long)pow(31, n - 1 - i);
    }

	return sum;
}

double balanceFactor(HashTable* ht){
	double bf = 0;
	int i=0;
	for(i=0;i<ht->size;i++){
		if(isEmpty(ht->a[i])==0)
		bf++;
	}
	return bf/ht->size*100;
}

int hash(char* x, int size) {
	long x2 = h(x);
	return (int) x2 % size;
}

void insert(HashTable *ht, char* x) {
    LinkedList* ll = ht->a[hash(x, ht->size)];
    if (ll->size > 0) {
        ht->collisions++;
    }
    addFront(ll, x);
}

int findInTable(HashTable *ht, char* x) {
    return find(ht->a[hash(x, ht->size)], x);
}


void printTable(HashTable *ht) {
	int i;
	printf("----------\n");
	for (i = 0; i < ht->size; i++){
		printf("%d --> ", i);
		print(ht->a[i]);
	}
	printf("# of Collisions=%d\n", ht->collisions);
	printf("Balance Factor %%=%.2f\n----------", balanceFactor(ht));
}

int main() {

	int i=0;
	HashTable* h = initHashTable(101);

	for(i=0;i<100;i++){
		int x = rand()%5+1;
		char *p = malloc(sizeof(char)*x);
		int j=0;
		for(j=0;j<x;j++)
			p[j] = (char) (rand() % 26 + 97);
		p[j]='\0';
		insert(h,p);
	}
	printTable(h);

	return 0;

}
