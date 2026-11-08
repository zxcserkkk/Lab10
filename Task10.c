#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double a(double x)
{
	double y;
	if (x <= 3)
		y = x * x - 3 * x + 9;
	else
		y = 1 / (x * x * x + 3);
	return y;
}
double b(double x)
{
	double y;
	y = x * exp(sin(x * x));
	return y;
}

double sc(double x, int N)
{
	double s = 0, a = x;
	int k;
	for (k = 1; k <= N; k++) {
		s = s + a;
		a = -a * x * x / ((2 * k) * (2 * k + 1));
	}
	return s;
}

double sd(double x, double eps)
{
	double s = 0, a = x;
	int k = 1;
	while (fabs(a) >= eps) {
		s = s + a;
		a = -a * x * x / ((2 * k) * (2 * k + 1));
		k++;
	}
	return s;
}

int main()
{
	setlocale(LC_ALL, ".UTF-8");
	double x, eps;
	int t, m, n;

	printf("1 - задание 1, 2 - задание 2: ");
	scanf("%d", &t);

	if (t == 1)
	{
		printf("Введите x: ");
		scanf("%lf", &x);
		do
		{
			printf("\n1 - F1(x)\n2 - F2(x)\n3 - произведение\n4 - разность квадратов\n5 - удвоенная сумма\n0 - выход\n");
			printf("Ваш выбор: ");
			scanf("%d", &m);
			if (m == 1)
				printf("fa(x)=%lf\n", a(x));
			else if (m == 2)
				printf("fb(x)=%lf\n", b(x));
			else if (m == 3)
				printf("произведение = %lf\n", a(x) * b(x));
			else if (m == 4)
				printf("разность квадратов = %lf\n", a(x) * a(x) - b(x) * b(x));
			else if (m == 5)
				printf("удвоенная сумма = %lf\n", 2 * (a(x) + b(x)));
			else if (m != 0)
				printf("Нет такого пункта\n");
		} while (m != 0);
	}

	if (t == 2)
	{
		printf("Введите x: ");
		scanf("%lf", &x);
		printf("Введите точность eps: ");
		scanf("%lf", &eps);
		printf("sin(x) из библиотеки = %.10lf\n\n", sin(x));
		printf(" N |    sc     | отклонение\n");
		for (n = 1; n <= 10; n++)
			printf("%2d | %.10lf | %+.4e\n", n, sc(x, n), sc(x, n) - sin(x));
		printf("\nsd = %.10lf, отклонение = %+.4e\n", sd(x, eps), sd(x, eps) - sin(x));
	}

	return 0;
}