#include <iostream>
using namespace std;


class AbstractEmployee {
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;
protected:
    string Name;
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
        if(age>=18)
        Age = age;
    }
    int getAge() {
        return Age;
    }

    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    Employee(string name, string company, int age) {
        Name =  name;
        Company = company;
        Age = age;
    }
    void AskForPromotion(){
        if (Age>30)
            cout << Name << " got Promoted" << endl;
        else 
            cout << Name << " Nope youre Not" << endl;

    }
};

class Developer: public Employee {
public:
    string Favprograminglanguage;
    Developer(string name, string company, int age, string favprograminglanguage) : Employee(name, company, age) {
        Favprograminglanguage = favprograminglanguage;
    }
    void fixBug(){
        cout << Name << " sedang fixbug di bahasa "  << Favprograminglanguage << endl;
    }

};

class Teacher: public Employee {
public:
    string Subject;
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age){
        Subject = subject;
    }
    void PreparedLesson() {
        cout << Name << " sedang mengajar di mata pelajaran "  << Subject << endl;
    }
};


int main(){

    Developer developer1 = Developer("Felix", "Pt len industri", 21, "c++");
    Teacher teacher1 = Teacher("Ghinova", "Pt len industri", 40, "Matematika");

    developer1.fixBug();
    developer1.AskForPromotion();

    teacher1.PreparedLesson();
    teacher1.AskForPromotion();

}