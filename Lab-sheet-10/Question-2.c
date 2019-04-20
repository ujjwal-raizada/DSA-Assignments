#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int minheap[1000000];
int mhp = 0;

int maxheap[1000000];
int hp = 0;

void insertmin(int x) {


	int i;
	for (i = mhp - 1; i >= 0; i--) {

		if (minheap[i] < x) {
			minheap[i + 1] = x;
			mhp++;
			break;
		}
		else {
			minheap[i + 1] = minheap[i];
		}
	}

	if (i == -1) {
		minheap[0] = x;
		mhp++;
		return;
	}

}

void printmaxheap() {

	for (int i = 0; i < hp; i++)
		printf("%d ", maxheap[i]);
	printf("\n");
}


void insertmax(int x) {


	int i;
	for (i = hp - 1; i >= 0; i--) {

		if (maxheap[i] > x) {
			maxheap[i + 1] = x;
			hp++;
			break;
		}
		else {
			maxheap[i + 1] = maxheap[i];
		}
	}

	if (i == -1) {
		maxheap[0] = x;
		hp++;
		return;
	}

}

void printminheap() {

	for (int i = 0; i < mhp; i++)
		printf("%d ", minheap[i]);
	printf("\n");
}

int minpop() {

	int t = minheap[0];
	for (int i = 0; i < mhp - 1; i++)
		minheap[i] = minheap[i + 1];

	return t;
}

int maxpop() {

	int t = maxheap[0];
	for (int i = 0; i < hp - 1; i++)
		maxheap[i] = maxheap[i + 1];
	hp--;

	return t;
}


int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    	insertmax(a[i]);
    }

    int mm = 0;

    for (int i = 0; i < k; i++) {
    	int t = maxpop();
    	printf("%d\n", t);
    	insertmax(t / 2);
    	mm += t;
    }

    printf("%d\n", mm);
    return 0;
}