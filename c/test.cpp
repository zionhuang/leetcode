// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     long a,b;
//     struct ListNode* pt1 = l1;
//     struct ListNode* pt2 = l2;
//     a = pt1->val;
//     b = pt2->val;
//     while(true) {
//         pt1 = pt1->next;
//         if(pt1 == NULL) {
//             break;
//         } else {
//             a = a * 10 + pt1->val;
//         }
//     }
//     while(true) {
//         pt2 = pt2->next;
//         if(pt2 == NULL) {
//             break;
//         } else {
//             b = b * 10 + pt2->val;
//         }
//     }
//     long c = a + b;
//     struct ListNode* head = NULL;
//     while(true) {
//         struct ListNode* cur = (struct ListNode *) malloc(sizeof(struct ListNode));
//         cur->val = c % 10;
//         cur->next = head;
//         head = cur;
//         c = c / 10;
//         if(c <= 0) {
//             break;
//         }
//     }
//     return head;
// }

#include<stdio.h>
int main() {
    printf("hello\n");
    return 0;
}