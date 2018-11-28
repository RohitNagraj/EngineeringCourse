package main; //To create the class file in main

import main.StudentPackage.*;

public class MainClass {
    public static void main(String[] args) {
        RegisterStudent s = new RegisterStudent();
        System.out.println("\n---------- SEMESTER 1 ----------");
        s.register(1);
        s.result();
        System.out.println("\n---------- SEMESTER 2 ----------");
        s.register(2);
        s.result();
        System.out.println("\n---------- SEMESTER 3 ----------");
        s.register(3);
        s.result();
        System.out.println("\n---------- SEMESTER 4 ----------");
        s.register(4);
        s.result();
        s.printCGPA();
    }
}