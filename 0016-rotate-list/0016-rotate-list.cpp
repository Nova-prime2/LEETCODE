
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int len = 1;

        while (temp->next != nullptr) {
            temp = temp->next;
            len++;
        }

        k = k % len;
        if (k == 0)
            return head;

        temp->next = head;  

        temp = head;
        for (int i = 1; i < len - k; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = nullptr;  

        return newHead;
    }
};
