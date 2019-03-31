#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int a = -1;
    int p = 0;
    int ans[n];
    int q[2 * 100000];
    int front = n;
    int back = n;
    for (int i = 0; i <= 9; i++) {
    	a++;
    	q[n + i] = a;
    	front++;
    	ans[p] = a;
    	p++;


    }
    // printf("a %d\nfront %d\n%d", a, front, q[front-1]);
    front--;
    int x = q[back];
    while (x <= n && back <= front) {

    	x = q[back];
    	printf("x: %d\n", x);
    	back++;
    	

    	int u = x % 10;
    	if (u == 0 || u == 9) {
    		if (u == 0) {
    			 q[front + 1] = (x * 10) + 1;
    			 a = (x * 10) + 1;
    		}
    		if (u == 9) {
    			q[front + 1] = (x * 10) + 8;
    			a = ( x * 10) + 8;
    		}
    		front++;
    		ans[p] = a;
    		p++;
    	}
    	else {
    		q[front + 1] = (x * 10) + u + 1;
    		front++;
    		a = (x * 10) + u + 1;
    		ans[p] = a;
    		p++;
    		q[front + 1] = (x * 10) + u - 1;
    		front++;
    		a = (x * 10) + u - 1;
    		ans[p] = a;
    		p++;
    	}


    }

    for (int i = 0; i < p - 1; i++)
    	printf("%d ", ans[i]);


    return 0;
}