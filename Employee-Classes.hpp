#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Employee
{
private:
    string name;
    string position;
    string position_description;
    int salary;
    vector<Employee> *managed_by;
    vector<Employee> *subordinates;
    string department;
    int level;

public:
    Employee()
    {
    }
    Employee(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        managed_by = nullptr;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    string return_name()
    {
        return name;
    }
    string return_position()
    {
        return position;
    }
    string return_position_description()
    {
        return position_description;
    }
    int return_salary()
    {
        return salary;
    }
    vector<Employee> return_managed_by()
    {
        return *managed_by;
    }
    vector<Employee> return_subordinates()
    {
        return *subordinates;
    }
    string return_department()
    {
        return department;
    }
    int return_level()
    {
        return level;
    }
    void display_employee_info()
    {
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Position Description: " << position_description << endl;
        cout << "Salary: " << salary << endl;
        cout << "Managed By: " << managed_by << endl;
        cout << "Subordinates: " << subordinates << endl;
        cout << "Department: " << department << endl;
        cout << "Level: " << level << endl;
    }
};