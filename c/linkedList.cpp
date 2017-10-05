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
    // 
    return l1;
}

int main() {
    int index1 = 4,index2 = 3;
    int a[] = {7,2,4,3};
    int b[] = {5,6,4};
    struct ListNode* l1 = createListByArray(a, index1);
    struct ListNode* l2 = createListByArray(b, index2);
    struct ListNode* res = addTwoNumbers(l1, l2);
    printList(res);
    return 0;
}