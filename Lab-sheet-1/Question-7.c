#include<stdio.h>
#define ll long long

char* reverse(char* t,int a,int b) {
	char temp[100];
	ll c = 0;
	for (int i = a; i <= b; i++) {
		temp[c] = t[i];
		c++;
	}
	c = 0;
	for (int i = b; i >= a; i--) {
		t[i] = temp[c];
		c++;
	}
	return t;
}

char* alternate(char* text) {
	int i = 0;
    ll c = 0;
	while(text[i] != '\n') {
    	if (text[i] != ' ') {
    		if (c%2 == 0) {
		    	int x = text[i] - 'a';
		    	x = (x+3)%26;
		    	text[i] = (char)(x+'a');
	    }
	    	c++;
    	}
    	i++;
    }
    return text;
}

char* decode_alternate(char* text) {
	int i = 0;
    ll c = 0;
	while(text[i] != '\n') {
    	if (text[i] != ' ') {
    		if (c%2 == 0) {
		    	int x = text[i] - 'a';
		    	x = (x-3)%25;
		    	if (x < 0)
		    		x = 26 + x;
		    	text[i] = (char)(x+'a');
	    }
	    	c++;
    	}
    	i++;
    }
    return text;
}

char* encode(char* text) {

	alternate(text);
	int i = 0;
	int a = 0, b = 0;
	while(text[i] != '\n') {

		if (text[i] == ' ') {
			b = i-1;
			reverse(text, a, b);
			a = i+1;
		}

		i++;
	}

	reverse(text, a, i-1);
	return text;
}

char* decode(char* text) {
	int i = 0;
	int a = 0, b = 0;
	while(text[i] != '\n') {

		if (text[i] == ' ') {
			b = i-1;
			reverse(text, a, b);
			a = i+1;
		}

		i++;
	}

	reverse(text, a, i-1);
	decode_alternate(text);
	return text;
}

int main() {
	    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char text[100];
    fgets(text, 100, stdin);

    
    encode(text);
    printf("%s", text);
    decode(text);
    printf("%s", text);

	return 0;
}