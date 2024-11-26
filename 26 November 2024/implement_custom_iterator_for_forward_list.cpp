#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class ForwardList {
    // Node structure
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    // Constructor
    ForwardList() : head(nullptr) {}

    // Destructor to clean up memory
    ~ForwardList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Add an element to the front of the list
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Custom iterator class
    class Iterator {
        Node* current;
        Node* prev;
        Node* head;

    public:
        // Constructor
        explicit Iterator(Node* node, Node* headNode) : current(node), prev(nullptr), head(headNode) {}

        // Dereference operator
        T& operator*() {
            return current->data;
        }

        // Const dereference operator for const iterators
        const T& operator*() const {
            return current->data;
        }

        // Pre-increment operator (++it)
        Iterator& operator++() {
            prev = current;
            current = current->next;
            return *this;
        }

        // Post-increment operator (it++)
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Pre-decrement operator (--it)
        Iterator& operator--() {
            if (current == head) {
                throw out_of_range("Cannot decrement iterator at the beginning of the list.");
            }

            Node* temp = head;
            prev = nullptr;

            // Traverse from the head to find the previous node
            while (temp && temp->next != current) {
                prev = temp;
                temp = temp->next;
            }

            current = prev;
            return *this;
        }

        // Post-decrement operator (it--)
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Begin iterator
    Iterator begin() {
        return Iterator(head, head);
    }

    // End iterator (nullptr indicates the end)
    Iterator end() {
        return Iterator(nullptr, head);
    }
};

int main() {
    ForwardList<int> flist;

    // Add elements to the forward list
    flist.push_front(10);
    flist.push_front(20);
    flist.push_front(30);

    // Iterate through the list using the custom iterator
    cout << "Elements in the forward list (using ++):" << endl;
    for (auto it = flist.begin(); it != flist.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Testing -- operator
    cout << "Elements in reverse order (using --):" << endl;
    auto it = flist.begin();
    ++it; // Move to the second element
    ++it; // Move to the third element

    // Print elements in reverse
    while (true) {
        cout << *it << " ";
        try {
            --it; // Move backward
        } catch (const out_of_range&) {
            break;
        }
    }
    cout << endl;

    return 0;
}


// Elements in the forward list (using ++):
// 30 20 10
// Elements in reverse order (using --):
// 10 30