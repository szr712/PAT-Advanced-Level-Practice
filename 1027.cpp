#include <bits/stdc++.h>

using namespace std;

int red,green,blue;
char tmp[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void ten2ra(int a){
    char x,y;
    x=tmp[a%13];
    a/=13;
    y=tmp[a%13];
    cout<<y<<x;
}

int main() {
    scanf("%d %d %d",&red,&green,&blue);
    cout<<"#";
    ten2ra(red);
    ten2ra(green);
    ten2ra(blue);
}
