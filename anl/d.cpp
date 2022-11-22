#include<bits/stdc++.h>
using namespace std;

const int N = 4;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int i = row, j = col;

    //left diagonal

    while(i>=0 && j>=0) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;

    // right diagonal

    while(i>=0 && j<N) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    i = row;
    j = col;

    //up

    while(i>=0) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
    }    

    return true;
}

bool solveNQ(vector<vector<int>>& board, int row) {
    if(row >= N) {
        return true;
    }

    for(int j=0;j<N;j++) {

        if(isSafe(board, row, j)) {

            board[row][j] = 1;

            if(solveNQ(board, row+1)) {
                return true;
            }

            //backtracking
            board[row][j] = 0;
        }
    }

    return false;
}

void solve(vector<vector<int>>& board) {

    if(!solveNQ(board, 1)) {
        cout<<"Queens cannot be placed\n";
        return;
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j]) {
                cout<<"Q ";
            }else {
                cout<<". ";
            }
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N,0));

    cout<<"Enter the position of 1st queen: ";
    int position;
    cin>>position;

    position--;

    board[0][position] = 1;

    solve(board);

}

// Time Complexity: O(N!)
// Auxiliary Space: O(N2)