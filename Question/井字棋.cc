class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        vector<vector<int>> dp(4, vector<int>(4, 0));
        
        for(int i = 1; i < 4; i++){
            for(int j = 1; j < 4; j++){
                if(board[i - 1][j - 1] == 1){
                    dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + 1;
                    
                    if(dp[i][j] == 3){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

