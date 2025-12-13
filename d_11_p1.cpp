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

int dfs(const string& n, map<string, vector<string>>& g, map<string, int>& vst) {
  if (vst.find(n) != vst.end()) {
    return vst[n];
  }

  if (n == "out") return 1;

  int curr = 0;
  if (g.contains(n)) {
    for (const string& nei : g[n]) {
      curr += dfs(nei, g, vst);
    }
  }

  vst[n] = curr;
  return curr;
}

int main() {
  fastIO();

  map<string, vector<string>> g;
  map<string, int> vst;
  string s;
  while (getline(cin, s)) {
    string pstr = s.substr(0, 3);
    istringstream ss(s.substr(5));
    string cstr;
    while (getline(ss, cstr, ' ')) {
      g[pstr].push_back(cstr);
    }
  }

  cout << dfs("you", g, vst) << endl;

  return 0;
}
