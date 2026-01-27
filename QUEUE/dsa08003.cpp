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
    deque<int> dq;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "PUSHBACK")
        {
            int n;
            cin >> n;
            dq.pb(n);
        }
        else if (s == "PUSHFRONT")
        {
            int n;
            cin >> n;
            dq.push_front(n);
        }
        else if (s == "PRINTFRONT")
        {
            if (!dq.empty())
            {
                cout << dq.front() << endl;
            }
            else
            {
                cout << "NONE\n";
            }
        }
        else if (s == "PRINTBACK")
        {
            if (!dq.empty())
            {
                cout << dq.back() << endl;
            }
            else
            {
                cout << "NONE\n";
            }
        }
        else if (s == "POPFRONT")
        {
            if (!dq.empty())
            {
                dq.pop_front();
            }
        }
        else if (s == "POPBACK")
        {
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
    }
    return 0;
}