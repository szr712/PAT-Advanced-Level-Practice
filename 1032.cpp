#include <bits/stdc++.h>

using namespace std;
int h1, h2;
int n;
vector<int> l1, l2;
int ne[100005];
bool used[100005];

int main() {
    scanf("%d %d %d", &h1, &h2, &n);
    memset(ne, -1, sizeof(ne));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        int tmp, next;
        char x;
        scanf("%d %c %d", &tmp, &x, &next);
        ne[tmp] = next;
    }
    int head = h1;
    while (head != -1) {
        l1.push_back(head);
        used[head] = 1;
        head = ne[head];
    }
    head = h2;
    while (head != -1) {
        if (used[head] == 1) {
            printf("%05d", head);
            return 0;
        }
        used[head] = 1;
        head = ne[head];
    }
//    for(int i=0;i<l1.size();i++){
//        for(int j=0;j<l2.size();j++){
//            if(l1[i]==l2[j]){
//                printf("%05d",l1[i]);
//                return 0;
//            }
//        }
//    }
    printf("-1");
}

