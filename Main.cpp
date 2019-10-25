#include <iostream>

using namespace std;


struct Point {
	double x;
	double y;
};

Point* table;
double a, b, h;
int n;

double f(double x) {
	return sqrt(1+x	);
}

void fillTable() {

	double k = 0;
	for (int i = 0; i <= n; i++, k += h) {
		table[i].x = a + k;
		table[i].y = f(a + k);
	}

}

void printTable() {
	cout.precision(3);
	cout << "\ni\t" << "xi\t" << "f(xi)" << endl;
	
	for (int i = 0; i <= n; i++) {
		cout << i << "\t" << table[i].x << "\t" << table[i].y << endl;
	}

	cout << endl;
}

double leftRectangle() {
	double res = 0.0;

	for (int i = 0; i < n; i++) res += table[i].y;

	return res*h;
}

double rightRectangle() {
	double res = 0.0;

	for (int i = 1; i <= n; i++) res += table[i].y;

	return res * h;
}

double centerRectanle() {
	double res = 0;

	for (int i = 0; i < n; i++) {
		double ss = f(a + h * (i + 0.5));
		cout << "ss ="  << ss << endl;
		res += ss;
	}

	return res * h;
}

double trapezoid() {
	double res = table[0].y + table[n].y;

	for (int i = 1; i < n; i++) {
		res += 2*table[i].y;
	}

	return (h / 2) * res;
}

double simpson() {
	double res = table[0].y + table[n].y;

	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) res += 2 * table[i].y;
		else res += 4 * table[i].y;
	}

	return (h / 3) * res;
}

int main() {
	setlocale(LC_ALL, "rus");
	
	cout << "a " << "b " << "n" << endl;
	cin >> a >> b >> n;
	h = (b - a) / n;

	table = new Point[n+1];
	fillTable();
	printTable();

	cout.precision(5);
	cout << "Метод левостороних прямоугольников: " << leftRectangle() << endl;
	cout << "Метод правостороних прямоугольников: " << rightRectangle() << endl;
	cout << "Метод серединных прямоугольников: " << centerRectanle() << endl;
	cout << "Метод трапеции: " << trapezoid() << endl;
	cout << "Метод Симпсона: " << simpson() << endl;

	system("pause");
	return 0;
}
