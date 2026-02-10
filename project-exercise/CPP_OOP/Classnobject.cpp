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
    Employee(string name, string company, int age) {
        Name =  name;
        Company = company;
        Age = age;
    }
};


int main(){
    Employee employee1 = Employee("Felix", "pt len industri", 25);

    employee1.IntroduceYourself();

    Employee employee2 = Employee("Rael","Itenas",21);
    employee2.IntroduceYourself();
}