//与前面有一题基本类似，区别在于对于17:00不能办理的用户是一定要办完的，只是对于17:00后才来的用户不办理
#include <bits/stdc++.h>

using namespace std;
struct person {
    double min;
    int pt;
};

int n, k;
vector<person> people;
queue<person> line[105];

double time(int hh, int mm, int ss) {
    double min = hh * 60.0;
    min += mm;
    min += ss / 60.0;
    return min;
}

bool cmp(person a, person b) {
    return a.min < b.min;
}

int main() {
    scanf("%d %d", &n, &k);
    int hh, mm, ss;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        double min = time(hh, mm, ss);
        person p;
        p.min = min;
        scanf("%d", &p.pt);
        if (min <= 1020.0)people.push_back(p);
    }
    double ans = 0.0;
    sort(people.begin(), people.end(), cmp);
    for (int i = 0; i < people.size(); i++) {
        if (people[i].min >= 480) break;
        else {
            ans += (480 - people[i].min);
            people[i].min = 480.0;
        }
    }
    for (int i = 0; i < k && i < people.size(); i++) {
        line[i].push(people[i]);
    }
    if (k < people.size()) {
        for (int i = k; i < people.size(); i++) {
            double mini = 1440.0;
            int t = -1;
            for (int j = 0; j < k; j++) {
                double tmp = (line[j].front().min + line[j].front().pt) - people[i].min;
                if (mini > tmp) {
                    mini = tmp;
                    t = j;
                }
            }
            if (mini > 0) {
                ans += mini;
                people[i].min = line[t].front().min + line[t].front().pt;
            }
            line[t].pop();
            line[t].push(people[i]);
        }
    }
    ans = ans / people.size();
    printf("%.1lf", ans);
}
