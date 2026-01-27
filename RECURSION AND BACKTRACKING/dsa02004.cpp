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
int n;
int used[1001];
string s;
set<string> se;
void Try(int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        se.insert(s);
        return;
    }
    if (i + 1 <= n - 1 && a[i + 1][j] == 1)
    {
        a[i + 1][j] = 0;
        s += "D";
        Try(i + 1, j);
        s.pop_back();
        a[i + 1][j] = 1;
    }
    if (j + 1 <= n - 1 && a[i][j + 1] == 1)
    {
        a[i][j + 1] = 0;
        s += "R";
        Try(i, j + 1);
        s.pop_back();
        a[i][j + 1] = 1;
    }
    if (i - 1 >= 0 && a[i - 1][j] == 1)
    {
        a[i - 1][j] = 0;
        s += "U";
        Try(i - 1, j);
        s.pop_back();
        a[i - 1][j] = 1;
    }
    if (j - 1 >= 0 && a[i][j - 1] == 1)
    {
        a[i][j - 1] = 0;
        s += "L";
        Try(i, j - 1);
        s.pop_back();
        a[i][j - 1] = 1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        se.clear();
        if (a[0][0] != 1)
        {
            cout << "-1" << endl;
            continue;
        }
        a[0][0] = 0;
        Try(0, 0);
        a[0][0] = 1;
        if (se.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            for (auto x : se)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}