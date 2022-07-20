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
    ListNode* middleNode(ListNode* head) {
        if(head == __null || head -> next == __null) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != __null && fast -> next != __null) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
};

/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        
        while(curr != __null) len++, curr = curr -> next;
        int middle = len / 2;
        
        while(middle--) head = head -> next;
        return head;
    }
};
*/