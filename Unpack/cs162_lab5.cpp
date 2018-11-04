//Put your header comments here with your name, class
//and purpose of the program

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 100;

//Place your structure definition here (globally):
struct userName
{
    char first[41];
    char mid;
    char last[41];
};
struct userCourse
{
    int crn;
    char userClass[20];
    int sect;
};

//Place any prototypes that use the structure here:
void getFirst(userName & name);
void getMid(userName & name);
void getLast(userName & name);

void getCrn(userCourse & course);
void getClass(userCourse & course);
void getSect(userCourse & course);

void dispResults(userName & name, userCourse & course);

int main()
{
     //Create a variable of the struct here:
    userName name;
    userCourse course;


     //Call the functions here:
    getFirst(name);
    cout << name.first << endl;
    getMid(name);
    cout << name.mid << endl;
    getLast(name);
    cout << name.last << endl;
    getCrn(course);
    cout << course.crn << endl;
    getClass(course);
    cout << course.userClass << endl;
    getSect(course);
    cout << course.sect << endl;

    dispResults(name, course);

     return 0;
}

//Implement the body of the functions here:
void dispResults(userName & name, userCourse & course)
{
    cout << "Your name is " << name.first << ' ' << name.mid << ' ' << name.last << endl;
    cout << "Your CRN: " << course.crn << '\n' << "Your Course Designator: " << course.userClass << endl;
    cout << "Your Section: " << course.sect << endl;


}
void getSect(userCourse & course)
{
    do
    {
    cout << "Please enter your section number. ";
    cin >> course.sect;
    cin.ignore(100, '\n');
        if(course.sect <= 0)
             cout << "Invalid input please try again. " << endl;
    }while(course.sect <= 0);

}
void getClass(userCourse & course)
{
    cout << "Please enter your course designator. ";
    cin.get(course.userClass, 20, '\n');
    cin.ignore(100, '\n');
}
void getCrn(userCourse & course)
{
    do
    {
    cout << "Please enter the CRN for this class. ";
    cin >> course.crn;
    cin.ignore(100, '\n');
        if(course.crn <= 0)
             cout << "Invalid input please try again. " << endl;
    }while(course.crn <= 0);

}
void getLast(userName & name)
{
    cout << "Please enter your last name. ";
    cin.get(name.last, 41, '\n');
    cin.ignore(100, '\n');

}
void getMid(userName & name)
{
    cout << "Please enter your middle initial. ";
    cin >> name.mid;
    cin.ignore(100, '\n');

}
void getFirst(userName & name)
{
    cout << "Please enter your first name. ";
    cin.get(name.first, 41, '\n');
    cin.ignore(100, '\n');

}
