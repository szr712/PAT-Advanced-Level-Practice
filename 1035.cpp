#include <bits/stdc++.h>

using namespace std;
int n;
struct team {
    char name[15];
    char password[15];
};

vector<team> modify;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        team tmp;
        scanf("%s %s", tmp.name, tmp.password);
        bool flag=0;
        for (int j = 0; j < strlen(tmp.password); j++) {
            if(tmp.password[j]=='1'){
                flag=1;
                tmp.password[j]='@';
            }
            if(tmp.password[j]=='0'){
                flag=1;
                tmp.password[j]='%';
            }
            if(tmp.password[j]=='l'){
                flag=1;
                tmp.password[j]='L';
            }
            if(tmp.password[j]=='O'){
                flag=1;
                tmp.password[j]='o';
            }
        }
        if(flag==1){
            modify.push_back(tmp);
        }
    }
    if(modify.size()>0){
        printf("%d\n",modify.size());
        for(int i=0;i<modify.size();i++){
            printf("%s %s\n",modify[i].name,modify[i].password);
        }
    }else{
        if(n==1){
            printf("There is 1 account and no account is modified\n");
        }else{
            printf("There are %d accounts and no account is modified\n",n);
        }
    }

}