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

int a[1000001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int> st;
        int res1[n];
        int res2[n];
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                res1[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            res1[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] < a[st.top()])
            {
                res2[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            res2[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++)
        {
            int greater = res1[i]; // Phan tu ben phai dau tien lon hon a[i]
            if (greater != -1)
            {
                if (res2[greater] != -1)
                {
                    cout << a[res2[greater]] << " ";
                }
                else
                {
                    cout << -1 << " ";
                }
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}