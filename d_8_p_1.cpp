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

vector<int> paren, sz;

int find(int i) {
  if (paren[i] == i) return i;
  return paren[i] = find(paren[i]);
}

void join(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (sz[j] > sz[i]) swap(i, j);
  paren[j] = i;
  sz[i] += sz[j];
}

int main() {
  fastIO();

  vector<vector<int>> points;
  vector<vector<long long>> point_dist;
  string s;
  while (cin >> s) {
    istringstream ss(s);
    string tempStr;
    int x, y, z;
    getline(ss, tempStr, ',');
    x = stoi(tempStr);
    getline(ss, tempStr, ',');
    y = stoi(tempStr);
    getline(ss, tempStr, ',');
    z = stoi(tempStr);
    points.push_back({x, y, z});
  }

  paren.resize(points.size());
  for (int i = 0; i < points.size(); ++i) paren[i] = i;
  sz.resize(points.size(), 1);

  for (int i = 0; i < points.size(); ++i) {
    for (int j = i + 1; j < points.size(); ++j) {
      long long dist = 0;
      for (int k = 0; k < 3; ++k) {
        dist += 1LL * abs(points[i][k] - points[j][k]) * abs(points[i][k] - points[j][k]);
      }
      point_dist.push_back({dist, i, j});
    }
  }

  sort(point_dist.begin(), point_dist.end());

  for (int i = 0; i < 1000; ++i) {
    join(point_dist[i][1], point_dist[i][2]);
  }

  sort(sz.rbegin(), sz.rend());

  cout << 1LL * sz[0] * sz[1] * sz[2] << endl;

  return 0;
}
