#include <bits/stdc++.h>

using namespace std;
char w[85], u[85][85];

int main() {
    scanf("%s", w);
    memset(u, ' ', sizeof(u));
    int n = strlen(w) + 2;
    int a, b;
    if (n % 3 == 0) {
        a = b = n / 3;
    } else if (n % 3 == 1) {
        a = n / 3;
        b = n / 3 + 1;
    } else if (n % 3 == 2) {
        a = n / 3;
        b = n / 3 + 2;
    }
    for (int i = 0; i < a; i++) {
        u[i][0] = w[i];
        u[i][b - 1] = w[n - 3 - i];
    }
    for (int i = a - 1; i < b + a - 2; i++) {
        u[a - 1][i - a + 1] = w[i];
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%c", u[i][j]);
        }
        printf("\n");
    }
}

