#include <iostream>
#include <cmath>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

class Employee
{
public:
    string name;
    string Employee_ID;
    float salary;
    //enum Gender {Male,Female, Other};
    //enum Designation {Executive, Manager, Engineer, Accountant, Clerk};
    string Gender;
    string Designation;

    void RandomNumber(int num);
    void printName();
    void deleteEmployeeByID(string eid);
    void printEmployee();
    void printEmployee(string eid);
};

void Employee::printEmployee()
{
    cout << "Name=" << name << " "
         << "Employee_ID= " << Employee_ID << " "
         << "Gender= " << Gender << " "
         << "Designation= " << Designation << "  "
         << "salary= " << salary << "\n";
}

string Employee_ID_maker(int i)
{
    string s = "KO000";
    string t = to_string(i);
    return s + t;
}

void Employee::RandomNumber(int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
        //cout<<arr[i]<<" ";
    }
}

bool is_prefix(string a, string b)
{
    auto s = mismatch(a.begin(), a.end(), b.begin(), b.end());
    if (s.first == a.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(Employee E[], int n, string name)
{
    for (int i = 0; i < n; i++)
    {
        if (E[i].name == name)
        {
            return true;
        }
    }
    return false;
}
void printEmployee(Employee E[], int r, string eid)
{
    for (int i = 0; i < r; i++)
    {
        if (E[i].Employee_ID == eid)
        {
            E[i].printEmployee();
        }
    }
}

static int deleteElement(Employee arr[], int n, string x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i].Employee_ID == x)
            break;

    if (i < n)
    {
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }

    return n;
}

void findEmployeeBySalary(Employee E[], int r, float min, float max)
{
    for (int i = 0; i < r; i++)
    {
        if (E[i].salary > min && E[i].salary < max)
        {
            E[i].printEmployee();
        }
    }
}
int main()
{
    Employee e;
    int n = 100 + rand() % 50;
    cout << "\n"
         << "Number of employees are: " << n << endl;
    e.RandomNumber(n);

    string name[10] = {"Tom", "Henry", "Dave", "Mike", "kal-el", "Harris", "Siddarth", "David", "Rebe", "Mohit"};
    float salary[10] = {124.45, 134.45, 69.75, 69.69, 73.69, 96.69, 34.69, 34.56, 87.76, 1.23};
    string gender[10] = {"Male", "Male", "Male", "Male", "Male", "Female", "Male", "Other", "Female", "Male"};
    string designation[10] = {"Executive", "Manager", "Engineer", "Accountant", "Clerk", "Executive", "Manager", "Engineer", "Accountant", "Clerk"};
    Employee E[10];
    for (int i = 0; i < 10; i++)
    {
        E[i].name = name[i];
        E[i].Employee_ID = Employee_ID_maker(i);
        E[i].Gender = gender[i];
        E[i].Designation = designation[i];
        E[i].salary = salary[i];
    }

    string w;
    cout << "\n"
         << "Printing by using keyword: ";
    cin >> w;
    for (int i = 0; i < 10; i++)
    {
        string a = w;
        string b = E[i].name;
        bool q = is_prefix(a, b);
        if (q)
        {
            E[i].printEmployee();
        }
    }
    string j;
    cout << "\n"
         << "Enter name of employee you want to check if present or not: ";
    cin >> j;
    if (check(E, 10, j))
    {
        cout << "Given name is Present."
             << "\n";
    }
    else
    {
        cout << "Given name is Not Present"
             << "\n";
    }

    cout << "\n\n"
         << "Deleting employee by employee id." << endl;
    cout << "Printing remaining employees: "
         << "\n"
         << endl;
    int r = deleteElement(E, 10, "KO0005");
    for (int i = 0; i < r; i++)
    {
        string a = "Fal";
        string b = E[i].name;
        bool q = is_prefix(a, b);
        E[i].printEmployee();
    }

    cout << "\n"
         << "Print using ID" << endl;
    printEmployee(E, r, "KO0004");

    cout << "\n\n"
         << "Printing employee's detail when salary range is given: " << endl;
    findEmployeeBySalary(E, r, 4.34, 69.69);
    return 0;
}