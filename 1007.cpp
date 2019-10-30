//使用前缀和，十分巧妙，一开始的思路是用dp发现太过复杂
#include <bits/stdc++.h>

using namespace std;

int s[10005] = {0};
int K;
const int nmax = -(0xfffffff - 1);

int main() {
    cin >> K;
    for (int i = 0; i < K; i++) {
        scanf("%d", &s[i]);
    }
    int sum = nmax, tmp = 0, left = 0, right = K - 1, tmpl = 0;
    for (int i = 0; i < K; i++) {
        tmp += s[i];
        if (tmp < 0) {
            tmp = 0;
            tmpl = i + 1;
        } else if (tmp > sum) {
            sum = tmp;
            left = tmpl;
            right = i;
        }
    }
    if (sum < 0) cout << 0 << " " << s[0] << " " << s[K-1];
    else cout << sum << " " << s[left] << " " << s[right];


}