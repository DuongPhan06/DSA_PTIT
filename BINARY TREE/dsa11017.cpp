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
    int data;
    struct node *pleft;
    struct node *pright;
};
typedef struct node NODE;
typedef NODE *TREE;
void khoitaoCay(TREE &t)
{
    t = NULL;
}
void themvaoCay(TREE &t, int x)
{
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pleft = NULL;
        p->pright = NULL;
        t = p;
    }
    else
    {
        if (x > t->data)
        {
            themvaoCay(t->pright, x);
        }
        else if (x < t->data)
        {
            themvaoCay(t->pleft, x);
        }
    }
}
void Duyet_NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        Duyet_NLR(t->pleft);
        Duyet_NLR(t->pright);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TREE t;
        khoitaoCay(t);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            themvaoCay(t, x);
        }
        Duyet_NLR(t);
        cout << endl;
    }
    return 0;
}