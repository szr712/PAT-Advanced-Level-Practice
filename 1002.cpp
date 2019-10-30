#include<bits/stdc++.h> 
using namespace std;


int main(){
	int a,b;
	int max=1010;
	double ans[1010];
	int flag[1010];
	scanf("%d",&a);
	int num=0;
	memset(flag,0,sizeof(flag));
	memset(ans,0,sizeof(ans));
	for(int i=0;i<a;i++){
		int zhi;
		double xi;
		scanf("%d %lf",&zhi,&xi);
		
		if(flag[zhi]==0){
			num++;flag[zhi]=1;
		}
		ans[zhi]+=xi;
		
		
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		int zhi;
		double xi;
		scanf("%d %lf",&zhi,&xi);
		if(flag[zhi]==0){
			num++;flag[zhi]=1;
		}
		ans[zhi]+=xi;
		if(ans[zhi]==0){
			num--;	
		}
	}
	printf("%d",num);
	for(int i=max-1;i>=0;i--){
		if(ans[i]!=0){
			printf(" %d %.1lf",i,ans[i]);
		}
	}	
}
