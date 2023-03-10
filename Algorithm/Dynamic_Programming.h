#pragma once

// Dynamic_Programming.h

/*
	※ 동적 계획법(dynamic programing)
		ㄴ 동적 계획법은 큰 문제를 작은 문제로 나눠 가면서 푸는 방식의 알고리즘.
		ㄴ  처음 주어진 문제를 더 작은 문제들로 나눈 뒤 각 조각의
		답을 계산하고, 이 답들로부터 원래 문제에 대한 답을
		계산해낸다는 점에서 분할 정복과 비슷하다.

		ㄴ 동적계획법에서는 쪼개진 작은 문제가 중복이되지만,
		분할 정복은 절대로 중복 될수 없다.

		ㄴ 동적 계획법에서는 어떤 부분 문제는 두 개 이상의 문제를
		푸는데 사용될 수 있기 때문에 이 문제의 답을 여러번 계산하는
		대신 한 번만 계산하고 그 결과를 재활용함으로써 속도를
		향상 시킬수 있다.

	※ 동적 계획법의 조건
		1. 겹치는 부분 문제
		겹치는 부분 문제는 어떤 문제가 여러개의 부분 문제로
		쪼개질 수 있을때 사용하는 용어.
		이때 부분 문제란 항상 새로운 부분 문제를 생성해 내기
		보다는 계속해서 같은 부분 문제가 여러번 재사용되거나
		재귀 알고리즘을 통해 해결되는 문제

		겹치는 부분 문제가 있다면, 큰 문제를 작은 문제들을
		통해서 정답을 구할수 있다.

		2. 최적 부분 구조.
		최적의 해결책이 그 부분 문제의 최적의 해결책으로부터
		설계될 수 있는 경우를 말한다.

		서울에서 부산을 가는 가장 빠른길이 대전과 대구를 순서대로
		거쳐야 한다면..?

		서울 대전 대구 부산 : 최단 경로

		대전에서 부산으로 가는 최단경로?
		대전 대구 부산 : 최단 경로 -> 최적 부분 구조

		가장 빠른 경로가 서울 대전 울산 부산
		대전에서 부산까지의 최단경로?

		피보나치 수열에서 10번째 값을 구하면서 얻은 4번째 피보나치 수
		피보나치 수열에서 9번째 값을 구하면서 얻은 4번째 피보나치 수

		어떻게 하든 모두 같은 값이 나오는데 계속 값을 구하는것이
		비효율적이다.
		그래서 이때 이를 해결할수 있는 방법이 메모리제이션

		동적 계획법에서는 각 문제를 단 한번만 풀어야 한다.
		중복되는 부분 문제를 여러번 풀지 않는다.
		최적 부분구조를 만족하기 때문에 같은 문제는 구할때마다
		정답이 같으므로 정답을 한 번 구했으면, 그 정답을 캐시에
		메모해놓는다.
		이렇게 메모하는 것을 코드의 구현에서는 배열에 저장하는 것으로
		할 수 있으며, 이를 메모리제이션이라 한다.

	※ 동적 계획법 구현 방식

	1. top-down : 큰 문제를 작은 문제로 쪼개가면서 푸는 방식.(재귀)
	2. bottom-top : 작은 문제부터 차례대로 푼다. (반복)

	top-down
		1. 큰 문제를 작은 문제로 나눈다.
		2. 작은 문제를 푼다.
		3. 작은 문제를 풀었으니, 큰 문제를 푼다.

	bottom-up
		1. 문제를 크기가 작은 문제부터 차례대로 푼다.
		2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점푼다.
		3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
		4. 반복하다 보면 가장 큰 문제를 풀 수 있다.

*/

#include<iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n <= 1)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int cache1[100];

int Fibonacci_Top_Down(int n)
{
	if (n <= 1)
		return n;
	{
		if (cache1[n] > 0)
			return cache1[n];

		return cache1[n] = Fibonacci_Top_Down(n - 1) + Fibonacci_Top_Down(n - 2);
	}
}

int cache2[100];

int Fibonacci_Bottom_Up(int n)
{
	cache2[0] = 0;
	cache2[1] = 1;

	for (int i = 2; i <= n; i++)
		cache2[i] = cache2[i - 1] + cache2[i - 2];
}