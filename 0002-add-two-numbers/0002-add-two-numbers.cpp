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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        int carry = 0;

        if(temp1 && temp2){//SABSE PEHLA STORE
           // max toh left DIGIT 1 hi hoga yaha coz 18----
            int num = temp1->val + temp2->val;

            if(num>9){
                carry = num / 10;//YE JO BACHA WO CARRY HOGA
            }
            int  ld = num % 10;//LAST DIGIT LELIYA
            ListNode *newNode1 = new ListNode(ld);

            head = newNode1;//LELIYA HEAD

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ListNode * temp = head;
        while(temp1 || temp2){
            int num = 0;
             if(temp1){
                num+=temp1->val;
                temp1 = temp1->next;
            }
           
            if(temp2){
                num+=temp2->val;
                temp2 = temp2->next;
            }
            
            
            if(carry>0){
                num+=carry;
            }
            
                carry = num / 10;
            
            
            int  ld = num % 10;//LAST DIGIT LELIYA
            ListNode *newNode = new ListNode(ld);
            temp->next = newNode;//temp ke next mai hoga newNode
            temp = newNode;//USSI ko TEMP bana DENGE
           
        }

        if(carry>0){
            ListNode* lastNode= new ListNode(carry);
            temp->next = lastNode;
        }
        return head;
    }
};