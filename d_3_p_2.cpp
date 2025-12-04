#include <bits/stdc++.h>

using namespace std;

const long long LL_INF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}

long long newVal(int n, vector<bool>& included, const string& s, int newDidx) {
  long long newMaxVal = 0;
  int bestExcludeIdx = -1;

  for (int toExcludeIdx = 0; toExcludeIdx < n; ++toExcludeIdx) {
    if (!included[toExcludeIdx]) continue;
    included[toExcludeIdx] = false;

    long long valueExcluding = 0;

    long long mul = pow(10, 11);
    for (int j = 0; j < n; ++j) {
      if (included[j]) {
        valueExcluding += (s[j] - '0') * mul;
        mul /= 10;
      }
    }
    valueExcluding += s[newDidx] - '0';

    if (valueExcluding > newMaxVal) {
      newMaxVal = valueExcluding;
      bestExcludeIdx = toExcludeIdx;
    }

    included[toExcludeIdx] = true;
  }

  if (bestExcludeIdx == -1) return -LL_INF;

  included[bestExcludeIdx] = false;
  included[newDidx] = true;
  return newMaxVal;
}

int main() {
  fastIO();

  string s;
  long long ans = 0;
  while (cin >> s) {
    int n = s.length();
    vector<bool> included(n, false);

    long long currMaxVal = 0;
    for (int i = 0; i < 12; ++i) {
      included[i] = true;
      currMaxVal += (s[i] - '0') * pow(10, 12 - i - 1);
    }

    for (int i = 12; i < n; ++i) {
      currMaxVal = max(currMaxVal, newVal(n, included, s, i));
    }

    ans += currMaxVal;
  }

  cout << ans << endl;

  return 0;
}
