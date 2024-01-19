#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define VMAX 20001
#define INF 30000000

int dist[VMAX];
vector<pair<int, int>> adj[VMAX];
bool processed[VMAX] {false};
priority_queue<pair<int, int>> q; // {distance, node n}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    for (int i = 1; i <= V; i++)
    {
        dist[i] = INF;
    }

    int start;
    cin >> start;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
    }

    dist[start] = 0;
    q.emplace(0, start);

    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if (processed[a])
        {
            continue;
        }

        processed[a] = true;

        for (auto u: adj[a])
        {
            int b = u.first;
            int w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.emplace(-(dist[b]), b);
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF";
        }
        else
        {
            cout << dist[i];
        }
        cout << '\n';
    }
    
    return 0;
}