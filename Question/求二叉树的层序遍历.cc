/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
        //判空
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        
        //利用队列对二叉树进行层序遍历
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                //获取该层二叉树的每个节点
                temp.push_back(curr->val);
                
                //将下一层的节点放入队列
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
            ret.push_back(temp);
        }
        
        return ret;
    }
};
