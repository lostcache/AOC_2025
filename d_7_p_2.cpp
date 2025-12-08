#include <bits/stdc++.h>
#include <numeric>
#include <string>

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

long long dfs(int ci, int cj, const vector<string>& map, vector<vector<long long>>& cache) {
  if (ci >= map.size()) {
    return 1;
  }

  if (cache[ci][cj] != 0) {
    return cache[ci][cj];
  }

  long long curr = 0;
  if (map[ci][cj] == '.' || map[ci][cj] == 'S') {
    curr += dfs(ci + 1, cj, map, cache);
  } else if (map[ci][cj] == '^') {
    if (cj - 1 >= 0) curr += dfs(ci, cj - 1, map, cache);
    if (cj + 1 < map[ci + 1].length()) curr += dfs(ci, cj + 1, map, cache);
  }

  cache[ci][cj] = curr;

  return cache[ci][cj];
}

int main() {
  fastIO();

  string s;
  vector<string> map;
  while (cin >> s) {
    map.push_back(s);
  }

  vector<vector<long long>> cache(map.size(), vector<long long>(map[0].length(), 0));

  // for (int j = 0; j < map[0].length(); ++j) {
  //   if (map[0][j] == 'S') cout << dfs(0, j, map, cache) << endl;
  // }

  int r = map.size(), c = map[0].length();
  for (int j = 0; j < c; ++j) {
    if (map[0][j] == 'S') cache[0][j] = 1;
  }

  for (int i = 1; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] == '.') {
        cache[i][j] += cache[i - 1][j];
      } else if (map[i][j] == '^') {
        if (j - 1 >= 0) cache[i][j - 1] += cache[i - 1][j];
        if (j + 1 < map[i].length()) cache[i][j + 1] += cache[i - 1][j];
      }
    }
  }

  cout << accumulate(cache[r - 1].begin(), cache[r - 1].end(), 0LL) << endl;

  return 0;
}
