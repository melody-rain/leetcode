#include <iostream>
using namespace std;

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
    ListNode *sortList(ListNode *head) {

        if (!head)
            return NULL;

        int minimum;

        ListNode *p1 = NULL;
        ListNode *pre = NULL;

        ListNode *temp = head->next;
        ListNode *minNode = head->next;
        ListNode *tempHead = head;

        bool isMin = true;
        bool findflag = false;
        while (temp)
        {
            minimum = temp->val;

            while (temp->next)
            {
                if (minimum > temp->next->val)
                {
                    minimum = temp->next->val;
                    minNode = temp->next;
                    pre = temp;
                    findflag = true;
                }

                temp = temp->next;
            }

            if (findflag)
            {
                pre->next = minNode->next;

                p1 = tempHead->next;
                tempHead->next = minNode;
                minNode->next = p1;
            }

            tempHead = tempHead->next;
            temp = tempHead->next;

            if (isMin)
            {
                head->next = minNode;
                isMin = false;
            }

            findflag = false;
        }

        return head;

    }
};

int main()
{
    ListNode in0(5);
    ListNode in1(9);
    ListNode in2(8);
    ListNode in3(10);
    ListNode in4(4);
    ListNode in5(1);

    in0.next = &(in1);
    in1.next = &(in2);
    in2.next = &(in3);
    in3.next = &(in4);
    in4.next = &(in5);

    ListNode *head = new ListNode(0);
    head->next = &(in0);

    Solution mySolution;
    ListNode* output = mySolution.sortList(head);
    for (int i = 0; i < 6; i++, output = output->next)
    {
        printf("%d\n", output->next->val);
    }
}
