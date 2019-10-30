//主要考察了输入输出，一开始用cout会有一个点超时
#include <bits/stdc++.h>

using namespace std;

struct stu {
    char id[7];
    char name[10];
    int grade;
};
int n, c;
vector<stu> record;

bool cmp1(stu a, stu b) {
    if (strcmp(a.id, b.id) < 0) return 1;
    else return 0;
}

bool cmp2(stu a, stu b) {
    int flag = strcmp(a.name, b.name);
    if (flag < 0) return 1;
    else if (flag == 0) {
        if (strcmp(a.id, b.id) < 0) return 1;
    }
    return 0;
}

bool cmp3(stu a, stu b) {
    if (a.grade < b.grade) return 1;
    else if (a.grade == b.grade) {
        if (strcmp(a.id, b.id) < 0) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        stu tmp;
        scanf("%s %s %d", tmp.id, tmp.name, &tmp.grade);
        record.push_back(tmp);
    }
    if (c == 1) sort(record.begin(), record.end(), cmp1);
    else if (c == 2) sort(record.begin(), record.end(), cmp2);
    else if (c == 3) sort(record.begin(), record.end(), cmp3);
    printf("%s %s %d", record[0].id, record[0].name, record[0].grade);
    for (int i = 1; i < n; i++) {
        printf("\n%s %s %d", record[i].id, record[i].name, record[i].grade);
    }

}
