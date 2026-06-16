import java.util.*;

class Process {
    int pid, burstTime, waitingTime, turnaroundTime;

    Process(int pid, int burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
    }
}

public class SJF {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter burst time for process " + (i + 1) + ": ");
            int bt = sc.nextInt();
            processes[i] = new Process(i + 1, bt);
        }

        
        Arrays.sort(processes, Comparator.comparingInt(p -> p.burstTime));

      
        processes[0].waitingTime = 0;

        for (int i = 1; i < n; i++) {
            processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        }

       
        double totalWT = 0, totalTAT = 0;
        for (int i = 0; i < n; i++) {
            processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
            totalWT += processes[i].waitingTime;
            totalTAT += processes[i].turnaroundTime;
        }

        
        System.out.println("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
        for (Process p : processes) {
            System.out.println("P" + p.pid + "\t" + p.burstTime + "\t" + p.waitingTime + "\t" + p.turnaroundTime);
        }

        System.out.printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
        System.out.printf("Average Turnaround Time = %.2f\n", totalTAT / n);

        sc.close();
    }
}

