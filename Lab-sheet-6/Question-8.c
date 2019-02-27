#include<stdio.h>
#include<string.h>

#define ll long long
char matrix[1000][1000];
int n, m;
char str[100];

int check(int i, int j) {
	if (i >= n || i < 0 || j >= m || j < 0)
		return 0;
	return 1;
}

int func (int i, int j, int pos) {
	
	if (!check(i, j))
		return 0;

	if (pos >= strlen(str))
		return 0;

	if (pos == strlen(str) - 1)
		if (matrix[i][j] == str[pos])
			return 1;
		else
			return 0;

	if (str[pos] == matrix[i][j]) {
		
		int a1 = func(i, j, pos + 1);
		int a2 = func(i + 1, j, pos + 1);
		int a3 = func(i, j + 1, pos + 1);
		int a4 = func(i - 1, j, pos + 1);
		int a5 = func(i, j - 1, pos + 1);
		return a1 + a2 + a3 + a4 + a5;


	}
	else {
		if (pos == 0) {
		int a2 = func(i + 1, j, pos);
		int a3 = func(i, j + 1, pos);
		return a2 + a3;
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
    	for (int j = 0; j < m; j++)
    		scanf(" %c", &matrix[i][j]);

    int t;
    scanf("%d", &t);

    while (t--) {
    	scanf("%s", str);

    	int ans = func(0, 0, 0);
    	if (ans > 0)
    		printf("yes\n");
    	else
    		printf("no\n");


    }


    


    return 0;
}