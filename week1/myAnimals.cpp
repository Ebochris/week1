#include <iostream>

class animal {
private:
	bool asleep;
public:
	int argAge = 0;
	int weight = 0;
	static int count;
	//attributes
	std::string species;
	std::string argName;


	// object functions
	void eat() {
		std::cout << "The animal have a dinner.\n";
	}
	void addWeight(int dw) {
		weight += dw;
	}
	bool isAsleep() {
		if (asleep == 1) {
			std::cout << "the animal sleep now. \n";
			return true;
		}
		else {
			std::cout << "the animal is awake";
			return false;
		}
	}
	void sleep() {
		asleep = true;
		std::cout << "The animal goes asleep.";
	}
	void wake() {
		asleep = false;
		std::cout << "The animal awake.";
	}

	// static function
	static int getCount() {
		return count;
	}


	//parametric constructor
	animal(std::string argSpecies, int argWeight) {
		species = argSpecies;
		weight = argWeight;
		asleep = false;
		std::cout << "Lets create a parametric constructor animal object \n";
		count++;
	}
	// Deconstructor
		~animal() {
		std::cout << "the object was deleted. \n";
	}
};

int animal::count = 0;

class dog : public animal {

public:
	std::string name;
	int age;
	dog(std::string argSpecies, int argWeight, std::string argName, int argAge) : animal(argSpecies, argWeight) {
		name = argName;
		age = argAge;
	};

	void bark() {
		std::cout << "Woof, woof. \n";
	}
	void eat(std::string food = "None") {
		if (food == "None") {
			std::cout << "the dog eats futt" << food << ".\n";
		}else{
		std::cout << "the dog eats meal. \n";
			}
	}
	friend bool operator < (dog dog1, dog dog2) {
		return dog1.weight < dog2.weight;
	}

};

int main() {

	dog meinHund1("dog", 13, "Bella", 13);
	dog meinHund2(  "dog", 12, "Hella", 4);

	std::cout << (meinHund1 < meinHund2);

}
