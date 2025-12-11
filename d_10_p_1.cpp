#include <bits/stdc++.h>

using namespace std;

const long long LL_INF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int diags[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}

int dfs(int currVal, int tar, int idx, int n, int used, const vector<vector<int>>& switches) {
  if (idx >= n) return INF;

  vector<int> currSw = switches[idx];
  int useVal = currVal;
  for (int swval : switches[idx]) {
    useVal ^= (1 << swval);
  }

  if (useVal == tar) return used + 1;

  return min(dfs(useVal, tar, idx + 1, n, used + 1, switches),
             dfs(currVal, tar, idx + 1, n, used, switches));
}

int main() {
  fastIO();

  string s;
  long long ans = 0;
  while (getline(cin, s)) {
    int target = 0;
    int len = 0;
    vector<vector<int>> switches;
    istringstream ss(s);
    string sss;
    while (getline(ss, sss, ' ')) {
      if (sss[0] == '[') {
        sss = sss.substr(1, sss.length() - 2);
        len = sss.length();
        for (int i = 0; i < len; ++i) {
          if (sss[i] == '#') {
            target |= (1 << (len - 1 - i));
          }
        }
      } else if (sss[0] == '(') {
        vector<int> a;
        string ssss;
        istringstream ssstr(sss.substr(1, sss.length() - 2));
        while (getline(ssstr, ssss, ',')) {
          assert(len > 0);
          a.push_back(len - 1 - stoi(ssss));
        }
        switches.push_back(a);
      } else if (sss[0] == '{') {
      }
    }
    ans += dfs(0, target, 0, switches.size(), 0, switches);
  }

  cout << ans << endl;

  return 0;
}
