#include<stdio.h>
#define ll long long
#define TRUE 1
#define FALSE 0
int n, m;
int matrix[1000][1000];
int dsu[1000];

void initialize() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			matrix[i][j] = 0;
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
    scanf("%d", &n);

    int f[n] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &f[i]);
    }

    int d;
    scanf("%d", &d);

    initial_dsu();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (abs(f[i] - f[j]) > d) {
                matrix[i][j] = 1;
                matrix[i][j] = 1;
                join_dsu(i, j);
                // printf("%d %d\n", i, j);
            }
        }

    // for (int i =0; i < n; i++)
    //     printf("%d ", dsu[i]);

    int hash[n] = {0};

    for (int i = 0; i < n; i++)
        hash[dsu[i]]++;

    // for (int i = 0; i < n; i++)
    //     printf("%d ", hash[i]);


    for (int k = 0; k < n; k++) {
        if (hash[k] > 0) {
            printf("\n");
            for (int i = 0; i < n; i++) {
                int flag = 0;
                for (int j = 0; j < n; j++) {
                    if (dsu[i] == k && dsu[j] == k) {
                        printf("%d ", matrix[i][j]);
                        flag = 1;
                    }
                }
                if (flag == 1)
                    printf("\n");
            }


        }
    }








    return 0;
}