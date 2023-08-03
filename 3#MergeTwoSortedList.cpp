/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Examples:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* nxt;
} Node;

Node* CreateNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->nxt = NULL;
    return newNode;
}

void DisplayList(Node* head){
    if(head==NULL){
        cout<<"NULL";
        return;
    }
    Node* ptr = head;
    while(ptr->nxt!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->nxt;
    }
    cout<<ptr->data;
    return;
}

Node* AddNode(Node* head,int value){
    if(head == NULL){
        Node* newNode = CreateNode(value);
        head = newNode;
        return head;
    }
    else{
        Node* newNode = CreateNode(value);
        Node* ptr = head;
        while(ptr->nxt!=NULL){
            ptr = ptr->nxt;
        }
        ptr->nxt = newNode;
        return head;
    }
}

Node* MergeList(Node* list1, Node* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    Node* head = list1;
    if(list1->data < list2->data){
        list1 = list1->nxt;
    }else{
        head = list2;
        list2 = list2->nxt;
    }

    Node* curr = head;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            curr->nxt = list1;
            list1 = list1->nxt;
        }else{
            curr->nxt = list2;
            list2 = list2->nxt;
        }
        curr = curr->nxt;
    }

    if(list1!=NULL) curr->nxt = list1;
    else curr->nxt = list2;
    return head;
}

int main(){

    Node* list1 = NULL;
    Node* list2 = NULL;

    list1 = AddNode(list1,2);
    list1 = AddNode(list1,3);
    list1 = AddNode(list1,9);
    list1 = AddNode(list1,10);

    list2 = AddNode(list2,4);
    list2 = AddNode(list2,8);
    list2 = AddNode(list2,12);

    cout<<"first list : ";
    DisplayList(list1);
    cout<<"\nSecond list : ";
    DisplayList(list2);

    Node* list3 = MergeList(list1,list2);

    cout<<"\nMerge List : ";
    DisplayList(list3);
    return 0;
}