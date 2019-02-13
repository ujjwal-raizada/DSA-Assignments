#include<stdio.h>
#include<string.h>

#define ll long long
int a[1000];
int n, m;

int products(int time) {

	int total_products = 0;

	for (int i = 0; i < n; i++)
		total_products += (time / a[i]);

	return total_products;

}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    	scanf("%d", &a[i]);

    int l = 0;
    int r = 1000000;

    while ( l <= r) {

    	int mid = l + (r - l) / 2;
    	int tp =products(mid);

    	if (tp == m) {
    		printf("%d", mid);
    	}

    	if (tp < m)
    		l = mid + 1;
    	else
    		r = mid - 1;
    }
    return 0;
}