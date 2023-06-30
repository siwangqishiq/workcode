#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == nullptr){
        return head;
    }

    vector<ListNode *> nodeList;
    ListNode *p = head;
    while(p != nullptr){
        nodeList.push_back(p);
        p = p->next;
    }//end while

    ListNode *newHead;
    for(int i = nodeList.size() - 1 ; i >= 0 ;i--){
        auto node = nodeList[i];
        if(i == nodeList.size() - 1){
            newHead = node;
        }

        node->next = nullptr;
        if(i > 0){
            node->next = nodeList[i - 1];
        }
    }//end for i
    return newHead;
}

void printList(ListNode *head){
    ListNode *p = head;
    while(p != nullptr){
        cout << p->val << "  ";
        p = p->next;
    }//end while
    cout << endl;
}

int main(){

    ListNode n0(1);
    ListNode n1(2);
    ListNode n2(3);
    ListNode n3(4);
    ListNode n4(5);

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = nullptr;

    auto head = reverseList(&n0);
    printList(head);

    return 0;
}

