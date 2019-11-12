//坑有点多啊，首先输入地图的时候起点和重点因为有G所以要用字符串输入才行，一开始用字符串长度来判断输入数是不是带G，后来发现正常起点可以有好几位的，就不能这样判断了
//atoi()和stoi()可以将字符串转成整数
//atoi()的参数是 const char* ,因此对于一个字符串str我们必须调用 c_str()的方法把这个string转换成 const char*类型的,而stoi()的参数是const string*,不需要转化为 const char*；
// stoi()会做范围检查，默认范围是在int的范围内的，如果超出范围的话则会runtime error！
// 而atoi()不会做范围检查，如果超出范围的话，超出上界，则输出上界，超出下界，则输出下界；
// 例子：
// string s1 = "2147482", s2 = "-214748";
// 	string s3 = "214748666666663", s4 = "-21474836488";
// 	cout << stoi(s1) << endl;
// 	cout << stoi(s2) << endl;
// 	cout << atoi(s3.c_str()) << endl;
// 	cout << atoi(s4.c_str()) << endl;
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
const int maxn = 0x3fffffff;

int n, m, k, range;
int maps[1100][1100];
int dis[1100];
bool used[1100];
struct best
{
	double mind;
	double avg;
	int index;
};

void dijkstra(int s) {
	fill(dis, dis + 1100, maxn);
	memset(used, 0, sizeof(used));
	dis[s] = 0;
	while (1) {
		int v = -1, min = maxn;
		for (int u = 1; u <= n+m; u++) {
			if (!used[u] && min > dis[u]) {
				v = u;
				min = dis[u];
			}
		}
		if (v == -1)break;
		used[v] = 1;
		for (int i = 1; i <= n+m; i++) {
			if (!used[i] && (dis[v] + maps[v][i] < dis[i])) {
				dis[i] = dis[v] + maps[v][i];
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &range);
	fill(maps[0], maps[0] + 1100 * 1100, maxn);
	for (int i = 0; i < k; i++) {
		char a[10], b[10];
		int d;
		scanf("%s %s %d", a, b, &d);
		int p1=0, p2=0;
		if (a[0] != 'G') {
			p1 = atoi(a);
		}
		else {
			p1 = atoi(a+1) + n;

		}
		if (b[0] != 'G') {
			p2 = atoi(b);
		}
		else
		{
			p2 = atoi(b + 1) + n;
		}
		maps[p1][p2] = d;
		maps[p2][p1] = d;
	}
	best tmp;
	tmp.avg = maxn;
	tmp.mind = -1;
	tmp.index = m + n + 1;
	for (int i = 1; i <= m; i++) {
		dijkstra(i + n);
		bool flag = 0;
		double min = maxn;
		double ans = 0.0;
		for (int j = 1; j <= n; j++) {
			if (dis[j] > range) {
				flag = 1;
				break;
			}
			if (min > dis[j]) min = dis[j];
			ans += dis[j];
		}
		if (!flag) {
			ans /= n;
			if (min > tmp.mind) {
				tmp.mind = min;
				tmp.avg = ans;
				tmp.index = i;
			}
			else if (min == tmp.mind) {
				if (ans < tmp.avg) {
					tmp.avg = ans;
					tmp.index = i;
				}
			}
		}
	}
	if (tmp.avg==maxn) {
		printf("No Solution\n");
	}
	else {

		printf("G%d\n", tmp.index);
		printf("%.1lf %.1lf", tmp.mind,tmp.avg);
	}
	system("PAUSE");
}