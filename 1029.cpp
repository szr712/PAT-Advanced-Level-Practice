#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> a;
int x, y;

bool cmp(ll a,ll b){
    return a<b;
}

int main() {
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        ll tmp;
        scanf("%lld",&tmp);
        a.push_back(tmp);
    }
    scanf("%d",&y);
    for(int i=0;i<y;i++){
        ll tmp;
        scanf("%lld",&tmp);
        a.push_back(tmp);
    }
    sort(a.begin(),a.end(),cmp);
//    for(int i=0;i<a.size();i++){
//        cout<<i<<":"<<a[i]<<endl;
//    }
    cout<<a[ceil((a.size())/2.0)-1]<<endl;

}

