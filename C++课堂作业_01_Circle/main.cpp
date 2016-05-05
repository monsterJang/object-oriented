#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
	double r;
	cout << "Please input the radius of a circle : " << endl;
	cin >> r;
	cout << "The erea of this circle is : " << endl;
	cout << CircleArea(r) << endl;

//	system("pause");
	return 0;
}