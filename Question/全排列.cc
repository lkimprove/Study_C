class Solution {
public:
    void Perm(vector<vector<int>>& ret, vector<int>& nums, int index, int size){
        //结束条件
        if(index == size){
            vector<int> tmp = nums;
            ret.push_back(tmp);
            return;
        }

        for(int i = index; i < size; i++){
            //在0位置依次固定nums中的每一个数
            //之后再固定1，2，3位置
            swap(nums[i], nums[index]);
            //向下递归（分治思想）
            Perm(ret, nums, index + 1, size);
            //还原原数组，避免重复
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        
        Perm(ret, nums, 0, nums.size());

        return ret;
    }
};
