#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
int infected = 0;

void bfs(int x)
{
    if (visited[x])
    {
        return;
    }

    visited[x] = true;
    infected++;

    for (auto a: nodes[x])
    {
        bfs(a);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> v;
    nodes.push_back(v);
    visited.push_back(false);

    for (int i = 0 ; i < N; i++)
    {
        vector<int> V;
        nodes.push_back(V);
        visited.push_back(false);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    bfs(1);
    cout << (infected - 1);
}