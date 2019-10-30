#include<bits/stdc++.h>

using namespace std;

void display(int a) {
    if (a == 0) cout << "W" << " ";
    else if (a == 1) cout << "T" << " ";
    else if (a == 2) cout << "L" << " ";
    else return;
}

int main() {
    double g[5][5] = {0};
    int ans[5] = {0};
    for (int i = 0; i < 3; i++) {
        ans[i] = 4;
        int mini = 1;
        for (int j = 0; j < 3; j++) {
            cin >> g[i][j];
            if (mini < g[i][j]) {
                mini = g[i][j];
                ans[i] = j;
            }
        }
    }
    double sum = 1;
    for (int i = 0; i < 3; i++) {
        display(ans[i]);
        sum *= g[i][ans[i]];
    }
    sum = (sum * 0.65 - 1) * 2;
    printf("%.2lf", sum);
}