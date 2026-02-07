#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution_of_iteration {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);  //dummy是一个“虚拟”头节点，方便操作。记得初始化
        ListNode *tail = &dummy;    //tail指针指向已合并链表的最后一个节点
        while(list1 && list2) {
            if(list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

class Solution_of_recursion {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr)
                return list2;
            else if (list2 == nullptr)
                return list1;
            else if (list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
};
int main(){
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution_of_iteration sol;
    Solution_of_recursion sol2;
    ListNode* mergedList = sol2.mergeTwoLists(list1, list2);
    while (mergedList != nullptr) {
        std::cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    return 0;
}