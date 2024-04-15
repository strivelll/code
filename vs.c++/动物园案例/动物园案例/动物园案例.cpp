#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
using namespace std;
class Animal {
public :
	virtual void speak()=0;
};
class Dog:public Animal {
public:
	Dog(string name, int age) {
		this->age = age;
		this->name = name;
	}
	virtual void speak() {
		cout << "name:" << name << " age:" << age << " ÍôÍôÍô"<<endl;
	}
private:
	string name;
	int age;
};
class Cat :public Animal {
public:
	Cat(string name, int age) {
		this->age = age;
		this->name = name;
	}
	virtual void speak() {
		cout << "name:" << name << " age:" << age <<" ß÷ß÷ß÷"<< endl;
	}
private:
	string name;
	int age;
}; class Tiger :public Animal {
public:
	Tiger(string name, int age) {
		this->age = age;
		this->name = name;
	}
	virtual void speak() {
		cout << "name:" << name << " age:" << age << " à»à»à»"<<endl;
	}
private:
	string name;
	int age;
};
class Zoo {
public:
	Zoo() {
		msize = 0;
		mcapacity = 1024;
		p = new Animal * [mcapacity];
	}
	int AddAnimal(Animal* animal) {
		if (msize == mcapacity) {
			cout << "ÈÝÁ¿ÒÑÂú" << endl;
			return -1;
		}
		p[msize++] = animal;
	}
	void startspeak() {
		for (int i = 0; i < msize; i++) {
			p[i]->speak();
		}
	}
	~Zoo() {
		for (int i = 0; i < msize; i++) {
			if (p[i] != NULL) {
				delete p[i];
				p[i] = NULL;
			}
		}
		delete[] p;
	}
private:
	int msize;
	int mcapacity;
	Animal** p;
};
int main()
{
	Zoo zoo;
	zoo.AddAnimal(new Dog("Ð¡ºÚ", 90));
	zoo.AddAnimal(new Cat("Ð¡»¨", 10));
	zoo.AddAnimal(new Tiger("Ð¡»¢", 20));
	zoo.startspeak();
	return 0;
}