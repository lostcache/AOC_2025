#include <bits/stdc++.h>
#include <numeric>
#include <sstream>
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

  vector<long long> nums;
  string s;
  while (cin >> s) {
    if (s == "X") break;
    nums.push_back(stoll(s));
  }

  vector<string> ops;
  while (cin >> s) {
    ops.push_back(s);
  }

  int cols = ops.size();
  vector<long long> cAns(cols);
  for (int i = 0; i < cols; ++i) {
    if (ops[i] == "*") cAns[i] = 1;
    else cAns[i] = 0;
  }

  for (int i = 0; i < nums.size(); ++i) {
    int ci = i % cols;
    string op = ops[ci];
    if (op == "*") {
      cAns[ci] *= nums[i];
    } else if (op == "+") {
      cAns[ci] += nums[i];
    }
  }

  cout << accumulate(cAns.begin(), cAns.end(), 0LL) << endl;

  return 0;
}
