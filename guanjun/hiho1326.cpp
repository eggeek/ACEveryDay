/* ***********************************************
Author        :guanjun
Created Time  :2016/7/2 23:20:23
File Name     :hiho1326.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	char s[maxn];
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int Min=INF;
		for(int i=0;i<=n+1;i++){
			int ans=0;
			for(int j=1;j<=i;j++){
				if(s[j]!='0')ans++;
			}
			for(int j=i+1;j<=n;j++){
				if(s[j]!='1')ans++;
			}
			Min=min(ans,Min);
		}
		cout<<Min<<endl;
	}
    return 0;
}
