#include <iostream>
#include <algorithm>

template<typename T>
class binarysearchtree
{
private:
    struct Elem
    {
        T data;
        Elem *left, *right, *parent;        
        Elem(): left(nullptr), right(nullptr), parent(nullptr) {};
        Elem(const T& data): data(data), left(nullptr), right(nullptr), parent(nullptr) {};
        Elem& operator=(const Elem& elem) { data = elem.data; left = elem.left; right = elem.right; parent = elem.parent; return *this;};
        Elem(const T& data, Elem& parent): data(data), left(nullptr), right(nullptr), parent(&parent) {};
    };
    Elem* root;

    void Write(const Elem* cur) const
    {
        if(cur != nullptr)  
        {    
            std::cout << cur->data << "\n";
            Write(cur->left);
            Write(cur->right);
        }
    }

public:
    binarysearchtree() {root = nullptr;};
    binarysearchtree(const T& root):root(new Elem(root)) {};
    void Add(const T& data);
    void Remove(const T& data);
    bool Search(const T& data) const;
    void WriteOut() const {Write(root);}
    //friend std::ostream& operator<< (std::ostream& os, const binarysearchtree<T>& t);
};

template<typename T>
void binarysearchtree<T>::Add(const T& data)
{
    if(root == nullptr)
    {
        root = new Elem(data);
    }
    else
    {
        Elem* p = root;
        
        Elem* q;
        while(p != nullptr)
        {
            q = p;
            if (p->data < data) {
                p = p->right;
            }
            else if(p->data > data) {
                p = p->left;
            }            
            else
            {
                std::cout << "Already exists \n";
                return;
            }
            Elem* n = new Elem(data, *q);
            if(q->data < data)
                q->right = n;
            else
                q->left = n;
        }        
    }
}
template<typename T>
void binarysearchtree<T>::Remove(const T& data)
{

}
template<typename T>
bool binarysearchtree<T>::Search(const T& data) const
{

}





int main()
{
    binarysearchtree<int> Tree;
    Tree.Add(3);
    Tree.Add(2);
    Tree.Add(5);
    Tree.Add(3);
    Tree.WriteOut();
    std::cout << "H";
    
    return 0;
}
