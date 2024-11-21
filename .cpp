#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

struct Employee {
    string name;    
    string position;
    double sal;      
};

Employee findHighestPaidEmployee(const vector<Employee>& emplo) {
    if (emplo.empty()) {
        throw runtime_error("Список працівників порожній!");
    }

    Employee highestPaid = emplo[0];
    for (const auto& employee : emplo) {
        if (employee.sal > highestPaid.sal) {
            highestPaid = employee;
        }
    }
    return highestPaid;
}

void addEmployee(vector<Employee>& employees, const string& name, const string& position, double salary) {
    employees.push_back({ name, position, salary });
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Employee> employees;

    addEmployee(employees, "Іван", "PM", 20000);
    addEmployee(employees, "Владислав", "Програміст", 19000);
    addEmployee(employees, "Максим", "Дизайнер", 18500);

    try {
        Employee highestPaid = findHighestPaidEmployee(employees);

       cout << "Працівник з найвищою зарплатою:\n";
       cout << "Ім'я: " << highestPaid.name << "\n";
       cout << "Посада: " << highestPaid.position << "\n";
       cout << "Зарплата: " << highestPaid.sal << "\n";
    }
    catch (const runtime_error& e) {
        cerr << "Помилка: " << e.what() << "\n";
    }

    return 0;
}
