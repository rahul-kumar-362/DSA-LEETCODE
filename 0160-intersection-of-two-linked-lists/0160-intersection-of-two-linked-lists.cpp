/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public://BETTER SOLN... ITERATIVE...
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;

        int count1 = 0;
        int count2 = 0;
        while(temp1){
            count1++;
            temp1  = temp1->next;
        }
        while(temp2){
            count2++;
            temp2  = temp2->next;
        }
        int d = abs(count1 - count2);//differnce hi toh lena hai...
        
        temp1 = headA;//REUSING THE PTRs
        temp2 = headB;
        if(count1>count2){
            while(d--){
                temp1 = temp1->next;
            }
        }
        else if(count2>count1){
            while(d--){
                temp2 = temp2->next;
            }
        }
        
        while(temp1 && temp2){
            if(temp1 == temp2)return temp1;//MILGAYA PEHLA NODE
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};