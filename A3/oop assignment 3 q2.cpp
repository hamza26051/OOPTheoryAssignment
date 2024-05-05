#include <iostream>
#include <string>

using namespace std;
template <typename T>
class Pet {
protected:
    string name;
    int age;

public:
    Pet(string _name, int _age) : name(_name), age(_age) {}

    virtual void makeSound() const = 0;

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

class Cat : public Pet<Cat> {
public:
    Cat(string _name, int _age) : Pet(_name, _age) {}

    void makeSound() const override {
        cout << "Meow" << endl;
    }
};

class Dog : public Pet<Dog> {
public:
    Dog(string _name, int _age) : Pet(_name, _age) {}

    void makeSound() const override {
        cout << "Woof" << endl;
    }
};

class Bird : public Pet<Bird> {
public:
    Bird(string _name, int _age) : Pet(_name, _age) {}

    void makeSound() const override {
        cout << "Chirp" << endl;
    }
};

int main() {
    Cat cat("Whiskers", 3);
    Dog dog("Buddy", 5);
    Bird bird("Tweetie", 1);

    Pet<Cat>* catPtr = &cat;
    Pet<Dog>* dogPtr = &dog;
    Pet<Bird>* birdPtr = &bird;

    cout << "Cat: " << catPtr->getName() << "Age: " << catPtr->getAge() << " Sound: ";
    catPtr->makeSound();

    cout << "Dog: " << dogPtr->getName() << "Age: " << dogPtr->getAge() << "Sound: ";
    dogPtr->makeSound();

    cout << "Bird: " << birdPtr->getName() << "Age: " << birdPtr->getAge() << "Sound: ";
    birdPtr->makeSound();

    return 0;
}

