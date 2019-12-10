/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode processDoubleLinkAdd(struct ListNode *head, struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *first, *next;
    struct ListNode *resultListNode = NULL;

     // init
    head = resultListNode;
    first = l1;
    next = l2;

    while (first != NULL && next != NULL)
    {
         resultListNode->val = first->val + next->val + pre;
         pre = resultListNode->val / 10;
         resultListNode->val = resultListNode->val % 10;
        
         printf("%d pre = %d", resultListNode->val, pre);
         resultListNode->next = (struct ListNode *)malloc(sizeof(struct ListNode)); 
         memset(resultListNode->next, 0x00, sizeof(struct ListNode));
         resultListNode = resultListNode->next;
    };

    return resultListNode;
}


void processTail(struct ListNode *resultListNode, struct ListNode* l1, int preValue)
{
    struct ListNode *current = NULL;
    current = l1;
    do
    {
        resultListNode->val = current->val + preValue;
        resultListNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        preValue = resultListNode->val / 10;
        resultListNode->val = resultListNode->val % 10;
        resultListNode = resultListNode->next;
        current = current->next;
    } while (current->next != NULL);
}


// main function
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head = NULL;
    resultListNode = (struct ListNode *)malloc(sizeof(struct ListNode));

   
    
    if (first->next == NULL && next->next != NULL) {
        return head;
    }

    if (first->next != NULL) {
        processTail(resultListNode, first->next, pre);
    } else {
        processTail(resultListNode, next->next, pre);
    }

    return head;
}