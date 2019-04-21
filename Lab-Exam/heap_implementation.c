#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int heap[1000];

int hp = 0;

void swap (int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void max_heapify(int x) {

	int left = 2 * x;
	int right = (2 * x) + 1;
	int largest = x;

	if (left <= hp && heap[left] > heap[x])
		largest = left;
	
	if (right <= hp && heap[right] > heap[largest])
		largest = right;

	if (largest != x) {
		swap(&heap[largest], &heap[x]);
		max_heapify(largest);
	}

}

void create_heap() {

	for (int i = hp / 2; i >= 1; i--)
		max_heapify(i);

}

void insert(int x) {

	heap[hp + 1] = x;
	hp++;

	for (int i = hp; heap[i / 2] < heap[i] && i >= 1; i = i / 2) {
		max_heapify(i / 2);
	}
	printf("\n");

}

void pop() {

	heap[1] = heap[hp];
	hp--;

	max_heapify(1);

}

void print_heap() {

	for (int i = 1; i <= hp; i++)
		printf("%d ", heap[i]);
	printf("\n");

}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    heap[0] = 999;

    int a;
    for (int i = 1; i <= 5; i++) {
    	scanf("%d", &a);
    	insert(a);
    	

    }
    print_heap();

   	pop();
    print_heap();

   	pop();
    print_heap();
    
   	pop();
    print_heap();
    
    pop();
    print_heap();
    


    return 0;
}