/*
 ----------------------------
 * Name: Hwang Eo Jun
 * Last modified: 2017-10-15
 * content: Calculator
 ----------------------------
*/
#include "stackarr.cpp"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define _Maxname 20

float Calcul(char* postfix);  //this is function which calculate postfix
void main(void)
{
   char post[_Maxname];                //this is array that allocated the character of postfix

   cout << "This is calculator" << endl;
   cout << "Please input the postfix: ";
   cin >> post;                         //save the postfix on post array

   
   cout << "result: ";				//Show the result
   cout.precision(4);
   cout << Calcul(post);
   cout << endl;   
   

   cin >> post;
}

float Calcul(char* postfix)
{
	Stack<float> tmpStack(_Maxname);		// cin을 통해 연산자,피연산자 등의 입력을 받아옴
	Stack<float> testStack(_Maxname);		// tmpStack에 저장된 것을 pop하여 저장
											// tmpStack의 순서를 뒤집어서 testStack에 넣게 됨
	Stack<float> testStack2(_Maxname);		// 임시로 값을 저장하는 역할의 stack
			

	for (int i = 0; i < _Maxname; i++)
	{
		if (postfix[i] == NULL)
			break;
		tmpStack.push(postfix[i]);
	}

	while(!tmpStack.empty())
	{
		testStack.push(tmpStack.pop());
	}

	while (!testStack.empty())
	{
		char tmp = testStack.pop();			// top의 값을 tmp에 저장하고
		testStack.push(tmp);				// top을 원래대로 되돌림


		// Stack의 top이 연산자가 아닌 숫자일 경우 testStack2에 push함
		if (tmp != '+' && tmp != '-' && tmp != '*' && tmp != '/')
		{
			char c[1];
			c[0]= testStack.pop();
			float i = atof(c);
			testStack2.push(i);
		}
		// Stack의 top이 연산자일 경우 testStack2에 저장해놓은 값을 pop하여 연산
		// 계산된 값은 tmpStack에 일시적으로 저장되고
		// testStack2에 더이상 연산할 값이 없으면 tmpStack의 값을 최종적으로 testStack에 저장
		// 마지막으로 testStack에 저장된 값을 return
		else
		{
			testStack.pop();
			if (tmp == '+')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() + tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() + testStack2.pop() );
			}

			else if (tmp == '-')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() - tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() - testStack2.pop());
			}

			// 나누기의 경우 testStack에서 위에있는 수를 아래에 있는 수로 나눠야 하므로 임시변수로 컨트롤함
			else if (tmp == '/')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					float f1 = tmpStack.pop();
					float f2 = tmpStack.pop();
					testStack.push( f2 / f1 );
				}
				else
				{
					float f1 = testStack2.pop();
					float f2 = testStack2.pop();
					tmpStack.push(f2/ f1);
				}
					
			}
			else if (tmp == '*')
			{
				if (testStack2.empty() && !tmpStack.empty())
				{
					testStack.push(tmpStack.pop() * tmpStack.pop());
				}
				else
					tmpStack.push(testStack2.pop() * testStack2.pop());
			}
		}

		// testStack에 값이 있고, testStack2, tmpStack이 비어있는 경우 연산이 끝난 것으로 간주하여
		// 해당 값을 리턴한다
		if (testStack.empty() && testStack2.empty())
		{
			return tmpStack.pop();
		}
		else if (!testStack.empty() && testStack2.empty() && tmpStack.empty() )
		{
			return testStack.pop();
		}
			
	}
}