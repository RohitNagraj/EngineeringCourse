package main.StudentPackage;

public class CGPA {
    public int marks[][] = new int[4][6]; // Assuming 6 subjects and 4 semesters
    public float sgpa[] = new float[4];
    float cgpa;

    public CGPA() {
    }

    public void printCGPA() {
        for (int i = 0; i < 4; i++) {
            System.out.println("SGPA in semester " + (i + 1) + " = " + sgpa[i]);
            cgpa += sgpa[i];
        }
        cgpa /= 4;
        System.out.println("The cgpa of the student is: " + cgpa);
    }
}