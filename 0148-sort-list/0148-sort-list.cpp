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
    ListNode* sortList(ListNode* head) {
        // Extract values to vector
        vector<int> vals;
        ListNode* curr = head;
        while (curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        
        // Sort values
        sort(vals.begin(), vals.end());
        
        // Rebuild linked list
        ListNode dummy(0);
        curr = &dummy;
        for (int val : vals) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        
        return dummy.next;
    }
};