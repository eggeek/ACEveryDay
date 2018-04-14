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
#define N 1010
int A;
bool g[N][N];

void do_case() {
  cin >> A;
  int curx = 2, cury = 2;
  int i, j;
  memset(g, 0, sizeof(g));
  while (true) {
    //cout << curx << endl;
    //cout << cury << endl;
    cout << curx << " " << cury << endl;
    //cerr << "print: " << curx << " " << cury << endl;
    cin >> i >> j;
    //cerr << "get: " << i << " " << j << endl;
    if (i == 0 && j == 0)
      break;
    else if (i == -1 && j == -1) {
      assert(false);
      //cerr << "i=-1, j=-1" << endl;
      break;
    }
    else {
      g[i][j] = 1;
    }
    if (g[curx-1][cury-1] && g[curx-1][cury] && g[curx-1][cury+1]) {
      curx += 1;
    }
  }
}

int main() {
  int num_test_cases;
  std::cin >> num_test_cases;
  for (int i = 0; i < num_test_cases; ++i)
    do_case();
  return 0;
}
