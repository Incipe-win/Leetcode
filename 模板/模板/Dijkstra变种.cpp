#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
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
    v.resize(n);
    for (int i = 0; i < n; ++i) {
      v[i].clear();
    }
  }

  void Add(int a, int b, int c) {
    v[a].push_back(make_pair(b, c));
    v[b].push_back(make_pair(a, c));
  }

  void GetDist(int st, vector<int> &dist, vector<int> &path,
               const vector<int> &vec, vector<int> &maxPeople,
               vector<int> &num) {
    for (int i = 0; i < n; ++i) {
      maxPeople[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      num[i] = 0;
    }
    maxPeople[st] = vec[st];
    num[st] = 1;
    for (int i = 0; i < n; ++i) {
      path[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
      dist[i] = 2147483647;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    dist[st] = 0;
    q.push(make_pair(0, st));
    while (!q.empty()) {
      int now = q.top().second;
      if (dist[now] != q.top().first) {
        q.pop();
        continue;
      }
      q.pop();
      for (int i = 0; i < (int)v[now].size(); i++) {
        int next = v[now][i].first, value = v[now][i].second;
        if (dist[now] + value < dist[next]) {
          dist[next] = dist[now] + value;
          q.push(make_pair(dist[next], next));
          path[next] = now;
          num[next] = num[now];
          maxPeople[next] = maxPeople[now] + vec[next];
        } else if (dist[now] + value == dist[next]) {
          num[next] += num[now];
          if (maxPeople[now] + vec[next] > maxPeople[next]) {
            maxPeople[next] = maxPeople[now] + vec[next];
          }
        }
      }
    }
  }
};