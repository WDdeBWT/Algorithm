#include <stdio.h>
#include <malloc.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int main()
{
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag_carry = 0;
    struct ListNode *head, *l3;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = head;
    l3->val = ((l1->val)+(l2->val))%10;
    if ((l1->val)+(l2->val) >= 10)
        flag_carry = 1;
    else
        flag_carry = 0;
    l1=l1->next;
    l2=l2->next;
    while (l1||l2)
    {
        if (l1&&l2)
        {
            l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            l3 = l3->next;
            l3->val = ((l1->val)+(l2->val)+flag_carry)%10;
            if ((l1->val)+(l2->val)+flag_carry >= 10)
                flag_carry = 1;
            else
                flag_carry = 0;
            l1=l1->next;
            l2=l2->next;
        }
        else if (l1 == NULL)
        {
            while (l2)
            {
                l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                l3 = l3->next;
                l3->val = ((l2->val) + flag_carry)%10;
                if ((l2->val) + flag_carry >= 10)
                    flag_carry = 1;
                else
                    flag_carry = 0;
                l2=l2->next;
            }
        }
        else if (l2 == NULL)
        {
            while (l1)
            {
                l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                l3 = l3->next;
                l3->val = ((l1->val) + flag_carry)%10;
                if ((l1->val) + flag_carry >= 10)
                    flag_carry = 1;
                else
                    flag_carry = 0;
                l1=l1->next;
            }
        }
    }
    if (flag_carry == 1)
    {
        l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->val = 1;
    }
    l3->next = NULL;
    return head;
}