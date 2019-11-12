class Solution {
public:
    int StrToInt(string str) {
        //如果传入的字符串有正负号
        bool sign = false;
        if(str[0] == '-'){
            sign = true;
        }
        
        long long ret = 0;
        for(int i = str.size() - 1, j = 0; i >= 0; i--, j++){
            //因为外部已经判断过正负号，若有正负号此处不做处理
            if(str[i] == '+' || str[i] == '-'){
                continue;
            }
            
            //判断字符串是否合法
            if(str[i] < '0' || str[i] > '9'){
                return 0;
            }
            
            //处理每一位数字
            long long tmp = (str[i] - '0') * pow(10, j);
            ret += tmp;
        }
        
        //处理符号位
        if(sign){
            ret = 0 - ret;
        }
        
        //若超出int范围
        if(ret < INT_MIN || ret > INT_MAX){
            return 0;
        }
        
        return ret;
    }
};
