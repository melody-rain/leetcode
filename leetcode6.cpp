#include <iostream>
#include <stack>
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
        if (!head || !head->next || !head->next->next)
            return;

        stack<ListNode*> s;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow->next != NULL) 
        {
            s.push(slow->next);
            slow = slow->next;
        }

        ListNode *h1 = head;
        if (fast->next == NULL) 
        {
            while (!s.empty()) 
            {
                ListNode *cur = s.top();
                s.pop();
                cur->next = h1->next;
                h1->next = cur;
                h1 = cur->next;
            }
            h1->next = NULL;
            return;
        }
        else 
        {
            while (!s.empty()) {
                ListNode *cur = s.top();
                s.pop();
                if (s.empty()) {
                    cur->next = NULL;
                    h1->next = cur;
                    return;
                }
                else {
                    cur->next = h1->next;
                    h1->next = cur;
                    h1 = cur->next;
                }
            }
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
    in1->next = in2;
    in2->next = in3;
    in3->next = in4;
    in4->next = in5;
    in5->next = in6;

    Solution mySolution;
    mySolution.reorderList(in0);
    for (int i = 0; i < 7; i++, in0 = in0->next)
    {
        printf("%d\n", in0->val);
    }
}
