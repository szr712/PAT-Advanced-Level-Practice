#include <bits/stdc++.h>

using namespace std;
int M;

int judge(int time1[], int time2[]) {
    if (time1[0] > time2[0]) return 1;
    else if (time1[0] < time2[0]) return -1;
    else {
        if (time1[1] > time2[1]) return 1;
        else if (time1[1] < time2[1]) return -1;
        else {
            if (time1[2] > time2[2]) return 1;
            else if (time1[2] < time2[2]) return -1;
            else return 0;
        }
    }
}

int main() {
    cin >> M;
    char tmpid[20], tmpin[20], tmpout[20];
    char idin[20], idout[20];
    int outtime[3] = {00, 00, 00};
    int intime[3] = {23, 59, 59};
    while (M--) {
        int in[3], out[3];
        scanf("%s %d:%d:%d %d:%d:%d",tmpid,&in[0],&in[1],&in[2],&out[0],&out[1],&out[2]);
        if (judge(in, intime) == -1) {
            for (int i = 0; i < 3; i++) {
                intime[i] = in[i];
            }
            strcpy(idin, tmpid);
        }
        if (judge(out, outtime) == 1) {
            for (int i = 0; i < 3; i++) {
                outtime[i] = out[i];
            }
            strcpy(idout, tmpid);
        }
    }
    cout<<idin<<" "<<idout<<endl;
}