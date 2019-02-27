#include<stdio.h>
#include<string.h>

#define ll long long

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[100];
    scanf("%s", str);

    int l = strlen(str);

    for (int i = 0; i < l; i++)
    	for (int j = i + 2; j < l; j++) {
    		printf("%d %d\n", i, j);
    		int flag = 0;
    		char t = 'a';
    		for (int k = i; k <= (j + i) / 2; k++) {
    			if (str[k] == str[(i + j) - k] && str[k] >= t) {
    				t = str[k];
    			}
    			else {
    				flag = 1;
    			}
    		}
    		if (flag == 0) {
    			for (int k = i; k <= j; k++)
    				printf("%c", str[k]);
    			printf("\n");
    		}

    	}

    


    return 0;
}