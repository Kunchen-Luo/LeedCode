struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val): val(val), next(nullptr) {}
};

//主要矛盾: 1. 非环形链表必然存在空指针; 2.如果链表成环，快指针必然追上慢指针
class Floyd_cycle_detection_algorithm_Solution {    
    public:
        bool hasCycle(ListNode *head) {
            if(!head || !head->next)    //先判断起始位置是否为空
                return false;
            ListNode *fast = head->next;
            ListNode *slow = head;  //因为循环条件先于循环体执行，如果两个指针在同一起点会导致提前退出循环，所以让慢指针先走
            while(fast != slow) {
                if(!fast || !fast->next)    //注意判断快指针步长内的指针是否存在空指针
                    return false;
                fast = fast->next->next;    //快指针一次走两步
                slow = slow->next;
            }
            return true;
        }
};