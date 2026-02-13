struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(nullptr) {};
};

class Solution_Of_iteration1 {
public:
    ListNode* reverseList(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        while(head->next) {
            ListNode *insertnode = head->next;
            head->next = insertnode->next;
            insertnode->next = dummy->next;
            dummy->next = insertnode;
        }
        return dummy->next;
    }
};

class Solution_Of_iteration2 {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};