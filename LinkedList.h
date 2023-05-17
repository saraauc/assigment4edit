#include <iostream>
#include <vector>

struct Node {
    int value;
    int count;
    Node* next;

    Node(int v, int c = 1) : value(v), count(c), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void add(int value);
    void remove(int value);
    void printall();
    void create_vector(std::vector<int> v);
    int sum();
    // bool isEnd(Node* node);
    bool isEmpty();
    void insertAfter(int firstValue, int secondValue);
};
