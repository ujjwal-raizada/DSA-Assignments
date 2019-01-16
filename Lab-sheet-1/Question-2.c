#include<stdio.h>
#define ll long long

ll min(ll x, ll y) {
	if (x < y)
		return x;
	else
		return y;
}

int main() {
	    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    scanf("%lld", &n);

 	// For upper right half,
	// mat[i][j] = (n-2*x)*(n-2*x)-(i-x)-(j-x)

	// For lower left half,
	// mat[i][j] = (n-2*x-2)*(n-2*x-2) + (i-x) + (j-x)

    ll matrix[n][n];


    for (ll i = 0; i < n; i++) {
    	for (ll j = 0; j < n; j++) {

    		ll x = min(min(i, j), min(n-1-i, n-1-j));

    		//printf("i:%lld j:%lld x:%lld\n", i, j, x);

    		// j => n - j - 1
    		if (i - j <= 0) {
    			matrix[n-i-1][n-j-1] = (n-2*x)*(n-2*x)-(i-x)-(j-x);
    		}
    		else {
    			matrix[n-i-1][n-j-1] = (n-2*x-2)*(n-2*x-2)+(i-x)+(j-x);
    		}
    	}
    }

    for (ll i = 0; i < n; i++) {
    	for (ll j = 0; j < n; j++) {
    		printf("%lld ", matrix[i][j]);
    	}
    	printf("\n");
    }





	return 0;
}