#include <iostream>
using namespace std; 

class Node
{
public: 
    shared_ptr<Node> next;
    string data;
    Node() {};
    Node(string data) : data{ data }, next{ nullptr } {}
    
    void setNext(shared_ptr<Node> next) {
        this->next = move(next);
    }

    void printData() {
        cout << this->next << endl; 
    }
};

class List {
public:
    shared_ptr<Node> root;

    void add(string data) {
        shared_ptr<Node>temp{ make_shared<Node>(data) };
        temp->setNext(root);
        this->root = temp; 
    }

    void print() {
        auto current = this->root;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }

};



int main()
{
 
    //shared_ptr<Node> bro0{ make_shared<Node>("testing0") };
    //shared_ptr<Node> bro1{ make_shared<Node>("testing1") };
    //shared_ptr<Node> bro2{ make_shared<Node>("testing2") };
    //shared_ptr<Node> bro3{ make_shared<Node>("testing3") };

    //bro0->setNext(bro1);
    //bro1->setNext(bro2);
    //bro2->setNext(bro3);
    //cout << bro0->data;
    List l0; 
    l0.add("1");
    l0.add("2");
    l0.add("3");
    l0.add("4");
    l0.add("5");
    l0.print();

}

