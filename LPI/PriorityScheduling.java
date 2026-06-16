import java.util.Scanner;

class Process {
    int id, burstTime, priority, waitingTime, turnaroundTime;

    Process(int id, int burstTime, int priority) {
        this.id = id;
        this.burstTime = burstTime;
        this.priority = priority;
    }
}

public class PriorityScheduling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();
        Process[] processes = new Process[n];

        // Input burst time and priority for each process
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Process " + (i + 1));
            System.out.print("Burst Time: ");
            int bt = sc.nextInt();
            System.out.print("Priority (Lower number = Higher priority): ");
            int pr = sc.nextInt();
            processes[i] = new Process(i + 1, bt, pr);
        }

        // Sort processes by priority (ascending)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (processes[j].priority > processes[j + 1].priority) {
                    Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            }
        }

        // Calculate waiting time and turnaround time
        processes[0].waitingTime = 0;
        processes[0].turnaroundTime = processes[0].burstTime;

        for (int i = 1; i < n; i++) {
            processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
            processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        }

        // Display process details
        System.out.println("\nProcess\tBT\tPriority\tWT\tTAT");
        int totalWT = 0, totalTAT = 0;
        for (Process p : processes) {
            System.out.println("P" + p.id + "\t" + p.burstTime + "\t   " + p.priority + "\t\t" + p.waitingTime + "\t" + p.turnaroundTime);
            totalWT += p.waitingTime;
            totalTAT += p.turnaroundTime;
        }

        System.out.println("\nAverage Waiting Time: " + (float) totalWT / n);
        System.out.println("Average Turnaround Time: " + (float) totalTAT / n);
        
        sc.close();
    }
}
