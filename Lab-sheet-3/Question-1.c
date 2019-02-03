#include<stdio.h>
#include <string.h>
#define ll long long

char t[100];
char p[100];

ll check() {
	ll c = 0;
	int tlen = strlen(t);
	for (ll i = 0; i < tlen; i++) {
		if (t[i] == p[c]) {
			c++;
		}
	}
	//printf("c: %d\n", c);
	int plen = strlen(p);
	if (plen == c)
		return 1;
	else
		return 0;

}

int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif



    scanf("%s", t);
    scanf("%s", p);
    //printf("%s", p);

    // t contains p
    int n;
    scanf("%d", &n);
    int order[n];

    for (int i = 0; i < n; i++) {
    	scanf("%d", &order[i]);
    }

    ll c = 0;
    while(1) {
    	if (check() && c < n) {
    		t[order[c] - 1] = '*';
    		c++;
    	}
    	else {
    		printf("%d", c - 1);
    		return 0;
    	}
    }
    


    return 0;
}