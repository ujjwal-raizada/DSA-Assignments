#include<stdio.h>
#include<string.h>

#define ll long long

int n;
int matrix[1000][1000];
int visited[1000][1000];

int max(int a, int b) {
	return (a > b ? a : b);
}

int check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] == 1 && visited[x][y] == 0)
		return 1;
	return 0;
}

int region(int x, int y) {

	if (!check(x, y)) {
		return 0;
	}

	visited[x][y] = 1;

	int d1 = region(x - 1, y);
	int d2 = region(x - 1, y - 1);
	int d3 = region(x - 1, y + 1);
	int d4 = region(x, y - 1);
	int d5 = region(x, y + 1);
	int d6 = region(x + 1, y - 1);
	int d7 = region(x + 1, y + 1);
	int d8 = region(x + 1, y);

	return (1 + d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8);



}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    scanf("%d", &n);

    

    for(int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		scanf("%d", &matrix[i][j]);
    		visited[i][j] = 0;
    	}
    }

    int maximum = -1;

    for(int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++) {
    		if (matrix[i][j] == 1 && visited[i][j] == 0)
    			maximum = max(maximum, region(i, j));
    	}

    printf("%d", maximum);

    return 0;
}