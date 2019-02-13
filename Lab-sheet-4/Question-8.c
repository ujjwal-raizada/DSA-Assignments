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

    scanf("%d", &a[0]);
    int temp = a[0];

    int peak;

    for (int i = 1; i < n; i++) {
    	scanf("%d", &a[i]);

        if (a[i] < a[i - 1])
            peak = i - 1;
    }

    int k;
    scanf("%d", &k);

    int l = peak + 1;
    int r = n + peak;

    while (l <= r) {

    	int mid = l + (r - l) / 2;

    	if (a[mid % n] == k) {
    		printf("%d", (mid % n) + 1);
    		break;
    	}
    	else {
    		if (k < a[mid % n])
    			r = mid - 1;
    		else
    			l = mid + 1;
     	}

    }

    
    


    return 0;
}