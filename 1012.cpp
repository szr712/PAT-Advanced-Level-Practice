#include<bits/stdc++.h>

using namespace std;

int n, m;
struct student {
    char id[8];
    int c, m, e, a;
    int rc, rm, re, ra;
};
student stu[2005];

bool cmpc(student a, student b) {
    return a.c > b.c;
}

bool cmpm(student a, student b) {
    return a.m > b.m;
}

bool cmpe(student a, student b) {
    return a.e > b.e;
}

bool cmpa(student a, student b) {
    return a.a > b.a;
}

void display(student t) {
    int mini = min(t.rc, t.rm);
    mini = min(mini, t.re);
    mini = min(mini, t.ra);
    printf("%d", mini);
    if (mini == t.ra) {
        printf(" A\n");
    } else if (mini == t.rc) {
        printf(" C\n");
    } else if (mini == t.rm) {
        printf(" M\n");
    } else if (mini == t.re) {
        printf(" E\n");
    }
}

int main() {
    scanf("%d %d", &n, &m);
    string cid;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
        stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3;
    }
    sort(stu, stu + n, cmpc);
    int tmp = -1;
    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (tmp != stu[i].c) {
            rank = i + 1;
        }
        stu[i].rc = rank;
        tmp = stu[i].c;
    }
    sort(stu, stu + n, cmpm);
    tmp = -1;
    rank = 1;
    for (int i = 0; i < n; i++) {
        if (tmp != stu[i].m) {
            rank = i + 1;
        }
        stu[i].rm = rank;
        tmp = stu[i].m;
    }
//    for(int i=0;i<n;i++){
//        cout<<stu[i].id<<" "<<stu[i].rm<<endl;
//    }
    sort(stu, stu + n, cmpe);
    tmp = -1;
    rank = 1;
    for (int i = 0; i < n; i++) {
        if (tmp != stu[i].e) {
            rank = i + 1;
        }
        stu[i].re = rank;
        tmp = stu[i].e;
    }
    sort(stu, stu + n, cmpa);
    tmp = -1;
    rank = 1;
    for (int i = 0; i < n; i++) {
        if (tmp != stu[i].a) {
            rank = i + 1;
        }
        stu[i].ra = rank;
        tmp = stu[i].a;
    }
    char test[8];
    while (m--) {
        scanf("%s", test);
        int i=0;
        for (i = 0; i < n; i++) {
            if (strcmp(test, stu[i].id) == 0) {
                display(stu[i]);
                break;
            }
        }
        if(i>=n){
            printf("N/A\n");
        }
    }
    system("Pause");
}