#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define INF 1e9
#define INF_LL 4e18
#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
int n, m;
vi a, l, r;

int main() {
  cin >> n;
  a.resize(n);
  for (int i=0; i<n; i++) cin >> a[i];
  cin >> m;
  l.resize(m);
  r.resize(m);
  for (int i=0; i<m; i++) {
    cin >> l[i] >> r[i];
  }

  int tot = 0;
  for (int i: a) tot += i;
  int res = -1;
  for (int i=0; i<m; i++) {
    if (l[i] <= tot && tot <= r[i]) {
      res = tot;
      break;
    }
    if (l[i] >= tot) {
      res = l[i];
      break;
    }
  }
  cout << res << endl;
  return 0;
}
