#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left {nullptr};
    node* right {nullptr};
};

void insert_node(node* rootNode, node* inNode)
{
    bool bigger = inNode->data > rootNode->data;
    
    if (!bigger)
    {
        if (nullptr != rootNode->left)
        {
            insert_node(rootNode->left, inNode);
        }
        else
        {
            rootNode->left = inNode;
        }
    }
    else
    {
        if (nullptr != rootNode->right)
        {
            insert_node(rootNode->right, inNode);
        }
        else
        {
            rootNode->right = inNode;    
        }
    }
}

void print_tree(node* inNode)
{
    // 리프 노드일시 early return
    if (nullptr == inNode->left && nullptr == inNode->right)
    {
        cout << inNode->data << '\n';
        return;
    }

    // 왼쪽 먼저
    if (nullptr != inNode->left)
    {
        print_tree(inNode->left);
    }
    if (nullptr != inNode->right)
    {
        print_tree(inNode->right);
    }

    cout << inNode->data << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 값을 미리 벡터로 받아놓음
    vector<int> input;
    int x;

    while (cin >> x)
    {
        input.push_back(x);
    }

    // 루트 노드 생성    
    node root;
    root.data = input[0];

    // 전위 순회한 값을 토대로 이진 검색 트리를 만든다
    for (int i = 1; i < input.size(); i++)
    {
        node* a = new node;
        a->data = input[i];

        insert_node(&root, a);
    }

    // 이진 검색 트리를 후위 순회하여 출력한다
    print_tree(&root);
}
