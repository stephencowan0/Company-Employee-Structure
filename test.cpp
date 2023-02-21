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