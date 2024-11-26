#include <iostream>  
#include <vector>  
using namespace std;
class Pet {
protected:
    const char* name; 

public:
    Pet(const char* name) : name(name) {}

    virtual void Sound() const = 0; // Чисто виртуальная функция  
    virtual void Show() const {
        cout << "Имя: " << name << endl;
    }
    virtual const char* Type() const = 0; // Чисто виртуальная функция  

    virtual ~Pet() {} // Виртуальный деструктор  
};

class Dog : public Pet {
public:
    Dog(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " говорит: Гав!" << endl;
    }

    const char* Type() const override {
        return "Собака";
    }
};

class Cat : public Pet {
public:
    Cat(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " говорит: Мяу!" << endl;
    }

    const char* Type() const override {
        return "Кошка";
    }
};

class Parrot : public Pet {
public:
    Parrot(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " говорит: Привет!" << :endl;
    }

    const char* Type() const override {
        return "Попугай";
    }
};

class Hamster : public Pet {
public:
    Hamster(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " говорит: Пи-пи!" << endl;
    }

    const char* Type() const override {
        return "Хомяк";
    }
};

int main() {
    // Создаем массив указателей на базовый класс Pet  
    vector<Pet*> pets;

    // Заполняем массив различными объектами  
    pets.push_back(new Dog("Шарик"));
    pets.push_back(new Cat("Мурка"));
    pets.push_back(new Parrot("Кеша"));
    pets.push_back(new Hamster("Хомка"));


    for (const auto& pet : pets) {
        pet->Show();
        pet->Sound();
        cout << "Тип: " << pet->Type() << endl << endl;
    }

    // Освобождаем память  
    for (const auto& pet : pets) {
        delete pet;
    }

    return 0;
}