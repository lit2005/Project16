#include <iostream>  
#include <vector>  
using namespace std;
class Pet {
protected:
    const char* name; 

public:
    Pet(const char* name) : name(name) {}

    virtual void Sound() const = 0; // ����� ����������� �������  
    virtual void Show() const {
        cout << "���: " << name << endl;
    }
    virtual const char* Type() const = 0; // ����� ����������� �������  

    virtual ~Pet() {} // ����������� ����������  
};

class Dog : public Pet {
public:
    Dog(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " �������: ���!" << endl;
    }

    const char* Type() const override {
        return "������";
    }
};

class Cat : public Pet {
public:
    Cat(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " �������: ���!" << endl;
    }

    const char* Type() const override {
        return "�����";
    }
};

class Parrot : public Pet {
public:
    Parrot(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " �������: ������!" << :endl;
    }

    const char* Type() const override {
        return "�������";
    }
};

class Hamster : public Pet {
public:
    Hamster(const char* name) : Pet(name) {}

    void Sound() const override {
        cout << name << " �������: ��-��!" << endl;
    }

    const char* Type() const override {
        return "�����";
    }
};

int main() {
    // ������� ������ ���������� �� ������� ����� Pet  
    vector<Pet*> pets;

    // ��������� ������ ���������� ���������  
    pets.push_back(new Dog("�����"));
    pets.push_back(new Cat("�����"));
    pets.push_back(new Parrot("����"));
    pets.push_back(new Hamster("�����"));


    for (const auto& pet : pets) {
        pet->Show();
        pet->Sound();
        cout << "���: " << pet->Type() << endl << endl;
    }

    // ����������� ������  
    for (const auto& pet : pets) {
        delete pet;
    }

    return 0;
}