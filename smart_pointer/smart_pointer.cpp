#include <iostream>
using namespace std; 

class Node {
public: 
    shared_ptr<Node> next;
    string data;
    Node() {};
    Node(string&& data) : data{ data }, next{ nullptr } {}
    Node(string& data) : data{ data}, next{ nullptr } {}
    
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
        shared_ptr<Node>temp{ make_shared<Node>(move(data)) };
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
    list0.push("testing");
    list0.push("testing1");
    list0.push("testing2");
    list0.push("testing3");
    list0.push("testing4");
    list0.shift("testing69");
    list0.print();
    list0.reverse();
    list0.print();
    list0.print();
    list0.print();
    list0.reverse();
    list0.print();
    list0.print();

    cout << list0.length() << endl;

}

