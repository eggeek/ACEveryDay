/*
By Snickeen
*/
#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define MST(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VL vector<LL>
#define VII vector<PII >
#define VLL vector<PLL >
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define FF first
#define SS second

template<typename T>inline void gn(T &x){
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
template<typename T>inline void gt(T x){
	if(!x)return;
	gt(x/10);putchar(x%10+'0');
}
 
const LL MAXN=2e5+10;
LL t,n,m,ans;
LL MOD=1e9+7,inf=0x1f1f1f1f;
db eps=1e-5;

LL f[MAXN][4];
map<PLL,PLL> ma; 
PLL x,y;

int main()
{
//	ios_base::sync_with_stdio(false);cin.tie(0);
	LL i,j,k,l,r=0,ca=0,u=0,w=0;
	cin>>n;
	repu(i,1,n){
		repu(j,1,3)cin>>f[i][j];
		sort(f[i]+1,f[i]+4);
		/*if(f[i][1]==f[i][3]){
			if(r<f[i][1]){
				r=f[i][1];
				ca=i;
			}
			continue;
		}
		*/
		y=ma[{f[i][3],f[i][2]}];
		//if(y.FF){
			k=min(f[i][1]+y.FF,f[i][2]);
			if(k>ans){
				ans=k;
				u=y.SS;
				w=i;
			}
		//}
		y=ma[{f[i][3],f[i][2]}];
		if(y.FF<f[i][1])ma[{f[i][3],f[i][2]}]={f[i][1],i};
	}
	if(!u){
		cout<<"1\n"<<w<<endl;
		return 0;
	}
	cout<<"2\n";
	cout<<u<<" "<<w;
	return 0;
}
