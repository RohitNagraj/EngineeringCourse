
// All the lines that have changed have a comment next to them
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator; //Import iterator

class Q12_ArrayListWithIterator {
    public static void main(String[] args) {
        ArrayList<String> Q = new ArrayList<>();

        Iterator itr = Q.iterator(); // Initialize iterator

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
                itr = Q.iterator(); // set iterator to Q's iterator
                while (itr.hasNext()) { // While theres elements remaining in iterator
                    System.out.println(itr.next()); // itr.next() returns the next element in the list
                }
                break;

            case 4:
                itr = Q.iterator(); // set iterator to Q's iterator
                while (itr.hasNext()) { // While theres elements remaining in iterator
                    String i = (String) itr.next(); // Iterator returns an object of type
                    // Object type which has to be type casted to string
                    if (i.length() < 5) // i contains the string now
                        System.out.println(i); // Print i
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