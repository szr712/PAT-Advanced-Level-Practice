//参考自https://blog.csdn.net/CV_Jason/article/details/84893138
#include <bits/stdc++.h>

using namespace std;
struct station {
    double pri;
    double dis;
};
double c, d, avg;
int n;
vector<station> route;

bool cmp(station a, station b) {
    return a.dis < b.dis;
}


int main() {
    scanf("%lf %lf %lf %d", &c, &d, &avg, &n);
    for (int i = 0; i < n; i++) {
        station tmp;
        scanf("%lf %lf", &tmp.pri, &tmp.dis);
        route.push_back(tmp);
    }
    sort(route.begin(), route.end(), cmp);
    if(route[0].dis!=0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    double gas = 0, total = 0, maxd = c * avg;
    int cur = 0;
    while (1) {
        bool tag = 0, cheaper = 0;
        double tmpcheap = 1000000;
        int cheapnum;
        for (int i = cur + 1; i < route.size(); i++) {
            if (route[i].dis - route[cur].dis <= maxd) {
                tag = 1;
                if (route[i].pri < route[cur].pri) {
                    cheaper = 1;
                    double dist = route[i].dis - route[cur].dis;
                    double agas = dist / avg - gas;
                    gas = 0;
                    total += agas * route[cur].pri;
                    cur = i;
                    break;
                }
                if (route[i].pri < tmpcheap) {
                    tmpcheap = route[i].pri;
                    cheapnum = i;
                }
            } else break;
        }
        if(!cheaper&&maxd>=(d-route[cur].dis)){
            double dist = d - route[cur].dis;
            double agas = dist / avg - gas;
            total += agas * route[cur].pri;
            printf("%.2lf\n",total);
            return 0;
        }
        if(tag&&!cheaper){
            double agas = c - gas;
            total+=agas * route[cur].pri;
            double dist=route[cheapnum].dis-route[cur].dis;
            gas=c-dist/avg;
            cur=cheapnum;
        }
        else if(!tag){
            printf("The maximum travel distance = %.2lf\n",route[cur].dis+maxd);
            return  0;
        }

    }
}

