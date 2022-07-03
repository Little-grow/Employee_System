#include <iostream>
using namespace std;
int size =1000;
double salarys[1000];
string names [1000];
int ages[1000];
int id = 0;

void Menu ()
{
    cout <<"\t Enter your choice:\n";
    cout <<"\t 1) Add new employee\n";
    cout <<"\t 2) Print all employees\n";
    cout <<"\t 3) Delete by age\n";
    cout <<"\t 4) Update Salary by name\n";
}

void AddNewEmployee()
{
    cout <<"\t\t Enter your name\n";
    cin >> names[id];

    cout << "\t\t Enter the salary\n";
    bool ok = false; double salary;
    while (!ok)
    {
      cin >> salary;
     if (cin.fail())
     {
         cout << "you should enter correct values\n";
         cin.clear();
         cin.ignore(10000,'\n');
         ok =false;
     }
     else
     {
         salarys[id]=salary;
         ok=true;
     }
    }

    cout << "\t\t Enter your age \n";
    ok =false ; int age;
    while (!ok)
    {
        cin >> age;
        if (cin.fail()|| age < 10)
     {
         cout << "you should enter correct values\n";
         cin.clear();
         cin.ignore(10000,'\n');
         ok =false;
     }
     else
     {
         ages[id]=age;
            ok=true;
     }
    }


 cout << "Employee add, thanks Mr "<< names[id]<<endl;

    ++id ;
}

void PrintAllEmployees()
{

    cout << "Name\t\t\tSalary\t\t age\n\n\n\n" ;
    for (int i=0; i < id;++i)
    {
        if (ages[i]!=-1)
            cout <<names[i] <<"\t\t\t" << salarys[i] <<"\t\t" << ages [i]<<endl;
    }

}
void DeleteByAge()
{
    int start ; int end;
    cout << "Enter the range of age ";
    cin >> start >> end;
    for (int i =0 ; i<id;++i )
    {
        if (ages[i]>=start&&ages[i]<=end)
            ages[i]=-1;
    }
}
void UpdateSalaryName()
{
    string name;
    cout << "Please enter your name\n";
    cin >> name;
    bool ok = false ;
    while (!ok)
    if (cin.fail()){
        cout << "you should enter correct values\n";
        cin.clear();
        cin.ignore (10000,'\n');
        ok=false;
    }

    else {

    int count =0;
    int TId;
    for (int i=0; i <= id;++i)
    {
        if (name==names[i])
        {
            ++count ;
            TId=i;
        }
    }
    if (count >1)
    {
        int age ;
        cout << "you have to input you age";
        cin >> age ;
        for (int i=0 ; i < id ;++i)
        {
            if (ages[i]==age)
            { cout << "Enter the new salary\n";
              cin >> salarys[i];
              cout << "Done! NiceDay!";
              break;
            }
        }
    }
    else if (count == 1 )
    {
            cout << "Enter the new salary\n";
            cin >> salarys[TId];
            cout << "Done! NiceDay!\n";
            break;
    }
    else if (count==0)
    {
        cout << "Not Found!\n Try again \n";
    }
    ok =true;
    }
}


void EmployeeSystem()
{
    while (true)
    {
        Menu();
        int choice =0; cin >> choice;
        if (choice==1)
               AddNewEmployee();
        else if (choice==2)
            PrintAllEmployees();
        else if (choice==3)
             DeleteByAge();
        else if (choice==4)
               UpdateSalaryName();
        else
                cout << "you should enter valid choice";
    }
}
int main()
{
    cout << "\t\t\t\tHello to our program\n";
    EmployeeSystem();
    return 0;
}
