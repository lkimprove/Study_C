//将数组排序，若存在出现次数超过一半的数字，则该数字一定在数组中间位置
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        
        int ret = numbers[numbers.size() / 2], count = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(ret == numbers[i]){
                count++;
            }
        }
        
        if(count > numbers.size() / 2){
            return ret;
        }
        else{
            return 0;
        }
    }
};


//若存在x出现的次数超过一半，则x出现的次数一定比其他所有数出现的次数加起来都多
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0, ret = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(count == 0){
                ret = numbers[i];
                count = 1;
            }
            else{
                if(ret == numbers[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        
        count = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(ret == numbers[i]){
                count++;
            }
        }
        
        if(count > numbers.size() / 2){
            return ret;
        }
        else{
            return 0;
        }
    }
};


