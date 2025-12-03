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
  cin >> s;

  istringstream ss(s);

  string rangeStr;
  long long ans = 0;
  while (getline(ss, rangeStr, ',')) {
    istringstream rangeSS(rangeStr);
    string lowerStr, upperStr;
    getline(rangeSS, lowerStr, '-');
    getline(rangeSS, upperStr);

    long long upper = stoll(upperStr), lower = stoll(lowerStr);

    int lowerLen = lowerStr.length(), upperLen = upperStr.length();

    // cout << lower << ' ' << upper << endl;
    if (lowerLen == upperLen) {
      if (lowerLen & 1) continue;

      long long currVal = 0;
      long long half = stoll(lowerStr.substr(0, lowerLen / 2));
      for (long long val = half; val < pow(10, lowerLen / 2); ++val) {
        long long fullVal = val + (val * pow(10, lowerLen / 2));
        if (fullVal < lower) continue;
        if (fullVal > upper) break;
        currVal += fullVal;
      }
      // cout << currVal << endl;
      ans += currVal;
    } else {
      long long currVal = 0;
      /* for lower len */
      if ((lowerLen & 1) == 0) {
        long long half = stoll(lowerStr.substr(0, lowerLen / 2));
        for (long long val = half; val < pow(10, lowerLen / 2); val++) {
          long long fullVal = val + (val * pow(10, lowerLen / 2));
          if (fullVal < lower) continue;
          currVal += fullVal;
        }
      }

      for (int len = lowerLen + 1; len < upperLen; ++len) {
        if (len & 1) continue;
        for (long long val = pow(10, len / 2 - 1); val < pow(10, len / 2); ++val) {
          currVal += val + (val * pow(10, len / 2));
        }
      }

      if ((upperLen & 1) == 0) {
        for (long long val = pow(10, upperLen / 2 - 1); val < pow(10, upperLen / 2); ++val) {
          long long fullVal = val + (val * pow(10, upperLen / 2));
          if (fullVal > upper) break;
          currVal += fullVal;
        }
      }
      // cout << currVal << endl;
      ans += currVal;
    }
  }

  cout << ans << endl;

  return 0;
}
