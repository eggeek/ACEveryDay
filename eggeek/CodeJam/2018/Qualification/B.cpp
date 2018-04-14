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
int n;
vi v;

void troubleSort(vi& nums) {
  bool done = false;
  while (!done) {
    done = true;
    for (int i=0; i<n-2; i++) {
      if (nums[i] > nums[i+2]) {
        swap(nums[i], nums[i+2]);
        done = false;
      }
    }
  }
}

int findWrong(const vi& nums) {
  for (int i=0; i<n-1; i++) {
    if (nums[i] > nums[i+1]) return i;
  }
  return -1;
}

void solve(vi& nums) {
  vi odd, even;
  for (int i=0; i<n; i+=2) {
    even.push_back(nums[i]);
  }
  for (int i=1; i<n; i+=2) {
    odd.push_back(nums[i]);
  }
  sort(ALL(odd));
  sort(ALL(even));
  for (int i=0; i<(int)even.size(); i++) {
    nums[i*2] = even[i];
  }
  for (int i=0; i<(int)odd.size(); i++) {
    nums[i*2+1] = odd[i];
  }
}

void print_arr(vi& nums) {
  for (int i=0; i<(int)nums.size(); i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

void do_case() {
  cin >> n;
  v.resize(n);
  for (int i=0; i<n; i++) cin >> v[i];
  //vi nums1(v.begin(), v.end());
  vi nums2(v.begin(), v.end());
  //troubleSort(nums1);
  solve(nums2);

  int idx = findWrong(nums2);
  //printf("nums1: %d, nums2: %d\n", findWrong(nums1), findWrong(nums2));
  //print_arr(nums1);
  //print_arr(nums2);
  //assert(findWrong(nums1) == idx);
  if (idx == -1) cout << "OK" << endl;
  else cout << idx << endl;
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
