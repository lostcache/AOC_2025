#include <bits/stdc++.h>
#include <queue>

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

int dfs(const string& dest, const string& n, map<string, vector<string>>& g,
        map<string, int>& vst) {
  if (vst.find(n) != vst.end()) {
    return vst[n];
  }

  if (n == dest) return 1;

  int curr = 0;
  if (g.contains(n)) {
    for (const string& nei : g[n]) {
      curr += dfs(dest, nei, g, vst);
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

  map<string, int> rank;
  queue<pair<string, int>> q;
  set<string> visited;
  visited.insert("svr");
  q.push({"svr", 0});
  rank["svr"] = 0;

  while (!q.empty()) {
    auto [curr_node, curr_rank] = q.front();
    q.pop();

    for (auto nei : g[curr_node]) {
      if (visited.find(nei) != visited.end()) continue;
      q.push({nei, curr_rank + 1});
      rank[nei] = curr_rank + 1;
      visited.insert(nei);
    }
  }

  string start = "dac", end = "fft";
  if (rank[start] > rank[end]) swap(start, end);

  map<string, int> vst_start;
  int ways_start = dfs(start, "svr", g, vst_start);

  map<string, int> vst_inter;
  int ways_intermediate = dfs(end, start, g, vst_inter);

  map<string, int> vst_end;
  int ways_end = dfs("out", end, g, vst_end);

  cout << 1LL * ways_start * ways_intermediate * ways_end << endl;

  return 0;
}
