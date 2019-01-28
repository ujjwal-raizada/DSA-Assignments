#include<stdio.h>
#define ll long long
#define TRUE 1
#define FALSE 0
int n, m;
int matrix[1000][1000];
int level[1000] = {0};

void initialize() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 999999999;
}

void bfs(int x) {
    int q[2*n+2];
    q[n] = x;
    int front = n+1;
    int back = n;
    level[x] = 0;

    int visited[n+1] = {FALSE};
    visited[x] = TRUE;

    while(front > back) {
        int v = q[front - 1];
        front--;
        for (int i = 1; i <= n; i++) {
            if (matrix[v][i] == 1 && visited[i] == FALSE) {
                level[i] = level[v] + 1;
                visited[i] = TRUE;
                q[back - 1] = i;
                back--;
            }
        }
    }
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    initialize();
    scanf("%d", &n);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    scanf("%d", &m);
    int uni[n+1] = {FALSE};

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        uni[x] = TRUE;
    }

    bfs(1);


    int min_dist = 999999999;
    int min_id;
    for (int i = 1; i <= n; i++) {
        if (uni[i] == TRUE && level[i] < min_dist) {
            min_dist = level[i];
            min_id = i;
        }
    }

    printf("Min Dis: %d\nMin id: %d", min_dist, min_id);






    return 0;
}