#include <iostream>

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            return l2;
        }

        if (!l2)
        {
            return l1;
        }

        if (!l1 && !l2)
        {
            return NULL;
        }

        int carry = 0;
        int val = 0;
        ListNode *head = new ListNode(0);
        ListNode *outputHead = head;
        int l1Val = 0;
        int l2Val = 0;
        while(l1 || l2)
        {
            if (l1)
            {
                l1Val = l1->val;
            }
            else
            {
                l1Val = 0;
            }

            if (l2)
            {
                l2Val = l2->val;
            }
            else
            {
                l2Val = 0;
            }

            val = l1Val + l2Val + carry;
            if (val > 9)
            {
                val = val - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ListNode *node = new ListNode(val);
            head->next = node;
            head = head->next;

            if (l1)
            {
                l1 = l1->next;
            }

            if (l2)
            {
                l2 = l2->next;
            }

            if (!l1 && !l2 && carry)
            {
                ListNode *node1 = new ListNode(carry);
                head->next = node1;
            }

        }

        return outputHead->next;
    }
};

int main()
{
    Solution mySolution;
    
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);

     n0->next = n1;
     n1->next = n2;

    ListNode *m0 = new ListNode(9);
    ListNode *m1 = new ListNode(9);
    ListNode *m2 = new ListNode(9);

    m0->next = m1;
    m1->next = m2;

    ListNode *output = mySolution.addTwoNumbers(n0, m0);
    while (output)
    {
        printf("%d ", output->val);
        output = output->next;
    }

    printf("\n");
}