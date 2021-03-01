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
	// ���� 5���� �ְ�, �� ������ ���� ����� ���� ��� ���� (����)
	// ���� �ð� ���� ����
	// ������ ���, ���� �ð��� �����ų� Ʋ���� ����
	// �Է°� ����ó�� �Ϻ����� ����
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
			// ���� Ȯ��(count �� ����) ���� �ð� üũ
		}
		if (answer == -1)
		{
			end();
		}
		else if(answer == num1 * num2)
		{
			// ����
			success();
			count++;
		}
		else
		{
			// ����
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
	printf("\n########## %d ��° ��й�ȣ ##########\n", level);
	printf("\n             %d x %d ��?\n\n", num1, num2);
	printf("#####################################\n");
	printf("\n��й�ȣ�� �Է��ϼ��� (���� : -1) >> ");
}
void	success()
{
	printf("\n >> Good! �����Դϴ� \n");
}
void	fail()
{
	printf("\n >> ��! Ʋ�Ƚ��ϴ� \n");
}

void	setTimelimit()
{
	printf("\n���� ���� �ð��� �Է��ϼ���\n(�� ������ �Է� / ���� ����: 0 / ����: -1) >> ");
	// ����, ����, ������� �����ϰ� �ϰ� �׿� ���� �˸��� �ð��� �������൵ ������ ��
	// ��й�ȣ �Է� ���ѽð��� �����ϱ� ������� �� ���� ���ѽð� �������� ��ü
}

void	end()
{
	printf("\n���α׷��� �����մϴ�\n");
	exit(0); // ���⼭ ���α׷� ����
}

void	timeout()
{
	printf("\n >> ���� �ð��� �������ϴ� \n");
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
	printf("\n ����� 5���� ��й�ȣ �� %d ���� �������ϴ�\n", count);
	exit(0);
}