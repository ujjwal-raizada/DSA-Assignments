#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int abs(int a) {

	if (a >= 0)
		return a;
	else
		return -1 * a;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    	scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmpfunc);

    int k;
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {

    	int l = i;
    	int r = n - 1;

    	while (l <= r) {

    		int mid = l + (r - l) / 2;

    		if (abs(a[mid] - a[i]) == k) {
    			printf("%d", a[mid] + a[i]);
    			return 0;
    		}

    		if (abs(a[mid] - a[i]) > k)
    			r = mid - 1;
    		else
    			l = mid + 1;    		

    	}

    }

    printf("-1");


    return 0;
}