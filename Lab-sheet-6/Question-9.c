#include<stdio.h>
#include<string.h>

#define ll long long


int findOptimal(int n) {

	if (n <= 6)
		return n;

	int max = 0;

	int b;
	for (b = n - 3; b >= 1; b--) {

		int curr = (n - b - 1) * findOptimal(b);
		if (curr > max)
			max = curr;

	}

	return max;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    printf("%d", findOptimal(n));

    





    


    return 0;
}