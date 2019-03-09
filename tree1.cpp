#include <iostream>

using namespace std;

template<class T> 
class Node
{
    public:
        T data;
        Node* left;
        Node* right;
        Node()
        {
            data = 0;
            left = NULL;
            right = NULL;
        }
};

template <class T>
class tree
{
    public:
        Node<T>* head;
        tree()
        {
            head = NULL;
        }
        void insert(T& x)
        {
            Node<T>* temp = new Node<T>;
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                insertNode(head, temp);
            }
        }
        void insertNode(Node<T>*& temp1, Node<T>*& temp2)
        {
            if (temp2->data > temp1->data)
            {
                if (temp1->right == NULL)
                {
                    temp1->right = temp2;
                }
                else
                {
                    insertNode(temp1->right, temp2);
                }
            }
            else
            {
                if (temp1->left == NULL)
                {
                    temp1->left = temp2;
                }
                else
                {
                    insertNode(temp1->left, temp2);
                }   
            }
        }
        void displayInOrder()
        {
            displayTree(head);    
        }
        void displayTree(Node<T>*& temp)
        {
            if (temp->left)
            {
                displayTree(temp->left);
            }
            cout << temp->data << " ";
            if (temp->right)
            {
                displayTree(temp->right);
            }
        }
        void displayPreOrder()
        {
            displayTree2(head);
        }
        void displayTree2(Node<T>*& temp)
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                displayTree2(temp->left);
            }
            if (temp->right)
            {
                displayTree2(temp->right);
            }
        }
        void displayPostOrder()
        {
            displayTree3(head);
        }
        void displayTree3(Node<T>*& temp)
        {
            if (temp->left)
            {
                displayTree3(temp->left);
            }
            if (temp->right)
            {
                displayTree3(temp->right);
            }
            cout << temp->data << " ";
        }
};

int main()
{
    tree<int> a;
    int n;
    int x;
    cout << "Enter the number of elements : ";
    cin >> n;
    while(n--)
    {
        cin >> x;
        a.insert(x);
    }
    a.displayInOrder();
    cout << endl;
    a.displayPreOrder();
    cout << endl;
    a.displayPostOrder();
    cout << endl;
    // cout << a.head->right->left->data << endl;
    return 0;
}