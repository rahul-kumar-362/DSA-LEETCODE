/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://BRUTE FORCE USING MAP AND HASHING
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mpp;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;

        while(temp1){
            mpp[temp1]++;
            temp1 = temp1->next;
        }
        while(temp2){
            if(mpp.count(temp2)){//AGAR same node aaya toh pehla return
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};