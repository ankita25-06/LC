/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode temp;
    struct ListNode* res = &temp;
    int carry = 0;
    int total = 0;
    while(l1 != NULL || l2!= NULL || carry){
        total = carry;
        if(l1){
            total += l1->val;
            l1 = l1->next;
        }
        if(l2){
            total += l2->val;
            l2 = l2->next;
        }
        carry = total/10;
        res->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        res = res->next;
        res->val = total % 10;
        res->next = NULL;
    }

    return temp.next;
}