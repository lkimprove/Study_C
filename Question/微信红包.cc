class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        //将所有的数据排序
        sort(gifts.begin(), gifts.end());
        //如果有出现次数超过一半的数，则这个数一定在中间
        int middle = gifts[n / 2];
        //计数
        int count = 0;
        //遍历查看这个数是否超过一半
        for(int i = 0; i < n; i++){
            if(middle == gifts[i]){
                count++;
            }
        }
        if(count > n / 2){
            return middle;
        }
        else {
            return 0;
        }
    }
};
