#include<stdio.h>
#include<string.h>

#define ll long long
int X, Y, n;
int matrix[1000][1000];
int visited[1000];

int dfs1(int x) {

	
	if (x == X)
		return 0;

	visited[x] = 1;

	for (int i = 0; i < n; i++) {
		if (matrix[x][i] == 1 && visited[i] == 0) {
				dfs1(i);
		}
	}

	return 0;
}

int dfs2(int x) {

	
	if (x == Y)
		return 0;

	visited[x] = 1;

	for (int i = 0; i < n; i++) {
		if (matrix[x][i] == 1 && visited[i] == 0) {
				dfs2(i);
		}
	}

	return 0;
}

void initialize() {
	for (int i = 0; i > 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 0;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    scanf("%d %d %d", &n, &X, &Y);
    initialize();

    for (int i = 0; i < n - 1; i++) {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	matrix[u][v] = 1;
    	matrix[v][u] = 1;
    }

   for (int i = 0;  i < n; i++)
   	visited[i] = 0;

    dfs1(Y);

    int x_child = 0;
    for (int i = 0;  i < n; i++)
    	if (visited[i] == 0)
    		x_child++;

    for (int i = 0;  i < n; i++)
   		visited[i] = 0;

   	dfs2(X);

    int y_child = 0;
    for (int i = 0;  i < n; i++)
    	if (visited[i] == 0)
    		y_child++;

    int total_pair = (n * (n - 1)); // 2 * NC2

    printf("x: %d, y: %d\n", x_child, y_child);

    int forbidden = (x_child) * (y_child);

    int ans = total_pair - forbidden;
    printf("%d", ans);

    return 0;
}