#include<iostream>
#include<math.h>
using namespace std;
int N;
int sudoku[100][100];

bool isSafe(int n,int i,int j){
    for(int k=0;k<N-1;k++){
        if(sudoku[i][k]==n || sudoku[k][j]==n)
            return false;
    }

    int s=sqrt(N);
    int row=i-i%s;
    int col=j-j%s;
    for(int r=row;r<row + s;r++){
        for(int c=col;c<col + s;c++){
            if(sudoku[r][c]==n){
                return false;
            }
        }
    }
    return true;
}

bool SolveSudoku(){
    int i,j;
    bool empty=false;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(sudoku[i][j]==0){
                empty=true;
                break;
            }
        }
        if(empty)
            break;
    }

    if(!empty) {
        return true;
    }

    for(int n=1;n<=N;n++){
        if(isSafe(n,i,j)){
            sudoku[i][j]=n;
            if(SolveSudoku())
                return true;
            sudoku[i][j]=0;
        }
    }
    return false;
}


int main()
{
    cout<<"Enter the size of sudoku:";
    cin>>N;
    cout<<"Partially fill the puzzle \nNote:represent empty spaces with 0"<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sudoku[i][j];
        }
    }
    cout<<endl;

    if(SolveSudoku()){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
    } else{
        cout<<"No solution exists";
    }
    return 0;
}