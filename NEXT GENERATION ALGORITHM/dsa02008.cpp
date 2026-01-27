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
int x[1001];
bool visited[1001];
int n, s;
int cnt = 0;
vector<string> v;
void Try(int i, int j, ll sum)
{
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == 0 && sum + a[i][j] <= s)
        {
            visited[j] = 1;
            x[i] = j; // Luu cac cot co the nhan
            if (sum + a[i][j] == s && i == n)
            {
                cnt++;
                string tmp;
                for (int k = 1; k <= i; k++)
                {
                    tmp = tmp + to_string(x[k]) + " ";
                }
                v.pb(tmp);
            }
            else
            {
                Try(i + 1, 1, sum + a[i][j]);
            }
            visited[j] = 0;
        }
    }
}
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 1, 0);
    cout << cnt << endl;
    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;
}