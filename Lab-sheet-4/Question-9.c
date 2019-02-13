#include<stdio.h>
#include<string.h>

#define ll long long

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

    int k;
    scanf("%d", &k);

    int l = 0;
    int r = n - 1;

    while (l <= r) {

    	int mid = l + (r - l) / 2;

    	if (a[mid] == k) {
    		printf("Naruto %d", mid + 1);
    		break;
    	}
    	else {
    		if (k < a[mid])
    			r = mid - 1;
    		else
    			l = mid + 1;
     	}

    }

    if (l > r) {
    	printf("Sasuke %d", l + 1);
    }

    


    return 0;
}