#include"Myarray.hpp"

class Mater {
public:
	Mater(){}
	Mater(string name, int age) {
		this->age = age;
		this->name = name;
	}
public:
	string name;
	int age;
};
void myprint( Myarray<Mater>& arr) {
	for (int i = 0; i < arr.getsize(); i++) {
		cout << "ĞÕÃû:" << arr[i].name << " ÄêÁä:" << arr[i].age << endl;
	}
}
int main()
{
	Myarray<Mater>arr(4);
	Mater a1("zhangshan", 10);
	Mater a2("zhang", 18);
	Mater a3("shan", 19);
	Mater a4("dsadas", 12);
	arr.push_back(a1);
	arr.push_back(a2);
	arr.push_back(a3);
	arr.push_back(a4);
	myprint(arr);
	Myarray<int>arr1(10);
	for (int i = 0; i < arr1.getcapacity(); i++) {
		arr1.push_back(i+1);
	}
	for (int i = 0; i < arr1.getcapacity(); i++) {
		cout << arr1[i] << " ";
	}
	return 0;
}