#include <iostream>
using namespace std;

/*Lawrence Scroggs, CS 162, Grade Calculator
 * The purpose of this program is to help the user find their grade
 * depending on what week we are in the class. Program starts with intro
 * then will prompt user to enter their current week and their current score
 * in the class.  Program will ask user to verify their info.  If correct
 * program will move onto the calculation of the grade then displays the grade.
 * Program will then prompt user if they want to run the program again.
 * EDIT: Had to change a few things I definitley oversimplified it initially.
 * Program will get the assignments individually. Program will then tally up
 * the possible points for the user.  Program will then will mirror the users
 * input back to them.  Program will then do the calculations.  Program will 
 * then reflect the users grade to them letter and percentage.  Program will 
 * then prompt user if they want to run again.
 *
 */

int main()
{
	float userGrade = 0; // Final Grade
	float userPercent = 0; // Totals the users percent applicable
	const int ALGOR = 10;  // Scores of Algorithm
	const int PROG = 100; // Scores of Program
	const int MID = 100; // Scores of Midterm Exam
	const int FINAL = 100; // Scores of Final
	const int QUIZ = 25; // Scores of Quizzes
	const int LAB = 5; // Scores of Lab
	int userAl = 0; // How many algorithms the user has done
	int userProg = 0; // User Programs completed
	int userEx = 0; // If user has done Midterm
	int userFin = 0; // If user has done final
	int userQ = 0; // User Quizzes complete
	int userLab = 0; // Lab tracker
	float progAssgn = 0; // Holds current possible points for Prog/Arg
	float labMan = 0; // Holds current possible points for Lab Manuals
	float quizBiz = 0; // Holds current possible points for Quizzes
	float finalBiz = 0; // Holds current posssible points for Final
	float midBiz = 0; // Holds current possible points for Midterm
	float gradeAlg = 0; // Next 6 variables hold scores from user
	float gradeProg = 0;
	float gradeMid = 0;
	float gradeFin = 0;
	float gradeLab = 0;
	float gradeQuiz = 0;
	float progGrade = 0;// Next 5 variables hold grade value for each section
	float midGrade = 0;
	float quizGrade = 0;
	float finGrade = 0;
	float labGrade = 0;
	char restart = 'Y';
	char userResponse = 'N'; //User response 
	int totalPercent = 0; // HOlds percent applicable in class

	/* Step one introduce user to program 
	 * instructions and prompt user for 
	 * how many of each of the assignments 
	 * and their scores on them.
	 * Echo these responses
	 * back to user
	 */

	do
	{
		do
		{
		cout << "Welcome to the Grade Calculator program for CS 162" << endl << endl;
		cout << "This program is going to ask you about how many assignments "
		     << endl << "you have completed and then your scores please use numeric values" << endl;

		cout << "Please enter the number of Algorithms completed so far: " << endl;
		cin >> userAl;
		cin.ignore(100,'\n');
		cout << "Please enter the total points of your Algorithm/s: " << endl;
		cin >> gradeAlg;
		cin.ignore(100,'\n');

		cout << "Please enter the number of Programs completed so far: " << endl;
		cin >> userProg;
		cin.ignore(100,'\n');
		cout << "Please enter the total points of your Program/s: " << endl;
		cin >> gradeProg;
		cin.ignore(100,'\n');
			if(userAl > 0 || userProg > 0)
				totalPercent += 25;

		cout << "Please enter 1 if you have done the midterm. Enter 0 if not: " << endl;
		cin >> userEx;
		cin.ignore(100,'\n');
			if(userEx > 0)
			{
				cout << "Please enter your Midterm score. " << endl;
				cin >> gradeMid;
				cin.ignore(100,'\n');
				totalPercent += 25;
			}

		cout << "Please enter 1 if you have done the Final. Enter 0 if not: " << endl;
		cin >> userFin;
		cin.ignore(100,'\n');
			if(userFin > 0)
			{
				cout << "Please enter your Final Score. " << endl;
				cin >> gradeFin;
				cin.ignore(100,'\n');
				totalPercent += 40;
			}

		cout << "Please enter 1 if lab book is done and graded. Enter 2 if Lab Final is complete. Enter 0 if not graded.: " << endl;
		cin >> userLab;
		cin.ignore(100,'\n'); 
			if(userLab > 0)
			{
				cout << "Please enter your total lab points: " << endl;
				cin >> gradeLab;
				cin.ignore(100,'\n');
				totalPercent += 5;
			}
		cout << "Please enter the number of quizzez you have taken: " << endl;
		cin >> userQ;
		cin.ignore(100,'\n');
			if(userQ > 0)
			{
				cout << "Please enter your total Quiz points: " << endl;
				cin >> gradeQuiz;
				cin.ignore(100,'\n');
				totalPercent += 5;
			}

		cout << "Is this information Correct?" << endl;
		cout << "Algorithms Complete " << userAl << " Your Points " << gradeAlg << endl;
		cout << "Programs Complete " << userProg << " Your Points " << gradeProg << endl;
		cout << "Midterm Score " << gradeMid << endl;
		cout << "Final Score " << gradeFin << endl;
		cout << "Labs Scored " << userLab << " Lab Points " << gradeLab << endl;
		cout << "Quizzes Complete " << userQ << " Your Points " << gradeQuiz << endl;
		cout << "If correct please type Y(case sensitive) If wrong please type N(case sensitive)" << endl;
		cin >> userResponse;
		cin.ignore(100,'\n');
		if(userResponse != 'N' && userResponse != 'Y')
		{
			cout << "Invalid Response. Please try again." << endl;
			cin >> userResponse;
			cin.ignore(100,'\n');
		}
		}while(userResponse == 'N');

	//Step Two: Calculate Current Points for each section. Calculate Grades
		progAssgn = ((userAl * ALGOR) + (userProg * PROG)); // calculates total points possible for program/algs so far
		labMan = (userLab * LAB); // calculates total points possible for Lab Manual so far

		midBiz = (userEx * MID); // calculates if user took midterm
		finalBiz = (userFin * FINAL); // calculates if user took final

		if(progAssgn > 0)
			progGrade = (((gradeAlg + gradeProg) / progAssgn) * 25);
		if(quizBiz > 0)
			quizGrade = ((gradeQuiz / quizBiz) * 5);
		if(labMan > 0)
			labGrade = ((gradeLab / labMan) * 5);
		if(midBiz > 0)
			midGrade = ((gradeMid / midBiz) * 25);
		if(finalBiz > 0)
			finGrade = ((gradeFin / finalBiz) * 40);

		userPercent = (progGrade + quizGrade + labGrade + midGrade + finGrade);
		userGrade = ((userPercent / totalPercent) * 100);

	/* Step Three: this part of the program will display the grade to the user.
	 * The program will then prompt the user if they want to run the program
	 * again.
	 */

		if(userGrade >= 90)
		{
			cout << "Your Grade is currently an A at %" << userGrade << '.' << endl;
		}
		else if(userGrade >= 80)
		{
			cout << "Your Grade is currently a B at %" << userGrade << '.' << endl;
		}
		else if(userGrade >= 70)
		{
			cout << "Your Grade is currently a C at %" << userGrade << '.' << endl;
		}
		else if(userGrade >= 60)
		{
			cout << "Your Grade is currently a D at %" << userGrade << '.' << endl;
		}
		else if (userGrade < 60)
		{
			cout << "Your Grade is current an F at %" << userGrade << '.' << endl;
		}

		cout << "Would you like to run the Program again Y or N. (case sensitive)." << endl;
		cin >> restart;
		cin.ignore(100,'\n');

	}while(restart != 'N');






	return 0;
}
