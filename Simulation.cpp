#include <iostream>
#include "Restaurant.h"
#include "DataReader.h"
#include "Time.h"

// Initialize list of drivers using .drivers file
std::list<Driver*>* aList = readDrivers();

// Declare a restaurant
Restaurant dominatos;

// Driver finder function
Driver * driverFinder(std::list<Driver*> driversList, string driverName) throw (logic_error)
{
    for (std::list<Driver*>::iterator it = driversList.begin(); it != driversList.end(); ++it)
    {
        if ((*it)->getName() == driverName)
            return *it;
    }
    
    throw logic_error ("This driver does not exist in system");
}

// Command function prototypes
void logout(string driver);
void order(Time time, string info);
void serve(Time time);
void depart(Time time, string driver);
void deliver(Time time, string driver, float tip);
void arrive(Time time, string driver);
void status();
void summary();

int main()
{
    // Assign first and second driver to variable
    std::list<Driver*>::iterator it = aList->begin();
    ++it;
    string firstDriver = (*it)->getName();
    ++it;
    string secondDriver = (*it)->getName();
    
    // Outputs sample input
    cout << "login " << firstDriver << endl;
    cout << "order 18:00 1 mushroom to 123 Holden Hall" << endl;
    cout << "order 18:02 4 spinach to 100 Liberty St" << endl;
    cout << "login " << secondDriver <<endl;
    cout << "serve 18:20" << endl;
    cout << "depart 18:20 " << secondDriver << endl;
    cout << "serve 18:28" << endl;
    cout << "deliver 18:30 " << secondDriver << " 2.00" << endl;
    cout << "order 18:30 1 cheese 1 sausage to 1000 Beall Ave" << endl;
    cout << "depart 18:31 " << firstDriver << endl;
    cout << "arrive 18:40 " << secondDriver << endl;
    cout << "logout " << secondDriver << endl;
    cout << "status" << endl;
    cout << "summary" << endl;
    cout << "quit" << endl;
    
    // Sample output
    
    for (std::list<Driver*>::iterator it = aList->begin(); it != aList->end(); ++it)
    {
        dominatos.addDriver(*it);
    }
    
}
    
    
void login(string driver)
{
   driverFinder(aList, driver)->login();
            
}

void logout(string driver)
{
    driverFinder(aList, driver)->logout();
}

void order(Time time, string info)
{
    Order * anOrder(time, info);
    dominatos.addOrder(anOrder);
}

void serve(Time time)
{
    dominatos.serveNextOrder();
    // what to do with time parameter?
}

void depart(Time time, string driver)
{
    Order * departingOrder = dominatos.departNextOrder();
    driverFinder(aList, driver)->depart(time, departingOrder);
}

void deliver(Time time, string driver, float tip)
{
    Driver * thisDriver = driverFinder(aList, driver);
    dominatos.deliver(thisDriver, time, tip);
}

void arrive(Time time, string driver)
{
    driverFinder(aList, driver)->arrive(time);
}

void status()
{
    dominatos.status();
}

void summary()
{
    dominatos.summary();
}


