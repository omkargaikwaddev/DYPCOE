import java.util.Scanner;

public class NextFitMemoryAllocation {
    private int[] memoryBlocks;
    private int lastAllocatedIndex;

    public NextFitMemoryAllocation(int[] blocks) {
        this.memoryBlocks = blocks;
        this.lastAllocatedIndex = 0;
    }

    public int[] allocate(int[] processSizes) {
        int[] allocation = new int[processSizes.length];
        for (int i = 0; i < allocation.length; i++) {
            allocation[i] = -1; 
        }

        for (int i = 0; i < processSizes.length; i++) {
            int size = processSizes[i];
            int start = lastAllocatedIndex;
            boolean allocated = false;

            int j = start;
            do {
                if (memoryBlocks[j] >= size) {
                    allocation[i] = j;          
                    memoryBlocks[j] -= size;    
                    lastAllocatedIndex = j;    
                    allocated = true;
                    break;
                }
                j = (j + 1) % memoryBlocks.length;
            } while (j != start);

            if (!allocated) {
                allocation[i] = -1;  
            }
        }
        return allocation;
    }

    public void printAllocation(int[] processSizes, int[] allocation) {
        System.out.println("\nProcess No.\tProcess Size\tBlock No.");
        for (int i = 0; i < processSizes.length; i++) {
            System.out.print((i + 1) + "\t\t" + processSizes[i] + "\t\t");
            if (allocation[i] != -1) {
                System.out.println(allocation[i] + 1);
            } else {
                System.out.println("Not Allocated");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of memory blocks: ");
        int blockCount = scanner.nextInt();
        int[] blocks = new int[blockCount];
        System.out.println("Enter sizes of memory blocks:");
        for (int i = 0; i < blockCount; i++) {
            blocks[i] = scanner.nextInt();
        }

        System.out.print("Enter number of processes: ");
        int processCount = scanner.nextInt();
        int[] processes = new int[processCount];
        System.out.println("Enter sizes of processes:");
        for (int i = 0; i < processCount; i++) {
            processes[i] = scanner.nextInt();
        }

        NextFitMemoryAllocation nextFit = new NextFitMemoryAllocation(blocks);
        int[] allocation = nextFit.allocate(processes);
        nextFit.printAllocation(processes, allocation);

        scanner.close();
    }
}

