// COMSC-210 | Midterm 1 | Christine Susic

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//a class doubly linked list 
class DoublyLinkedList {
//private data
private:
    //a struct containing the a node
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

//public data
public:
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    //function to insert values at head, tail, in between, etc.
    //takes two arguments, value and position
    void insert_after(int value, int position) {
        
        //validates the index of the position
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        //new node is created, value is used as an argument
        Node* newNode = new Node(value);
        if (!head) { //if the list is empty 
            head = tail = newNode; //the newNode becomes the head and the tail
            return;
        }

        //if the list is not empty
        Node* temp = head; //new pointer points to the head
        //for loop with position
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next; //makes sure temp is valid (within the list)

        //if temp is not valid(outside the list)
        if (!temp) {
            //error message
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; //delete Node
            return;
        }

        //newNodes next pointer becomes temps next pointer
        newNode->next = temp->next; 
        //newNodes previous pointer becomes temp
        newNode->prev = temp;
        //redirects pointers
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    //function to delete 
    void delete_val(int value) {
        //if the list is empty
        if (!head) return;

        Node* temp = head;
        
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; 

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; 

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; 

        delete temp;
    }

    //function to delete nodes position
    void delete_pos(int pos) {
        if (!head) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp; //delete temp pointer
    }

    void push_back(int v) {
        //new node is created, v is used as an argument
        Node* newNode = new Node(v);
        if (!tail) //if the list is empty
            head = tail = newNode; //the newNode becomes the head and the tail
        else { //if the list is not empty
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        //new node is created, v is used as an argument
        Node* newNode = new Node(v);
        if (!head) //if the list is empty
            head = tail = newNode; //the newNode becomes the head and the tail
        else { //if the list is not empty
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }
    
    void pop_front() {

        if (!head) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head; //new pointer temp points to the head

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;  //delete temp pointer
    }

    void pop_back() {
        if (!tail) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) { //if the tail 
            tail = tail->prev;
            tail->next = nullptr;
        }
        else //otherwise
            head = tail = nullptr; //set head and tail to null
        delete temp; //delete temp pointer
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        while (current) { //if current is valid
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    
    //output data structure starting with
    //every first element, skip second, 
    //output thid, skip fourth, etc
    //demo method
    void every_other_element() {
        
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}