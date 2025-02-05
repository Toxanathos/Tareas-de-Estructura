#include <iostream>
using namespace std;

struct NODE
{
    int m_data;
    NODE* m_pNext;
};

class Stack
{
private:
    NODE* m_pTop;

public:
    Stack() : m_pTop(nullptr) {}


    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }


    void Push(int data)
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = m_pTop;
        m_pTop = newNode;
        cout << "Elemento " << data << " insertado en la pila." << endl;
    }


    void Pop()
    {
        if (m_pTop == nullptr)
        {
            cout << "La pila esta vacia, no se puede borrar (pop)." << endl;
            return;
        }
        NODE* temp = m_pTop;
        m_pTop = m_pTop->m_pNext;
        cout << "Elemento " << temp->m_data << " eliminado de la pila." << endl;
        delete temp;
    }


    int Top() const {
        if (m_pTop == nullptr)
        {
            cout << "La pila esta vacia." << endl;
            return -1;
        }
        return m_pTop->m_data;
    }


    bool IsEmpty() const {
        return m_pTop == nullptr;
    }


    void Print() const
    {
        if (m_pTop == nullptr) {
            cout << "La pila está vacía." << endl;
            return;
        }

        NODE* current = m_pTop;
        cout << "Contenido de la pila: ";
        while (current != nullptr)
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    Stack stack;


    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(5);


    stack.Print();


    cout << "Valor superior de la pila: " << stack.Top() << endl;


    stack.Pop();
    stack.Print();


    cout << "Valor superior de la pila después de hacer pop: " << stack.Top() << endl;


    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    return 0;
}
