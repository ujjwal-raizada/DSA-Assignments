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

    int l = 0;
    int r = n - 1;

    while (l <= r) {

    	int mid = l + (r - l) / 2;

    	if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1]) {
    		printf("%d", a[mid]);
    		return 0;
    	}

    	if (mid % 2 == 0) {
    		if (a[mid] == a[mid + 1])
    			l = mid + 1;
    		else
    			r = mid - 1;
    	}
    	else {
    		if (a[mid] == a[mid - 1])
    			l = mid + 1;
    		else
    			r = mid - 1;
    	}
    }




    return 0;
}