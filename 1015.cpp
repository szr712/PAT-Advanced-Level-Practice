//主要是对1有特判，1不是素数
#include <bits/stdc++.h>

using namespace std;


int n, d;

bool isPrime(int n) {
    bool prime = true;
    for (int i = 2; i <= (int) sqrt(n * 1.0); i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}


vector<int> de2ra(int ra, int n) {
    vector<int> tmp;
    while (n != 0) {
        int t = n % ra;
        tmp.push_back(t);
        n /= ra;
    }
    return tmp;
}

int ra2de(vector<int> n, int ra) {
    int t = 1;
    int ans = 0;
    for (int i = n.size() - 1; i >= 0; i--) {
        ans += n[i] * t;
        t *= ra;
    }
    return ans;
}

int main() {
    while (scanf("%d", &n)) {
        if (n < 0) return 0;
        else {
            scanf("%d", &d);
            if (n <= 1) {
                cout << "No" << endl;
                continue;
            }
            vector<int> tmp = de2ra(d, n);
            int ans = ra2de(tmp, d);
            bool flag[2] = {0};
            if (isPrime(n) && isPrime(ans) && ans != 1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
}
