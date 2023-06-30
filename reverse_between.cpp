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


void printList(ListNode *head){
    ListNode *p = head;
    while(p != nullptr){
        cout << p->val << "  ";
        p = p->next;
    }//end while
    cout << endl;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == nullptr){
        return head;
    }

    int index = 1;
    ListNode *p = head;
    ListNode *leftPrior =head;
    while(index < left){
        p = p->next;
        index++;
        leftPrior = p;
    }

    ListNode *rightTail = nullptr;
    vector<ListNode *> subList;
    while(index <= right){
        subList.push_back(p);
        index++;
        p = p->next;
        rightTail = p;
    }//end while

    ListNode *newHead = nullptr;
    for(int i = subList.size() - 1 ; i >= 0 ; i--){
        if(newHead == nullptr){
            newHead = subList[i];
        }

        auto p = subList[i];
        p->next = nullptr;
        if(i - 1 >= 0){
            p->next = subList[i - 1];
        }
    }

    if(leftPrior != nullptr){
        leftPrior ->next = newHead;
    }

    if(rightTail != nullptr){
        if(subList.size() > 0){
            ListNode *lastNode = subList[0];
            lastNode->next = rightTail;
        }
    }
    return head;
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

    auto head = reverseBetween(&n0 , 2, 4);
    printList(head);

    return 0;
}

