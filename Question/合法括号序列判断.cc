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


//STL栈（stack）
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> s;
        
        for(int i = 0; i < n; i++){
            if(A[i] == '('){
                s.push(A[i]);
            }
            else if(A[i] == ')'){
                if(s.empty()){
                    return false;
                }
                
                s.pop();
            }
            else{
                return false;
            }
        }
        
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
