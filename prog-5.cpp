#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
struct node
{
    node * prev;
    node * next;
    std::string data;

    node(node * p, node * n, const std::string& s)
        :prev(p), next(n), data(s)
    {
    }
};

struct list
{
    node * head;
    node * tail;
    size_t n;
    
    list()
        :head(0), tail(0), n(0)
    {
    }

    ~list()
    {
        for(node * n = head; n; n = n->next)
            delete n;
    }

    size_t size() const
    {
        return n;
    }

    node * append(const std::string& str)
    {
        if(tail)
        {
            tail = tail->next = new node(tail, 0, str);
        }
        else
        {
            tail = head = new node(0, 0, str);
        }
        return tail;
    }

    node * add_after(node* n, const std::string& str)
    {
        node * a = new node(n, n->next, str);
        
        if (n->next == nullptr) { //if at end of list
            tail = a;
        } else {
            n->next->prev = a;
        }

        n->next = a;
        return a;
    }

    void remove(node* n)
    {

        //If n is the only element in the list
        if (n->prev == nullptr && n->next == nullptr) {
            assert(head == tail && head == n);
            head = tail = nullptr;
        }

        //If n is the head
        else if (n->prev == nullptr && n->next != nullptr) {

            assert(n == head);
            head = n->next;
            head->prev = nullptr;
        }

        //If n is the tail
        else if (n->prev != nullptr && n->next == nullptr) {

            assert(n == tail);
            tail = n->prev;
            tail->next = nullptr;
        }

        //If n is in the middle somewhere
        else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }



        delete n;
    }

    void print()
    {
        for(node * n = head; n; n = n->next)
            std::cout << n->data << std::endl;
    }
};

int main()
{
    list L;

    node * a = L.append("A");
    node * c = L.append("C");
    node * e = L.append("E");
    L.print();

    node * b = L.add_after(a, "B");
    node * d = L.add_after(c, "D");
    node * f = L.add_after(e, "F");
    L.print();

    L.remove(a);
    L.remove(d);

    L.print();

    return 0;
}

