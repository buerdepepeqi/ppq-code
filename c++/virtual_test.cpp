/*************************************************************************
 * @File Name: virtual_test.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Tue Mar 25 23:43:37 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>

using namespace std;

class Person
{
public:
	Person()
	{
		cout << "我是基类构造函数" << endl;
	}
    

    ~Person()
    //virtual ~Person()
	{
		cout << "我是基类析构函数" << endl;
	}

    void Display()
	{
		cout << "我是基类" << endl;
	}
};

class Student : public Person
{
public:
	Student()
	{
		cout << "我是派生类构造函数" << endl;
	}
	~Student()
	{
		cout << "我是派生类析构函数" << endl;
	}
	void Display() {
		cout << "我是派生类" << endl;
	}
};

int main()
{
	Person *p = new Student();
	p->Display();
	delete p;
	system("pause");
	return 0;
}
