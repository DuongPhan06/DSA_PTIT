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
int x[1001];
int cnt = 0;
vector<string> v;
void Try(int i, int bd, ll sum)
{
    for (int j = bd; j >= 1; j--)
    {
        if (sum + j <= n)
        {
            x[i] = j;
            if (sum + j == n)
            {
                cnt++;
                string tmp;
                tmp += "(";
                for (int k = 1; k <= i; k++)
                {
                    tmp = tmp + to_string(x[k]) + " ";
                }
                tmp.pop_back();
                tmp += ") ";
                v.pb(tmp);
            }
            else
            {
                Try(i + 1, j, sum + j);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Try(1, n, 0);
        cout << cnt << endl;
        for (string x : v)
        {
            cout << x;
        }
        cout << endl;
        cnt = 0;
        v.clear();
    }
    return 0;
}