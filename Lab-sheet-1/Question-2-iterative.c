#include<stdio.h>
#define ll long long

int main() {
      //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    scanf("%lld", &n);

    ll steps = 1;
    ll counter = 0;
    ll up, down, right, left;
    up = 1;
    down = 3;
    right = 0;
    left = 2;

    ll x, y;
    x = n/2;
    y = n/2;
    ll matrix[n][n];
    matrix[x][y] = 1;
    ll p = 2;
    while(p <= n*n) {
      if (counter == right) {
        for (ll i = 1; i <= steps; i++) {
          matrix[x][y+i] = p;
          p++;
        }
        y += steps;
      }

      if (counter == left) {
        for (ll i = 1; i <= steps; i++) {
          matrix[x][y-i] = p;
          p++;
        }
        y -= steps;
      }

      if (counter == up) {
        for (ll i = 1; i <= steps; i++) {
          matrix[x-i][y] = p;
          p++;
        }
        x -= steps;
      }

      if (counter == down) {
        for (ll i = 1; i <= steps; i++) {
          matrix[x+i][y] = p;
          p++;
        }
        x += steps;
      }

      printf("x: %lld  y: %lld\n", x, y);
      counter = ((counter+1)%4);
      if (counter%2 == 0)
        steps++;
    }

    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        printf("%lld ", matrix[i][j]);
      }
      printf("\n");
    }


  return 0;
}