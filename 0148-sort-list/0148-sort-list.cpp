/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*splitAtMid(ListNode* head)
    {
      ListNode*fast=head;
      ListNode*slow=head;
      ListNode*prev=NULL;
      while(fast!=NULL && fast->next!=NULL)
      {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
      }
      if(slow!=NULL)
      {
        prev->next=NULL;
      }
      return slow;//at mid
    }
    
    ListNode*merge(ListNode*left,ListNode*right){
        ListNode dummy(0);//creates a dummy node with value 0
        ListNode* tail = &dummy;
        while(left!=NULL && right!=NULL){//while(left && right)bhi chalega
            if(left->val<=right->val){
                tail->next=left;
                left=left->next;
            }
            else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        if(left!=NULL){
            tail->next=left;//attach full remaining part
        }
        if(right!=NULL){
            tail->next=right;//attach full remaining part
        }
        return dummy.next;
        //dummy.next	Access member when dummy is an object ✅
    }
    ListNode* sortList(ListNode* head) {
        //merge sort 
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*rightHead=splitAtMid(head);
        ListNode*left=sortList(head);//recursion
        ListNode*right=sortList(rightHead);
        return merge(left,right);
    }
};