#include<stdio.h>
#include<string.h>
#define ll long long
int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char s[1000];
    scanf("%s", s);
    int slen = strlen(s);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
    	int f, r, k;
    	scanf("%d, %d, %d", &f, &r, &k);
    	int lr = r - f + 1;
    	int shift = k % lr;
    	char sa[1000];
    	char st[1000];


    	for (int i = f - 1; i < r; i++) {
    			sa[i - f + 1] = s[i];
    	}

    	for (int i = 0; i < lr; i++) {
    		int shift_temp = (i + shift) % lr;
    		st[shift_temp] = sa[i];
    	}

    	for (int i = 0; i < slen; i++) {
    		if (i >= f - 1 && i <= r - 1)
    			s[i] = st[i - f + 1];
    	}
    }

    printf("%s", s);

    


    return 0;
}