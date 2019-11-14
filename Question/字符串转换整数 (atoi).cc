class Solution {
public:
    int myAtoi(string str) {
        //寻找第一个不为空格的字符
        size_t pos = str.find_first_not_of(" ");
        if(pos == string::npos){
            return 0;
        }

        //判断正负号
        int sign = 1;
        if(str[pos] == '-'){
            sign = -1;
            pos++;
        }
        else if(str[pos] == '+'){
            pos++;
        }

        //遍历字符串
        long long ret = 0;
        for(int i = pos; i < str.size(); i++){
            //判断当前字符是否合法
            if(str[i] >= '0'  && str[i] <= '9'){
                //判断是否越界
                if(ret < INT_MAX){
                    ret = ret * 10 + (str[i] - '0');
                }
                else{
                    if(sign == 1){
                        return INT_MAX;
                    }
                    else{
                        return INT_MIN;
                    }
                }
            }
            else{
                break;
            }
        }

        //边界值判断
        if(ret > INT_MAX){
            if(sign == 1){
                return INT_MAX;
            }
            else{
                return INT_MIN;
            }
        }

        return (sign * ret);
    }
};
