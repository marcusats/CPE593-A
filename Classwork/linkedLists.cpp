#include <iostream>

using namespace std;

class LinkedList {
    private: 
    struct Node {
        int val;
        Node* next;
    };

    Node* head;

    public:
    LinkedList() : head(nullptr){


        
    }

    ~LinkedList() {
        //delete every node
    }
    void addFirst(int val) {

        Node* temp = new Node();

        temp->val = val;
        temp->next = head;
        head = temp; 

    }

    void addLast(int val) {
        Node* p;
        for (p = head;p->next != nullptr; p = p->next)
        ;

        Node* temp = new Node();
        temp->val = val;
        temp->next = nullptr;
        p->next = temp;
    }

    void removeLast() {
        //Always check before you remove
        if(head == nullptr){
            return;
        }

        Node* p = head;
        if (head->next== nullptr){
            delete head;
            head = nullptr;
        }
        
        Node* q = p->next;

        for (; q->next != nullptr; p = q, q= q->next)
        ;

        delete q;
        p->next = nullptr;

    }

    void removeFirst() {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    friend ostream& operator <<(ostream& s, const LinkedList& list) {
        for (Node* p = list.head; p !=nullptr; p=p->next){
            s<<p->val << ' ';
        }
        return s;
    }


};

int main( ) {
    LinkedList a;

    a.addFirst(3);
    a.addLast(1);
    a.addLast(4);
    a.addLast(1);
    a.addLast(5);
    a.removeLast();

    cout<< a << endl;


}