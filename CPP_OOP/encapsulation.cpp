#include <iostream>
using std::string;

class Employee {
private:
    string Name;
    string Company;
    int Age;
public: 
    // setter and getter Name 
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    // setter and getter Company
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    // setter and getter Age
    void setAge(int age) {
        Age = age;
    }
    int getAge() {
        return Age;
    }

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
    // employee1.Name = "Felix";
    // employee1.Company = "SomeCompany";
    // employee1.Age = 25;

    employee1.IntroduceYourself();

    Employee employee2 = Employee("Rael","Itenas",21);
    // employee2.Name = "Rael";
    // employee2.Company = "BujangCompany";
    // employee2.Age = 21;
    employee2.IntroduceYourself();
    employee1.setAge(39);
    std::cout<<employee1.getName()<<" is "<<employee1.getAge()<<" years old" << std::endl;
}