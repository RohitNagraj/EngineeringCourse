package main.StudentPackage;

import java.util.Scanner;
import main.ResultPackage.*;

interface Student {
    void setName();

    void setBranch();
}

public class RegisterStudent extends Result implements Student {

    public RegisterStudent() {
    }

    public void setName() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        name = sc.next();
    }

    public void setBranch() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter branch: ");
        branch = sc.next();
    }

    public void register(int sem) {

        semester = sem; // Semester is given as a parameter for registration
        if (semester == 1) {
            setName();
            setBranch();
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the subjects registered: -");
        for (int i = 0; i < 6; i++) {
            subjects[i] = sc.next();
        }

        totalCredits = 0;
        System.out.println("Enter their respective credits: -");
        for (int i = 0; i < 6; i++) {
            credits[i] = sc.nextInt();
            totalCredits += credits[i];
        }

        if (totalCredits > 30) {
            System.out.println("Credits cannot exceed 30");
            throw new java.lang.Error("CreditLimit");
        }
    }
}