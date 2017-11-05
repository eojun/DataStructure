//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueArr.cpp
//
//  SOLUTION: Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queuearr.h"

//--------------------------------------------------------------------

// ** Queue 생성자 **
template < class QE >
Queue<QE>::Queue(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// elements (defaults to defMaxQueueSize).

: maxSize(maxNumber+1),
front(-1),
rear(-1)
{
	element = new QE[maxNumber+1];
}

//--------------------------------------------------------------------

// ** Queue Destructor ** 
template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	delete[] element;
}

//--------------------------------------------------------------------

// ** 삽입 함수 **
template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Array)
	if (empty())							// 빈 Queue일 경우 
	{
		rear = (rear + 1) % maxSize;		// rear의 값을 1 올리고
		element[rear] = newElement;			// element의 rear인덱스에 새로운 값을 삽입 
		if(front == -1)						// 맨 처음 프로그램을 시작하는 경우 front==-1인데,
			front = maxSize-1;				// 이 경우에 front가 맨 뒤 인덱스를 가리키게 함
	}

	else if(!full())						// 빈 Queue가 아닐 경우
	{
		rear = (rear + 1) % maxSize;		// rear의 값을 1 올리고
		element[rear] = newElement;			// element의 rear인덱스에 새로운 값을 삽입
	}

	else
		cout << "Queue is full" << endl;
	
}

//--------------------------------------------------------------------

// ** 삭제 함수 **
template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently added (front) element from a queue and
// returns it.

{
	// pre-lab (Array)
	if (!empty())							// 빈 Queue가 아닐 경우
	{
		front = (front + 1) % maxSize;		// front의 값을 1올리고
		return element[front];				// element의 front인덱스를 리턴
	}										// circular queue의 경우 front가 한 칸을 비우고 계산해야 하기 때문에
	else                                    // [front+1]에 있는 것이 사용되는 값
		cout << "Queue is empty" << endl;
}

//--------------------------------------------------------------------

// ** 초기화 함수 **
template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Array)
	front = -1;					// Array로 구현하는 Queue 구조이기 때문에
	rear = -1;					// 단순히 front와 rear를 초기값인 -1로 맞춰준다.
}

//--------------------------------------------------------------------

// ** 빈 Queue인지 확인 ** 
template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	// pre-lab (Array)
	return (rear == front);		// rear == front 이면 빈 Queue로 간주
}

//--------------------------------------------------------------------

// ** Queue가 꽉 찼는지 확인 ** 
template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 1) % maxSize == front);			// rear+1 이 front와 같으면 Queue를 full로 간주
}													// circular이기 때문에 %maxszie로 처리

//--------------------------------------------------------------------

// ** 구조 시각화하여 출력 ** 
template < class QE >
void Queue<QE>::showStructure() const

// Array implementation. Outputs the elements in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{

	if (empty())
	{
		cout << "front = " << front << "  rear = " << rear << endl;
		cout << "Empty queue" << endl;
	}
		
	else
	{
		cout << "front = " << front << "  rear = " << rear << endl;

		// pre-lab (Array)
		int tmp = front;									// 임시 변수 tmp에 front 값을 저장하고
		while (rear != tmp)									// tmp값이 rear와 같아질 때 까지
		{
			cout << element[(tmp +1) % maxSize] << "\t";	// element의 front에 해당하는 index의 값을 출력
			tmp = (tmp + 1) % maxSize;						// tmp는 값이 늘어나며 front가 dequeue된 것처럼 index를 처리함
		}
	}
}

// ** Queue의 맨 앞에 값을 삽입 ** 
template < class QE >
void Queue<QE>::putFront(const QE &newDataItem){
	//In-Lab. 2
	if (empty())							// 빈 Queue일 경우
	{
		enqueue(newDataItem);				// enqueue함수와 동일
	}

	else if (!full())						// 빈 Queue가 아닐 경우 
	{
		element[front] = newDataItem;		// 새 값을 front에 삽입
		if (front != 0)						// front가 0이 아니면
			front = (front - 1) % maxSize;	// front의 값을 1 줄여줌
		else // front == 0					// front가 0이면
			front = maxSize - 1;			// 인덱스 값이 음수가 되는 것을 막기 위해 값을 순환시켜줌 
	}

	else
		cout << "Queue is full" << endl;
}

// ** Queue의 맨 뒤에서 값을 꺼냄 ** 
template < class QE >
QE Queue<QE>::getRear(){
	//In-Lab. 2
	if (!empty())								// 빈 Queue가 아닐 경우
	{
		int tmp = rear;							// 임시 변수 tmp에 rear값을 저장하고
		if (rear != 0)							// rear가 0이 아닐 경우
			rear = (rear - 1) % maxSize;		// rear의 값을 1 줄여줌
		else // rear == 0						// rear가 0이면
			rear = maxSize - 1;					// 인덱스 값이 음수가 되는 것을 막기 위해 값을 순환시켜줌
		return element[tmp];					// 임시 변수 tmp에 저장한 만큼의 index로 element의 값 리턴
	}
	else
		cout << "Queue is empty" << endl;
}

// ** Queue의 길이 출력 ** 
template < class QE >
int Queue<QE>::getLength(){
	//In-Lab. 3

	int len = 0;							//길이를 리턴할 변수 선언 

	if (empty())
		cout << "Empty queue" << endl;
	else
	{
		// pre-lab (Array)
		int tmp = front;					// 임시변수 tmp에 front값을 저장하고
		while (rear != tmp)					// tmpr가 rear를 만날 때 까지 루프를 돌림
		{ 
			len++;							// 루프를 돌 때마다(값이 있을 때마다) 길이 1 증가
			tmp = (tmp + 1) % maxSize;		// tmp값을 1씩 증가시키며 rear에 다가감
		}
	}

	return len;								// len에 저장된 길이를 리턴
}
