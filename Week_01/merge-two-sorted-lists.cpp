// 题目描述
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode* lBegin = NULL;
        ListNode* lEnd = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode* lTmp = NULL;
            if (l1->val < l2->val)
            {
                lTmp = l1;
                l1 = l1->next;
            }
            else
            {
                lTmp = l2;
                l2 = l2->next;
            }
            if (lBegin == NULL)
            {
                lBegin = lTmp;
                lEnd = lTmp;
            }
            else
            {
                lEnd->next = lTmp;
                lEnd = lEnd->next;
            }
        }
        if (l1 != NULL)
        {
            lEnd->next = l1;
        }
        if (l2 != NULL)
        {
            lEnd->next = l2;
        }
        return lBegin;
    }
};

// 两个链表一起从头遍历即可，注意判空
