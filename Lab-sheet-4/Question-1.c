#include<stdio.h>
#include<string.h>

#define ll long long

int a[1000];

int sum(int k) {

	int s = 0;
	for (int i = 0; i < k; i++)
		s += a[i] + (k * (i + 1));
	return s;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n, s;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++)
    	scanf("%d", &a[i]);

    int l = 0;
    int r = n;
    int cost;

    while (l <= r) {

    	int mid = l + (r - l) / 2;

    	cost = sum(mid);
    	if (cost == s) {
    		printf("inside loop\n");
    		printf("cost: %d, n: %d", cost, mid);
    		return 0;
    	}
    	else {
    		if (cost < s)
    			l = mid + 1;
    		else
    			r = mid - 1;
    	}

    }

    if (l > r) {
    	printf("outside loop\n");
    	cost = sum(r);
    	printf("cost: %d, n: %d", cost, r);
    }

    


    return 0;
}