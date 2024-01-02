#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visited;
queue<int> q;

void dfs(int V)
{
    if (visited[V])
    {
        return;
    }

    cout << V << ' ';
    visited[V] = true;

    for (auto n: nodes[V])
    {
        dfs(n);
    }
    
}

void bfs(int V)
{
    q.push(V);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (visited[now])
        {
            continue;
        }

        for (auto n: nodes[now])
        {
            q.push(n);
        }

        cout << now << ' ';
        visited[now] = true;
    }
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    vector<int> empty;
    nodes.push_back(empty);
    visited.push_back(false);

    for (int i = 0; i < N; i++)
    {
        vector<int> v;
        nodes.push_back(v);
        visited.push_back(false);
    }

    for (int i = 0; i < M; i++)
    {
        int source;
        int destination;
        
        cin >> source >> destination;
        nodes[source].push_back(destination);
        nodes[destination].push_back(source);
    }

    for (size_t i = 1; i < nodes.size(); i++)
    {
        sort(nodes[i].begin(), nodes[i].end());
    }

    dfs(V);
    cout << '\n';

    for (size_t i = 0; i < visited.size(); i++)
    {
        visited[i] = false;
    }

    bfs(V);

    return 0;
}