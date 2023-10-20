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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode *dummy = new ListNode(0,head);
        ListNode *prev = dummy;
        ListNode *curr = head;

        ListNode *nextPair=NULL;
        ListNode *second=NULL;

        while(curr!=NULL && curr->next!=NULL){
            //save pointers
            nextPair=curr->next->next;
            second=curr->next;

            // reverse this pair
            second->next=curr;
            curr->next=nextPair;
            prev->next=second;

            // update pointers
            prev=curr;
            curr=nextPair;
        }
        return dummy->next;
    }
};