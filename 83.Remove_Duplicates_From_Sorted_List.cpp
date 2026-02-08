struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *cur = head;
        while(cur->next) {
            if(cur->next->val == cur->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;    //注意：删除节点之后不要遍历下一个节点，因为可能再下一个节点的值也相等，所以记得加上else.
        }
        return head;
    }
};