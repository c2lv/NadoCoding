#include <stdio.h>

int	main(void)
{
	/*int	age;

	age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);*/

	/*float f;
	double d;

	f = 46.5f;
	printf("%.1f\n", f);
	d = 4.428;
	printf("%.2lf\n", d);*/

	// const int YEAR = 2000;
	// printf(" : %d\n", YEAR);
	// YEAR = 2001;

	// printf
	// int add = 3 + 7; // 10
	// printf("3 + 7 = %d\n", add);
	// printf("%d x %d = %d\n", 30, 79, 30 * 79);

	// scanf
	// https://wikidocs.net/2154
	// int input;
	// printf(" : ");
	// scanf_s("%d", &input);
	// printf(" : %d\n", input);

	// int one, two, three;
	// printf(" : ");
	// scanf_s("%d %d %d", &one, &two, &three);
	// printf(" : %d\n", one);
	// printf(" : %d\n", two);
	// printf(" : %d\n", three);

	// char c = 'A';
	// printf("%c\n", c);

	// char str[256];
	// scanf_s("%s", str, sizeof(str));
	// printf("%s\n", str);

	char name[256];
	printf("�̸��� ������? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("�� ���̿���? ");
	scanf_s("%d", &age);

	float weight;
	printf("�����Դ� �� kg�̿���? ");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� �� cm�̿���? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("���� ���˸� ���������? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n--- ������ ���� ---\n\n");
	printf(" �̸�      : %s\n", name);
	printf(" ����      : %d\n", age);
	printf(" ������    : %.2f\n", weight);
	printf(" Ű        : %.2lf\n", height);
	printf(" ����      : %s\n", what);

	return 0;
}
