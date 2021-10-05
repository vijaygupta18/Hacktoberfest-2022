//  [USING BITMASK TECHNIQUE MOST OPTIMIZED SOLUTION TO FIND ALL DISTINCT SOLUTIONS TO NQUEENS PUZZLE].
// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> res;
vector<int> board;
int done;
void nQueens(int boardState = 0, int leftDiagonal = 0, int rightDiagonal = 0, int idx = 0)
{
  if (boardState == done)
  {
    vector<string> ans;
    ans.clear();
    int A = board.size();
    for (int i = 0; i < A; ++i)
    {
      string s(A, '.');
      s[board[i]] = 'Q';
      ans.push_back(s);
      s.clear();
    }
    res.push_back(ans);
  }
  else
  {
    int safe = done & (~(boardState | leftDiagonal | rightDiagonal));
    while (safe)
    {
      int pos = safe & (-safe);
      board[idx] = log2l(pos);
      nQueens(boardState | pos, (leftDiagonal | pos) << 1, (rightDiagonal | pos) >> 1, idx + 1);
      board[idx] = -1;
      safe -= pos;
    }
  }
}
vector<vector<string>> solveNQueens(int A)
{
  res.clear();
  board = vector<int>(A, -1);
  done = (1 << A) - 1;
  nQueens(0, 0, 0);
  board.clear();
  done = 0;
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<string>> ans = solveNQueens(n);
  if (ans.empty())
  {
    cout << "\t\tNO SOLUTION AVAILABLE";
  }
  for (vector<string> soln : ans)
  {
    cout << "\t\t\t\tSOLUTION :\n\n";
    for (string row : soln)
      cout << "\t\t\t\t" << row << "\n";
    cout << "\n\n\n";
  }
  return 0;
}
