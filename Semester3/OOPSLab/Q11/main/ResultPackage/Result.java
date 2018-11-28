package main.ResultPackage;

import main.StudentPackage.CGPA;
import java.util.Scanner;

public class Result extends CGPA {
    char grade[][] = new char[4][6];
    public int credits[] = new int[6], semester, totalCredits;
    public String name, branch, subjects[] = new String[6];

    public Result() {
    }

    public void result() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the marks in " + subjects[0] + ": ");
        marks[semester - 1][0] = sc.nextInt();
        System.out.print("Enter the marks in " + subjects[1] + ": ");
        marks[semester - 1][1] = sc.nextInt();
        System.out.print("Enter the marks in " + subjects[2] + ": ");
        marks[semester - 1][2] = sc.nextInt();
        System.out.print("Enter the marks in " + subjects[3] + ": ");
        marks[semester - 1][3] = sc.nextInt();
        System.out.print("Enter the marks in " + subjects[4] + ": ");
        marks[semester - 1][4] = sc.nextInt();
        System.out.print("Enter the marks in " + subjects[5] + ": ");
        marks[semester - 1][5] = sc.nextInt();

        int t = 0;
        for (int i = 0; i < 6; i++) {
            if (marks[semester - 1][i] > 90)
                grade[semester - 1][i] = 'S';
            else if (marks[semester - 1][i] > 80)
                grade[semester - 1][i] = 'A';
            else if (marks[semester - 1][i] > 70)
                grade[semester - 1][i] = 'B';
            else if (marks[semester - 1][i] > 60)
                grade[semester - 1][i] = 'C';
            else if (marks[semester - 1][i] > 50)
                grade[semester - 1][i] = 'D';
            else
                grade[semester - 1][i] = 'F';
        }

        for (int i = 0; i < 6; i++) {
            if (grade[semester - 1][i] == 'S') {
                sgpa[semester - 1] += credits[i] * 10;
            } else if (grade[semester - 1][i] == 'A') {
                sgpa[semester - 1] += credits[i] * 9;
            } else if (grade[semester - 1][i] == 'B') {
                sgpa[semester - 1] += credits[i] * 8;
            } else if (grade[semester - 1][i] == 'C') {
                sgpa[semester - 1] += credits[i] * 7;
            } else if (grade[semester - 1][i] == 'D') {
                sgpa[semester - 1] += credits[i] * 6;
            } else if (grade[semester - 1][i] == 'F') {
                sgpa[semester - 1] += credits[i] * 0;
            }
        }
        sgpa[semester - 1] = sgpa[semester - 1] / totalCredits;
        try {
            if (sgpa[semester - 1] > 10)
                throw new Exception("InvalidSGPA");
        } catch (Exception e) {
            System.out.println("SGPA is invalid");
        }

        System.out.println("SGPA = " + sgpa[semester - 1]);
    }

}