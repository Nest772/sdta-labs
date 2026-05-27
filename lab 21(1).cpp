#include <iostream>
#include <string>

using namespace std;

int main()
{
    int overallBudget;
    int bestSalary;
    int currentSalary;
    double totalCoeff;
    double currentTotal;
    double bestTotal;

    overallBudget=380000;
    totalCoeff=7.0*1.0+10.0*1.2+10.0*1.6+1.0*1.8+3.0*2.0+1.0*2.4+1.0*2.6+1.0*3.0;
    bestSalary=0;
    bestTotal=0.0;

    for(currentSalary=1;currentSalary<=overallBudget;currentSalary++)
    {
        currentTotal=currentSalary*totalCoeff;
        if(currentTotal<=overallBudget)
        {
            if(currentTotal>bestTotal)
            {
                bestTotal=currentTotal;
                bestSalary=currentSalary;
            }
        }
    }

    cout<<"Salary Optimization Results:"<<endl;
    cout<<"Cleaner Base Salary: "<<bestSalary<<" UAH"<<endl;
    cout<<"Nurse Salary: "<<bestSalary*1.2<<" UAH"<<endl;
    cout<<"Doctor Salary: "<<bestSalary*1.6<<" UAH"<<endl;
    cout<<"Head of Pharmacy Salary: "<<bestSalary*1.8<<" UAH"<<endl;
    cout<<"Head of Department Salary: "<<bestSalary*2.0<<" UAH"<<endl;
    cout<<"Chief Doctor Salary: "<<bestSalary*2.4<<" UAH"<<endl;
    cout<<"Head of Household Salary: "<<bestSalary*2.6<<" UAH"<<endl;
    cout<<"Head of Hospital Salary: "<<bestSalary*3.0<<" UAH"<<endl;
    cout<<endl;
    cout<<"Total Budget Spent: "<<bestTotal<<" UAH out of "<<overallBudget<<" UAH"<<endl;

    return 0;
}