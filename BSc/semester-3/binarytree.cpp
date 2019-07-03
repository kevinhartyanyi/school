#include <iostream>

using namespace std;

template<typename T>
class binaryTree
{

private:

    struct Node
    {
        T value;
        Node* parent;
        Node* right;
        Node* left;
        Node(const T& value, Node* parent)
        {
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
            this->parent = parent;
        }
    };

    Node* root;
    void Inorder(Node* current)
    {
        if(current != nullptr)
        {
            Inorder(current->left);
            cout << current->value << "\n";
            Inorder(current->right);
        }
    }

    void Postorder(Node* current)
    {
        if(current != nullptr)
        {
            Postorder(current->left);        
            Postorder(current->right);
            cout << "Deleted: " << current->value << "\n";
            delete current;
        }
    }

    void Add(const T& value, Node* current)
    {
        if(current != nullptr)
        {
            if(value > current->value)
            {
                if(current->right != nullptr)
                    Add(value,current->right);
                else
                {
                    current->right = new Node(value, current);
                    cout << "Created new: " << value << "\n";
                }
                    
            }
            else if(value < current->value)
            {
                if(current->left != nullptr)
                    Add(value,current->left);
                else
                {
                    current->left = new Node(value, current);
                    cout << "Created new: " << value << "\n";
                }
            }
            else
            {
                cout << "Already exists\n";
            }
        }
    }

    
public:

    binaryTree(const T& value):root(new Node(value, nullptr)) {}
    void Nodes()
    {
        Inorder(root);
    }
    void AddNode(const T& value)
    {
        Add(value, root);
    }

    ~binaryTree()
    {
        Postorder(root);
    }
    
    

};

int main()
{
    binaryTree<int> tree(5);
    tree.AddNode(6);
    tree.AddNode(2);
    tree.AddNode(10);
    tree.AddNode(6);
    tree.AddNode(9);
    tree.AddNode(1);
    tree.Nodes();
}