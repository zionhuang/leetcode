#include<stdio.h>
#include<malloc.h>

//链表结构体定义
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createListByArray(int a[], int len) {
    int i=1;
    struct ListNode* head;
    head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = a[0];
    struct ListNode* pt = head;
    while(i < len) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = a[i];
        temp->next = NULL;
        pt->next = temp;
        pt = pt->next;
        i++;
    }
    return head;
}

void printList(struct ListNode* l) {
    while(l) {
        printf("%d=>",l->val);
        l = l->next;
    }
    printf("null\n");
}

int lenOfList(struct ListNode *l)
{
    struct ListNode *pt = l;
    int count = 0;
    while (pt != NULL)
    {
        count++;
        pt = pt->next;
    }
    return count;
}

struct ListNode* reverseList(struct ListNode *l)
{
    struct ListNode *pre = NULL;
    while (l != NULL)
    {
        struct ListNode *temp = l->next;
        l->next = pre;
        pre = l;
        l = temp;
    }
    l = pre;
    return l;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int len1 = lenOfList(l1);
    int len2 = lenOfList(l2);
    if (len1 < len2)
    {
        struct ListNode *temp = l1;
        l1 = l2;
        l2 = temp;
    }
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    printList(l1);
    printList(l2);
    int carry = 0;
    int temp;
    struct ListNode *head1 = l1;
    struct ListNode *head2 = l2;
    while (head2)
    {
        temp = head1->val + head2->val + carry;
        carry = temp / 10;
        head1->val = temp % 10;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(carry && head1) {
        temp = head1->val + carry;
        carry = temp / 10;
        head1->val = temp % 10;
        head1 = head1->next;
    }
    l1 = reverseList(l1);
    if(carry) {
        struct ListNode* newHead = (struct ListNode*) malloc(sizeof(struct ListNode));
        newHead->val = 1;
        newHead->next = l1;
        l1 = newHead;
    }
    return l1;
}

// 这个题目理解错了，下面现在求的是，如果链表的第一个是奇数，那么按原来的相对顺序排列：奇数奇数。。。偶数偶数。。。
// 如果第一个是偶数，就排列成：偶数偶数。。。奇数奇数
struct ListNode* oddEvenList(struct ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    if(head->val%2 != 0) {
        struct ListNode* oddHead = head;
        struct ListNode* oddTail = head;
        struct ListNode* evenHead = NULL;
        struct ListNode* evenTail = NULL;
        while(oddTail->next != NULL) {
            if(oddTail->next->val%2 == 0) {
                if(evenHead == NULL) {
                    evenHead = oddTail->next;
                    evenTail = oddTail->next;
                } else {
                    evenTail->next = oddTail->next;
                    evenTail = evenTail->next;
                }
                while (evenTail->next != NULL)
                {
                    if (evenTail->next->val % 2 == 0)
                    {
                        evenTail = evenTail->next;
                    }
                    else
                    {
                        break;
                    }
                }
                oddTail->next = evenTail->next;
                evenTail->next = NULL;
                if(oddTail->next != NULL) {
                    oddTail = oddTail->next;
                }
            } else {
                oddTail = oddTail->next;
            }
        }
        oddTail->next = evenHead;
        return oddHead;
    } else{
        struct ListNode *evenHead = head;
        struct ListNode *evenTail = head;
        struct ListNode *oddHead = NULL;
        struct ListNode *oddTail = NULL;
        while (evenTail->next != NULL)
        {
            if (evenTail->next->val % 2 != 0)
            {
                if (oddHead == NULL)
                {
                    oddHead = evenTail->next;
                    oddTail = evenTail->next;
                }
                else
                {
                    oddTail->next = evenTail->next;
                    oddTail = oddTail->next;
                }
                while (oddTail->next != NULL)
                {
                    if (oddTail->next->val % 2 != 0)
                    {
                        oddTail = oddTail->next;
                    }
                    else
                    {
                        break;
                    }
                }
                evenTail->next = oddTail->next;
                oddTail->next = NULL;
                if (evenTail->next != NULL)
                {
                    evenTail = evenTail->next;
                }
            }
            else
            {
                evenTail = evenTail->next;
            }
        }
        evenTail->next = oddHead;
        return evenHead;
    }
}

ListNode *oddEvenListTrue(ListNode *head)
{
    if (!head)
        return head;
    ListNode *odd = head, *evenhead = head->next, *even = evenhead;
    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
    return head;
}

struct ListNode* oddEvenListMy(struct ListNode* head)
{
    if(head == NULL) {
        return head;
    }
    struct ListNode* odd = head;
    struct ListNode* evenHead = head->next;
    struct ListNode* even = evenHead;
    while(even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    int index1 = 7;
    // int index2 = 3;
    int a[] = {1,7,3,4,5,6,8};
    // int b[] = {5,6,4};
    struct ListNode* l1 = createListByArray(a, index1);
    printList(l1);
    l1 = oddEvenListMy(l1);
    printList(l1);
    return 0;
}