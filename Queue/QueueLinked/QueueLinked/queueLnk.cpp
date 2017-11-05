//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueLnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queueLnk.h"

//--------------------------------------------------------------------

// ** QueueNode 생성자 ** 
template < class QE >
QueueNode<QE>::QueueNode(const QE &elem, QueueNode<QE> *nextPtr)

// Creates a queue node containing element elem and next pointer
// nextPtr.

: element(elem),
next(nextPtr)
{}

//--------------------------------------------------------------------

// ** Queue 생성자 ** 
template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

: front(0),
rear(0)
{}

//--------------------------------------------------------------------

// ** Queue Destructor ** 
template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	// pre-lab (Linked)
	clear();
}

//--------------------------------------------------------------------

// ** 노드 삽입 ** 
template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Linked)
	if (empty())										// 빈 노드일 경우
	{
		front = new QueueNode<QE>(newElement, 0);		// 새로운 노드를 만들고 front가 이것을 가리킴
		rear = front;									// 노드가 하나이기 때문에 rear와 front가 동일한 노드를 가리킴
		front->next = rear;
		rear->next = 0;
	}
	else
	{													// 빈 노드가 아닐 경우
		QueueNode<QE> * tmp = rear;						// rear의 값을 임시 포인터에 저장하고
		rear = new QueueNode<QE>(newElement, 0);		// rear에 새로운 노드를 삽입
		tmp->next = rear;								// 새 노드가 삽입된 rear가 임시 포인터에 저장된 이전의 rear를 가리킴
	}


}

//--------------------------------------------------------------------

// ** 노드 삭제 **
template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently (front) element from a queue and
// returns it.

{
	// pre-lab (Linked)
	if (!empty())							// 빈 노드가 아닐 경우
	{	
		QueueNode<QE> * tmp = front;		// 임시 포인터에 front를 저장하고
		front = front->next;				// front 노드는 front 다음 노드를 가리킴
		return tmp->element;				// 임시 포인터에 저장한 노드의 element를 리턴
	}
	else
		cout << "Empty queue" << endl;

}

//--------------------------------------------------------------------

// ** 초기화 **
template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Linked)
	while (!empty())					// 빈 노드가 아닐 경우
	{
		QueueNode<QE> * tmp = front;	// 임시 포인터에 front노드를 저장
		front = front->next;			// front가 front 다음의 노드를 가리키게 함
		delete tmp;						// 임시 포인터에 저장된 노드를 삭제
	}

}


//--------------------------------------------------------------------

// ** 빈 노드인지 확인 **
template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	if (front == 0)			// front가 0이면 빈 노드로 간주
		return 1;
	else
		return 0;

}


//--------------------------------------------------------------------

// ** 노드 구조 시각화하여 출력 ** 
template < class QE >
void Queue<QE>::showStructure() const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	// pre-lab (Linked)
	if (empty())								// 빈 노드인 경우
		cout << "Empty queue" << endl;			// 빈 메세지 출력

	else                                        // 빈 노드가 아닐 경우 
	{
		QueueNode<QE> * tmp = front;			// 임시 포인터에 front노드를 저장
		while (tmp!=rear)						// 임시 포인터가 rear와 같지 않을 때까지
		{
			cout << tmp->element << "\t";		// 임시 포인터의 element를 출력하고
			tmp = tmp->next;					// 임시 포인터가 그 다음 노드를 가리키게 함
		}
		if (tmp == rear)						// while loop를 빠져 나오고 tmp == rear인 경우는
			cout << tmp->element << endl;		// 노드가 한개인 경우이기 때문에 마지막으로 이를 출력하고 함수 종료
	}

}