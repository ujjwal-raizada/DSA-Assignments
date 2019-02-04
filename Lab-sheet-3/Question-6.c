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

    int extra;
    if (slen % 2 == 0)
    	extra = 0;
    else
    	extra = 1;

    int hash[26] = {0};

    for (int i = 0; i < slen; i++) {
    	hash[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++ ) {
    	if (hash[i] % 2 != 0 && extra == 0) {
    		printf("No");
    		return 0;
    	}

    	if (hash[i] % 2 != 0 && extra == 1)
    		extra--;
    }

    printf("Yes");


    return 0;
}

