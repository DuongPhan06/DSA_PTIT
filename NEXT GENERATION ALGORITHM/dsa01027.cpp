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
bool visited[1001];
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
                for (int i = 1; i <= n; i++)
                {
                    cout << a[x[i]] << " ";
                }
                cout << endl;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Try(1);
    return 0;
}