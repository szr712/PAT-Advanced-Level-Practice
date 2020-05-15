//堆排和插入排序的判断，堆排需要熟知一下
//另外考虑清楚是否能取等的问题
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

int n;
vector<int> ori, cmp;

void adjust(int low,int high) {
	int tmp = cmp[low];
	int i = low * 2 + 1;
	while (i <= high) {
		if (i + 1 <= high && cmp[i] < cmp[i + 1]) {//找到较大的结点
			i++;
		}
		if (tmp > cmp[i])//不需要交换
			break;
		cmp[low] = cmp[i];
		low = i;
		i= low * 2 + 1;
	}
	cmp[low] = tmp;
}

int main() {
	scanf("%d", &n);
	int t = n;
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		ori.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		cmp.push_back(tmp);
	}
	int p = 0;
	while (p < n - 1 && cmp[p] <= cmp[p + 1]) {//可以是小于等于
		p++;
	}
	p++;
	int index = p;
	while (p < n&&ori[p] == cmp[p]) {
		p++;
	}
	if (p == n ) {
		printf("Insertion Sort\n");
		sort(cmp.begin(), cmp.begin() + index + 1);
	}
	else
	{
		printf("Heap Sort\n");
		p = n-1;
		//如果堆排序，那最后肯定比最大堆的堆顶大，找到比堆顶小的就是还未排序的部分
		while (p > 1 && cmp[p] >= cmp[0]) {
			p--;
		}
		swap(cmp[0], cmp[p]);
		adjust(0, p-1);
	}
	printf("%d", cmp[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", cmp[i]);
	}
	system("PAUSE");
	return 0;

}