#include <iostream>
#include "ListDbl.h"

using namespace std;

// ** ListNode 생성자 **
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *priorPtr, ListNode *nextPtr)
	:element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

// ** List 생성자 **
template<class LE>
List<LE>::List(int ignored)
{
	head = new ListNode<LE>(0, NULL, NULL);
	cursor = head;
}

// ** List 소멸자 ** 
template<class LE>
List<LE>::~List()
{
	clear();
}

// ** 노드 삽입 ** 
template<class LE>
void List<LE>::insert(const LE &newElement)
{
	if (empty())	// 빈 노드의 경우
	{
		ListNode<LE> * newNode = new ListNode<LE>(newElement, head, NULL);
		cursor = newNode;
		head->next = newNode;
	}

	else           
	{
		
		if (cursor->next == NULL)  // 리스트의 맨 끝에 노드를 삽입할 경우
		{
			ListNode<LE> * newNode = new ListNode<LE>(newElement, cursor, NULL);
			cursor->next = newNode;
		}
		else                       
		{
			ListNode<LE> * newNode = new ListNode<LE>(newElement, cursor, cursor->next);
			cursor->next->prior = newNode;
			cursor->next = newNode;
		}
		cursor = cursor->next;
	}
}

// ** 노드 삭제 **
template<class LE>
void List<LE>::remove()
{
	if (!empty())
	{
		ListNode<LE> * tmp = cursor;

		if (cursor->next == NULL)       // 리스트의 마지막 노드일 경우
		{
			cursor->prior->next = NULL;
			cursor = head->next;        // 커서를 처음 노드로 설정
		}
		else if (cursor->prior == head) // 리스트의 처음 노드일 경우
		{
			cursor->next->prior = head;
			head->next = cursor->next;
			cursor = cursor->next;
		}
		else
		{
			cursor->next->prior = cursor->prior;
			cursor->prior->next = cursor->next;
			cursor = cursor->next;
		}

		delete tmp;
	}
	else
		cout << "Empty list" << endl;
}


// ** 노드 대체 **
template<class LE>
void List<LE>::replace(const LE &newElement)
{
	ListNode<LE> * tmp = cursor;		// 현재 커서를 임시 포인터에 저장 후
	cursor = new ListNode<LE>(newElement, cursor->prior, cursor->next);	// 새 노드를 현재 커서 위치에 삽입
	tmp->prior->next = cursor;
	if (tmp->next != NULL)
		tmp->next->prior = cursor;
	delete tmp;							// 임시 포인터에 저장한 노드 메모리 상에서 삭제
}

// ** 초기화 **
template<class LE>
void List<LE>::clear()
{
	while (!empty())
	{
		remove();
	}
}
								
// ** 빈 리스트인지 확인 **
template<class LE>
int List<LE>::empty() const
{
	if (head->next==NULL)
		return 1;
	else
		return 0;
}
	
template<class LE>
int List<LE>::full() const
{
	return 0;
}
						
// ** 커서를 처음으로 ** 
template<class LE>
bool List<LE>::gotoBeginning()
{
	if (!empty())
	{
		cursor = head->next;
		return true;
	}
	return false;
}

// ** 커서를 마지막으로 ** 
template<class LE>
bool List<LE>::gotoEnd()
{
	if (!empty())
	{
		while (cursor->next != NULL)	// 노드의 next가 NULL이 아닐 동안
			cursor = cursor->next;		// 커서를 다음 노드로 이동
		return true;
	}
	return false;
}
	
// ** 다음 노드로 커서 이동 ** 
template<class LE>
bool List<LE>::gotoNext()
{
	if (cursor->next != NULL)			// 노드의 next가 NULL이 아니면
	{
		cursor = cursor->next;			// 커서를 다음 노드로 이동
		return true;
	}
	return false;
		
}

// ** 이전 노드로 커서 이동 ** 
template<class LE>
bool List<LE>::gotoPrior()
{
	if (cursor->prior == head)			// 커서의 이전 노드가 head이면
		return false;					// 이동하지 않음
	else
	{
		cursor = cursor->prior;			// 커서를 이전 노드로 이동
		return true;
	}
		
}
	
// ** 커서가 가리키는 노드의 element 리턴 ** 
template<class LE>
LE List<LE>::getCursor() const
{
	if(!empty())
		return cursor->element;
	cout << "Empty list" << endl;
	return 0;
}
										
// ** 리스트 구조 출력 ** 
template<class LE>
void List<LE>::showStructure() const
{
	if(empty())
		cout << "Empty List" << endl;
	else
	{
		ListNode<LE> * tmp = head->next;	// 임시 포인터는 처음 노드부터 시작
		while (tmp->next != NULL)			// 임시 포인터의 next가 NULL이 아닐 동안
		{
			cout << tmp->element << '\t';	// 포인터가 가리키는 노드의 element를 출력하고
			tmp = tmp->next;				// 다음 노드로 이동
		}
		cout << tmp->element << endl;		// 마지막 노드의 element 출력
	}	
}

// ** 리스트 반전 **
template<class LE>
void List<LE>::reverse()
{
	if (empty())
		cout << "Empty List" << endl;
	else
	{
		int len = length();						// 현재 리스트에 몇개의 노드가 있는지 계산
		LE * arr = new LE[len];					// 노드 만큼의 LE클래스 배열 생성

		ListNode<LE> * tmpNode = head->next;	// 임시 포인터를 처음 노드로 설정

		for (int i = 0; i < len; i++)			// 노드 개수만큼 for loop를 돌면서
		{
			if (tmpNode->next != NULL)			// 임시 포인터의 next가 NULL이 아닐 동안
			{
				arr[i] = tmpNode->element;		// 배열에 각 노드의 element 저장
				tmpNode = tmpNode->next;		// 임시 포인터를 next로 이동
			}
		}
		arr[len - 1] = tmpNode->element;		// 배열의 마지막 인덱스에 마지막 노드의 element 저장

		int index = 0;							// 리스트를 초기화 하기 전에, 현재 커서의 위치를 index로 저장하기 위한 변수
		ListNode<LE> *tmpCursor = head->next;	// 임시 포인터가 처음 노드부터 시작하여,
		while (tmpCursor != cursor)				// 임시 포인터가 cursor와 같아질 때 까지
		{
			index++;							// index를 증가시키고
			tmpCursor = tmpCursor->next;		// 임시 포인터가 다음 노드를 가리키게 함
		}
		
		clear();								// 리스트 초기화

		for (int i = len-1; i >=0; i--)
		{
			insert(arr[i]);						// 배열에 있는 element를 리스트에 반대 순서로 insert
		}

		gotoBeginning();						// 커서를 처음 노드로 위치시키고
		for (int i = 0; i < len-index-1; i++)	// 전체 노드의 길이에서 index-1을 뺀 만큼 노드를 이동시킨다. (리스트를 뒤집었기 때문)
		{
			cursor = cursor->next;
		}

	}
	
	
}

// ** 노드의 개수 계산 ** 
template<class LE>
int List<LE>::length() const
{
	int len = 1;

	if (empty())	// 빈 리스트일 경우 노드 0개
		return 0;
	else
	{
		ListNode<LE> * tmpCursor = head->next;	// 처음 노드부터 계산
		while (tmpCursor->next != NULL)
		{
			len++;								// 노드가 존재할 경우 len 증가
			tmpCursor = tmpCursor->next;		// 다음 노드로 이동
		}
		return len;								// 노드 개수 리턴
	}
}