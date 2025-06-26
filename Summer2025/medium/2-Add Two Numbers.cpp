using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* current = result;
        ListNode* end = current;
        int carry = 0;
        while(l1 && l2) {
            current->val = l1->val + l2->val + carry;
            if(current->val >= 10) {
                carry = current->val/10;
                current->val = current->val % 10;
            }
            else {
                carry = 0;
            }
            end = current;
            current->next = new ListNode(-1);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            current->val = l1->val + carry;
            if(current->val >= 10) {
                carry = current->val/10;
                current->val = current->val % 10;
            }
            else {
                carry = 0;
            }
            end = current;
            current->next = new ListNode(-1);
            current = current->next;
            l1 = l1->next;
        }
        while(l2) {
            current->val = l2->val + carry;
            if(current->val >= 10) {
                carry = current->val/10;
                current->val = current->val % 10;
            }
            else {
                carry = 0;
            }
            end = current;
            current->next = new ListNode(-1);
            current = current->next;
            l2 = l2->next;
        }
        if(carry > 0) {
            current->val = carry;
        }
        else {
            end->next = nullptr;
        }
        return result;
    }
};