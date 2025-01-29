#include <iostream>
using namespace std;
/****************
     TAREA 1
ANDERSON ALEXIS VARILLAS SALDAÑA
EMANUEL HERNÁN CABEZA LUCAS

*****************/

struct NODE
{
	int m_data; 
	struct NODE *m_pNext;
};

class CLinkedList
{
	private:
		NODE *m_pRoot; 
	public:
		CLinkedList() : m_pRoot(nullptr) {}
		
		void InsertFinal(int data) 
		{
			NODE* newNode = new NODE;
			newNode->m_data = data;
			newNode->m_pNext = nullptr;
			
			if (m_pRoot == nullptr) 
			{
				m_pRoot = newNode;
			} 
			else 
			{
				NODE* current = m_pRoot;
				while (current->m_pNext != nullptr) {
					current = current->m_pNext;
				}
				current->m_pNext = newNode;
			}
		}

		void InsertBegin(int data) 
		{
        	NODE* newNode=new NODE;
        	newNode->m_data=data;
        	newNode->m_pNext=m_pRoot;
        	m_pRoot=newNode;
    	}

		void Print() const 
		{
			NODE* current = m_pRoot;
			while (current != nullptr) 
			{
				cout << current->m_data << " -> ";
				current = current->m_pNext;
			}
			cout << "nullptr" << endl;
		}
		
		void Delete(int data) 
		{
			if (m_pRoot == nullptr) 
				return; 
			
			if (m_pRoot->m_data == data) 
			{
				NODE* temp = m_pRoot;
				m_pRoot = m_pRoot->m_pNext;
				delete temp;
				return;
			}
			
			NODE* current = m_pRoot;
			while (current->m_pNext != nullptr && current->m_pNext->m_data != data) 
			{
				current = current->m_pNext;
			}
			
			if (current->m_pNext != nullptr) 
			{
				NODE* temp = current->m_pNext;
				current->m_pNext = current->m_pNext->m_pNext;
				delete temp;
			} else 
			{
				cout << "Value " << data << " not found in the list!" << endl;
			}
		}
};


int main(int argc, char *argv[]) 
{
	CLinkedList list;
	
	list.InsertFinal(10);
	list.InsertFinal(20);
	list.InsertFinal(30);
	list.InsertFinal(5);

	list.Print();

	list.InsertBegin(4);
    list.InsertBegin(2);
	
	cout << "Deleting 20 from the list." << endl;
	list.Delete(20);
	list.Print();
	
	
	return 0;
}