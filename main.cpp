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
    vector<CEO> CEOs;
    vector<Store_Manager> Store_Managers;
    vector<Assistant_Store_Manager> Assistant_Store_Managers;
    vector<Department_Manager> Department_Managers;
    for (int i = 0; i < rows_of_data.size(); i++)
    {
        string current_row = rows_of_data[i];
        current_row = current_row[current_row.length() - 1];
        int employee_type = stoi(current_row);
        switch (employee_type)
        {
        case 3:
        {
            CEO new_CEO = create_CEO_from_data(rows_of_data[i]);
            CEOs.push_back(new_CEO);
            break;
        }
        case 2:
        {
            Store_Manager new_Store_Manager = create_Store_Manager_from_data(rows_of_data[i]);
            Store_Managers.push_back(new_Store_Manager);
            break;
        }
        case 1:
        {
            Assistant_Store_Manager new_Assistant_Store_Manager = create_Assistant_Store_Manager_from_data(rows_of_data[i]);
            Assistant_Store_Managers.push_back(new_Assistant_Store_Manager);
            break;
        }
        case 0:
        {
            Department_Manager new_Department_Manager = create_Department_Manager_from_data(rows_of_data[i]);
            Department_Managers.push_back(new_Department_Manager);
            break;
        }
        default:
            break;
        }
    }

    for (int i = 0; i < CEOs.size(); i++)
    {
        CEOs[i].set_subordinates(&Store_Managers);
    }
    for (int i = 0; i < Store_Managers.size(); i++)
    {
        Store_Managers[i].set_subordinates(&Assistant_Store_Managers);
    }
    for (int i = 0; i < Assistant_Store_Managers.size(); i++)
    {
        Assistant_Store_Managers[i].set_subordinates(&Department_Managers);
    }
    cout << "The Companys Management Structure is as Follows:" << endl
         << endl;
    cout << "CEO: " << CEOs[0].return_name() << endl
         << endl;
    cout << "Store Manager: " << Store_Managers[0].return_name() << endl
         << endl;
    cout << "Assisstant Store Managers: " << endl;
    for (int i = 0; i < Assistant_Store_Managers.size(); i++)
    {
        cout << Assistant_Store_Managers[i].return_name() << " is the " << Assistant_Store_Managers[i].return_position_description() << endl;
    }
    cout << endl;
    cout << "Department Managers: " << endl;
    for (int i = 0; i < Department_Managers.size(); i++)
    {
        cout << Department_Managers[i].return_name() << " is the " << Department_Managers[i].return_position_description() << endl;
    }

    return 0;
}