#include "TemplateClass.h"


int main()
{
	TemplateClass<float> myTClass = TemplateClass<float>(1.5f, 3.1f);
	myTClass.GetValues();
	cout << "value1 + value2 : " <<myTClass.Add() << endl;

	return 0;
}