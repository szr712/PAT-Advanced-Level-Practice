//最后还是有三个测试点未过，可以考虑使用二分查找解决超时的问题，但还有两个点答案错误不知道什么问题，可以可以考虑ra2de改成longlong
#include <bits/stdc++.h>

using namespace std;

char change[40];
char N1[15],N2[15];
int tag,ra;
int n1[15],n2[15];

void char2int(char a[],int b[]){
    for(int i=strlen(a)-1;i>=0;i--){
        for(int j=0;j<=35;j++){
            if(a[i]==change[j]){
                b[strlen(a)-i-1]=j;
            }
        }
    }
}

int ra2de(int ra,int a[]){
    int ans=0;
    for(int i=0;i<15;i++){
        if(a[i]==0) continue;
        ans+=a[i]*pow(ra,i);
    }
    return ans;
}

int main() {
   for(int i=0;i<10;i++){
        change[i]=i+'0';
   }
   for(int i=10;i<=35;i++){
       change[i]=i-10+'a';
   }
   scanf("%s %s %d %d",N1,N2,&tag,&ra);
   char2int(N1,n1);char2int(N2,n2);
   if(tag==1){
       int m=ra2de(ra,n1);
       for(int i=2;i<=m;i++){
           int tmp=ra2de(i,n2);
           if(tmp==m) {
               cout<<i;
               return 0;
           }
       }
       cout<<"Impossible"<<endl;
   }
    if(tag==2){
        int m=ra2de(ra,n2);
        for(int i=2;i<=m;i++){
            int tmp=ra2de(i,n1);
            if(tmp==m) {
                cout<<i;
                return 0;
            }
        }
        cout<<"Impossible"<<endl;
    }
}