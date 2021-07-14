#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
  }
};

class Dijkstra {
 private:
  int n;
  vector<vector<pair<int, int>>> v;

 public:
  void Init(int n) {
    this->n = n;
    v.clear();
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      v[i].clear();
    }
  }

  void Add(int a, int b, int c) {
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }

  void GetDist(int st, vector<int> &dist, vector<int> &path) {
    for (int i = 1; i <= n; ++i) {
      path[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      dist[i] = INT_MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    dist[st] = 0;
    q.push(make_pair(0, st));
    while (!q.empty()) {
      int now = q.top().second;
      q.pop();
      for (int i = 0; i < (int)v[now].size(); i++) {
        int next = v[now][i].first, value = v[now][i].second;
        if (dist[now] + value < dist[next]) {
          dist[next] = dist[now] + value;
          q.push(make_pair(dist[next], next));
          path[next] = now;
        }
      }
    }
  }
};