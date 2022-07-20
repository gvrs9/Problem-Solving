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
private:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        if(curr == __null) {
            head = prev;
            return;
        }
        
        ListNode* forward = curr -> next;
        reverse(head, forward, curr);
        curr -> next = prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // Recursive Approach
        if(head == __null || head -> next == __null) return head;
        ListNode* prev = __null;
        ListNode* curr = head;
        
        reverse(head, curr, prev);
        return head;
    }
};

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative Approach
        
        ListNode* prev = __null;
        ListNode* curr = head;
        ListNode* forward = __null;
        
        while(curr != __null) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};
*/