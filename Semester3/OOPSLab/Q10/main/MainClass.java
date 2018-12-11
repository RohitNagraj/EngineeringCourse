//Please read the README file
package main;

import java.util.Scanner;
import main.Faculty;
import main.ISE.ISE_Department;

public class MainClass {

    public static void main(String[] args) {

        int menu, counter = 0; // Counter keeps track of the no of faculty profiles
        Faculty f[] = new Faculty[10]; // Array of Faculty objects
        String s;
        boolean flag = false;
        ISE_Department ise = new ISE_Department();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Add new faculty record");
            System.out.println("2. Print details of existing faculty record");
            System.out.println("3. Delete a faculty record");
            System.out.println("4. List of experienced faculty");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");
            menu = sc.nextInt();

            switch (menu) {
            case 1:
                f[counter] = new Faculty();
                ise.readData(f[counter]); // Calling ise's readData function which in in
                // ISE_Department file with faculty object as parameter
                counter++;
                break;

            case 2:
                System.out.print("Enter name of the faculty: ");
                s = sc.next();
                flag = false;
                for (int i = 0; i < counter; i++) {

                    if (f[i] != null) {

                        if (s.equals(f[i].name)) {
                            ise.printData(f[i]);
                            flag = true; // If profile found
                        }
                    }
                }
                if (flag == false)
                    System.out.println("Faculty not found");
                break;

            case 3:
                System.out.print("Enter name of the faculty: ");
                s = sc.next();
                flag = false;
                for (int i = 0; i < counter; i++) {
                    if (f[i] != null) {
                        if (s.equals(f[i].name)) {
                            f[i] = null; // Makes the pointer in the array null so it doesn't
                            // point to that object anymore
                            flag = true;
                        }
                    }
                }
                if (flag == false)
                    System.out.println("Faculty not found");
                break;

            case 4:
                for (int i = 0; i < counter; i++) {
                    if (f[i] != null) {
                        if (f[i].yearsOfExperience >= 20) {
                            ise.printData(f[i]);
                        }
                    }
                }
                break;

            case 5:
                System.exit(0);

            default:
                System.out.print("Wrong choice\n");
            }
        }
    }
}