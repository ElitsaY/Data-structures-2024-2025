#include <iostream>
#include <set>


class Person {
	int age;
	std::string name;

public:
	Person(int age, const std::string& name) : age(age), name(name) {}

	int getAge() const {
		return this->age;
	}
};

class Comparator {
public:
	bool operator()(const Person& p1, const Person& p2) const {
		return p1.getAge() < p2.getAge();
	}
};

int main() {

	std::set<Person, Comparator> sp;
	sp.emplace(5, "gosho");
}