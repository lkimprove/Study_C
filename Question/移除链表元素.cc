/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sen = new ListNode(0);
        sen->next = head;

        ListNode* prev = sen, *curr = head, *toDelete = nullptr;
        while(curr != nullptr){
            if(curr->val == val){
                prev->next = curr->next;
                toDelete = curr;
            }
            else{
                prev = curr;
            }
            curr = curr->next;

            if(toDelete != nullptr){
                delete toDelete;
                toDelete = nullptr;
            }
        }

        ListNode* ret = sen->next;
        delete sen;
        return ret;
    }
};
