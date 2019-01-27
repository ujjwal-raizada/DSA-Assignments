#include<stdio.h>
#define ll long long
#define TRUE 1
#define FALSE 0
int n, m;
int matrix[1000][1000];

void initialize() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 999999999;
}

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    initialize();
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
    	int x, y;
    	scanf("%d %d", &x, &y);
    	matrix[x][y] = 1;
    	matrix[y][x] = 1;

    }

    for (int k = 0; k < n; k++)
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    int t;
    scanf("%d", &t);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            if (matrix[i][j] == t)
                printf("%d -> %d\n", i, j);

    return 0;
}