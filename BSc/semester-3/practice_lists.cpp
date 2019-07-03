
#include <iostream>

struct listelem
{
    int key;
    listelem* next;

    listelem(int key) 
    {
        (*this).key = key;
    };
};

class list
{
public:
    listelem* elem;


    list() {elem = nullptr;};
    listelem* First() {return elem;};
    ~list()
    {
        while(elem->next != nullptr)
        {            
            listelem* tmp = elem;
            elem = elem->next;
            delete tmp;
        }
    }
    
    
};

void Add(list& l, int value)
{
    listelem *pe = nullptr;
    listelem *p = l.First();
    listelem *first = l.First();

    if(p == nullptr)
    {
        listelem* q = new listelem(value);
        q->next = q;
        l.elem = q;
    }
    else
    {
        while(p->key < value && p->next != first)
        {
            pe = p;
            p = p->next;
        }
        listelem* q = new listelem(value);
        if(p->next == first)
        {
            if(p->key < value)
            {
                q->next = first;
                p->next = q;
            }
            else
            {
                l.elem = q;
                q->next = p;
            }
        }
        else
        {
            if(pe == nullptr)
            {
                l.elem = q;
            }
            else
            {
                pe->next = q;
            }
            q->next = p;
        }
    }
}


int main()
{
    list A;
    Add(A, 3);
}