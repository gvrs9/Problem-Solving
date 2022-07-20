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
    void print(ListNode* &head) {
        ListNode* temp = head;
        while (temp != __null) cout << temp -> val << " -> ", temp = temp -> next;
        cout << "null" << "\n";
    }
public:
    bool isPalindrome(ListNode* head) {
        // Find middle while reversing the first half and check!! --> order of oroginal LL is restored after disturbing it. For more reference, go to the attached link
        // https://leetcode.com/problems/palindrome-linked-list/discuss/64500/11-lines-12-with-restore-O(n)-time-O(1)-space/117753
        if(head == __null) return true;
        ListNode* slow = head; // slow is basically curr!!
        ListNode* fast = head;
        ListNode* prev = __null;
        ListNode* forward = head;
        
        while(fast != __null && fast -> next != __null) {
            forward = slow -> next;
            fast = fast -> next -> next;
            slow -> next = prev;
            prev = slow;
            // slow = slow -> next;
            slow = forward; // same as above commented line!!
        }
        ListNode* tail = __null; // __null or head or uninitialised
        if(fast != __null) tail = slow -> next;
        else tail = slow;
        // cout << slow -> val << "\n";
        
        while(prev != __null) {
            if(tail -> val != prev -> val) return false;
            ListNode* temp = slow;
            slow = prev;
            tail = tail -> next;
            prev = prev -> next;
            slow -> next = temp;
        }
        
        // print(head);
        return true;
    }
};


/*
ListNode* tail = __null; // __null or head or uninitialised
        if(fast != __null) tail = slow -> next;
        else tail = slow;
        
        while(prev != __null) {
            if(tail -> val != prev -> val) return false;
            ListNode* temp = slow, slow = prev,
            tail = tail -> next, prev = prev -> next, slow -> next = temp;
        }
*/

/*
// Find middle while reversing the first half and check!! --> order of oroginal LL is disturbed. For more reference, go to the attached link's dry run diagram and see as to why and how.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Find middle while reversing the first half check!!
        // https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow
        if(head == __null) return true;
        ListNode* slow = head; // slow is basically curr!!
        ListNode* fast = head;
        ListNode* prev = __null;
        ListNode* forward = head;
        
        while(fast != __null && fast -> next != __null) {
            fast = fast -> next -> next;
            forward = slow -> next;
            slow -> next = prev;
            prev = slow;
            // slow = slow -> next;
            slow = forward; // same as above commented line!!
        }
        if(fast != __null) slow = slow -> next;
        
        while(slow != __null) {
            if(slow -> val != prev -> val) return false;
            slow = slow -> next, prev = prev -> next;
        }
        return true;
    }
};

*/

/*
// Find middle, reverse Last half and check!! --> order of the original LL is disturbed!!

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
        // Find middle, reverse Last half and check!!
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
*/