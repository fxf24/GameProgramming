#include <iostream>
using namespace std;

class BaseClass
{
public :
	string isPublic;

protected :
	string isProtected;

private :
	string isPrivate;

public :
	BaseClass()
	{
		isPrivate   = "Private";
		isProtected = "Private";
		isPublic    = "Private";
	}

public :
	void PrintMember()
	{
		cout << "isPrivate   : " << isPrivate   << endl;
		cout << "isProtected : " << isProtected << endl; 
		cout << "isPublic    : " << isPublic    << endl;
	}
};

// 상속시 접근제한자의 기능
// 기반 클래스 제한자			 파생 클래스 제한자
//						: public
// public					public
// protected				protected
// private					private
//						: protected
// public					protected
// protected				protected
// private					private
//						: private
// public					private
// protected				private
// private					private

class DerivedClass1 : public BaseClass
{
public :
	DerivedClass1()
	{
		isPublic    = "Public";				// public
		isProtected = "Protected";			// protected
		// isPrivate == "Private" - Error - // private
	}
};

class DerivedClass2 : protected BaseClass
{
public :
	DerivedClass2()
	{
		isPublic    = "Protected";			// protected
		isProtected = "Protected";			// protected
		// isPrivate == "Private" - Error - // private
	}
};

class DerivedClass3 : private BaseClass
{
public :
	DerivedClass3()
	{
		isPublic	= "Private";			// private
		isProtected = "Private";			// private
		// isPrivate == "Private" - Error - // private
	}
};


int main()
{
	DerivedClass1 Public    = DerivedClass1();
	Public.isPublic;
	// Public.isProtected; - Error -
	// Public.isPrivate;   - Error -
	Public.PrintMember();
	
	DerivedClass2 Protected = DerivedClass2();
	//Protected.isPublic;	 - Error -
	//Protected.isProtected; - Error -
	//Protected.isPrivate;   - Error -

	DerivedClass3 Private   = DerivedClass3();
	//Private.isPublic;    - Error -
	//Private.isProtected; - Error -
	//Private.isPrivate;   - Error -

	return 0;
}