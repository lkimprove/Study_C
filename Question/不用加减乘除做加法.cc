class Solution {
public:
    int Add(int num1, int num2)
    {
        //^ 求本位
        //& 求进位
        //当不存在进位时，运算结束
        
        int standard = num1 ^ num2;
        int carry = num1 & num2;
        
        while(carry){
            carry = carry << 1;
            
            int tmp1 = standard ^ carry;
            int tmp2 = standard & carry;
            
            standard = tmp1;
            carry = tmp2;
        }
        
        return standard;
    }
};
