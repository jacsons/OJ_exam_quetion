// #### 题目描述
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// #### 本题答案
// https://leetcode-cn.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 两数相加
// 链表异常相加，会出现三种情况

// 1、没有进位，长度为传入长度
// 2、刚刚好有一个进位，那多申请一个长度在尾部
// 3、两个长度差距很大，这进位后 +0；

// 函数设计
// 传入数据 两个链表
// 1、两者先相加
// 2、判断最后一个是否大于10，大于记录，进行尾部处理
// 3、返回


/*
*  申请新的node
*/
struct ListNode* mallocListNode()
{
    struct ListNode* result = NULL;

    result = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (result == NULL) {
        return NULL;
    }

    result = memset(result, 0, sizeof(struct ListNode));
    if (result == NULL) {
        return NULL;
    }

    return result;
}

struct ListNode* processTailValue(struct ListNode *resultListNode, int preValue)
{
    if (preValue > 0) {
        resultListNode->next = mallocListNode();
        resultListNode = resultListNode->next;
        resultListNode->val = preValue; 
    }

    return resultListNode;
}

struct ListNode* processTail(struct ListNode *resultListNode, struct ListNode* inpuListNode, int preValue)
{
    struct ListNode *firstInputNext = NULL;
    int twoNodeSum = preValue;
   
    firstInputNext = inpuListNode;
    while (firstInputNext != NULL)
    {
        resultListNode->next = mallocListNode();
        resultListNode = resultListNode->next;
        twoNodeSum = twoNodeSum + firstInputNext->val;
        resultListNode->val = twoNodeSum % 10; 
        twoNodeSum = (twoNodeSum - resultListNode->val) / 10;
        
        firstInputNext = firstInputNext->next;
    }
    
    processTailValue(resultListNode, twoNodeSum);

    return resultListNode;
}

struct ListNode* processTwoLinkAdd(struct ListNode* l1, struct ListNode* l2)
{
    int twoNodeSum = 0;
    struct ListNode *resultListNode = NULL;
    struct ListNode *resultHead = NULL;
    struct ListNode *firstInputNext = NULL;
    struct ListNode *lastInputNext = NULL;

    firstInputNext = l1;
    lastInputNext = l2;

    resultHead = mallocListNode();
    resultListNode = resultHead;
    while (firstInputNext != NULL && lastInputNext != NULL)
    {
       resultListNode->next = mallocListNode();
       resultListNode = resultListNode->next;
       twoNodeSum = twoNodeSum + firstInputNext->val + lastInputNext->val;
       resultListNode->val = twoNodeSum % 10;
       twoNodeSum = (twoNodeSum - resultListNode->val) / 10;

       firstInputNext = firstInputNext->next;
       lastInputNext = lastInputNext->next;
    };

    if (firstInputNext != NULL || lastInputNext != NULL) {
       if (firstInputNext != NULL) {
           processTail(resultListNode, firstInputNext, twoNodeSum);
       } else {
           processTail(resultListNode, lastInputNext, twoNodeSum);
       } 
    } else
    {
         processTailValue(resultListNode, twoNodeSum);
    }
    
    // 去除头结点
    resultListNode = resultHead->next;
    free(resultHead);

    return resultListNode;
}

// main function
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }
    // process two list add
    return processTwoLinkAdd(l1, l2);
}

