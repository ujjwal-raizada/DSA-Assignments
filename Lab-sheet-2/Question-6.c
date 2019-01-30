#include<stdio.h>
#define ll long long
#define TRUE 1
#define FALSE 0
int n, m;
int matrix[1000][1000];
int matrix2[1000][1000];
int dsu[1000];

void initialize() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 0;

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            matrix2[i][j] = 0;
}

void initial_dsu() {
    for (int i =0; i < n; i++)
        dsu[i] = i;
}

void join_dsu(int a, int b) {
    int t = dsu[b];
    for (int i = 0; i < n; i++)
        if (dsu[i] == t)
            dsu[i] = dsu[a];
}

int abs(int a) {
    if (a >= 0)
        return a;
    else
        return (-1)*a;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    initialize();
    scanf("%d %d", &n, &m);

    int edges[m+1][2];
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        matrix[x][y] = i+1;
        matrix[y][x] = i+1;
        edges[i+1][0] = x;
        edges[i+1][1] = y;
    }

    for (int k = 1; k <= m; k++) {
        int u = edges[k][0];
        int v = edges[k][1];

        for (int i = 0; i < n; i++) {
            // u -> , v ->
            if (matrix[u][i] > 0 && i != v) {
                matrix2[k][matrix[u][i]] = 1;
                matrix2[matrix[u][i]][k] = 1;
            }

            if (matrix[v][i] > 0 && i != u) {
                matrix2[k][matrix[v][i]] = 1;
                matrix2[matrix[v][i]][k] = 1;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }









    return 0;
}
