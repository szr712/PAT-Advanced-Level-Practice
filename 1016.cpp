//此题很长，逻辑很多，总体上写的还算简洁，主要的难点在于没有消费的用户是不能输出的，因此需要增加一个f来判定，一直卡在测试点1，因为最后一句话没有f特判，改正后就OK了
#include <bits/stdc++.h>

using namespace std;

struct record {
    string name;
    int mo, dd, hh, mm;
    bool flag;
    int time;
};

double rate[25] = {0};
int n;
vector<record> rs;

int getime(int d, int h, int m) {
    int ans = 0;
    ans += (d - 1) * 24 * 60;
    ans += h * 60;
    ans += m;
    return ans;
}

bool cmp(record a, record b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}


double money(record a, record b) {
    double ans = 0;
    if (a.hh == b.hh && a.dd == b.dd) {
        ans = (b.mm - a.mm) * rate[a.hh];
        return ans;
    } else if (a.dd == b.dd) {
        ans += (60 - a.mm) * rate[a.hh] + b.mm * rate[b.hh];
        for (int i = a.hh + 1; i <= b.hh - 1; i++) {
            ans += rate[i] * 60;
        }
        return ans;
    } else {
        ans += (b.dd - a.dd - 1) * rate[24];
        ans += (60 - a.mm) * rate[a.hh] + b.mm * rate[b.hh];
        for (int i = a.hh + 1; i <= 23; i++) {
            ans += rate[i] * 60;
        }
        for (int i = 0; i <= b.hh - 1; i++) {
            ans += rate[i] * 60;
        }
        return ans;
    }

}

int main() {
    double day = 0;
    for (int i = 0; i < 24; i++) {
        int tmp;
        scanf("%d", &tmp);
        rate[i] = tmp / 100.0;
        day += rate[i] * 60;
    }
    rate[24] = day;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        record tmp;
        char line[20];
        cin >> tmp.name;
        scanf("%d:%d:%d:%d %s", &tmp.mo, &tmp.dd, &tmp.hh, &tmp.mm, line);
        if (strcmp(line, "on-line") == 0) tmp.flag = 1;
        else tmp.flag = 0;
        tmp.time = getime(tmp.dd, tmp.hh, tmp.mm);
        rs.push_back(tmp);
    }
    sort(rs.begin(), rs.end(), cmp);
    string tname = rs[0].name;
    double total = 0;
    bool f = 0;
    for (int i = 0; i < rs.size(); i++) {
        record r1;
        r1 = rs[i];
        if (r1.name != tname) {
            if (f == 1) printf("Total amount: $%.2lf\n", total);
            f = 0;
            total = 0;
            tname = r1.name;
        }
        if (r1.flag == 1) {
            for (int j = i + 1; j < rs.size(); j++) {
                if (rs[j].name != tname) {
                    break;
                }
                if (rs[j].flag == 0) {
                    double mon = money(r1, rs[j]);
                    if (f == 0 && mon > 0) {
                        f = 1;
                        cout << r1.name << " ";
                        printf("%02d\n", r1.mo);
                    }
                    total += mon;
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", r1.dd, r1.hh, r1.mm, rs[j].dd, rs[j].hh,
                           rs[j].mm, rs[j].time - r1.time, mon);
                    i = j;
                    break;
                }
                if (rs[j].flag == 1) {
                    break;
                }
            }
        }

    }
    if (f == 1)printf("Total amount: $%.2lf\n", total);

}
