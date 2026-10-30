/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://BRUTE FORCE USING hashing...
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;//0 ya 1 size LL ke liye...
        unordered_map<ListNode*,int>mpp;
        ListNode*temp = head;
        mpp[temp]++;//1 daldiya 
        temp = temp->next;
        while(temp){
            if(mpp.count(temp)){//Pehle se hai toh return 
                return temp;
            }
            mpp[temp]++;//NAHI TOH DAALDO AAGE KE LIYE...
            temp = temp->next;//agar Last tak pohcha toh
        }
        return NULL;
    }
};