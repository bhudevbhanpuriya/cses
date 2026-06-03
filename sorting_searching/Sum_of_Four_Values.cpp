#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pair<int, int> p;
        p.first = a;
        p.second = i;
        // first in pair represents value, second represents index
        arr.push_back(p);
    }
    sort(begin(arr), end(arr));
    for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        int target = x - arr[i].first - arr[j].first;

        int l = j + 1;
        int r = n - 1;

        while (l < r)
        {
            int sum = arr[l].first + arr[r].first;

            if (sum == target)
            {
                cout << arr[i].second + 1 << " "
                     << arr[j].second + 1 << " "
                     << arr[l].second + 1 << " "
                     << arr[r].second + 1 << "\n";
                return 0;
            }

            if (sum < target)
                l++;
            else
                r--;
        }
    }
}
    cout << "IMPOSSIBLE" << endl;
}