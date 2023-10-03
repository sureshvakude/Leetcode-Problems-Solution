/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        ListNode* temp = head;
        int size = 1;
        
        while(temp->next != NULL){
            temp = temp->next;
            size++;
        }

        temp->next = head;
        int rotate = k % size;
        int skip = size - rotate;
        ListNode* newLast = head;
        
        for(int i=1; i<skip; i++){
            newLast = newLast->next;    
        }

        head = newLast->next;
        newLast->next=NULL;
        return head;
}

int main(){
    return 0;
}