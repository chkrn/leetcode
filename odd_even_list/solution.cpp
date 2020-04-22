// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/784/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(!head || !head->next)
            return head;

        auto oddEnd = head;
        auto evenHead = head->next;
        auto evenEnd = head->next;

        auto cur = head->next;
        bool isOdd = true;
        while(cur = cur->next) {
            if(isOdd) {
                oddEnd->next = cur;
                oddEnd = cur;
            } else {
                evenEnd->next = cur;
                evenEnd = cur;
            }

            isOdd = !isOdd;
        }

        oddEnd->next = evenHead;
        evenEnd->next = NULL;

        return head;
    }
};
