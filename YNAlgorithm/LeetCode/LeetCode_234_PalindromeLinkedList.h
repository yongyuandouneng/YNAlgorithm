//
//  LeetCode_234.h
//  YNLeetCode
//
//  Created by ZYN on 2018/12/19.
//  Copyright © 2018 yongneng. All rights reserved.
//  LeetCode 判断是否是回文链表 最优解是 时间 O(n) 空间 O(1)

#import <Foundation/Foundation.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define MAX_ITEMS 1000000
#define STACK_EMPTY -1

typedef int valueType;

typedef struct {
    valueType top;
    unsigned capacity;
    valueType *array;
} Stack;

/// 创建栈
Stack *createStack(unsigned capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack -> top = STACK_EMPTY;
    stack -> capacity = capacity;
    stack -> array = (valueType *)malloc(stack->capacity *sizeof(valueType));
    return stack;
}

/// 判断栈满
valueType isFull(Stack *stack) { return stack -> top == stack -> capacity - 1; }

/// 判断栈空
valueType isEmpty(Stack *stack) { return stack -> top == -1; }

/// 入栈
void push(Stack *stack, valueType item) {
    if (isFull(stack)) return;
    stack -> array[++stack -> top] = item;
}

/// 出栈
valueType pop(Stack *stack) {
    if (isEmpty(stack)) return STACK_EMPTY;
    return stack -> array[stack -> top --];
}

bool isPalindromeForStack(struct ListNode *head) {
    /// 参数校验
    if (head == NULL || head -> next == NULL) return true;
    /// 创建栈
    Stack *stack = createStack(MAX_ITEMS);
    struct ListNode *slow = head, *fast = head;
    
    /// 快慢指针移动 push 入栈
    while (fast && fast -> next) {
        push(stack, slow -> val);
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    /// fast 不为空说明 链表是 奇数 需要把慢指针往前面移动一位
    /// fast 为空说明是 链表 是偶数 位置刚刚好 在右边的第一个位置
    if (fast) {
        slow = slow -> next;
    }
    
    while (slow) {
        if (pop(stack) != slow -> val) return false;
        slow = slow -> next;
    }
    
    return true;
}

typedef struct {
    int data[100000];
    int top;
} StackK;

/// 快慢指针 逆指针 折半对比 实现 时间 O(n) 空间 O(1)
bool isPalindrome (struct ListNode *head) {
    if (head == NULL || head -> next == NULL) return true;
    struct ListNode *slowNode = head, *fastNode = head, *preNode = NULL;
    while(fastNode && fastNode -> next) {
        fastNode = fastNode -> next -> next;
        struct ListNode *next = slowNode -> next;
        slowNode -> next = preNode;
        preNode = slowNode;
        slowNode = next;
    }
    
    if (fastNode) {
        slowNode = slowNode -> next;
    }
    
    while (slowNode) {
        if (preNode -> val != slowNode -> val) return false;
        preNode = preNode -> next;
        slowNode = slowNode -> next;
    }
    return true;
}

/// 快慢指针 栈 实现 时间 O(n) 空间 O(n)
bool isPalindromeForMyStack (struct ListNode *head) {
    if (head == NULL || head -> next == NULL) return true;
    StackK *stack = (StackK *)malloc(sizeof(StackK));
    stack -> top = -1;
    struct ListNode *slowNode = head, *fastNode = head;
    while (slowNode) {
        if (fastNode) {
            fastNode = fastNode -> next;
            if (fastNode) {
                stack -> data[++ stack -> top] = slowNode -> val;
                fastNode = fastNode -> next;
            }
        } else {
            if(stack -> data[stack -> top] != slowNode -> val) return false;
            stack -> top --;
        }
        slowNode = slowNode -> next;
    }
    return true;
}

/// 数组遍历 时间 O(n) 空间 O(n)
bool isPalindromeForArray(struct ListNode *head) {
    struct ListNode *p = head;
    if (!p) return true;
    int arr[100000];
    int i = 0, count = 0;
    while (p) {
        arr[i] = p -> val;
        p = p -> next;
        i++;
    }
    if (i == 0) return false;
    count = i;
    int j = count - 1;
    for (int i = 0; i < count; i++) {
        if (i >= j) {
            return true;
        }
        if (arr[i] != arr[j]) {
            return false;
        }
        j--;
    }
    return false;
}


/// 回文字符串
bool palindromeString (char str[]) {
    int len = strlen(str);
    if (len == 1) return false;
    int i = 0;
    int j = len - 1;
    
    for (i = 0; i < len; i++) {
        if (i >= j) {
            return true;
        }
        char head = str[i];
        char tail = str[j];
        if (head != tail) {
            return false;
        }
        j--;
    }
    return false;
}
