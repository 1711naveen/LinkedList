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
        if(k==0)
            return head;
        if(head==NULL)
            return NULL;

        ListNode* temp = head;
        ListNode* last = NULL;
        ListNode* q = NULL;
        int count = 0;

        while(temp!=NULL){
            count++;
            last=temp;
            temp=temp->next;
        }
        last->next = head;

        k = k%count;
        count = count - k;

        while(count--){
            q=head;
            head=head->next;
        }
        q->next = NULL;
        return head;
    }
};