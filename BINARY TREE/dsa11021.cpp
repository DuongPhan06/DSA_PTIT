#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pf push_front
#define mp make_pair
#define MAX_N 1e9
#define MIN_N -1e9
#define MAX_SIZE 1000000
#define PI 3.141592653589793238
#define pb push_back
#define sz(s) s.size()
const int mod = 1e9 + 7;
#define faster                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

struct node
{
    int val;
    node *right, *left;
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void ThemNode(node *&root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
    }
    else
    {
        if (x > root->val)
        {
            ThemNode(root->right, x);
        }
        else if (x < root->val)
        {
            ThemNode(root->left, x);
        }
    }
}
void Node_la(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
    }
    Node_la(root->left);
    Node_la(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        node *t = NULL;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ThemNode(t, x);
        }
        Node_la(t);
        cout << endl;
    }
    return 0;
}