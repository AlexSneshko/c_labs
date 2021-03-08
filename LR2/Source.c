#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool check_order(float weight, float length) {
	if (weight < 50 || weight > 300 || length < 0 || length > 4000) {
		return false;
	}
	return true;
}

int count_number_of_cars(float weight) {
	int cutted_weight = (int)weight;
	int number_of_cars = (cutted_weight - cutted_weight % 20) / 20 + 1;

	if (weight == (int)weight && (int)weight % 20 == 0) {
		return weight / 20;
	}

	return (int)weight / 20 + 1;
}

int factorial(int last_number) {
	if (last_number == 1) {
		return 1;
	}
	return last_number * factorial(last_number - 1);
}

float count(float x, int i, double *sum_row, float sin_x, float fault) {
	double term;
	term = pow(-1, i - 1) * pow(x, (double)(2 * i - 1)) / factorial(2 * i - 1);

	if (term < fault) {
		term = pow(-1, i - 1) * pow(x, (double)(2 * i - 1)) / factorial(2 * i - 1);
		printf("%lf\t -- %lf\n", pow(x, 2 * i - 1), term);
		*sum_row += term;
		return term;
	}
	term = (-1) * count(x, i + 1, sum_row, sin_x, fault) * (2 * i) * (2 * i + 1) / pow(x, 2);
	printf("%d\t -- %lf\n", i, term);
	*sum_row += term;

	return term;

}


void program1() {

	float weight;
	float length;
	int number_of_cars;
	float insurance_cost;
	float full_cost;
	char chooser;

	while (true) {
		printf("print weight(tons): ");
		scanf_s("%f", &weight);
		printf("print length: ");
		scanf_s("%f", &length);

		if (check_order(weight, length)) {
			printf("order accepted\n");

			number_of_cars = count_number_of_cars(weight);
			printf("number of cars: %d\n", number_of_cars);

			full_cost = length * 2;
			printf("full cost: %.2f\n", full_cost);

			insurance_cost = full_cost * 0.05;
			printf("insurance cost: %.2f\n", insurance_cost);

		}
		else {
			printf("impractical or imposible\n");
		}
		printf("\nprint c - continue, q - quit: ");
		scanf_s("%c\n", &chooser);
		if (chooser != 'c') {
			break;
		}
	}
}


void program_2() {

	double x = 0.8, fault = 0.02, sin_x, sum_row = 0;

	/*
	printf("print x : ");
	scanf_s("%f", &x);
	printf("print fault: ");
	scanf_s("%f", &fault);
	*/

	sin_x = sin(x);
	int i = 0;


	//printf("%lf\n",pow(-1, 4 - 1)* pow(x, 2 * 4 - 1) / factorial(1, 2 * 4 - 1));
	count(x, 1, &sum_row, sin_x, fault);
	printf("sin(x) = %lf\n", sin_x);
	printf("sum of raw = %lf\n", sum_row);
}

void enter(int* a) {
	scanf_s("%d", a);
}

int main() {
	
	//program1();
	program_2();

	/*
	int a;
	enter(&a);
	printf("izi %d", a);
	*/

	_getch();
	return 0;
}