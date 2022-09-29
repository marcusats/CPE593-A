#include<iostream>
#include <string>
using namespace std;


class DoubleLinkedList {
private:
	class Node {
	public:
		Node* next;
		Node* prev;
		int val;
	};

	Node* head;
	Node* tail;
public:
	DoubleLinkedList() : head(nullptr), tail(nullptr){
        

	}
  // DO NOT FORGET THE DESTRUCTOR!!!
  ~DoubleLinkedList() {
        for (Node* p = head; p !=nullptr; p=p->next){
                delete p->prev;
        }
    }
	void addStart(int v) {
        Node* a = new Node();
        a->val = v;
        a->next = head;
        a->prev = nullptr;
        head = a;
        if (tail == nullptr ){
            tail = a;
        }
	}

	void addEnd(int v) {
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        temp->prev = tail;
        tail->next= temp;
        tail = temp;
	}

	void removeStart() {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
	}

	void removeEnd() {

        //Always check before you remove
        if(head == nullptr){
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        


	}

	// insert v before pos. insert(0,v) would insert at the front.
	void insert(int pos, int v) {
        int count = 0;
        for (Node* p = tail; p != nullptr; p=p->prev){
            if(pos == count){
                p->val = v;
                break;
            }
            count++;
        }
        
	}
	// implement to print out the list
	friend ostream& operator <<(ostream& s, const DoubleLinkedList& list) {
        string c = "<->";
        for (Node* p = list.head; p !=nullptr; p=p->next){
            if (p->next == nullptr) {
                s<<p->val << ' ';
            }else{
                s<<p->val << ' ' << c << ' ';
            }
            
        }
        return s;
	}
};

int main() {
	DoubleLinkedList a;
	const uint32_t n = 1000000;
	for (int i = 0; i < n; i++)
		a.addStart(i);
	for (int i = 0; i < n; i++)
		a.addEnd(i);

	for (int i = 0; i < (3*n/2); i++)
		a.removeStart();
	cout << a << '\n';
	for (int i = 0; i < n/2 - 5; i++)
		a.removeEnd();

	cout << a << '\n';
	for (int i = 0; i < 10; i++)
		a.insert(1, i);
    
	cout << a << '\n';
}