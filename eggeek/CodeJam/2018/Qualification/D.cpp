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
const double eps = 1e-8;
const double PI = acos(-1.0);
double A;

double getV(double angle) {
  //double rad = angle * PI / 180.0;
  double rad = angle;
  return sin(rad) + cos(rad);
}

void solve_sml() {
  double a = A;
  double lb = 0.0, ub = PI / 4.0;
  //cerr << "init: " << getV(ub) << endl;
  for (int i=0; i<100; i++) {
    double mid = (lb + ub) / 2.0;
    if (getV(mid) > a + eps) {
      ub = mid;
    }
    else if (getV(mid) < a - eps) {
      lb = mid;
    }
    else {
      lb = mid;
      break;
    }
  }

  //cerr << "lb current A: " << getV(lb) << endl;
  //cerr << "lb para: " << lb / PI << endl;

  //cerr << "ub current A: " << getV(ub) << endl;
  //cerr << "ub para: " << ub / PI << endl;
  //cerr << "expect: " << getV(PI / 4.0) << endl;
  double ax, ay, az;
  double bx, by, bz;
  double cx, cy, cz;
  //double rad = lb * PI / 180.0;
  double rad = lb;
  ax = 0.5 * cos(rad), ay = 0, az = 0.5 * sin(rad);
  bx = 0, by = 0.5, bz = 0;
  cx = -0.5 * sin(rad), cy = 0, cz = 0.5 * cos(rad);
  //cerr << "rad: " << rad / PI << " pi" << endl;
  printf("%.6lf %.6lf %.6lf\n", ax, az, ay);
  printf("%.6lf %.6lf %.6lf\n", cx, cz, cy);
  printf("%.6lf %.6lf %.6lf\n", bx, bz, by);
}

void solve_big() {
  double a = A / getV(PI / 4.0);
  double lb = 0.0, ub = PI / 4.0;
  for (int i=0; i<100; i++) {
    double mid = (lb + ub) / 2.0;
    if (getV(mid) > a + eps) {
      ub = mid;
    }
    else if (getV(mid) < a - eps) {
      lb = mid;
    }
    else {
      lb = mid;
      break;
    }
  }
  double ax, ay, az;
  double bx, by, bz;
  double cx, cy, cz;
  double r = lb;
  double t = PI / 4.0;
  double d = 0.5;
  ax = d * cos(t), ay = 0, az = d * sin(t);
  bx = 0, by = cos(r) * d, bz = sin(r) * d;
  cx = -sin(t) * d, cy = -sin(r) * cos(t) * d, cz = cos(r) * cos(t) * d;
  //cerr << "current: " << getV(r) << "*" << getV(t) << "=" << getV(r) * getV(t) << endl;
  printf("%.6lf %.6lf %.6lf\n", ax, az, ay);
  printf("%.6lf %.6lf %.6lf\n", cx, cz, cy);
  printf("%.6lf %.6lf %.6lf\n", bx, bz, by);
}

void do_case() {
   cin >> A;
   if (A <= getV(PI / 4.0)) {
    solve_sml();
   }
   else {
     solve_big();
   }
}

int main() {
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    cout << "Case #" << i << ":" <<endl;
    do_case();
  }
  return 0;
}
