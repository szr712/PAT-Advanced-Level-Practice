// 如果是插入排序的话，那前面一部分肯定是按照顺序的，然后后面是按照插入顺序
// 于是我一开始想到，可以从后向前遍历，找到第一个不符合插入顺序的位置
// 但是这样遍历会有一个问题，插入的每个值可能本身就在符合规则的位置上，从后向前遍历可能或弄错上升序列的长度
// 后来发现每个序列的长度最长就100
// 那很简单
// 就暴力模拟就行了
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<stdio.h>
using namespace std;

int n;
vector<int> seq;
vector<int> ans;
vector<int> ins;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        seq.push_back(tmp);
        ins.push_back(tmp);
    }
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        ans.push_back(tmp);
    }
    int g=2;
    for(;g<n;g++){
        sort(ins.begin(),ins.begin()+g);
        int i=0;
        for(i=0;i<n;i++){
            if(ins[i]!=ans[i]){
                break;
            }
        }
        if(i>=n){
            printf("Insertion Sort\n");
            g++;
            sort(ins.begin(),ins.begin()+g);
            printf("%d",ins[0]);
            for(int i=1;i<n;i++){
                printf(" %d",ins[i]);
            }
            return 0;
        }
    }
    printf("Merge Sort\n");
    for(int group=2;group<=n;group*=2){
        for(int i=0;i<n;){
            if(i+group>=n){
                sort(seq.begin()+i,seq.end());
            }
            else{
                sort(seq.begin()+i,seq.begin()+i+group);
            }
            i+=group;
        }
        int j;
        for(j=0;j<n;j++){
            if(ans[j]!=seq[j]){
                break;
            }
        }
        if(j<n){
            continue;
        }
        group*=2;
        for(int i=0;i<n;){
            if(i+group>=n){
                sort(seq.begin()+i,seq.end());
            }
            else{
                sort(seq.begin()+i,seq.begin()+i+group);
            }
            i+=group;
        }
        printf("%d",seq[0]);
        for(int x=1;x<n;x++){
            printf(" %d",seq[x]);
        }
        return 0;
    }

}

