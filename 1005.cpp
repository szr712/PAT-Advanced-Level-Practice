#include <bits/stdc++.h>

using namespace std;

string trans[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    char num[105];
    cin>>num;
    int sum=0;
    for(int i=0;i<strlen(num);i++){
        int tmp=num[i]-'0';
        sum+=tmp;
    }
    vector <int> ans;
    for(int i=0;;i++){
        if(sum<10) {
            ans.push_back(sum);
            break;
        }
        int tmp=sum%10;
        sum/=10;
        ans.push_back(tmp);
    }
    cout<<trans[ans[ans.size()-1]];
    for(int i=ans.size()-2;i>=0;i--){
        cout<<" "<<trans[ans[i]];
    }
    cout<<endl;
}