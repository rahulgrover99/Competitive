#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent, rnk;

void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

int solve(int A, vector<vector<int> > &B) {
    int cost = 0;
    vector<Edge> edges;
    for (auto x : B){
        edges.push_back({x[0], x[1], x[2]});
    }
    parent.resize(A);
    rnk.resize(A);
    for (int i = 0; i < A; i++)
        make_set(i);
    
    sort(edges.begin(), edges.end());
    
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }
    return cost;
}

int main(){
    int A = 5;
    vector<vector<int> > B {
  {1, 2, 3},
  {2, 3, 4},
  {3, 4, 5},
  {4, 5, 6},
  {5, 1, 2},
  {2, 4, 3},
  {2, 5, 5},
  {1, 3, 2}
};

    cout << solve(A, B) << endl;
}
