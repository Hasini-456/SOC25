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
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> s;

        // ListNode* node = head;
        // while(node){
        //     if(s.find(node) != s.end()) return true;
        //     s.insert(node);
        //     node = node->next;
        // }
        // return false;

        ListNode* a = head;
        ListNode* b = head;
        while(b && b->next){
            a = a->next;
            b = b->next->next;
            if(a == b) return true;
        }
        return false;
    }
};