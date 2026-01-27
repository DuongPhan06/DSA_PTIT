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

int n;
int a[1000001];
int x[1001];
vector<string> v;
void in(int i)
{
    string t = "";
    for (int k = 1; k <= i; k++)
    {
        t = t + to_string(a[x[k]]) + " ";
    }
    v.pb(t);
}

void Try(int i, int bd)
{
    for (int j = bd; j <= n; j++)
    {
        if (a[j] >= a[x[i - 1]])
        {
            x[i] = j;
            if (i >= 2)
            {
                in(i);
            }
            Try(i + 1, j + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, 1);
    sort(v.begin(), v.end());
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}