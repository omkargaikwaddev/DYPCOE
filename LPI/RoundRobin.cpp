#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;       // Process ID
    int burstTime; // Total CPU time needed
    int remaining; // Remaining CPU time
    int waitingTime = 0;
    int turnaroundTime = 0;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter burst times for processes:\n";
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Process " << processes[i].pid << ": ";
        cin >> processes[i].burstTime;
        processes[i].remaining = processes[i].burstTime;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    int time = 0;      // Current time
    bool done;

    // Round Robin Loop
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining > 0) {
                done = false; // There is a pending process
                if (processes[i].remaining > quantum) {
                    time += quantum;
                    processes[i].remaining -= quantum;
                } else {
                    time += processes[i].remaining;
                    processes[i].waitingTime = time - processes[i].burstTime;
                    processes[i].remaining = 0;
                    processes[i].turnaroundTime = time;
                }
            }
        }
    } while (!done);

    // Output results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].pid << "\t" 
             << processes[i].burstTime << "\t\t" 
             << processes[i].waitingTime << "\t\t" 
             << processes[i].turnaroundTime << "\n";
    }

    return 0;
}

