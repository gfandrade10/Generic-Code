#include <iostream>
#include <vector>
#include <memory>

class Person{
    public:
        Person() {}

        Person(std::string name, size_t age, size_t id, long salary) 
            : Name (name), Age(age), ID(id), Salary(salary)
            {
                std::cout << "New person created: " << Name << std::endl << std::endl;
            }
        
        ~Person()
        {
            std::cout << Name << " removed from system." << std::endl;
        }

        Person& operator=(const Person& ref)
        {
            this->Name = ref.Name;
            this->Age = ref.Age;
            this->ID = ref.ID;
            this->Salary = ref.Salary;
            return *this;
        }
    
        void changeSalary(long Slr);
        void incrementAge();
        void Print();
    
    private:
        std::string Name;
        size_t Age;
        size_t ID;
        long Salary;
};

typedef std::unique_ptr<Person> NewPerson;

void Person::changeSalary(long Slr)
{
    this->Salary = Slr;
}

void Person::incrementAge()
{
    Age++;
}

void Person::Print()
{
    std::cout << "Person information:\n";
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Age: " << Age << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Salary: " << Salary << "\n\n";
}

NewPerson CreatePerson(){
    std::string name;
    size_t age;
    size_t id;
    long salary;

    std::cout << "Enter new Person information:\n";
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Salary: ";
    std::cin >> salary;
    NewPerson Obj(new Person(name, age, id, salary));

    return Obj;
}

void WinMain(){
    NewPerson pit = CreatePerson();
    Person gui;
    std::cout << "People data:\n\n";

    gui = (*pit);
    gui.Print();
    pit->Print();

    std::cin.get();
}