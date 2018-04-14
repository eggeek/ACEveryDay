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
map<string, int> h;
ll D;
string p;

struct Node {
  string str;
  int steps;
};
queue<Node> q;

ll getDamage(const string& str) {
  ll cur = 1;
  ll res = 0;
  for (char i: str) {
    if (i == 'S') res += cur;
    if (i == 'C') cur <<= 1;
  }
  return res;
}

int solve_sml() {
  h.clear();
  q.push({p, 0});
  int res = -1;
  while (!q.empty()) {
    Node c = q.front(); q.pop();
    if (getDamage(c.str) <= D) {
      res = c.steps;
      break;
    }
    for (int i=1; i<(int)c.str.size(); i++) {
      if (c.str[i] == 'S' && c.str[i-1] == 'C') {
        string news = string(c.str.begin(), c.str.end());
        swap(news[i], news[i-1]);
        if (h.count(news))
          continue;
        h[news] = c.steps + 1;
        q.push({news, c.steps + 1});
      }
    }
  }
  while (!q.empty()) q.pop();
  return res;
}

int solve_big() {
  string cur = string(p);
  int cnts = 0;
  for (char i: cur) if (i == 'S') cnts++;
  if (cnts > D) return -1;
  int res = 0;
  while (getDamage(cur) > D) {
    for (int i=(int)cur.size(); i>0; i--) {
      if (cur[i] == 'S' && cur[i-1] == 'C') {
        swap(cur[i], cur[i-1]);
        res++;
        break;
      }
    }
  }
  return res;
}

void do_case() {
  cin >> D >> p;
  int res = solve_big();
  if (res != -1) cout << res << endl;
  else cout << "IMPOSSIBLE" << endl;
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    cout << "Case #" << i << ": ";
    do_case();
  }
  return 0;
}
