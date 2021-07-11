/* Problem 3 statement:
    You are a big bank and you are making a list of the most financially reliable customers.
    This is going to be a sorted list and with most reliable customers in the end.

    Now there are multiple criteria for determining the overall reliability and
    all of them must be used according to their priorities.

    Following are the criteria:

    1. Total Account Balance - The more the better
    2. Age - The less the better
    3. Salary - The more the better
    4. Number of dependents - The less the better

    These criteria have the priority as mentioned above, i.e.

    Total account balance will take priority over age.
    So for example, P1 with age 25 and 100 account balance will be
    placed higher than P2 with age 22 and account balance 80 but if
    both had the same account balance then P2 will be placed higher.

    The same way, all the 4 criteria will come into picture in sorting all the people accordingly.
    Now you are given a list of objects with each object representing
    a person and has the above attributes. Your task is to sort them. */

#include<bits/stdc++.h>
using namespace std;

//Defining a structure to store individual customer attributes.
struct Customer{
string name;
int totalAccountBalance;
int age;
int salary;
int noOfDependents;
};


//Function to compare two customers.
bool compareCustomers(Customer a, Customer b)
{
    //Return true for higher account balance
    if(a.totalAccountBalance != b.totalAccountBalance)
    {
        return a.totalAccountBalance>b.totalAccountBalance;
    }

    //If account balance is same then return true for less age
    if(a.age != b.age)
    {
        return a.age<b.age;
    }

    //If age is also same then return true for higher salary
    if(a.salary != b.salary)
    {
        return a.salary>b.salary;
    }

    //If salary is also same then return true for less no of dependents
    return (a.noOfDependents<b.noOfDependents);
}

//Function to sort customers.
void sortCustomers(Customer arr[], int n)
{
    sort(arr, arr+n, compareCustomers);
}
int main()
{
    //Let's assume there are 5 customers in the bank.
    int totalCustomers = 5;

    //Array of structure to store customer details.
    Customer record[totalCustomers];


    //Storing the details of individual customers.
    for(int i=0; i<totalCustomers; i++)
    {
        string person;
        int cBalance, cAge, cSalary, cDependents;

        cout<<"Enter customer name: "<<endl;
        cin>>person;
        cout<<"Enter "<<person<<"'s"<<" total balance: "<<endl;
        cin>>cBalance;
        cout<<"Enter "<<person<<"'s"<<" age: "<<endl;
        cin>>cAge;
        cout<<"Enter "<<person<<"'s"<<" salary: "<<endl;
        cin>>cSalary;
        cout<<"Enter no. of dependents of "<<person<<" "<<endl;
        cin>>cDependents;

        cout<<endl<<endl;

        record[i].name = person;
        record[i].totalAccountBalance = cBalance;
        record[i].age = cAge;
        record[i].salary = cSalary;
        record[i].noOfDependents = cDependents;

    }

    //Function to sort customers as per criteria.
    sortCustomers(record, totalCustomers);

    cout<<"Name"<<" "<<"Total balance"<<" "<<"Age"<<" "<<"Salary"<<" "<<"No of Dependents"<<endl;

    //Printing the sorted records.
    for(int i=0; i<totalCustomers; i++)
    {
        cout<<record[i].name<<"        ";
        cout<<record[i].totalAccountBalance<<"         ";
        cout<<record[i].age<<"   ";
        cout<<record[i].salary<<"   ";
        cout<<record[i].noOfDependents<<endl;
    }

    return 0;
}
