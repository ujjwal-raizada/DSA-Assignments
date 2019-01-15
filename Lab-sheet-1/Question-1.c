#include<stdio.h>
#define ll long long

int main() {
	    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    scanf("%lld", &n);

    // min row, max column
    ll matrix[n][n];
    ll row[n] = {0}; // value, i, j
    ll column[n] = {0}; // value i, j

    // for (ll i = 0; i < n; i++)
    // 	printf("%lld %lld %lld\n", row[i][0], row[i][1], row[i][2]);

    for (ll i = 0; i < n; i++) {
    	row[i] = 99999;
    	column[i] = -99999;
    }


    for (ll i = 0; i < n; i++) {
    	for (ll j = 0; j < n; j++) {
    		scanf("%lld", &matrix[i][j]);
    		if (matrix[i][j] < row[i])
    			row[i] = matrix[i][j];

    		if (matrix[i][j] > column[j])
    			column[j] = matrix[i][j];
    	}
    }

    for (ll i = 0; i < n; i++)
    	printf("%lld %lld\n", row[i], column[i]);

    ll saddle_x;
    ll saddle_y;
    ll saddle_value;
    ll saddle_flag = 0;

    for (ll i = 0; i < n; i++) {
    	for (ll j = 0; j < n; j++) {
    		if (row[i] == matrix[i][j] && column[j] == matrix[i][j]) {
    			saddle_flag = 1;
    			saddle_x = i;
    			saddle_y = j;
    			saddle_value = matrix[i][j];
    		}

    	}
    }

    if (saddle_flag) {
    	printf("Saddle Point: (%lld, %lld) %lld ", saddle_x, saddle_y, saddle_value);
    }
    else {
    	printf("No saddle point.");
    }


	return 0;
}