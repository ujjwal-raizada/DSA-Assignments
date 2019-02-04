#include<stdio.h>
#include<string.h>

#define ll long long
int n, m;
int matrix[1000][1000];
int visited[1000] = {0};

int dfs(int x, int y) {

	visited[x] = 1;

	if (x == y) {
		//printf("x: %d, y: %d\n", x, y);
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (matrix[x][i] == 1 && visited[i] == 0) {
			int result = dfs(i, y);
			if (result == 1)
				return 1;
		}
	}
	return 0;
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    //int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		matrix[i][j] = 0;



    for (int i = 0; i < m; i++) {
    	int x, y;
    	scanf("%d %d", &x, &y);
    	matrix[x-1][y-1] = 1;
    }

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
    	for (int j = 0; j < n; j++)
    		visited[j] = 0;

    	int x, y;
    	scanf("%d %d", &x, &y);
    	if (dfs(x-1, y-1)) {
    		printf("Yes\n");
    	}
    	else {
    		printf("No\n");
    	}

    }


    


    return 0;
}