# Намиране на среден елемент в едносвързан списък

```c++
ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        if (slow == nullptr || slow->next == nullptr) {
            return head;
        }
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }
```

Задачи в час:   https://leetcode.com/problem-list/awvsu9dt/
