#include <bits/stdc++.h>
#include <cmath>
#include <unordered_set>

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

    for (int len = lowerLen; len <= upperLen; ++len) {
      long long currSum = 0;
      set<long long> seen;

      for (int sublen = 1; sublen < len; sublen++) {
        if (len % sublen == 0) {
          int nsubs = len / sublen;
          for (int val = pow(10, sublen - 1); val < pow(10, sublen); ++val) {
            long long currVal = 0;
            long long mul = 1;
            for (int i = 0; i < nsubs; ++i) {
              currVal += val * mul;
              mul *= pow(10, sublen);
            }
            if (currVal < lower) continue;
            if (currVal > upper) break;
            if (seen.find(currVal) != seen.end()) continue;
            currSum += currVal;
            seen.insert(currVal);
          }
        }
      }
      ans += currSum;
    }
  }

  cout << ans << endl;

  return 0;
}
