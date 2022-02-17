#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e3 + 2;
int dp[N][N];

int CoinChange(vector<int> &a, int n, int x)
{

    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (n <= 0)
        return 0;

    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }

    dp[n][x] = CoinChange(a, n, x - a[n - 1]) + CoinChange(a, n - 1, x);

    return dp[n][x];
}

int main()
{
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            dp[i][j] = -1;
        }
    }

    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    int V;
    cin >> V;

    int arr[V + 1];

    cout << CoinChange(v, m, V);

    //*****top down approach**********
    // int arr[V + 1];
    // arr[0] = 1;
    // for (int i = 1; i <= V; i++)
    // {
    //     arr[i] = 0;
    // }

    // for (int j = 1; j <= m; j++)
    // {
    //     for (int i = 0; i <= V; i++)
    //     {

    //         if (i - j >= 0)
    //         {
    //             arr[i] += arr[i - j];
    //         }
    //     }
    // }

    // cout << arr[V];

    // debugg
    //  for (auto i : arr)
    //  {
    //      cout << i << " ";
    //  }
    return 0;
}