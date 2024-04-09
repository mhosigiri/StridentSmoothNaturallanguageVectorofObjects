//working with an Array of structures with students
//Dr_T Programming Fundamentals II 
// Arnes KC , Luis Soto

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std; 

struct Point 
{
    int x;
    int y;  
};
//object Oriented Coding 
class Person
{
  private:
    int age; 
    string name; 
  public:
    void setAge(int a) { age = a; }
    void setName(string n) { name = n; }
    int getAge() const { return age; }
    string getName() const { return name; }
    void print()
    {
      cout << "\nName: " << name << endl; 
      cout << "Age: " << age; 
    }
};
class Income{
private:
  string incomeName;
  double incomeValue;
public:
  Income() {incomeName = "", incomeValue = 0.0;}
  Income(string iName, double iValue) {incomeName = iName; incomeValue = iValue;}
  void setIncomeName(string iName) {incomeName = iName;}
  void setIncomeValue(double  iValue) {incomeValue = iValue;}
  string getIncomeName()const {return incomeName;}
double getIncomeValue() const {return incomeValue;}
void printIncome()
{
  cout << "\n" << incomeName << "\t$" << incomeValue << endl;
}
};

class Expense
{
private:
string expenseName;
double expenseValue;
public:
Expense() {expenseName = "", expenseValue = 0.0;}
Expense(string iName, double iValue) {expenseName = iName; expenseValue = iValue;}
void setExpenseName(string iName) {expenseName = iName;}
void  setExpenseValue(double iValue) {expenseValue = iValue;}
string getExpenseName()const {return expenseName;}
double getExpenseValue() const {return expenseValue;}
void printExpense()
{
  cout << "\n" << expenseName << "\t$" << expenseValue << endl;
}
};

int main() 
{

  vector<Income> vIncome;
  vector<Expense> vExpense;
  string name;
  double value;
  char choice;

  do {
    cout << "\nEnter Income Name: ";
    cin >> name;
    cout << "Enter Income Value: ";
    cin >> value;

    vIncome.push_back(Income(name, value));

    cout << "\nEnter another income? (y/n): ";
    cin >> choice;
  } while (tolower(choice) == 'y');

  do {
    cout << "\nEnter Expense Name: ";
    cin >> name;
    cout << "Enter Expense Value: ";
    cin >> value;

    vExpense.push_back(Expense(name, value));

    cout << "\nEnter another expense? (y/n): ";
    cin >> choice;
  } while (tolower(choice) == 'y');

  double totalIncome = 0.0;
  double totalExpense = 0.0;
  for(const auto& income : vIncome)
    {
      totalIncome += income.getIncomeValue();
    }
  for(const auto& expense : vExpense)
    {
      totalExpense += expense.getExpenseValue();
    }

  cout << "\nTotal Income: $" << endl;
  for(auto& income : vIncome)
    {
      income.printIncome();
    }
  for(auto& expense : vExpense)
    {
      expense.printExpense();
    }

  cout << "\nTotal Income: $" << totalIncome << endl;
  cout << "\nNet Total: $" << (totalIncome - totalExpense) << endl << endl;

  Point arr[10]; //10 x,y points can be stored

  //place some manual data in the first point
  arr[0].x = 10; 
  arr[0].y = 20; 

  //print the first two points to screen 
  cout << "(" << arr[0].x << ", " << arr[0].y << ")" << endl; 

  //DrT Challenge 1
  //use a for loop to automatically populate arr[] x and y
  for(int i = 0; i < 10; i++)
  {
    arr[i].x = i; 
    arr[i].y = (i + 1); 
  }

  //DrT Challenge 2 
  //use a for loop or shortcut to print all values in arr[]
  for(int j = 0; j < 10; j++)
  {
    cout << "(" << arr[j].x << ", " << arr[j].y << ")" << endl; 
  }
  /******************************/
  //A vector of Person objects!!! Wow!! 
  vector<Person> allThePeople; 

  //Populate allThePeople with Data
  vector<string> names = {"Tyson", "Yolanda", "Tyrel"}; 
  vector<int> ages = {39, 25, 19}; 

  //delcare 3 Person objects, place data in them from the names, and ages vector 
  Person p1;
  p1.setName(names[0]);  //put "Tyson" as this value
  p1.setAge(ages[0]);  // put 39 as this value 

  Person p2;
  p2.setName(names[1]);
  p2.setAge(ages[1]);

  Person p3;
  p3.setName(names[2]);
  p3.setAge(ages[2]);  

  //add p1, p2, and p3 as elements in the allThePeople vector
  allThePeople.push_back(p1); 
  allThePeople.push_back(p2);
  allThePeople.push_back(p3); 

  //DrT Challenge 3 print all the data in the allThePeople vector
  for(int i = 0; i < allThePeople.size(); i++)
  {
      cout << "\nname: " << allThePeople[i].getName() << endl;  
      cout << "age: " << allThePeople[i].getAge() << endl;
      cout << "\nProfile: "; 
      allThePeople[i].print(); //void function call 
      cout << endl; 
  }



  return 0; 
}