#include <iostream>
#include <vector>
#include <string>


class Animal
{
protected:
	std::string m_name;

public:
	Animal(std::string name) //our name constructor
		: m_name(name)
	{
	}
	std::string getName()
	{
		return this->m_name;
	}

	virtual const std::string speak() = 0; //pure virtual func
};

class Doggo : public Animal
{
public:
	Doggo(std::string name)
		:Animal(name)//og animal constructor
	{

	}
	virtual const std::string speak()
	{
		return "Woof! C:";
	}
};
class Bird : public Animal
{
public:
	Bird(std::string name)
		:Animal(name)//og animal constructor
	{

	}
	virtual const std::string speak()
	{
		return "SCREECH <O}";
	}
};

class Cat : public Animal
{
public:
	Cat(std::string name)
		:Animal(name) //using the original animal constructor
	{
	}
	virtual const std::string speak()
	{
		return "MEOW! :3";
	}
};

int main()
{
	using namespace std;
	vector <Animal*> animalv;
	bool isDone = false;
	while (isDone == false)
	{
		cout << "A. Add Doggo" << endl;
		cout << "B. Add Bird" << endl;
		cout << "C. Add Cat" << endl;
		cout << "D. Display All" << endl;
		cout << "Q. Quit" << endl;
		char input;
		cin >> input;

		string aname;
		switch (input)
		{
		case 'a':
		{
			cout << "What is the name of this doggo?" << endl;
			cin >> aname;
			Doggo aDoggo(aname);
			animalv.push_back(&aDoggo);
			break;
		}
		case 'b':
		{
			cout << "What is the name of this birb?" << endl;
			cin >> aname;
			Bird aBird(aname);
			animalv.push_back(&aBird);
			break;
		}
		case 'c':
		{
			cout << "What is the name of this kitty?" << endl;
			cin >> aname;
			Cat aCat(aname);
			animalv.push_back(&aCat);
			break;
		}
		case 'd':
			for (int x = 0; x < animalv.size(); x++)
				cout << animalv[x]->getName() << " says " << animalv[x]->speak() << endl;
			break;
		case 'q':
			isDone = true;
			break;
		}//end switch

	}

	return 0;
}

