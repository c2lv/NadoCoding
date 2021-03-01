#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	getRandomNumber(int level);
void	showQuestion(int level, int num1, int num2);
void	success();
void	fail();
void	setTimelimit();
void	end();
void	timeout();
void	checkTimeout(int initial_time, int lim, int count);
void	result(int count);

int	main(void)
{
	// 문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
	// 제한 시간 설정 가능
	// 맞히면 통과, 제한 시간이 지나거나 틀리면 실패
	// 입력값 예외처리 완벽하지 않음
	setTimelimit();
	int tlim = 1;
	int lim = -1;
	scanf_s("%d", &lim);
	if (lim == -1)
	{
		end();
	}
	else if (lim == 0)
	{
		tlim = 0;
	}

	srand(time(NULL));
	int count = 0;
	time_t initial_time = time(NULL);
	for (int i = 1; i <= 5; i++)
	{
		// x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		// printf("%d x %d ?", num1, num2);
		showQuestion(i, num1, num2);
		int answer = -1;
		scanf_s("%d", &answer);
		if (tlim)
		{
			checkTimeout(initial_time, lim, count);
			// 정답 확인(count 값 변동) 전에 시간 체크
		}
		if (answer == -1)
		{
			end();
		}
		else if(answer == num1 * num2)
		{
			// 성공
			success();
			count++;
		}
		else
		{
			// 실패
			fail();
		}
	}

	result(count);

	return 0;
}

int	getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void	showQuestion(int level, int num1, int num2)
{
	printf("\n########## %d 번째 비밀번호 ##########\n", level);
	printf("\n             %d x %d 는?\n\n", num1, num2);
	printf("#####################################\n");
	printf("\n비밀번호를 입력하세요 (종료 : -1) >> ");
}
void	success()
{
	printf("\n >> Good! 정답입니다 \n");
}
void	fail()
{
	printf("\n >> 땡! 틀렸습니다 \n");
}

void	setTimelimit()
{
	printf("\n도전 제한 시간을 입력하세요\n(초 단위로 입력 / 제한 없음: 0 / 종료: -1) >> ");
	// 쉬움, 보통, 어려움을 선택하게 하고 그에 따라 알맞은 시간을 설정해줘도 괜찮을 듯
	// 비밀번호 입력 제한시간은 구현하기 어려워서 총 도전 제한시간 구현으로 대체
}

void	end()
{
	printf("\n프로그램을 종료합니다\n");
	exit(0); // 여기서 프로그램 종료
}

void	timeout()
{
	printf("\n >> 제한 시간이 지났습니다 \n");
}

void	checkTimeout(int initial_time, int lim, int count)
{
	if ((time(NULL) - initial_time) > lim)
	{
		timeout();
		result(count);
	}
}

void	result(int count)
{
	printf("\n 당신은 5개의 비밀번호 중 %d 개를 맞혔습니다\n", count);
	exit(0);
}