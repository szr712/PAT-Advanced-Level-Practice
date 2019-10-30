//主要考察了map和set的用法，以及整行输入的用法，map对于映射的建立十分有用，需要多考虑使用
//还有整行输入的用法
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, set<int >> title, author, key, publish, year;
string ti, au, ke, pu, ye;
int id;

void search(map<string, set<int >> &ma, string &str) {
    if (ma.find(str) == ma.end()) printf("Not Found\n");
    else {
        set<int>::iterator it;
        for (it = ma[str].begin(); it != ma[str].end(); it++) {
            printf("%07d\n", *it);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &id);
        getline(cin, ti);
        title[ti].insert(id);
        getline(cin, au);
        author[au].insert(id);
        while (cin >> ke) {
            key[ke].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }
        getline(cin, pu);
        publish[pu].insert(id);
        getline(cin, ye);
        year[ye].insert(id);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int tmp;
        string str;
        scanf("%d: ", &tmp);
        getline(cin, str);
        printf("%d: ",tmp);
        cout<<str<<endl;
        if (tmp == 1) search(title, str);
        else if (tmp == 2) search(author, str);
        else if (tmp == 3) search(key, str);
        else if (tmp == 4) search(publish, str);
        else if (tmp == 5) search(year, str);
    }
}
