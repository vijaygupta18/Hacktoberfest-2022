//Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
//Note: In a path, no cell can be visited more than one time.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findPath(int i, int j, vector<vector<int>> &m, int n, string s, vector<string> &res)
    {
        if (i < 0 or j < 0 or i >= n or j >= n or m[i][j] == 0 or m[i][j] == 100)
        {
            return;
        }
        else if (i == n - 1 and j == n - 1)
        {
            res.push_back(s);
            return;
        }
        else
        {
            m[i][j] = 100;
            findPath(i + 1, j, m, n, s + 'D', res);
            findPath(i - 1, j, m, n, s + 'U', res);
            findPath(i, j + 1, m, n, s + 'R', res);
            findPath(i, j - 1, m, n, s + 'L', res);
            m[i][j] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        findPath(0, 0, m, n, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}