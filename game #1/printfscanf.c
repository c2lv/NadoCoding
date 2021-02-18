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
	printf("이름이 뭐예요? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇 살이에요? ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 몇 kg이에요? ");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇 cm이에요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀어요? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n--- 범죄자 정보 ---\n\n");
	printf(" 이름      : %s\n", name);
	printf(" 나이      : %d\n", age);
	printf(" 몸무게    : %.2f\n", weight);
	printf(" 키        : %.2lf\n", height);
	printf(" 범죄      : %s\n", what);

	return 0;
}
