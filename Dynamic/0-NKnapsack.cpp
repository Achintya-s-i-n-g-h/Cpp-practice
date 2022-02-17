#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int dp[N][N];

int Knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    if (W <= 0)
    {
        return 0;
    }
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if (wt[n - 1] > W)
    {
        dp[n][W] = Knapsack(W, wt, val, n - 1);
    }
    else
    {
        dp[n][W] = max(Knapsack(W, wt, val, n - 1), val[n - 1] + Knapsack(W - wt[n - 1], wt, val, n - 1));
    }
    return dp[n][W];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }

    int n;
    cin >> n;
    int W;
    cin >> W;

    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << Knapsack(W, wt, val, n);

    return 0;
}