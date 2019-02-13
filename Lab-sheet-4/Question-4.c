#include<stdio.h>
#include<string.h>
#include<math.h>

#define ll long long


int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int dom[n];
    int cost[n];
    int final_cost = 999999;
    int final_height = 0;
    int dominos_sum = 0;
    int final_no_tower;

    for (int i = 0; i < n; i++) {
    	scanf("%d", &dom[i]);
    	dominos_sum += dom[i];
    }

    for (int i = 0; i < n; i++)
    	scanf("%d", &cost[i]);

    for (int x = 1; x < (int)pow(2, n); x++) {

    	int tower_count = 0;

    	for (int i = 0; i < n; i++)
    		if (x & (1 << i))
    			tower_count++;

    	int temp_cost = 0;
    	int height = (dominos_sum / tower_count);

    	if (dominos_sum % tower_count == 0) {

    		for (int i = 0; i < n; i++) {

    			if (x & (1 << i))
    				temp_cost += abs(height - dom[i]) * cost[i];
    			else
    				temp_cost += dom[i] * cost[i];

    		}

    		if (temp_cost < final_cost) {
    			final_cost = temp_cost;
    			final_height = height;
    			final_no_tower = tower_count;
    		}

    	}

    }

    printf("cost: %d, height: %d, no. of tower: %d\n", final_cost, final_height, final_no_tower);

    return 0;
}