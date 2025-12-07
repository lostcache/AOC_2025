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

  long long ans = 0;
  for (auto [s, e] : mr) {
    ans += (e - s + 1);
  }

  cout << ans << endl;

  return 0;
}
