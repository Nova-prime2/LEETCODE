
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> s;

        while (list1) {
            s.push_back(list1->val);
            list1 = list1->next;
        }

        while (list2) {
            s.push_back(list2->val);
            list2 = list2->next;
        }

        sort(s.begin(), s.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for (int i = 0; i < s.size(); i++) {
            temp->next = new ListNode(s[i]);
            temp = temp->next;
        }

        return dummy->next;
    }
};
