#include<stdio.h>
#include<string.h>

#define ll long long

int k;

int question(int v) {

	int temp = v;
	int sum = v;

	while (temp > 0) {

		temp = temp / k;
		sum += temp;
	}

	return sum;

}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d %d", &n, &k);

    int l = 0;
    int r = n;

    while (l <= r) {

    	int mid = l + (r- l) / 2;
    	int questions = question(mid);

    	if (questions == n) {
    		printf("%d", mid);
    		return 0;
    	}

    	if (questions < n)
    		l = mid + 1;
    	else
    		r = mid - 1;
    }

    if (l < r)
    	printf("%d", r);

    return 0;
}