#include<stdio.h>
#define ll long long

ll check_prime(ll n) {
	for (ll i = 2; i*i <= n; i++) {
		if (n%i == 0 && n != 2)
			return 0;
	}
	return 1;
}

int main() {
	    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll a, b;
    scanf("%lld %lld", &a, &b);

    for (ll i = a; i <= b; i++) {
    	ll t = check_prime(i);
    	if (t == 1)
    		printf("%lld\n", i);
    }

	return 0;
}