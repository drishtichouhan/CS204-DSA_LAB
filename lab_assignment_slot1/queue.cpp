#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int f;
    int r;
    int s;
    unsigned capacity;
    int *arr;
};
int isFull(Node *node)
{
    if (node->s == node->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(Node *node)
{
    if (node->s == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node *createq(unsigned capacity)
{
    Node *q = new Node();
    q->capacity = capacity;
    q->f = 0;
    q->s = 0;
    q->r = capacity - 1;
    q->arr = new int[(q->capacity * sizeof(int))];
    return q;
}
void enqueue(Node *que, int val)
{
    if (isFull(que))
    {
        return;
    }
    que->r = (que->r + 1) % que->capacity;
    que->arr[que->r] = val;
    que->s += 1;
}
int dequeue(Node *que)
{
    if (isempty(que))
    {
        return -1;
    }
    int item = que->arr[que->f];
    que->f = (que->f + 1) % que->capacity;
    que->s -= 1;
    return item;
}
int getf(Node *node)
{
    if (isempty(node))
    {
        return INT_MIN;
    }
    return node->arr[node->f];
}
int getr(Node *node)
{
    if (isempty(node))
    {
        return INT_MIN;
    }
    return node->arr[node->r];
}

int main()
{
    Node *que = createq(1000);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'E')
        {
            int l;
            cin >> l;
            enqueue(que, l);
            cout << que->s << endl;
        }
        else
        {

            cout << dequeue(que) << " ";
            cout << que->s << endl;
        }
    }

    return 0;
}