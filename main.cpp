#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Employee-Classes.hpp"
using namespace std;

vector<string> read_data()
{
    ifstream data_file("current_employees.csv");
    vector<string> rows_of_data;
    if (data_file.is_open())
    {
        string row;
        while (getline(data_file, row))
        {
            rows_of_data.push_back(row);
        }
    }
    data_file.close();
    return rows_of_data;
}

Employee create_employee_from_data(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string name = class_data[0];
    string position = class_data[1];
    string position_description = class_data[2];
    int salary = stoi(class_data[3]);
    string department = class_data[6];
    int level = stoi(class_data[7]);

    Employee new_employee = Employee(name, position, position_description, salary, department, level);
    return new_employee;
}

CEO create_CEO_from_data(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string name = class_data[0];
    string position = class_data[1];
    string position_description = class_data[2];
    int salary = stoi(class_data[3]);
    string department = class_data[6];
    int level = stoi(class_data[7]);

    CEO new_CEO = CEO(name, position, position_description, salary, department, level);
    return new_CEO;
}

Store_Manager create_Store_Manager_from_data(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string name = class_data[0];
    string position = class_data[1];
    string position_description = class_data[2];
    int salary = stoi(class_data[3]);
    string department = class_data[6];
    int level = stoi(class_data[7]);

    Store_Manager new_Store_Manager = Store_Manager(name, position, position_description, salary, department, level);
    return new_Store_Manager;
}

Assistant_Store_Manager create_Assistant_Store_Manager_from_data(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string name = class_data[0];
    string position = class_data[1];
    string position_description = class_data[2];
    int salary = stoi(class_data[3]);
    string department = class_data[6];
    int level = stoi(class_data[7]);

    Assistant_Store_Manager new_Assistant_Store_Manager = Assistant_Store_Manager(name, position, position_description, salary, department, level);
    return new_Assistant_Store_Manager;
}

Department_Manager create_Department_Manager_from_data(string string_of_data)
{
    vector<string> class_data;
    stringstream words(string_of_data);
    string data;
    while (getline(words, data, ','))
    {
        class_data.push_back(data);
    }

    string name = class_data[0];
    string position = class_data[1];
    string position_description = class_data[2];
    int salary = stoi(class_data[3]);
    string department = class_data[6];
    int level = stoi(class_data[7]);

    Department_Manager new_Department_Manager = Department_Manager(name, position, position_description, salary, department, level);
    return new_Department_Manager;
}

int main()
{
    vector<string> rows_of_data = read_data();
    vector<Employee> employees;
    for (int i = 0; i < rows_of_data.size(); i++)
    {
        Employee new_employee = create_employee_from_data(rows_of_data[i]);
        employees.push_back(new_employee);
    }
    for (int i = 0; i < employees.size(); i++)
    {
        employees[i].display_employee_info();
    }
    return 0;
}