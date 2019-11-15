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
        for(auto& it : A){
            //入栈
            if(it == '('){
                s.push(it);
            }
            else if(it == ')'){
                //判断是否栈中存在(
                if(s.empty() || s.top() != '('){
                    return false;
                }
                
                //出栈
                s.pop();
            }
            //字符非法
            else{
                return false;
            }
        }
        
        return true;
    }
};
