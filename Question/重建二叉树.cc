//根据二叉树的前序遍历和中序遍历，重建二叉树

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //终止条件
        if(pre.size() == 0 || vin.size() == 0){
            return NULL;
        }
        
        //创建根节点
        TreeNode* root = new TreeNode(pre[0]);
        
        //通过根节点找到左右子树的中序遍历
        vector<int> left_vin, right_vin;
        int flag = 0;    //标志位
        for(auto i = vin.begin(); i != vin.end(); i++){
            //跳过根节点，并将标志位置为1
            if(*i == root->val){
                flag = 1;
                continue;
            }
            //左子树的中序遍历
            if(flag == 0){
                left_vin.push_back(*i);
            }
            //右子树的中序遍历
            if(flag == 1){
                right_vin.push_back(*i);
            }
        }
        
        //通过左子树的中序遍历获取左右子树的前序遍历
        vector<int> left_pre, right_pre;
        flag = 0;
        for(auto i = pre.begin() + 1;i != pre.end(); i++){
            for(auto j = left_vin.begin(); j != left_vin.end(); j++){
                //若相等，则说明左子树有该节点
                if(*i == *j){
                    flag = 1;    //将标志位置为1
                }
            }
            //左子树的前序遍历
            if(flag == 1){
                left_pre.push_back(*i);
            }
            //右子树的前序遍历
            if(flag == 0){
                right_pre.push_back(*i);
            }
            flag = 0;
        }
        
        //左右子树递归
        root->left = reConstructBinaryTree(left_pre, left_vin);
        root->right = reConstructBinaryTree(right_pre, right_vin);
        
        return root;
    }
};
