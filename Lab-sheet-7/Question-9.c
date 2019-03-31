#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int comp(const void *a, const void *b) {

	int temp;
	int x = *(int*)a;
	int y = *(int*)b;

	int ans1 = 0;
	int ans2 = 0;

	int c1 = 1;
	int t1 = y;
	while (t1 > 0) {
		c1 *= 10;
		t1 = t1 / 10;
	}

	ans1 = (x * c1) + y;


	int c2 = 1;
	int t2 = x;
	while (t2 > 0) {
		c2 *= 10;
		t2 = t2 / 10;
	}

	ans2 = (y * c2) + x;

	if (ans1 < ans2)
		return 1;
	else
		return -1;

}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int number[n];
    for (int i = 0; i < n; i++) {
    	scanf("%d", &number[i]);
    }

    qsort(number, n, sizeof(int), comp);

    for (ll i = 0; i < n; i++)
    	printf("%d", number[i]);

    


    return 0;
}