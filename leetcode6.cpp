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
    void reorderList(ListNode *head)
    {
        if (!head)
            return;
        if (!head->next || !head->next->next)
            return;

        ListNode *tail = head;

        ListNode *temp = head->next;
        ListNode *bak = NULL;
        ListNode *pre = NULL;

        ListNode *pHead = head;

        while (1)
        {
            while (1)
            {
                if (!temp->next->next)
                {
                    tail = temp;
                    pre = temp;
                    break;
                }
                temp = temp->next;
            }

            bak = pHead->next;
            pHead->next = tail->next;
            tail->next->next = bak;
            pre->next = NULL;
            pHead = pHead->next->next;
            temp = pHead->next;
            if (!pHead->next || !temp->next)
                break;
        }
    }
};

int main()
{
    ListNode *in0 = new ListNode(1);
    ListNode *in1 = new ListNode(2);
    ListNode *in2 = new ListNode(3);
    ListNode *in3 = new ListNode(4);
    ListNode *in4 = new ListNode(5);
    ListNode *in5 = new ListNode(6);
    ListNode *in6 = new ListNode(7);
    
    in0->next = in1;
//     in1->next = in2;
//     in2->next = in3;
//     in3->next = in4;
//     in4->next = in5;
//     in5->next = in6;

    Solution mySolution;
    mySolution.reorderList(in0);
    for (int i = 0; i < 2; i++, in0 = in0->next)
    {
        printf("%d\n", in0->val);
    }
}
