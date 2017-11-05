#include "listrec.h"
#include <assert.h>
#include "stacklnk.cpp"

// ** Constructor **
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *nextPtr):
	element(elem),
	next(nextPtr)
{}

template < class LE >
List<LE>::List(int ignored = 0):
	head(0),
	cursor(0)
{}

//  ** Destructor ** 
template < class LE >
List<LE>::~List()
{
	clear();
}


// ** 삽입함수 ** 
template < class LE >
void List<LE>::insert(const LE &newElement)      // Insert after cursor
{
	if (head == 0)
	{
		head = new ListNode<LE>(newElement, 0);
		cursor = head;
	}

	else
	{
		ListNode<LE> * tmp = new ListNode<LE>(newElement, 0);
		cursor->next = tmp;
		cursor = tmp;
	}
}

// ** 리스트 초기화 **
template < class LE >
void List<LE>::clear()							// Clear list
{
	assert(head != 0);
	ListNode<LE> * tmp = head;
	ListNode<LE> * tmp2;
	while (tmp != 0)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		delete tmp2;
	}
	head = 0;
	cursor = 0;
}

// ** 리스트 출력 ** 										  
template < class LE >
void List<LE>::showStructure() const			// Output the list structure -- used in testing/debugging
{
	ListNode<LE> * tmp = head;
	while (tmp != 0)
	{
		cout << tmp->element << '\t';
		tmp = tmp->next;
	}
	cout << '\n';
}


// Prelab functions

// ** 리스트 출력(recursive 사용) ** 
template < class LE >
void List<LE>::write() const					// Output list elements
{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

// ** 리스트 끝에 삽입 **
template < class LE >
void List<LE>::insertEnd(const LE &newElement)	// Insert at end
{
	insertEndSub(head, newElement);
}

// ** 리스트 처음부터 시작해서 출력해가며 끝에 도달하면 되돌아오면서 출력 **
template < class LE >
void List<LE>::writeMirror() const				// Mirror view of list
{
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}

// ** 리스트 반전(recursive 사용) **
template < class LE >
void List<LE>::reverse()						// Reverse list
{
	reverseSub(0, head);
}

// ** 리스트 끝에서 삭제 **
template < class LE >
void List<LE>::deleteEnd()						// Delete from end
{
	deleteEndSub(head);
	cursor = head;
}

// ** 리스트 길이 리턴 **
template < class LE >
int List<LE>::length() const					// Length of list
{
	return lengthSub(head);
}


// Bridge functions
template < class LE >
void List<LE>::unknown1() const;                    // Bridge Exercise

template < class LE >
void List<LE>::unknown2();                          // Bridge Exercise

// In-lab functions

// ** 리스트 반전 ( 반복문 사용 ) ** 
template < class LE >
void List<LE>::iterReverse()                        // In-lab Exercise 1
{
	int len = length();
	LE  * arr = new LE[len];
	ListNode<LE> * tmp = head;
	for (int i = 0; i < len; i++)
	{
		arr[i] = tmp->element;
		tmp = tmp->next;
	}
	clear();
	for (int i = len - 1; i >= 0; i--)
	{
		insert(arr[i]);
	}
	
}

// ** 리스트 처음부터 시작해서 출력해가며 끝에 도달하면 되돌아오면서 출력 **
// ** (반복문 사용) **
template < class LE >
void List<LE>::stackWriteMirror() const             // In-lab Exercise 1
{
	Stack<ListNode<LE>*> tempStack;
	ListNode<LE> *p;
	p = head;
	cout << "stackWriteMirror: " << endl;
	while (p != 0)
	{
		tempStack.push(p);
		cout << p->element;
		p = p->next;
	}

	while (!tempStack.empty())
	{
		p = tempStack.pop();
		cout << p->element;
	}
	cout << endl;
}

template < class LE >
void List<LE>::cRemove();                           // In-lab Exercise 2

template < class LE >
void List<LE>::aBeforeb();                          // In-lab Exercise 3



// ** recursive를 수행하는 함수들 **

template < class LE >
void List<LE>::writeSub(ListNode<LE> *p) const
{
	if (p != 0)
	{
		cout << p->element;
		writeSub(p->next);
	}
}

template < class LE >
void List<LE>::insertEndSub(ListNode<LE> *&p, const LE &newElement)
{
	if (p != 0)
		insertEndSub(p->next, newElement);
	else
	{
		p = new ListNode<LE>(newElement, 0);
		cursor = p;
	}
}

template < class LE >
void List<LE>::writeMirrorSub(ListNode<LE> *p) const
{
	if (p != 0)
	{
		cout << p->element;
		writeMirrorSub(p->next);
		cout << p->element;
	}
}

template < class LE >
void List<LE>::reverseSub(ListNode<LE> *p, ListNode<LE> *nextP)
{
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next);
		nextP->next = p;
	}
	else
		head = p;
}

template < class LE >
void List<LE>::deleteEndSub(ListNode<LE> *&p)
{
	if (p->next != 0)
		deleteEndSub(p->next);
	else
	{
		delete p;
		p = 0;
	}
}

template < class LE >
int List<LE>::lengthSub(ListNode<LE> *p) const
{
	int result;

	if (p == 0)
		result = 0;
	else
		result = lengthSub(p->next) + 1;

	return result;
}

// Recursive partners of the Bridge functions
template < class LE >
void List<LE>::unknown1Sub(ListNode<LE> *p) const;

template < class LE >
void List<LE>::unknown2Sub(ListNode<LE> *&p);


// Recursive partners of the In-lab functions
template < class LE >
void List<LE>::cRemoveSub(ListNode<LE> *&p);         // In-lab Exercise 2

template < class LE >
void List<LE>::aBeforebSub(ListNode<LE> *&p);        // In-lab Exercise 3
