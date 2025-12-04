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

  vector<string> map;
  string s;
  while (cin >> s) {
    map.push_back(s);
  }

  int r = map.size(), c = map[0].length(), ans = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (map[i][j] != '@') continue;

      int nNei = 0;
      for (auto [di, dj] : dirs) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && map[ni][nj] == '@') {
          nNei++;
        }
      }

      for (auto [di, dj] : diags) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && map[ni][nj] == '@') {
          nNei++;
        }
      }

      if (nNei < 4) {
        ans += 1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
