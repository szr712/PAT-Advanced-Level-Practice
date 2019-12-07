#include<bits/stdc++.h>

using namespace std;

int n;
double price,rate;
int start;
double maxn;
int t;

map<int,vector<int>> chain;

void dfs(int root,double p){
    if(p>maxn){
       t=1;
       maxn=p;
    }
    else if(p==maxn){
        t++;
    }
    for(int i=0;i<chain[root].size();i++){
        dfs(chain[root][i],p*(1+rate/100));
    }

}

int main()
{
    scanf("%d %lf %lf",&n,&price,&rate);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp!=-1){
            chain[tmp].push_back(i);
        }
        else{
            start=i;
        }
    }
    maxn=-1;
    t=0;
    dfs(start,price);
    //maxn*=(1+rate/100);
    printf("%.2f %d",maxn,t);
}

