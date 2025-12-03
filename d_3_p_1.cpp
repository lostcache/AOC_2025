#include <bits/stdc++.h>

using namespace std;

const long long LL_INF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}

int main() {
  fastIO();

  string s;
  long long ans = 0;
  while (cin >> s) {
    int len = s.size();
    int curr_max = 0;
    for (int i = 0; i < len; ++i) {
      int di = s[i] - '0';
      for (int j = i + 1; j < len; ++j) {
        int dj = s[j] - '0';
        curr_max = max(curr_max, di * 10 + dj);
      }
    }
    ans += curr_max;
  }
  cout << ans << endl;
  return 0;
}
