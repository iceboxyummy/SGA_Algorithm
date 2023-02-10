#pragma once

// 03_Stack_Calculator.h

/*
	※ 전위 중위 후위 표기법

		ㅁ 중위 표기법(in-fix)
			ㄴ 피연산자 사이에 연산자를 두는 방식
			ㄴ 1 + 2

		ㅁ 전위 표기법(pre-fix)
			ㄴ 피연산자 앞에 연산자를 두는 방식
			ㄴ + 1 2

		ㅁ 후위 표기법(post-fix)
			ㄴ 피연산자 뒤에 연산자를 두는 방식
			ㄴ 1 2 +

	-> 사람은 중위 방식이 편하지만 컴퓨터는 전위, 후위 방식이 편함

	※ 중위식을 전위나 후위식으로 변환하는 법

		ㅁ 변환법
			1. 먼저 연산 우선순위에 따라 괄호로 묶어준다.
			2. 전위, 후위에 따라 괄호안에 있는 연산자를 앞이나 뒤로 옮겨준다.
			3. 괄호를 제거한다.

		ㅁ 중위식을 후위식으로 변환
			0. 중위식 : 3 + 4 * 2 / 2 + 32 - 6 * 7
			1. (((3 + ((4 * 2) / 2)) + 32) - (6 * 7))
			2. (((3 ((4 2 *) 2 /) +) 32) + (6 7 *) -)
			3. 3 4 2 * 2 / + 32 + 6 7 * -

		-> 여기서 연산자를 앞으로 옮기면 전위식 표기

	※ 중위식을 후위식으로 바꾸는 알고리즘
		ㅁ 변환법
			1. 숫자를 만나면 후위식 버퍼에 삽입, 숫자를 구성하는 연속된 문자를 모두 추출해서
			하나의 숫자로 만들고, 이어지는 피연산자와의 구분을 위해 공백을 하나 삽입한다.

			ex)
			1111 * 이면
			1 * 111, 11 * 11 111 * 1  구분이 안됨
			-> 11 11 * 이런식으로 넣어준다.

			2. 연산자를 만나면 스택에 넣는다. 두 번째 부터는 '('를 제외한 연산자는 스택을 검사하여 자신(연산자)보다
			우선순위가 같거나 높은 연산자들을 모두 꺼내서 버퍼에 넣는다.

			3. 여는 괄호'('를 만나면 스택에 넣는다. 스택에서 우선순위의 연산자를
			어디까지 꺼낼것인가 를 결정하기 위함이다.

			4. 닫는 괄호 ')'를 만나면 스택안에 있는 여는 괄호'('를 만날때 까지 스택 안에 있는
			연산자들을 모두 버퍼에 넣어준다.

			5. 1 ~ 4까지 반복을 하고, 모든 과정이 끝나면, 스택에 남아있는 연산자들을 꺼내서
			버퍼에 넣어준다.

		ㅁ 우선순위
			ㄴ 높을수록 우선시한다.

			0 : (
			1 : + -
			2 : * /
			3 : ^
*/

#include <stack>
#include <cctype>
#include <assert.h> 
using namespace std;

class Stack_Calculator
{
public:
	// 입력받은 연산자의 우선순위를 반환해주는 함수
	static int GetPriority(char op)
	{
		switch (op)
		{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		}
		return 100;
	}

	// 받은 중위식 mid를 후위식으로 바꾸어 post에 넣어준다.
	static void MakePostfix(char* post, const char* mid)
	{
		const char* expression = mid;
		char* new_exp = post;
		char c;

		stack<char> cs;

		while (*expression != '\0')
		{
			if (isdigit(*expression) != false)
				// 숫자 
			{
				// 숫자를 만나면 후위식 버퍼에 삽입
				// 숫자를 구성하는 연속된 문자들도 모두 추출하여 넣어준다.
				while (isdigit(*expression) != false || *expression == '.')
					*new_exp++ = *expression++;

				// 다른 피연산자와의 구분을 위해 공백을 하나 삽입한다.
				*new_exp++ = ' ';
			}

			else
				// 문자
			{
				if (strchr("^*/+-", *expression) != nullptr)
					// 일반 연산자
				{
					// 자신(연산자)보다 우선순위가 같거나 높은 연산자들을 꺼내 후위식에 넣어준다.
					while (cs.empty() != true
						&& GetPriority(cs.top()) >= GetPriority(*expression))
					{
						*new_exp++ = cs.top();
						cs.pop();
					}

					// 연산자를 스택에 넣어준다.
					cs.push(*expression++);
				}
				else
					// 괄호
				{
					if (*expression == '(')
						cs.push(*expression++); // '('는 스택에 넣어준다
					else if (*expression == ')')
					{
						// ')'를 만나면 스택안에 있는 '('를 만날때까지
						// 스택안에 있는 연산자들을 모두 버퍼에 넣어준다.
						while (true)
						{
							c = cs.top();
							cs.pop();
							if (c == '(')
								break;
							*new_exp++ = c;
						}
						expression++;
					}
					else
						expression++;
				}
			}
		}

		// 스택에 남아잇는 연산자들을 꺼내서 버퍼에 삽입
		while (cs.empty() != true)
		{
			*new_exp++ = cs.top();
			cs.pop();
		}

		// 문자열 마지막 위치에 null문자 삽입
		*new_exp = '\0';
	}

	// 후위식을 입력받아 계산한 결과를 반환해준다.
	static double CalcPostfix(const char* post)
	{
		const char* p = post;
		double num;
		double left, right;
		stack<double>ds;

		while (*p)
		{
			if (isdigit(*p) != false)
				// 숫자
			{
				num = atof(p);
				ds.push(num);

				while (isdigit(*p) != false || *p == '.')
					p++;
			}

			else
				// 연산자
			{
				if (strchr("^*/+-", *p) != nullptr)
				{
					// 연산자라면 스택에서 숫자를 꺼내 연산 후 계산 결과를 다시 스택에 삽입
					right = ds.top();
					ds.pop();

					left = ds.top();
					ds.pop();

					switch (*p)
					{
					case'+':ds.push(left + right); break;
					case'-':ds.push(left - right); break;
					case'*':ds.push(left * right); break;
					case'/':ds.push(left / right); break;
					case'^':ds.push(pow(left, right)); break;
					}
				}
				++p;
			}
		}
		return ds.top();
	}
};