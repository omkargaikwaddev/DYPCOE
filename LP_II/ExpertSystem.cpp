#include <iostream>      // For input and output
#include <string>        // For using string

using namespace std;

int main() {

    string issue;   // Variable to store user issue

    cout << "==================================" << endl;
    cout << "     HELP DESK EXPERT SYSTEM     " << endl;
    cout << "==================================" << endl;

    // Ask user for issue
    cout << "\nEnter your issue: ";

    // Take complete line input
    getline(cin, issue);

    // Check different problems

    // Internet issue
    if (issue == "internet") {

        cout << "\nSolution:" << endl;
        cout << "1. Restart your router." << endl;
        cout << "2. Check network cables." << endl;
        cout << "3. Contact ISP if problem continues." << endl;
    }

    // Slow computer issue
    else if (issue == "slow computer") {

        cout << "\nSolution:" << endl;
        cout << "1. Close unnecessary programs." << endl;
        cout << "2. Restart the computer." << endl;
        cout << "3. Scan for viruses." << endl;
    }

    // Printer issue
    else if (issue == "printer") {

        cout << "\nSolution:" << endl;
        cout << "1. Check printer connection." << endl;
        cout << "2. Refill paper and ink." << endl;
        cout << "3. Restart the printer." << endl;
    }

    // Password issue
    else if (issue == "password") {

        cout << "\nSolution:" << endl;
        cout << "1. Click on forgot password." << endl;
        cout << "2. Reset using registered email." << endl;
    }

    // Unknown issue
    else {

        cout << "\nSorry!" << endl;
        cout << "Issue not found in knowledge base." << endl;
        cout << "Please contact technical support." << endl;
    }

    return 0;   // End program
}

/*
Example Output
==================================
     HELP DESK EXPERT SYSTEM
==================================

Enter your issue: printer

Solution:
1. Check printer connection.
2. Refill paper and ink.
3. Restart the printer.
*/

/*
Simple Explanation
What is an Expert System?

An Expert System:

Mimics human expert decision making
Gives automatic solutions based on rules
Working of this Program
User enters issue
Program checks issue using if-else
Displays suitable solution

Why it is called Expert System?

Because it stores:

Predefined knowledge
Expert-like solutions
Concepts Used
Input Handling
String Matching
Decision Making using if-else
*/