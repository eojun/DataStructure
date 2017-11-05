//--------------------------------------------------------------------
//
//  Laboratory 5                                        stacklnk.cpp
//
//  SOLUTION: Linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
// #include <alloc.h>
#include "stacklnk.h"

//--------------------------------------------------------------------

// ** StackNode 생성자 **
template < class SE >
StackNode<SE>::StackNode(const SE &elem, StackNode<SE> *nextPtr)
// Creates a stack node containing element elem and next pointer
// nextPtr.
: element(elem),
next(nextPtr)
{

}

//--------------------------------------------------------------------

// ** Stack 생성자 **
template < class SE >
Stack<SE>::Stack(int ignored)
// Creates an empty stack. The parameter is provided for compatability
// with the array implementation and is ignored.
: top(0)
{

}

//--------------------------------------------------------------------

// ** Stack Destructor ** 
template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
	while(!empty())						// 빈 노드가 아닐 경우
	{
		StackNode<SE> * tmp = top;		// 임시 포인터가 top을 가리키게 함
		top = top->next;				// top은 top의 다음 노드를 가리킴
		elementCount--;					// 노드의 개수를 세는 변수 감소
		delete tmp;						// tmp에 저장된 노드 삭제
	}
}

//--------------------------------------------------------------------

// ** 노드 삽입 함수 **
template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
	if (full())								
	{
		cout << "stack is full" << endl;
		return;
	}
	
	if (empty())								 // 빈 노드일 경우
	{
		top = new StackNode<SE>(newElement, 0);  // top에 새로운 노드를 삽입
		elementCount++;
	}				
	
	else
	{
		StackNode<SE> * tmp = top;					// 임시 포인터가 현재 top을 가리키게 함
		top = new StackNode<SE>(newElement, tmp);	// top이 새로운 노드를 가리키고, top->next = tmp
		elementCount++;								// // 노드의 개수를 세는 변수 증가
	}

}

//--------------------------------------------------------------------

// ** 노드 제거 함수 **
template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
	if (empty())
	{
		cout << "empty stack" << endl;
		return 0;
	}
	else                                     // 빈 노드가 아닐 경우
	{
		StackNode<SE> * tmp = top;			 // 임시 포인터 tmp가 top을 가리키게 함
		SE tmpElement = top->element;		 // 리턴을 위해 임시 변수 tmpElement에 top의 element값을 저장 
		top = top->next;					 // top이 top의 다음 노드를 가리킴
		elementCount--;						 // 노드의 개수를 세는 변수 감소
		delete tmp;							 // tmp가 가리키는 노드 삭제
		return tmpElement;					 // 임시 변수 tmpElement에 저장된 값을 리턴
	}
}

//--------------------------------------------------------------------

// ** 노드 초기화 함수 **
template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
	
	while (!empty())					// 빈 노드가 아닌 동안 루프 돌림
	{
		StackNode<SE> * tmp = top;		// 임시 포인터 변수 tmp가 top을 가리키게 함
		top = top->next;				// top이 top 다음 노드를 가리키게 함
		delete tmp;						// tmp에 저장된 노드 제거
	}
}

//--------------------------------------------------------------------

// ** 빈 노드인지 확인 **
template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
	if (top == 0)			// top==0이면 빈 노드로 간주
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------

// ** 노드가 꽉 찼는지 확인 **
template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0. Cannot be
// done cleanly in generic C++ because there is sometimes overhead
// associated with a memory allocation.
{
	if (elementCount >= defMaxStackSize)	// ** elementCount변수가 defMaxStackSize 이상이면 full로 간주
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------

// ** 노드 구조 시각화하여 출력 **
template < class SE >
void Stack<SE>::showStructure() const
// Linked list implementation. Outputs the elements in a stack. If
// the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.
{
	if (empty())							
		cout << "empty stack" << endl;		
	else
	{
		StackNode<SE> *tmp = top;						// 임시 포인터 변수 tmp가 top을 가리킴
		while (tmp!=0)									// tmp가 0이 아닐 동안
		{
			cout << tmp->element << endl;				// tmp의 element를 출력
			tmp = tmp->next;							// tmp가 tmp의 다음 노드를 가리킴
		}	
	}
}