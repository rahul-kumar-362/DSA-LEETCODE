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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=1;//1st node already count karli


        ListNode*temp=head;

        if(head==NULL || head->next==NULL)return head; 
       
        while( temp->next!=NULL  ){
            n++;
            temp=temp->next;
        }
        // n=n+1;


        k=k%n;
        ListNode*temp2=head;
        int k2=n-k;
        while(k2>1){
            temp2=temp2->next;
            k2--;
        }


        temp->next=head;

        //ListNode* bhai=temp2->next;
        head=temp2->next;
        temp2->next=NULL;




        return head;









    }
};