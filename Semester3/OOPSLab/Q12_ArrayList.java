
// To implement LikedList, just change the keyword ArrayList to LinkedList everywhere
import java.util.Scanner;
import java.util.ArrayList;

class Q12_ArrayList {
    public static void main(String[] args) {
        ArrayList<String> Q = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int choice;
        String x;
        while (true) {
            System.out.println("\n\n--------    MENU    --------");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Print names with len < 5");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
            case 1:
                System.out.print("Enter string to enqueue: ");
                x = sc.next();
                Q.add(Q.size(), x);
                System.out.println("Enqueued successfully");
                break;

            case 2:
                System.out.println("The string dequeued is: " + Q.remove(0));
                break;

            case 3:
                for (int i = 0; i < Q.size(); i++) {
                    System.out.println(Q.get(i));
                }
                break;

            case 4:
                for (int i = 0; i < Q.size(); i++) {
                    if (Q.get(i).length() < 5)
                        System.out.println(Q.get(i));
                }
                break;
            case 5:
                System.exit(0);
            default:
                System.out.println("Wrong choice");
            }
        }
    }
}