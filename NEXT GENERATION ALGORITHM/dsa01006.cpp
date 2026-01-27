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
bool visited[1001];
vector<string> v;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == false)
        {
            visited[j] = true;
            x[i] = j;
            if (i == n)
            {
                string tmp;
                for (int i = 1; i <= n; i++)
                {
                    tmp += to_string(x[i]);
                }
                v.pb(tmp);
            }
            else
            {
                Try(i + 1);
            }
            visited[j] = false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        cin >> n;
        Try(1);
        reverse(v.begin(), v.end());
        for (string x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}