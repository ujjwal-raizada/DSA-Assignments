#include<stdio.h>
#define ll long long

int visited[1000000];
int am[1000][1000];
int n, m;
int path[1000][1000];

// void dfs(int node) {

//  visited[node] = 1;
//  printf("%d ", node);

//  for (ll i = 0; i < n; i++)
//      if (am[node][i] != 0 && visited[i] == 0)
//          dfs(i);
// }

void initialize(int n) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            am[i][j] = 999999; // infinity
            if (i == j)
                am[i][j] = 0;
        }

    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

void print_path(int u, int v) {

    while(v != u) {
        printf("%d -> ", v);
        v = path[u][v];
    }
}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    scanf("%d %d", &n, &m);
    initialize(n);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        am[x][y] = w;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", am[i][j]);
        }
        printf("\n");
    }
    

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (am[i][j] <  999999 && am[i][j] != 0)
                path[i][j] = i;
            else
                path[i][j] = n;
        }


    

    // floyd warshall Algorithm

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][j] > am[i][k] + am[k][j]) {
                    am[i][j] = am[i][k] + am[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", am[i][j]);
        }
        printf("\n");
    }

    printf("\n\nPath:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }

    // min. weight cycle

    int min = 999999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (min > am[i][j]+am[j][i])
                    min = am[i][j]+am[j][i];
            }
        }
    }

    printf("Min: %d\n", min);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (min == am[i][j]+am[j][i])
                    printf("u: %d, v: %d\n", i, j);
                    //print_path(i, j);
                

            }
        }
    }






    return 0;
}