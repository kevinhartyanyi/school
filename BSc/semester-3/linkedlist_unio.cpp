#include <iostream>

struct Elem
{
    int value;
    Elem* next;
    Elem* prev;
};

class HeadListTwo
{
    
    Elem* head;
public:
    HeadListTwo() {head = new Elem(); head->prev = nullptr; head->next = nullptr;}
    void New(int value) 
    {
        Elem* n = new Elem();
        n->value = value;
        n->next = nullptr;
        Elem* s = head;
        while(s->next != nullptr)
            s = s->next;
        s->next = n;
        n->prev = s;
    }
    void write()
    {
        Elem* s = head;
        while(s->next != nullptr)
        {
            std::cout << s->next->value << std::endl;
            s = s->next;
        }
    }

    Elem* Head() {return head;};
};

void Unio(HeadListTwo L1, HeadListTwo L2)
{
    Elem *p,*q,*k = L1.Head(); L2.Head(); L2.Head();

    while(p->next != nullptr)
    {
        if(k->value < p->value && k != nullptr)
        {
            while(k->value < p->value && k->next != nullptr)
            {
                k = k->next;
            }
            if(p == L1.Head())
            {
                p->next = q;
                q->prev = p;
            }
            else
            {
                p->prev->next = q;                
                q->prev = p->prev;
            }
            if(k->next != nullptr)
            {
                k = k->next;
                k->prev->next = p;
                p->prev = k->prev;
            }
            else
            {
                k->next = p;
                p->prev = k;
                k = nullptr;
            }
            q = k;
        }
        p = p->next;        
    }
    if(k != nullptr)
    {
        p->next = k;
        k->prev = p;
    }
    
}

int main()
{
    HeadListTwo L1;
    L1.New(4);
    L1.New(6);
    HeadListTwo L2;
    L2.New(5);
    L2.New(10);

    Unio(L1,L2);

    L1.write();


}