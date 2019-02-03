#include<stdio.h>
#include<string.h>
#define ll long long
int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char s[101];
    scanf("%s", s);

    int l = strlen(s);

    for (int i = 0; i < l; i++) {
    	int ch = s[i] - 'a';
    	int shift = (ch + 3) % 26;
    	char value = shift + 'a';
    	s[i] = value;
    }

    printf("%s", s);
    


    return 0;
}