class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    int Dp(int i, int cur, vector<int> arr){
        //结束条件
        if(cur == -1 && i != 0){
            return -1;
        }
        else if(i == 0){
            return 0;
        }
        //如果 arr[cur] 大于 i,向后考虑
        if(arr[cur] > i){
            Dp(i, cur - 1, arr);
        }
        //用了该数
        int use = Dp(i - arr[cur], cur - 1, arr);
        //没用该数
        int unuse = Dp(i, cur - 1, arr);
        //结果判断
        if(use == 0 || unuse == 0){
            return 0;
        }
        return -1;
    }
    
    bool IsMinSum(vector<int> arr, int len, int i){
        //[0, cur] 为 arr 中比 i 小的区间
        int cur = len - 1;
        for(int j = 0; j < len; j++){
            if(arr[i] == i){
                return false;
            }
            if(arr[j] > i){
                cur = j - 1;
                break;
            }
        }
        //判断i是否为最小组成和
        int  ret = Dp(i, cur, arr);
        if(ret == 0){
            return false;
        }
        return true;
    }
    
	int getFirstUnFormedNum(vector<int> arr, int len) {
        //区间[min, max]
        sort(arr.begin(), arr.end());
        int min = arr[0];
        int max = 0;
        for(int i = 0; i < len; i++){
            max += arr[i];
        }
        //结果
        int ret = max + 1;
        //遍历区间
        for(int i = min + 1; i < max; i++){
            if(IsMinSum(arr, len, i)){
                ret = i;
                break;
            }
        }
        return ret;
    }
};
