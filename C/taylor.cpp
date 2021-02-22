//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//void taylor(float x, float eps)
//{
//	float f = 0;
//	float a = 1;
//	float b = 0;
//	int N;
//	for (N = 1; abs(a) >= eps; N++)
//	{
//		f += a;
//		b = a;
//		a *= -x * x / (N * 2 * (N * 2 - 1));
//	}
//	cout << "f = " << f << ", N = " << N << ", x = " << x << endl;
//}
//int main() {
//	double A, B, dx, eps;
//	float i;
//	cout << "A = ";
//	cin >> A;
//	cout << "B = ";
//	cin >> B;
//	cout << "dx = ";
//	cin >> dx;
//	cout << "eps = ";
//	cin >> eps;
//	cout << "+-----+--------+-----+" << endl;
//	cout << "| x | f(x) | N |" << endl;
//	cout << "+-----+--------+-----+" << endl;
//
//	for (i = A; i < B + dx; i += dx) {
//		taylor(i, eps);
//	}
//}
