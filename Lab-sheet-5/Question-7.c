#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int comp(const void * a, const void * b) {
	return *(int*)a - *(int*)b;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    int d[n];

    for (int i = 0; i < n; i++)
    	scanf("%d", &d[i]);

    int matrix[n][n] = {0};

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		matrix[i][j] = 0;

    qsort(d, n, sizeof(int), comp);
    
    int height = d[n - 1];

    for (int i = 0; i < height; i++) {
    	matrix[i][i + 1] = 1;
    	//matrix[i + 1][i] = 1;
    }

    int node = height + 1;
    int exist = 1;
    int extra_edge;

    for (int i = 1; i < n; i++) {

    	if (exist != d[i]) {
    		extra_edge = d[i] - 1;
	    	matrix[d[i] - 1][node] = 1;
	    	//matrix[node][d[i] - 1] = 1;
	    	node++;
	    }
	    else {
	    	exist++;
	    }
    }

    printf("extra: %d\n", extra_edge);
    int a = -1, b = -1;
    for (int i = 0; i < n; i++) {
    	if (matrix[extra_edge][i] == 1 && a == -1)
    		a = i;
    	else if (matrix[extra_edge][i] == 1 && b == -1 && a != -1)
    		b = i;
    }

     matrix[a][b] = 1;
    // matrix[b][a] = 1;
    printf("%d %d\n", a, b);

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		printf("%d ", matrix[i][j]);
    	}
    	printf("\n");
    }

    return 0;
}