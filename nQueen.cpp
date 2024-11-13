#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>board;

bool isSafe(int row,int col,int n){
    for(int i=0;i<row;i++){                            //check row
        if(board[i][col]==1) return false;
    }
    int rowD=row;
    int colD=col;
    while(rowD>=0 && colD>=0){
        if(board[rowD][colD]==1) return false;
        rowD--;
        colD--;
    }
    rowD=row;
    colD=col;
    while(rowD>=0 && colD>=0){
        if(board[rowD][colD]==1) return false;
        rowD--;
        colD++;
    }
    return true;
}

bool queen(int row,int n){
    if(row>=n){              //ALL QUEENS PLACED
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(row,i,n)){
            board[row][i]=1;
        
        if(queen(row+1,n)){
            return true;
        }
        board[row][i]=0;                   //BACKTRACKING
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    if(queen(0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}