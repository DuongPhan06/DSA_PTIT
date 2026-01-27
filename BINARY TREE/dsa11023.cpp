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
        right = left = NULL;
    }
};

void ThemNode(node *&t, int x)
{
    if (t == NULL)
    {
        t = new node(x);
    }
    else
    {
        if (x > t->val)
        {
            ThemNode(t->right, x);
        }
        else if (x < t->val)
        {
            ThemNode(t->left, x);
        }
    }
}

int height(node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    return 1 + max(height(t->right), height(t->left));
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
    }
    cout << height(t) - 1 << endl;
    return 0;
}