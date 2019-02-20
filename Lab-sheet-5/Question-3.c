#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long
int arr[1000000];
int ap = 0;

int comp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}


void insert() {
	//printf("insert\n");
	int x;
	scanf("%d", &x);

	int p = 0;
	if (x >= arr[ap - 1]) {
		arr[ap] = x;
		ap++;
	}
	else {
		while(arr[p] <= x)
			p++;
		for (int i = ap; i > p; i--) {
			arr[i] = arr[i - 1];
		}
		arr[p] = x;
		ap++;
	}
	
}



void delet() {
	int x;
	scanf("%d", &x);

	int p = 0;
	while(arr[p] != x)
		p++;

	for (int i = p; i < ap; i++) {
		arr[i] = arr[i + 1];
	}
	ap--;
}

void sort() {
	qsort(arr, ap, sizeof(int), comp);
}

void swap() {

	int a, b;
	scanf("%d %d", &a, &b);

	int p1 = 0, p2 = 0;
	while(arr[p1] != a)
		p1++;
	while(arr[p2] != b)
		p2++;

	arr[p1] = b;
	arr[p2] = a;

}

void print() {
	for (int i = 0; i < ap; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char c;
    do {
    	scanf("%d%c", &arr[ap], &c);
    	ap++;
    } while (c != '\n');

     // for (int i = 0; i < 7; i++)
     // 	printf("%d ", arr[i]);
    int n;
    scanf("%d", &n);

    while (n--) {

    	char op;
    	scanf(" %c", &op);

    	if (op == 'I')
    		insert();
    	if (op == 'D')
    		delet();
    	if (op == 'S') {
    		char op2;
    		scanf(" %c", &op2);
    		if (op2 == 'W')
    			swap();
    		else
    			sort();
    	}
    	print();
    }





    


    return 0;
}