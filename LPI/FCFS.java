import java.util.*;
class Process{
 int ID, AT, BT, CT, WT, TT;
 
 Process(int ID,int AT,int BT)
 {
 	this.ID=ID;
 	this.AT=AT;
 	this.BT=BT;
 }
 
 }
 
class FCFS
 {
 public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter number of processes:-");
		int n=sc.nextInt();
		
		Process[] processes=new Process[n];
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter arrival time of processes"+(i+1)+":");
			int at=sc.nextInt();
			System.out.println("Enter burst time of processes"+(i+1)+":");
			int bt=sc.nextInt();
			
			processes[i]=new Process(i+1,at,bt);
		}  
		Arrays.sort(processes, Comparator.comparingInt(p -> p.AT));

		int cT=0;
		
		for(Process p : processes)
		{
		 if(cT < p.AT){
		  cT = p.AT;
		 }
		 p.CT=cT+p.BT;
		 p.TT=p.CT-p.AT;
		 p.WT=p.TT-p.BT;
		 cT=p.CT;
		}
		
		System.out.println("\nPID\tAT\tBT\tCT\tTAT\tWT");
		for(Process p : processes)
		{
		System.out.println(p.ID+"\t"+p.AT+"\t"+p.BT+"\t"+p.CT+"\t"+p.TT+"\t"+p.WT);
		}
	}
 }




