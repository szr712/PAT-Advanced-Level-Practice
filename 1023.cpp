#include <bits/stdc++.h>

using namespace std;

char in[25];
vector<int> num;
vector<int> ori;
bool f[25]={0};
bool flag=1;

int main() {
    scanf("%s",in);
    int t;
    for(int i=0;i<strlen(in);i++){
        t=in[i]-'0';
        num.push_back(t);
        ori.push_back(t);
    }
    int tmp=0;
    for(int i=num.size()-1;i>=0;i--){
        num[i]=num[i]*2+tmp;
        tmp=num[i]/10;
        num[i]%=10;
    }
    if(tmp>0){
        num.insert(num.begin(),tmp);
    }
    for(int i=0;i<num.size()&&flag==1;i++){
        int j;
        for(j=0;j<ori.size();j++){
            if(num[i]==ori[j]&&f[j]==0){
                f[j]=1;
                break;
            }
        }
        if(j==ori.size()) {
            cout<<"No"<<endl;
            flag=0;
        }
    }
    if(flag==1){
        cout<<"Yes"<<endl;
    }
    for(int i=0;i<num.size();i++){
        cout<<num[i];
    }
    cout<<endl;
}
