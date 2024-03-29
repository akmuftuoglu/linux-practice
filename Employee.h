#ifndef EMPL_H
#define EMPL_H
#include <string>
using namespace std;
/**
   A basic employee class that is used in many examples
   in the book "Computing Concepts with C++ Essentials"
*/
class Employee
{
public:
   /**
      Constructs an employee with empty name and no salary.
   */
   Employee();
   /**
      Constructs an employee with a given name and salary.
      @param employee_name the employee name
      @param initial_salary the initial salary
   */
   Employee(string employee_name, double initial_salary);
   /**
      Sets the salary of this employee.
      @param new_salary the new salary value
   */
   void set_salary(double new_salary);
   /**
      Gets the salary of this employee.
      @return the current salary
   */
   double get_salary() const;
   
   /**
      Gets the name of this employee.
      @return the employee name
   */
   string get_name() const;
    
    /**
       Give the employee a raise by percent
     @param percent a positive number: new_salary = (1+percent*0.01)*old_salary
    */
    void raise(double percent);
    
private:
   string name;
   double salary;
};
#endif
