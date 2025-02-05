#include <iostream>
using namespace std;
/****************
     TAREA 4
ANDERSON ALEXIS VARILLAS SALDAÑA
EMANUEL HERNÁN CABEZA LUCAS

*****************/

struct NODE
{
	int m_data; 
	struct NODE *m_pNext;
};

class CCircularLinkedList
{
private:
	NODE *m_pRoot; 

public:
	CCircularLinkedList() : m_pRoot(nullptr) {}
	
	void Insert(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;

		
		if (m_pRoot == nullptr) 
		{
			m_pRoot = newNode;
			newNode->m_pNext = m_pRoot;
		} 
		else 
		{
			NODE* current = m_pRoot;
			while (current->m_pNext != m_pRoot) 
			{
				current = current->m_pNext;
			}
			current->m_pNext = newNode;
			newNode->m_pNext = m_pRoot;
		}
	}
	
	
	void Print() const 
	{
		if (m_pRoot==nullptr)
    	{
        	cout<<"Lista vacía."<<endl;
        	return;
    	}
    
    	NODE* current = m_pRoot;
    	do 
    	{
        	cout << current->m_data << " -> ";
        	current = current->m_pNext;
    	} 
		while (current != m_pRoot);

    	cout << "Fin" << endl;
	}
	
	void Delete(int data)
	{
    	if (m_pRoot == nullptr)
        	return;

    	NODE **secondary=&m_pRoot;
    	NODE *init=m_pRoot;
    	bool found=false;

    	do 
    	{
        	if ((*secondary)->m_data==data)
        	{
            	NODE *temp=*secondary;
            	if (temp==m_pRoot)
            	{
                	NODE *trunk=m_pRoot;
                	while(trunk->m_pNext!=m_pRoot)
                    	trunk=trunk->m_pNext;
                	m_pRoot=m_pRoot->m_pNext;
                	*secondary=m_pRoot;
                	trunk->m_pNext=m_pRoot;
            	}
            	else
            	{
                	*secondary=(*secondary)->m_pNext;
            	}
            	delete temp;
            	found=true;
            	break;
        	}
        	secondary=&((*secondary)->m_pNext);
    	}
		while (*secondary!=init);

    	if (!found)
        cout<<"¡Valor "<<data<<" no encontrado en la lista!"<<endl;
	}
};


int main(int argc, char *argv[]) 
{
	CCircularLinkedList list;
	
	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(5);
	
	list.Print();
	
	cout << "Deleting 20 from the list." << endl;
	list.Delete(20);
	list.Print();
	
	
	return 0;
}