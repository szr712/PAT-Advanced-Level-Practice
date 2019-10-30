#include <bits/stdc++.h>

using namespace std;

int n, b;
vector<int> n2;

void de2b() {
    int tmp = n;
    while (tmp != 0) {
        int t = tmp % b;
        n2.push_back(t);
        tmp /= b;
    }
}

int main() {
    scanf("%d %d", &n, &b);
    de2b();
    int half = n2.size() / 2,i;
    for (i = 0; i < half; i++) {
        if (n2[i] != n2[n2.size() - i-1])break;
    }
    if(i<half) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    for(int i=n2.size()-1;i>0;i--){
        printf("%d ",n2[i]);
    }
    printf("%d",n2[0]);
}
