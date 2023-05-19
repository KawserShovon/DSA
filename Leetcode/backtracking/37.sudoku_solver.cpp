bool isSafe(char val, int row, int col, vector<vector<char>>& board)
{
    int storerow = row;
    int storecol = col;

    //check full row
    for(int i=0; i<9; i++)
    {
        if(board[i][col]==val)
        {
            return false;
        }
    }

    //check full col
    for(int i=0; i<9; i++)
    {
        if(board[row][i] == val)
        {
            return false;
        }
    }

    int nrow = (row/3)*3;
    int ncol = (col/3)*3;

    for(int r= 0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(board[r+nrow][c+ncol] == val)
            {
                return false;
            }
        }
    }


    return true;
}

bool solve( vector<vector<char>>& board)
{
    
    for(int row = 0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            if(board[row][col] == '.')
            {
                for(int i=1;i<=9; i++)
                {
                    char c = '0'+i;
                    if(isSafe(c,row,col,board))
                    {

                        board[row][col] = c;
                        
                        if(solve(board))
                        {
                            return true;
                        }
                        else 
                        {
                            board[row][col] = '.';
                        }
                        
                    }
                }
                return false;
            }

           
        }

    }

    return true;
}

void solveSudoku(vector<vector<char>>& board)
{
    solve(board);
}


