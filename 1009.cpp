#include <bits/stdc++.h>

using namespace std;
double xi[2005];
double tmp[2005];

int main() {
    memset(xi, 0, sizeof(xi));
    memset(tmp, 0, sizeof(tmp));
    //int num=0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int zhi;
        double xishu;
        cin >> zhi >> xishu;
        tmp[zhi] = xishu;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int zhi;
        double xishu;
        cin >> zhi >> xishu;
        for (int j = 0; j < 2005; j++) {
            if (tmp[j] != 0) {
                xi[zhi + j] += tmp[j] * xishu;
            }
        }
//        for(int j=0;j<2005;j++){
//            if(xi[j]!=0){
//                cout<<j<<" "<<xi[j]<<endl;
//            }
//        }
    }
    int num = 0;
    for (int i = 0; i < 2005; i++) {
        if (xi[i] != 0) num++;
    }
    cout << num;
    for (int i = 2004; i >= 0; i--) {
        if (xi[i] != 0) printf(" %d %.1lf", i, xi[i]);
    }

}