#include <bits/stdc++.h>
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

int main() {
  fastIO();

  string s;
  vector<string> map;
  while (cin >> s) {
    map.push_back(s);
  }

  long long ans = 0;
  for (int i = 1; i < map.size(); ++i) {
    for (int j = 0; j < map[i].length(); ++j) {
      char prev = map[i - 1][j], curr = map[i][j];
      if (prev != 'S' && prev != '|') continue;
      if (curr == '^') {
        if (j - 1 > 0) map[i][j - 1] = '|';
        if (j + 1 < map[i].length()) map[i][j + 1] = '|';
        ans++;
      } else {
        map[i][j] = '|';
      }
    }
  }

  cout << ans << endl;

  return 0;
}
