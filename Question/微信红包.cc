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

//修改版1.0
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        //排序
        sort(gifts.begin(), gifts.end());
        
        int ret = 0;
        int tmp = 1, sum = 1;
        
        for(int i = 0; i < n - 1; i++){
            //获取当前数字的出现次数
            if(gifts[i] == gifts[i + 1]){
                tmp++;
            }
            //判断当前数字出现的次数是否为最多的
            else{
                if(tmp > sum){
                    sum = tmp;
                    ret = gifts[i];
                    tmp = 1;
                }
                else{
                    tmp = 1;
                }
            }
        }
        
        //判断出现最多数字的次数是否超过一半
        if(sum > (n / 2)){
            return ret;
        }
        else{
            return 0;
        }
    }
};


//修改版2.0
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        //设出现最多次数的数为ret，若其出现次数大于一半
        //则ret出现的次数一定大于其他所有数字出现次数之和
        
        int count = 0;
        int ret = 0;
        for(int i = 0; i < n; i++){
            if(count == 0){
                ret = gifts[i];
                count++;
            }
            else{
                if(ret == gifts[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        
        int size = 0;
        for(int i = 0; i < n; i++){
            if(gifts[i] == ret){
                size++;
            }
        }
        
        if(size > (n / 2)){
            return ret;
        }
        else{
            return 0;
        }
        
    }
};
