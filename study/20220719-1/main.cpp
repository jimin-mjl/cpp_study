#include "calculator.h"

int main()
{
	Calculator cal;
	cal.Init();

	cout << "3.2 + 2.4 = " << cal.Add(3.2f, 2.4f) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5f, 1.7f) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2f, 1.5f) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9f, 1.2f) << endl;
	cal.ShowOpCount();
}
