#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

ll a[1000009];

ll merge(ll start, ll mid, ll end) {

	ll p = start;
	ll q = mid + 1;
	ll k = 0;
	ll arr[end - start + 1];
	ll count = 0;

	for (ll i = start; i <= end; i++) {

		if (p > mid)
			arr[k++] = a[q++];
		else if (q > end)
			arr[k++] = a[p++];

		else if (a[p] <= a[q])
			arr[k++] = a[p++];
		else {
			arr[k++] = a[q++];
			count += (mid - p + 1);
		}

	}

	for (ll i = start; i <= end; i++)
		a[i] = arr[i - start];

	return count;
}


ll merge_sort(ll start, ll end) {


	ll inv_count = 0;
	if (start < end) {
		ll mid = (start + end) / 2;

		inv_count += merge_sort(start, mid);
		inv_count += merge_sort(mid + 1, end);

		inv_count += merge(start, mid, end);
	}
	return inv_count;
}


int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    scanf("%lld", &n);

    for (ll i = 0; i < n; i++)
    	scanf("%lld", &a[i]);

    ll count = merge_sort(0, n - 1);
    printf("%lld", count);
    
    return 0;
}
