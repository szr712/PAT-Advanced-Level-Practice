//这是一道逻辑题，题目十分复杂，有很多地方需要仔细思考
/*
 * 如果到达的时候需要排队，那一旦空出来VIP桌子，排队中的VIP用户直接使用
 * 如果到达的时候不需要排队，并且有多个桌子空出来，那VIP用户直接使用下标较小的VIP桌，若普通用户则使用下标较小的普通桌
 * 如果一个用户使用时间超过两小时，那就按照两个小时计算
 * 最后按照被服务的时间顺序输出
 */
#include <bits/stdc++.h>

using namespace std;

struct person {
    int arrive, use, start;
    bool served, vip;
};

struct table {
    int endtime, cnt;
    bool vip;
};

bool cmp1(person a, person b) {
    return a.arrive < b.arrive;
}

bool cmp2(person a, person b) {
    return a.start < b.start;
}

vector<person> r;
vector<table> t;
int n, m, k;

int time2int(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        person tmp;
        int h, m, s, u;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &u, &tmp.vip);
        tmp.arrive = time2int(h, m, s);
        tmp.use = u * 60;
        if(u>120) tmp.use=7200;
        tmp.start = 0;
        tmp.served = 0;
        r.push_back(tmp);
    }
    sort(r.begin(), r.end(), cmp1);
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++) {
        table tmp;
        tmp.vip = 0;
        tmp.cnt = 0;
        tmp.endtime = 28800;
        t.push_back(tmp);
    }
    for (int i = 0; i < k; i++) {
        int id;
        scanf("%d", &id);
        t[id - 1].vip = 1;
    }
    for (int i = 0; i < r.size();) {
        int minend = INT_MAX, minindex;
        //先找到最快空闲的下标最小的桌子
        for (int j = 0; j < t.size(); j++) {
            if (minend > t[j].endtime) {
                minend = t[j].endtime;
                minindex = j;
            }
        }
        if (minend >= 75600 || r[i].arrive >= 75600) {
            break;
        }
        int pid = i, tid = minindex;
        if (minend >= r[i].arrive) {
            if (t[tid].vip) {
                for (int x = pid; x < r.size() && r[x].arrive <= minend; x++) {
                    if (!r[x].served && r[x].vip) {
                        pid = x;
                        break;
                    }
                }
            } else if (r[pid].vip) {
                for (int j = 0; j < m; j++) {
                    if (t[j].vip && t[j].endtime <= r[pid].arrive) {
                        tid = j;
                        break;
                    }
                }
            }
        } else {
            if (r[pid].vip) {
                for (int j = 0; j < m; j++) {
                    if (t[j].vip && t[j].endtime <= r[pid].arrive) {
                        tid = j;
                        break;
                    }
                }
            }
        }
        r[pid].start = max(r[pid].arrive, t[tid].endtime);
        r[pid].served = 1;
        t[tid].endtime = r[pid].start + r[pid].use;
        t[tid].cnt++;
        while (i < r.size() && r[i].served) ++i;
    }
    sort(r.begin(),r.end(),cmp2);
    for(int i=0;i<r.size();i++){
        if(r[i].served){
            int wait=r[i].start-r[i].arrive;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",r[i].arrive/3600,r[i].arrive%3600/60,r[i].arrive%60,r[i].start/3600,r[i].start%3600/60,r[i].start%60,(int)(1.0*wait/60+0.5));
        }
    }
    printf("%d",t[0].cnt);
    for(int i=1;i<m;i++){
        printf(" %d",t[i].cnt);
    }
}
