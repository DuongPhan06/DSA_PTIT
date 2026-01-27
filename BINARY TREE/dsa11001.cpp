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
    char c;
    node *left, *right;
    node(char x)
    {
        c = x;
        right = left = NULL;
    }
};
bool check(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->c;
        inOrder(root->right);
    }
}
void solve(string &s)
{
    stack<node *> st;
    node *root;
    for (int i = 0; i < s.size(); i++)
    {
        if (!check(s[i]))
        {
            st.push(new node(s[i]));
        }
        else
        {
            node *tmp = new node(s[i]);
            node *t1 = st.top();
            st.pop();
            node *t2 = st.top();
            st.pop();
            tmp->left = t2;
            tmp->right = t1;
            st.push(tmp);
        }
    }
    if (!st.empty())
    {
        root = st.top();
    }
    inOrder(root);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
        cout << endl;
    }
    return 0;
}