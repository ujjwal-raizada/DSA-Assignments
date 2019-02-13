#include<stdio.h>
#include<string.h>

#define ll long long

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    	scanf("%d", &a[i]);

    int pointer_1 = 0;
    int pointer_2 = 1;

    while (pointer_2 < n && a[pointer_1] == a[pointer_2]) {
    	pointer_1 += 2;
    	pointer_2 += 2;
    }

    printf("%d", a[pointer_1]);

    


    return 0;
}