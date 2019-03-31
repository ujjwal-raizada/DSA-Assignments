#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

// Priority Queue
int pq[1000000] = {0};
int n = 0;

int pq_min[1000000] = {0};
int n_min = 0;

void max_heapify(int i) {

	int left = 2 * i;
	int right = 2 * i + 1;
	int largest = i;

	if (right <= n && pq[right] > pq[i])
		largest = right;

	if (left <= n && pq[left] > pq[largest])
		largest = left;

	if (largest != i) {
		// swap i && largest
		int t = pq[i];
		pq[i] = pq[largest];
		pq[largest] = t;

		max_heapify(largest);
	}


}

void min_heapify(int i) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int smallest = i;

	if (left <= n_min && pq_min[left] < pq_min[i])
		smallest = left;

	if (right <= n_min && pq_min[right] < pq_min[smallest])
		smallest = right;

	if (smallest != i) {
		// swap i && smallest
		int t = pq_min[i];
		pq_min[i] = pq_min[smallest];
		pq_min[smallest] = t;

		min_heapify(smallest);
	}
}

void build_maxheap() {
	for (int i = n / 2; i >= 1; i--) {
		max_heapify(i);
	}
}

void build_minheap() {
	for (int i = n_min / 2; i >= 1; i--) {
		min_heapify(i);
	}
}

int pq_max() {
	return pq[1];
}

int pq_minimum() {
	return pq_min[1];
}


int pq_pop() {
	if (n == 0)
		return -1;

	int max = pq[1];
	pq[1] = pq[n];
	n = n - 1;
	max_heapify(1);
	return max;
}

int pq_min_pop() {
	if (n_min == 0)
		return -1;

	int min = pq[1];
	pq_min[1] = pq_min[n_min];
	n_min = n_min - 1;
	min_heapify(1);
	return min;
}

void pq_increase_value(int i, int val) {

	if (val < pq[i]) {
		return;
	}

	pq[i] = val;
	while(i > 1 && pq[i / 2] < pq[i]) {
		// swap pq[i/2] && i
		int t = pq[i / 2];
		pq[i / 2] = pq[i];
		pq[i] = t;

		i = i / 2;
	}

}

void pq_decrease_value(int i, int val) {

	if (val > pq_min[i]) {
		return;
	}

	pq_min[i] = val;
	while(i > 1 && pq_min[i / 2] > pq_min[i]) {
		// swap pq[i/2] && i
		int t = pq_min[i / 2];
		pq_min[i / 2] = pq_min[i];
		pq_min[i] = t;

		i = i / 2;
	}

}

void pq_insert(int val) {

	n = n + 1;
	pq[n] = -1;
	pq_increase_value(n, val);

}

void pq_min_insert(int val) {

	n_min = n_min + 1;
	pq_min[n_min] = 9999999;
	pq_decrease_value(n_min, val);

}

void print_max() {
	for (int i = 1; i <= n; i++)
		printf("%d ", pq[i]);
	printf("\n");
}


void print_min() {
	for (int i = 1; i <= n_min; i++)
		printf("%d ", pq_min[i]);
	printf("\n");
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

  //   pq_insert(5);
  //   pq_insert(4);
  //   pq_insert(9);
  //   pq_insert(1);
  //   pq_insert(10);
  //   pq_insert(3);
  //   pq_insert(11);

  //   print_max();

  //   pq_pop();
  //   print_max();

  //   pq_pop();
  //   print_max();

  //   pq_pop();
  //   print_max();

  //   pq_pop();
  //   print_max();

  //   pq_pop();
  //   print_max();

 	// pq_pop();
  //   print_max();


    pq_min_insert(1);
    pq_min_insert(2);
    pq_min_insert(8);
    pq_min_insert(4);
    pq_min_insert(10);
    pq_min_insert(11);

    print_min();

    pq_min_pop();
    print_min();

    pq_min_pop();
    print_min();

    pq_min_pop();
    print_min();

    pq_min_pop();
    print_min();

    pq_min_pop();
    print_min();

    pq_min_pop();
    print_min();

    


    return 0;
}