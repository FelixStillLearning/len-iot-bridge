#include <iostream>
using std::string;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
};


int main(){
    Employee employee1;
    employee1.Name = "Felix";
    employee1.Company = "SomeCompany";
    employee1.Age = 25;

    employee1.IntroduceYourself();

    Employee employee2;
    employee2.Name = "Rael";
    employee2.Company = "BujangCompany";
    employee2.Age = 21;
}