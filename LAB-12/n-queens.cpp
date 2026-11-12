#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n){
  for(int i = 0; i < row; i++) if(board[i][col] == 'Q') return false;
  for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 'Q') return false; 
  for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (board[i][j] == 'Q') return false; 

  return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& sol){
  if(row == n){
    sol.push_back(board);
    return;
  }
  
  for(int col = 0; col < n; col++){
    if(isSafe(row, col, board, n)){
      board[row][col] = 'Q';
      solve(row + 1, n, board, sol);
      board[row][col] = '.';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cout << "Enter the number of rows: ";
  cin >> n;

  vector<string> board(n, string(n, '.')); 
  vector<vector<string>> sol;

  solve(0, n, board, sol);

  if (!sol.empty()) {
    cout << "Total solutions for " << n << "-Queens: " << sol.size() << "\n\n";

    for (int i = 0; i < sol.size(); i++) {
      cout << "Solution " << i + 1 << ":\n";
      
      for (const auto& row : sol[i]) cout << row << "\n";
      cout << "\n";
    }
  } else {
    cout << "No valid board configurations exist.\n";
  }

  return 0;
}
