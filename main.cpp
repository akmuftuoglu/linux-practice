//
//  main.cpp
//  HW7 PIC10C
//
//  Created by Aral Muftuoglu
//

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#include "Employee.h"

using namespace std;



bool compareBySalary(const Employee &one, const Employee &two)
{
    return (one.get_salary() < two.get_salary());
}

int main() {

    vector<Employee> data;
    
    ifstream inputFile;
    inputFile.open("employee.txt");
    
    if (inputFile.is_open() == true)
    {
        string line;
    
        while (getline(inputFile, line))
        {
            string name;
            string initial_salary;
            double salary;
            
            for (int i = 0; i < 30; i++)   // name is first 30 characters
            {
                name += line[i];
            }
            
            for (int i = 30; i < 40; i++)  // salary is the last 10 characters
            {
                if (line[i] != ' ')
                {
                    initial_salary += line[i];
                }
            }
            
            salary = stod(initial_salary);
            
            Employee x(name, salary);
            x.raise(5.0);
            data.push_back(x);
        }
    }
    else
    {
        cout << "File not opened" << endl;
    }
    
    inputFile.close();
    
    std::sort(data.begin(), data.end(), compareBySalary);
   
    ofstream outputFile;
    outputFile.open ("SalaryRanking.txt");
    

    
    for (int i = 0; i < data.size(); i++)
    {
        int charCount = 0;
        string raised_salary = to_string(data[i].get_salary());
        
        for (int j = 0; j < raised_salary.size(); j++)
        {
            if (raised_salary[j] != '.')
            {
                charCount++;
            }
            else
            {
                charCount += 3; // decimal and two digits after it
                break;
            }
            
        }
        
        int charDifference = 10 - charCount;
        
        outputFile << data[i].get_name();
        
        for (int k = 0; k < charDifference; k++)
        {
            outputFile << ' ';
        }
        
        outputFile << setprecision(2) << fixed << data[i].get_salary() << endl;
    }
   
    outputFile.close();

    
    return 0;
}
