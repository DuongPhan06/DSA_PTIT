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

int a[1001][1001];
int check = 0;
string s = "";
int n;
vector<string> v;
void Try(int i, int j)
{
    if (i == n && j == n)
    {
        v.pb(s);
        return;
    }
    if (a[i + 1][j] == 1 && i + 1 <= n)
    {
        s += "D";
        Try(i + 1, j);
        s.pop_back();
    }
    if (a[i][j + 1] == 1 && j + 1 <= n)
    {
        s += "R";
        Try(i, j + 1);
        s.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        if (a[1][1] == 1)
        {
            Try(1, 1);
        }
        if (v.size() != 0)
        {
            for (string x : v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
        v.clear();
    }
    return 0;
}