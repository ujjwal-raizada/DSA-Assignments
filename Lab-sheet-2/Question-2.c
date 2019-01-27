#include<stdio.h>
#define ll long long

int n, m;
int matrix[1000][1000];
int prev[1000];
int level[1000];
int s;

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
	level[x] = 0;
	int y;


	int max = -1;
	int visited[1000] = {0};
	visited[x] = 1;
	int d = 0;
	while(front > back) {
		int v = q[front - 1];
		front--;
		
		for (int i = 0; i < n; i++) {
			if (matrix[v][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				prev[i] = v;
				printf("%d ", i);
				q[back-1] = i;
				level[i] = level[v] + 1;
				if (level[i] > max) {
					max = level[i];
					y = i;
				}
				back--;



			}
		}

	}
	printf("\nx:%d, y:%d", x, y);
	s = y;
	return max;

}

int main() {

    //Using text files for input output
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    scanf("%d %d", &n, &m);
    initialize();

    for (int i = 0; i < m; i++) {
    	int x, y;
    	scanf("%d %d", &x, &y);
    	matrix[x][y] = 1;
    	matrix[y][x] = 1;

    }
    
    int dist = bfs(6);

    int z = s;
    printf("\n%d -> ", s);
    while (z != 6) {
    	z = prev[z];
    	printf("%d -> ", z);

    }

    printf("\n");
    for (int i = 0; i < n; i++)
    	printf("%d", prev[i]);



    return 0;
}