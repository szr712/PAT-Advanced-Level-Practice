//使用了一个比较巧妙的方法，因为分数是0到100的  所以以此为下标，省去排序的时间了，只要拍一下字符串就行了
#include <bits/stdc++.h>

using namespace std;

struct person{
    string num;
    int score;
    int local;
    int lrank;
};
vector<person> total[105];
int n;

bool cmp(person a,person b){
    return a.num<b.num;
}

int main() {
    scanf("%d",&n);
    int location=0;
    int all=0;
    while(n--){
        vector<person> tmp[105];
        int k;
        scanf("%d",&k);
        all+=k;
        location++;
        while(k--){
            person p;
            cin>>p.num;
            scanf("%d",&p.score);
            p.local=location;
            tmp[p.score].push_back(p);
        }
        int lrank=0;
        int t=1;
        for(int i=100;i>=0;i--){
            lrank=t;
            for(int j=0;j<tmp[i].size();j++){
                t++;
                tmp[i][j].lrank=lrank;
                total[i].push_back(tmp[i][j]);
            }
        }
    }
    printf("%d\n",all);
    int lr=0;
    int t=1;

    for(int i=100;i>=0;i--){
        lr = t;
        sort(total[i].begin(),total[i].end(),cmp);
        for(int j=0;j<total[i].size();j++){
            t++;
            cout<<total[i][j].num;
            printf(" %d %d %d\n",lr,total[i][j].local,total[i][j].lrank);
        }
    }
}
