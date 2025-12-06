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

int main() {
  fastIO();

  string inp;
  vector<pair<long long, long long>> r;
  while (cin >> inp) {
    istringstream ss(inp);

    if (inp == "X") break;

    string sStr, eStr;
    getline(ss, sStr, '-');
    getline(ss, eStr, '-');
    r.push_back({stoll(sStr), stoll(eStr)});
  }

  sort(r.begin(), r.end());

  vector<pair<long long, long long>> mr;

  long long prevS = r[0].first, prevE = r[0].second;
  for (int i = 1; i < r.size(); ++i) {
    long long currS = r[i].first, currE = r[i].second;
    if (currS <= prevE) {
      prevE = max(currE, prevE);
    } else {
      mr.push_back({prevS, prevE});
      prevS = currS, prevE = currE;
    }
  }
  mr.push_back({prevS, prevE});

  vector<long long> sa;
  vector<long long> ea;
  for (auto [s, e] : mr) {
    sa.push_back(s);
    ea.push_back(e);
  }

  long long x, ans = 0;
  while (cin >> x) {
    int sidx = upper_bound(sa.begin(), sa.end(), x) - sa.begin();
    sidx--;
    if (sidx < 0) continue;
    if (ea[sidx] >= x) ans++;
  }

  cout << ans << endl;

  return 0;
}
