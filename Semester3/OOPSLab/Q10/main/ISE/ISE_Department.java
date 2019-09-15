package main.ISE;

import java.util.Scanner;
import main.*;

public class ISE_Department implements Department {

    public void readData(Faculty f) {
        int tempAge;
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter name: ");
        f.name = sc.next();
        System.out.print("\nEnter age: ");
        tempAge = sc.nextInt();
        if (tempAge <= 58) {
            f.age = tempAge;
        } else {
            throw new java.lang.Error("AgeException");
        }
        System.out.print("\nEnter designation: ");
        f.designation = sc.next();
        System.out.print("\nEnter years of experience: ");
        f.yearsOfExperience = sc.nextInt();
        System.out.print("\nEnter joining date: ");
        f.joiningDate = sc.next();
        System.out.print("\nEnter subjects handled: ");
        f.subjectsHandled = sc.next();
        System.out.print("\nData entered successfully\n");
    }

    public void printData(Faculty f) {
        System.out.print("\nName: " + f.name);
        System.out.print("\nAge: " + f.age);
        System.out.print("\nDesignation: " + f.designation);
        System.out.print("\nYears of experience: " + f.yearsOfExperience);
        System.out.print("\nJoining date: " + f.joiningDate);
        System.out.println("\nSubjects handled: " + f.subjectsHandled);
    }
}