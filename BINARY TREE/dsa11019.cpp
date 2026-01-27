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
    node *left, *right;
    node(int x)
    {
        val = x;
        left = right = NULL;
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
void Duyet_LRN(node *t)
{
    if (t != NULL)
    {
        Duyet_LRN(t->left);
        Duyet_LRN(t->right);
        cout << t->val << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        node *t = NULL;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            ThemNode(t, x);
        }
        Duyet_LRN(t);
        cout << endl;
    }
    return 0;
}