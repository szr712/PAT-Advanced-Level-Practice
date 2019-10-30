//一开始使用vector来储存大数，但是一直不对，最后两个点过不了，所以还是应该用字符串比较稳，判断回文也方便
#include <bits/stdc++.h>

using namespace std;
int n,k;
string num,num2;

void add(){
    int t=0;
    for(int i=num.length()-1;i>=0;i--){
        int tmp=num[i]-'0'+num2[i]-'0';
        num[i]=(tmp+t)%10+'0';
        t=(tmp+t)/10;
    }
    if(t>0) num.insert(num.begin(),'1');
}

int main() {
    cin>>num>>k;
    num2=num;
    reverse(num2.begin(),num2.end());
    if(num2==num) {
        cout<<num<<endl<<0<<endl;
        return 0;
    }
    else{
        for(int i=0;i<k;i++){
            add();
            num2=num;
            reverse(num2.begin(),num2.end());
            if(num2==num){
                cout<<num<<endl<<i+1;
                return 0;
            }
        }
    }
    cout<<num<<endl<<k<<endl;

}
