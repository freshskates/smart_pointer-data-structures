#include <iostream>
#include <string> 
#include <memory>
using namespace std; 

class Node {
public: 
    shared_ptr<Node> next;
    string data;
    Node() {};
    Node(string&& data) : data(data), next{ nullptr } {};
    Node(string& data) : data(data), next{ nullptr } {}
    
};
    
class List {
    int nodes = 0; 
    shared_ptr<Node> root;
    shared_ptr<Node> tail;
public:
    List() : root{ nullptr }, tail{ nullptr }{}

    void shift(string&& data) {
        shared_ptr<Node>temp{ make_shared<Node>(move(data)) };
        temp->next = root;
        root = temp;
        nodes++;
    }

    void push(string&& data) {
        shared_ptr<Node>temp= make_shared<Node>(move(data)) ;
        if (tail == nullptr || root == nullptr)
            root = (tail = temp);
        else {
            tail->next = temp;
            tail = temp; 
        }
        nodes++;
    }

    int length() {
        return nodes;
    }
    
    void print() {
        shared_ptr<Node> current = this->root;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
    void insert(int n, string&& data) {
        if (n == 0) {
            shift(move(data));
            return; 
        }
        shared_ptr<Node>temp = make_shared<Node>(move(data));
        int count = 0; 
        shared_ptr<Node> current = this->root, next;
        while (current->next != nullptr && count < n - 1) {
            current = current->next;
            count++;
        }
        next = current->next;
        current->next = temp; 
        temp->next = next; 
    }
    void reverse() {
        shared_ptr<Node> current = this->root, previous = nullptr, next = nullptr;
        tail = current; 
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current; 
            current = next; 
        }
        root = previous; 
    }
   
};



int main()
{
 
    List list0; 
    int n = 10, id = 0;
    string base = "user_";
    for (int i = 0; i < n; i++)
        list0.push(base + to_string(++id));
    
    list0.print();
    list0.insert(0, "newuser1");
    list0.insert(0, "newuser2");
    list0.insert(2, "newuser3");
    list0.insert(0, "newuser4");
    list0.print();

}

