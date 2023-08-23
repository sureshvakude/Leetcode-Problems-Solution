/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying 
the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
} ListNode;

ListNode* AddNode(ListNode* head, int val){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return head;
    }
    ListNode* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

void Display(ListNode* head){
    if(head == NULL){
        cout<<"null";
        return;
    }
    ListNode* ptr = head;
    while(ptr->next != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<ptr->val;
    return;
}

ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* curr = head, *nxt=head->next;
        while(true){
            swap(curr->val,nxt->val);
            if(!(nxt->next && nxt->next->next)) break;
            curr = curr->next->next;
            nxt = nxt->next->next;
        }
        return head;
}

int main(){
    ListNode* head = NULL;
    head = AddNode(head,15);
    head = AddNode(head,1);
    head = AddNode(head,2);
    head = AddNode(head,5);
    head = AddNode(head,9);
    head = swapPairs(head);
    Display(head);
    return 0;
}