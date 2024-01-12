#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> order[32001];
bool visited[32001] {false};
stack<int> st;

void bfs(int v)
{
    if (visited[v])
    {
        return;
    }

    visited[v] = true;

    if (!order[v].empty())
    {
        for (int c: order[v])
        {
            bfs(c);
        }
    }

    st.push(v);
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        order[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
    {
        bfs(i);
    }

    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
}