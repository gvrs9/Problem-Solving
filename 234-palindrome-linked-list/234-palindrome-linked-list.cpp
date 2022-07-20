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
    ListNode* reverse(ListNode* tempHead) {
        ListNode* prev = __null;
        ListNode* curr = tempHead;
        ListNode* forward = tempHead;
        
        while(curr != __null) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != __null && fast -> next != __null) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        if(fast == __null) cout << "even nodes";
        else cout << "odd nodes";
        // if(fast -> next == __null) cout << "odd nodes"; // this stmt only works when odd nodes are there otherwise will give error as null doesn't have next to point!!
        // else cout << "even nodes";
        
        // for odd nodes, fast will not be "NULL". Instead, fast -> next is "NULL"!! And for even, it is vice-versa!!
        if(fast != __null) slow = slow -> next;
        
        slow = reverse(slow);
        fast = head;
        
        while(slow != __null) {
            if(slow -> val != fast -> val) return false;
            slow = slow -> next, fast = fast -> next;
        }
        return true;
    }
};