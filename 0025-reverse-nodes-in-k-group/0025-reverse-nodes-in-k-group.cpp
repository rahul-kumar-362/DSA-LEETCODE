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
public://BRUTE FORCE...
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*>st;
        ListNode*temp = head;
        ListNode* ans = new ListNode(0);//dummy Node...
        ListNode*temp2 = ans;
        int curr = 0;
        while(temp){
            curr++;
            st.push(temp);
            temp = temp->next;
            if(curr == k){
                curr = 0;//reinitialise
                while(!st.empty()){
                    temp2->next = st.top();
                    temp2 = st.top();
                    st.pop();
                }
            }
        }
        //LAST MAI ADD sidha sidha
        stack<ListNode*>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()){
            temp2->next = st2.top();
            temp2 = st2.top();
            st2.pop();
        }
        temp2->next = NULL;//TAAKI LAST MAI PROBLEM NA AAYE...
        return ans->next;
    }
};