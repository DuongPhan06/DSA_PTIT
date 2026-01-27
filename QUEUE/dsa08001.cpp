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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                cout << q.size() << endl;
            }
            else if (x == 2)
            {
                if (q.empty())
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else if (x == 3)
            {
                int a;
                cin >> a;
                q.push(a);
            }
            else if (x == 4)
            {
                if (!q.empty())
                {
                    q.pop();
                }
            }
            else if (x == 5)
            {
                if (!q.empty())
                {
                    cout << q.front() << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else if (x == 6)
            {
                if (!q.empty())
                {
                    cout << q.back() << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}