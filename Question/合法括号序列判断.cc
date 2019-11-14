class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int sign = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == '(' || A[i] == ')'){
                if(A[i] == '('){
                    sign++;
                }
                else{
                    sign--;
                }
            }
            else{
                return false;
            }
        }
        
        if(sign == 0){
            return true;
        }
        else{
            return false;
        }
        
    }
};
