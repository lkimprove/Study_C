class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        int m = board.size();
        int n = board[0].size();
        
        //board[0][0]不需要改变
        //第一列的每个位置的礼物价值之和，只能往下走
        for(int i = 1; i < m; i++){
            board[i][0] += board[i - 1][0];
        }
        //第一行的每个位置的礼物价值之和，只能往右走
        for(int i = 1; i < n; i++){
            board[0][i] += board[0][i - 1];
        }
        
        for(int x = 1; x < m; x++){
            for(int y = 1; y < n; y++){
                //达到上边位置（board[x - 1][y]）的礼物价值之和的最大值
                int upPlace = board[x - 1][y];
                //到达左边位置（board[x][y - 1]）的礼物价值之和的最大值
                int leftPlace = board[x][y - 1];
                
                if(leftPlace > upPlace){
                    board[x][y] += leftPlace;
                }
                else{
                    board[x][y] += upPlace;
                }
            }
        }
        
        return board[m - 1][n - 1];
    }
};
