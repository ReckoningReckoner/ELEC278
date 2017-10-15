/*
 * heaps.c
 *
 *  Created on: Nov 1, 2016
 *      Author: hisham
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Heap {
	int* a;
	int last;
	int maxSize;
} Heap;

Heap* initHeap(int size) {
	Heap* h = malloc(sizeof(Heap));
	h->a = malloc(sizeof(int) * size);
	h->last = -1;
	h->maxSize = size;
	return h;
}

void swap(int* heap, int i, int j) {
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}
void reheapUp(Heap* heap, int index) {
	if (index <= 0)
		return;
	int parent_index = (index - 1) / 2;
	if (heap->a[index] < heap->a[parent_index])
		swap(heap->a, index, parent_index);
	else
		return;
	reheapUp(heap, parent_index);
}
void reheapDown(Heap* heap, int i) {
	int left;
	int right;
	int smallest;
	int smallestIndex;
	if (2 * i + 1 <= heap->last) {
		left = heap->a[2 * i + 1];
		if (2 * i + 2 <= heap->last) {
			right = heap->a[2 * i + 2];
		} else {
			right = -1;
		}
		if (left < right || right == -1) {
			smallest = left;
			smallestIndex = 2 * i + 1;
		} else {
			smallest = right;
			smallestIndex = 2 * i + 2;
		}
		if (heap->a[i] > smallest) {
			swap(heap->a, i, smallestIndex);
			reheapDown(heap, smallestIndex);
		}
	}

}
int withdrawMin(Heap* h) {
	int min = h->a[0];
	h->a[0] = h->a[h->last];
	h->last--;
	reheapDown(h, 0);
	return min;
}
void insert(Heap* heap, int x) {
	if (heap->last == heap->maxSize - 1)
		return;
	heap->a[++heap->last] = x;
	reheapUp(heap, heap->last);
}

void print(Heap* heap) {
	printf("Heap: ");
	int i = 0;
	for (i = 0; i <= heap->last; i++) {
		printf("%d, ", heap->a[i]);
	}
	printf("\n");
}

Heap* heapify(int a[], int size) {
	Heap* h = malloc(sizeof(Heap));
	h->maxSize = size;
	h->a = a;
	h->last = 0;
	int i = 0;
	for (i = 1; i < size; i++) {
		h->last++;
		reheapUp(h, h->last);
	}
	return h;
}

int findMin(Heap* h) {
	if (h->last != -1)
		return h->a[0];
	return -1;
}

int getNumOperations(Heap* h, int k)
{
    int temp[h->last + 1];
    int temp_size = 0;
    int counter = 0;

    while (h->last >= 0)
    {
        int t = withdrawMin(h);
        temp_size++;
        temp[temp_size - 1] = t;

        if (t < k)
        {
            if (temp_size >= 2)
            {
                insert(h, temp[0] + 2 * temp[1]);
                int i;
                for (i = 2; i < temp_size; i++)
                {
                    insert(h, temp[i]);
                }
            }
            else
            {
                insert(h, temp[0] + 2 * withdrawMin(h));
            } 

            counter++;
            temp_size = 0; // clear array

            if (h->last == 0 && findMin(h) < k) { //only one element left
                return -1;
            }
        }
    }

    return counter;
}



int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    if (n == 1)
    {
        printf("%d\n", -1);
        return 0;
    }

    Heap* h = initHeap(n);
    int i;
    for (i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        insert(h, val);
    }    
    printf("%d\n", getNumOperations(h, k));

    return 0;
}
