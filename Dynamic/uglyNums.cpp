#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 10;
    int c2, c3, c5;
    c2 = c3 = c5 = 0;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == 2 * dp[c2])
            c2++;
        if (dp[i] == 3 * dp[c3])
            c3++;
        if (dp[i] == 5 * dp[c5])
            c5++;
    }
    cout << dp[n - 1] << endl;

    return 0;
}