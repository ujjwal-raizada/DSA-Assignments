#include<stdio.h>
#include<string.h>

#define ll long long

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k, s, T;
    scanf("%d %d %d %d", &n, &k, &s, &T);
    int petrol[k];
    for (int i = 0; i < k; i++)
    	scanf("%d", &petrol[i]);

    int cost = 99999999;

    while (n--) {

    	int c, v;
    	scanf("%d %d", &c, &v);
    	int ip = v;
    	int t = 0;
    	int pos1 = 0;

    	petrol[k] = s;

    	for (int i = 0; i <= k; i++) {

    		int fl = ip - (petrol[i] - pos1);
    		if (fl < 0)
    			continue;

    		t = t + ((petrol[i] - pos1) * 2);
    		if (fl >= (petrol[i] - pos1))
    			t = t - (petrol[i] - pos1);
    		else
    			t = t - fl;
    		pos1 = petrol[i];

    	}

    	printf("c: %d, t: %d\n", c, t);

    	if (t <= T)
    		if (c < cost)
    			cost = c;



    }

    printf("%d\n", cost);
    


    return 0;
}