class Solution {
public:
    int jumpFloorII(int number) {
        //法一：
        //j(n) = j(n - 1) + j(n - 2) + ...+ j(1) + 1
        //j(n - 1) = j(n -2) + ...+ j(1) + 1
        //j(n) = 2 * j(n -1)
        /*if(number == 1){
            return 1;
        }
        return 2 * jumpFloorII(number - 1);*/
        //法二：
        //每个台阶要么跳，要么不跳，最后一个台阶必须跳，
        //所以总的跳法为 2^(n - 1)
        return 1 << (number - 1);
    }
};
