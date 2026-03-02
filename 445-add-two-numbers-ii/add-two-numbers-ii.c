/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int s1[1000], s2[1000];
    int top1 = -1, top2 = -1;

    // Push l1 values into stack
    while (l1) {
        s1[++top1] = l1->val;
        l1 = l1->next;
    }

    // Push l2 values into stack
    while (l2) {
        s2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* head = NULL;

    // Add while stack not empty or carry exists
    while (top1 >= 0 || top2 >= 0 || carry) {

        int sum = carry;

        if (top1 >= 0)
            sum += s1[top1--];

        if (top2 >= 0)
            sum += s2[top2--];

        carry = sum / 10;

        // create new node
        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;

        // insert at front
        newNode->next = head;
        head = newNode;
    }

    return head;
}