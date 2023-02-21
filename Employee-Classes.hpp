#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Employee
{
protected:
    string name;
    string position;
    string position_description;
    int salary;
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
        cout << "Subordinates: " << subordinates << endl;
        cout << "Department: " << department << endl;
        cout << "Level: " << level << endl;
    }
};

class Head_Clerk : public Employee
{
protected:
    vector<Employee> *subordinates;

public:
    Head_Clerk(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    void set_subordinates(vector<Employee> *new_subordinates)
    {
        subordinates = new_subordinates;
    }
    vector<Employee> return_subordinates()
    {
        return *subordinates;
    }
};

class Department_Manager : public Employee
{
protected:
    vector<Head_Clerk> *subordinates;

public:
    Department_Manager(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    void set_subordinates(vector<Head_Clerk> *new_subordinates)
    {
        subordinates = new_subordinates;
    }
    vector<Head_Clerk> return_subordinates()
    {
        return *subordinates;
    }
};

class Assistant_Store_Manager : public Employee
{
protected:
    vector<Department_Manager> *subordinates;

public:
    Assistant_Store_Manager(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    void set_subordinates(vector<Department_Manager> *new_subordinates)
    {
        subordinates = new_subordinates;
    }
    vector<Department_Manager> return_subordinates()
    {
        return *subordinates;
    }
};

class Store_Manager : public Employee
{
protected:
    vector<Assistant_Store_Manager> *subordinates;

public:
    Store_Manager(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    void set_subordinates(vector<Assistant_Store_Manager> *new_subordinates)
    {
        subordinates = new_subordinates;
    }
    vector<Assistant_Store_Manager> return_subordinates()
    {
        return *subordinates;
    }
};

class CEO : public Employee
{
protected:
    vector<Store_Manager> *subordinates;

public:
    CEO(string new_name, string new_position, string new_position_description, int new_salary, string new_department, int new_level)
    {
        name = new_name;
        position = new_position;
        position_description = new_position_description;
        salary = new_salary;
        subordinates = nullptr;
        department = new_department;
        level = new_level;
    }
    void set_subordinates(vector<Store_Manager> *new_subordinates)
    {
        subordinates = new_subordinates;
    }
    vector<Store_Manager> return_subordinates()
    {
        return *subordinates;
    }
};