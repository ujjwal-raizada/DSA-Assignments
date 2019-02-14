#include<stdio.h>
#include<string.h>

#define ll long long

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    int a1[n];
    int a2[m];

    for (int i = 0; i < n; i++)
    	scanf("%d", &a1[i]);

    for (int i = 0; i < m; i++)
    	scanf("%d", &a2[i]);
    

    int map[1000] = {0};
    for (int i = 0; i < m; i++) {
    	map[a2[i]] = i + 1;
    }


    int value = m + 1;
    for (int i = 0; i < 1000; i++) {

    	if (map[i] == 0) {
    		map[i] = value;
    		value++;
    	}

    }

    for (int i = 0; i < n - 1; i++)
    	for (int j = i + 1; j < n; j++) {

    		if (map[a1[i]] > map[a1[j]]) {
    			int temp = a1[i];
    			a1[i] = a1[j];
    			a1[j] = temp;
    		}

    	}

    for (int i = 0; i < n; i++)
    	printf("%d ", a1[i]);


    
    


    return 0;
}