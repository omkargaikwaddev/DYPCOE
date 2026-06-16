#include <iostream>      // For input and output
#include <vector>        // For using vector
#include <algorithm>     // For sorting jobs

using namespace std;

// Structure to store job details
struct Job {

    char id;        // Job ID

    int deadline;   // Deadline of job

    int profit;     // Profit earned from job
};

// Function to compare jobs by profit
bool compare(Job a, Job b) {

    // Sort jobs in descending order of profit
    return a.profit > b.profit;
}

int main() {

    int n;   // Variable to store number of jobs

    // Ask user for number of jobs
    cout << "Enter number of jobs: ";

    // Take input
    cin >> n;

    // Create vector to store jobs
    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline and Profit:" << endl;

    // Loop to input all jobs
    for (int i = 0; i < n; i++) {

        // Input job ID
        cin >> jobs[i].id;

        // Input deadline
        cin >> jobs[i].deadline;

        // Input profit
        cin >> jobs[i].profit;
    }

    // Sort jobs according to maximum profit
    sort(jobs.begin(),
         jobs.end(),
         compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {

        // Update maximum deadline
        if (jobs[i].deadline > maxDeadline) {

            maxDeadline = jobs[i].deadline;
        }
    }

    // Create slot array
    vector<char> slot(maxDeadline, '-');

    // Variable to store total profit
    int totalProfit = 0;

    // Traverse all jobs
    for (int i = 0; i < n; i++) {

        // Try to schedule job before its deadline
        for (int j = jobs[i].deadline - 1;
             j >= 0;
             j--) {

            // If slot is empty
            if (slot[j] == '-') {

                // Assign job to slot
                slot[j] = jobs[i].id;

                // Add profit
                totalProfit += jobs[i].profit;

                // Exit loop after scheduling
                break;
            }
        }
    }

    // Print scheduled jobs
    cout << "\nScheduled Jobs:" << endl;

    for (int i = 0; i < maxDeadline; i++) {

        // Print only filled slots
        if (slot[i] != '-') {

            cout << slot[i] << " ";
        }
    }

    // Print total profit
    cout << "\n\nTotal Profit = "
         << totalProfit
         << endl;

    return 0;   // End program
}

/*
Example Input
Enter number of jobs: 5

Enter Job ID, Deadline and Profit:
A 2 100
B 1 19
C 2 27
D 1 25
E 3 15
*/

/*
Example Output
Scheduled Jobs:
C A E

Total Profit = 142
*/

/*
Simple Explanation
What is Job Scheduling Problem?

In this problem:

Each job has:
Deadline
Profit
Only one job can be done at a time
Goal:
Maximize total profit
Greedy Approach

This algorithm:

Selects jobs with highest profit first
Places each job in the latest available slot before deadline
Why is it Greedy?

Because at every step it chooses:

The job with maximum immediate profit

Working Example
Job	Deadline	Profit
A	2	        100
B	1	        19
C	2	        27
D	1	        25
E	3	        15

After sorting by profit:

A → C → D → B → E

Jobs selected:

C A E

Total Profit:

27 + 100 + 15 = 142

Time Complexity
Operation	        Complexity
Sorting Jobs	    O(n log n)
Scheduling Jobs	    O(n²)
Overall	            O(n²)
*/