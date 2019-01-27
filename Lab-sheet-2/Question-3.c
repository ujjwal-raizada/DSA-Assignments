#include<stdio.h>
#define ll long long
#define TRUE 1
#define FALSE 0
int n, m;
int matrix[1000][1000];

void initialize() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 0;
}
int bfs(int x) {

	int q[(2*n)+2];
	q[n] = x;
	int front = n+1;
	int back = n;
	int level[1000] = {0};
	level[x] = 1;
	//int y;

	// 1: Red 2: Blue

	//int max = -1;
	int visited[1000] = {0};
	visited[x] = 1;
	int d = 0;
	while(front > back) {
		int v = q[front - 1];
		front--;
		
		for (int i = 0; i < n; i++) {
			if (matrix[v][i] == 1) {
				if (visited[i] == 0) {
					visited[i] = 1;
					// prev[i] = v;
					printf("%d ", i);
					q[back-1] = i;
					level[i] = (level[v] == 1) ? 2 : 1;
					
					back--;
				}
				else {
					if (level[i] == level[v])
						return 0;
				}
			}
		}
	}
return 1;
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

    int is_biparted = bfs(0);

    if (is_biparted == TRUE)
    	printf("Graph is Bipartite");
    else
    	printf("Graph is not bipartite");


    return 0;
}