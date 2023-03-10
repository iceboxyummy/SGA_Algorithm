#pragma once

// Divide_Conquer.h

/*
	※ 분할 정복(Divide - Conquer)
			ㄴ 어떠한 큰 문제를 해결하기 위해 큰 문제를 작은 단위의 문제로 나누어서 해결하는 방식
			ㄴ 부분 문제가 중복 안됨.
			ㄴ 병렬처리 가능
			ㄴ 메모리제이션 사용 안함

	※ 동적 프로그래밍과의 차이점
			ㄴ 크기가 작은 부분 문제들을 해결한 후 해당 부분문제의 해를 이용해서 보다 큰 크기의 부분문제를 해결하는 방식.
			ㄴ 부분 문제가 중복되며, 메모리제이션을 사용함.
			ㄴ 병렬처리 불가능

	※ 분할 정복의 요령
			1. Divide : 문제가 분할이 가능한 경우 2개 이상의 문제로 나눈다.
			2. Conquer : 나누어진 문제가 여전히 분할이 가능하면 다시 분할, 그렇지 않으면 문제를 해결
			3. Combine : 정복한 문제들을 통합하여 원래 문제의 답을 얻는다.
*/

/*
	https://www.acmicpc.net/problem/1780

		 0  1  2     3  4  5     6  7  8

	0	00 00 00	+1 +1 +1	-1 -1 -1
	1	00 00 00	+1 +1 +1	-1 -1 -1
	2	00 00 00	+1 +1 +1	-1 -1 -1

	3	+1 +1 +1	00 00 00	00 00 00
	4	+1 +1 +1	00 00 00	00 00 00
	5	+1 +1 +1	00 00 00	00 00 00

	6		00 +1 -1	00 +1 -1
	7		00 +1 -1	00 +1 -1
	8		+1 00 -1	00 +1 -1

	00	01	-1

	00	-1	+1

	00	+1	-1
*/