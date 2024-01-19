#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define VMAX 10001

vector<pair<pair<int, int>, int>> edge;
int link[VMAX];

int find(int x)
{
    while (x != link[x])
    {
        x = link[x];
    }
    return x;
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    link[b] = a;
}


// 가중치에 맞게 오름차순 정렬
bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    // 서로소집합 초기화
    for (int i = 1; i <= V; i++)
    {
        link[i] = i;
    }

    // 간선 만들기
    for (int i = 0; i < E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edge.push_back(make_pair(make_pair(a, b), w));
    }

    // 오름차순으로 정렬함.
    sort(edge.begin(), edge.end(), compare);

    int minweight = 0;
    
    for (auto e: edge)
    {
        int a, b;
        a = e.first.first;
        b = e.first.second;

        if (!same(a, b))
        {
            unite(a, b);
            minweight += e.second;
        }
    }
    
    cout << minweight;
    
    return 0;
}