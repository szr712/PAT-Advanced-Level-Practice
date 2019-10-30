#include <bits/stdc++.h>

using namespace std;

int main() {
    int floor, N;
    int stay = 0;
    cin >> N;
    int time = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &floor);
        if (floor > stay) {
            time += (floor - stay) * 6 + 5;
        } else if (floor <= stay) {
            time += (stay - floor) * 4 + 5;
        }
        stay = floor;
    }
    cout << time << endl;
}