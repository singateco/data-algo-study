#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int num;
    vector<node*> children;
};

vector<node*> emp;
int depth[51];

bool compare(node* a, node* b)
{
    if (depth[b->num] >= depth [a->num])
    {
        return false;
    }

    return true;
}

int dfs(node* n)
{
    if (n->children.empty())
    {
        depth[n->num] = 0;
        return depth[n->num];
    }

    for (auto c: n->children)
    {
        dfs(c);
    }

    sort(n->children.begin(), n->children.end(), compare);

    for (int i = 0; i < n->children.size(); i++)
    {
        depth[n->num] = max(depth[n->children[i]->num] + i + 1 , depth[n->num]);
    }
    return depth[n->num];
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        node* n = new node;
        emp.push_back(n);
        n->num = i;

        int parent;
        cin >> parent;
       
        if (parent != -1)
        {
            emp[parent]->children.push_back(n);
        }
    }

    cout << dfs(emp[0]);
}