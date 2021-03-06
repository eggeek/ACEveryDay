# SDUT 3258 Square Number

 给出$n,n\le1e6$个数$a_i\le1e6$，问其中有多少个数对满足这个数对的乘积是平方数

对于一个数$x = \prod\limits_{i=1}^np_i^{e_i}$

我们记$sim(x) = \prod\limits_{i=1}^np_i^{e_i mod\;2}$

那么其实一个数对$(x,y)$能满足他们的乘积是平方数当且仅当$sim(x) = sim(y)$

然后就可以用哈希了

代码如下

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
#define LL long long
int pri[maxn];

void sieve(){
    memset(pri,-1,sizeof(pri));
    pri[1] = 1;
    for(LL i=2;i<maxn;i++){
        if(pri[i] == -1){
            pri[i] = i;
            for(int j=i*2;j<maxn;j+=i){
                if(pri[j] == -1) pri[j] = i;
                else pri[j] *= i;
            }
            int cnt = 0;
            for(LL j=i*i;j<maxn;j*=i){
                cnt++;
                for(LL k=1;k*j<maxn;k++){
                    if(cnt%2) pri[k*j] /= i;
                    else pri[k*j] *= i;
                }
            }
        }
    }
}

int Hash[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int n;
    sieve();
    while(T-- && ~scanf("%d",&n)){
        int x;
        LL ans = 0;
        memset(Hash,0,sizeof(Hash));
        while(n--){
            scanf("%d",&x);
            x = pri[x];
            ans += Hash[x];
            Hash[x]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

```

