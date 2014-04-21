#include <iostream>
using namespace std;
//No head pointer in oj.leetcode? the first node containing the testing data should be the head node in the testing system I think. 
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return NULL;
        if (!head->next)
            return head;

        ListNode *createdHead = new ListNode(-1);
        createdHead->next = head;

        ListNode *temp = createdHead->next;
        ListNode *tail = createdHead->next;
        ListNode *bk = NULL;
        ListNode *pre = NULL;
        ListNode *post = NULL;

        while (tail->next)
        {
            if (tail->next->val < createdHead->next->val)
            {
                bk = createdHead->next;
                post = tail->next->next;

                createdHead->next = tail->next;
                tail->next->next = bk;

                tail->next = post;
            }
            else if (tail->next->val >= tail->val)
            {
                tail = tail->next;

            }
            else
            {
                temp = createdHead->next;
                while (1)
                {
                    if (temp->next->val >= tail->next->val && temp->val <= tail->next->val)
                    {
                        pre = temp;
                        post = pre->next;
                        bk = tail->next->next;
                        pre->next = tail->next;
                        tail->next->next = post;
                        tail->next = bk;
                        break;
                    }

                    temp = temp->next;
                }
            }
        }

        return createdHead->next;

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

    ListNode *head = new ListNode(5);
    head->next = &(in0);

    Solution mySolution;
    ListNode* output = mySolution.insertionSortList(head);
    for (int i = 0; i < 7; i++, output = output->next)
    {
        printf("%d\n", output->val);
    }
}
