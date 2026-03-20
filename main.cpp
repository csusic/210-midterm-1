// COMSC-210 | Midterm 1 | Christine Susic

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

//a class doubly linked list 
class DoublyLinkedList {
//private data
private:
    //a struct containing the node
    struct Node {
        int data; //integer to hold the data
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

    //function to delete node by value
    void delete_val(int value) {
        //if the list is empty
        if (!head) return;

        //new pointer temp points to the head
        Node* temp = head;
        
        //searches for the node with a specific value
        while (temp && temp->data != value)
            temp = temp->next;

        //the value isn't found
        if (!temp) return; 

        //checks to see if the node is the head
        if (temp->prev) //if the hode is the head
            temp->prev->next = temp->next; //node redirected
        else //otherwise
            head = temp->next; //delete head

        //checks to see if the node is the tail
        if (temp->next) //if the node is the tail
            temp->next->prev = temp->prev; //node redirected
        else //otherwise
            tail = temp->prev; //delete tail

        delete temp; //delete memory
    }

    //function to delete nodes position
    void delete_pos(int pos) {
        if (!head) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
    
        //if the position is 1
        if (pos == 1) {
            pop_front(); //delete node
            return;
        }
    
        Node* temp = head; //new pointer temp points to the head
    
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
            head = tail = nullptr;  //set head and tail to null
        delete temp;  //delete temp pointer
    }

    void pop_back() {
        if (!tail) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail; //new pointer temp points to the tail

        if (tail->prev) { //if 
            tail = tail->prev;
            tail->next = nullptr; //set 
        }
        else //otherwise
            head = tail = nullptr; //set head and tail to null
        delete temp; //delete temp pointer
    }

    //deleting the whole linked list
    ~DoublyLinkedList() {
        while (head) { //while head exists
            Node* temp = head; //new pointer temp points to the head
            head = head->next; //head points to the next
            delete temp; //delete temp pointer
        }
    }
    
    //function to print the doubly linked list
    void print() {
        Node* current = head;
        if (!current) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        while (current) { //if current is valid
            cout << current->data << " "; //output current data
            current = current->next; //traverse forwards
        }
        cout << endl;
    }

    //function to print the doubly linked list in reverse
    void print_reverse() {
        Node* current = tail;
        if (!current) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        while (current) { //if current is valid
            cout << current->data << " "; //output current data
            current = current->prev; //traverse backwards
        }
        cout << endl;
    }
    
    //output data structure starting with
    //every first element, skip second, 
    //output thid, skip fourth, etc.
    void every_other_element() {
        Node* current = head;
        if (!current) { //if the list is empty
            cout << "List is empty." << endl;
            return;
        }
        while (current) { //if current is valid
            cout << current->data << " "; //output current data
            current = current->next->next; //traverse forwards by every other
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    //driver program
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();
    
    cout << "List prints every other element: ";
    list.every_other_element();
    
    return 0;
}