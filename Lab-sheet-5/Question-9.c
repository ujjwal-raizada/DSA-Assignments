#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int comp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
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

    qsort(a, n, sizeof(int), comp);

    int ans = 999999999;

    for (int i = 0; i < n; i++) {

    	int l = 0;
    	int r = n - 1;

    	while(l <= r) {

    		int mid = l + (r - l) / 2;

    		if (a[mid] <= a[i] * 2) {
    			ans = min(ans, i + (n - 1 - mid));
    			l = mid + 1;
    		}
    		else
    			r = mid - 1;

    	}

    }

    printf("%d", ans);

    


    return 0;
}