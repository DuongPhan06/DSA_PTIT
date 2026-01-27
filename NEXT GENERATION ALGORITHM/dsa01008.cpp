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

int n, k;
vector<string> v;
int x[1001];
void Try(int i, int cnt)
{
    if (i == n + 1)
    {
        if (cnt == k)
        {
            for (int i = 1; i < n + 1; i++)
            {
                cout << x[i];
            }
            cout << endl;
        }
        return;
    }
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (j == 1)
        {
            Try(i + 1, cnt + 1);
        }
        else
        {
            Try(i + 1, cnt);
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
        cin >> n >> k;
        Try(1, 0);
    }
    return 0;
}