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
    cin.ignore();
    queue<int> q;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "PUSH")
        {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (s == "PRINTFRONT")
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
            }
            else
            {
                cout << "NONE\n";
            }
        }
        else if (s == "POP")
        {
            if (!q.empty())
            {
                q.pop();
            }
        }
    }
    return 0;
}