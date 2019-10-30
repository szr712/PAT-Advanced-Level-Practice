#include<bits/stdc++.h>

using namespace std;
const int maxn = 0xfffffff;
int n, m, k, q;
int p[1005] = {0};
int t[1005] = {0};
queue<int> line[25];

void display(int a, int b) {
    if (a - p[b] >= 540) {
        printf("Sorry\n");
    } else {
        int h = a / 60 + 8;
        int m = a - (h - 8) * 60;
        printf("%02d:%02d\n", h, m);
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n && i <= k; i++) {
        t[i] = p[i];
        line[i].push(i);
    }
    if (n < k) {
        for (int i = n + 1; i <= m * n && i <= k; i++) {
            t[i] = t[i - n] + p[i];
            if (i % n == 0) {
                line[n].push(i);
            } else {
                line[i % n].push(i);
            }
        }
    }
    if (k > m * n) {
        for (int i = n * m + 1; i <= k; i++) {
            int min = maxn, tmp = 0;
            for (int j = 1; j <= n; j++) {
                if (t[line[j].front()] < min) {
                    tmp = j;
                    min = t[line[j].front()];
                }
            }
            line[tmp].pop();
            int last = line[tmp].back();
            line[tmp].push(i);
            t[i] = p[i] + t[last];
        }
    }
    while (q--) {
        int tmp;
        scanf("%d", &tmp);
        display(t[tmp], tmp);
    }


}
