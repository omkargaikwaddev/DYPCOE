import java.util.Scanner;
class first{
    public static void main(String[] args) {
       int a[] = new int[5];
       int n;
        Scanner sc = new Scanner(System.in);
         System.out.println("Enter the number of elements in the array:");
         n = sc.nextInt();
         for (int i = 0; i < n; i++) {
             a[i] = sc.nextInt();
         }
            System.out.println("The even elements from array:\n");
            for(int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) {
                    System.out.print(a[i] + " ");
                }
            }
    }
}