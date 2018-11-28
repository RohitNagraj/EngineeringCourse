package prog10.resultPkg;

public class StudentGrade {

    float SGPA;
    char grade1, grade2, grade3;
    String subject1, subject2, subject3;

    void setGrades(char g1, char g2, char g3) {

        grade1 = g1;
        grade2 = g2;
        grade3 = g3;

    }

    void setCourses(String s1, String s2, String s3) {

        subject1 = s1;
        subject2 = s2;
        subject3 = s3;

    }

    void setSGPA(int g) {
        try {

            if (g > 10)
                //throw new InvalidSGPAException("SGPA cannot be more than 10");
            //else if (g <= 0)
                //throw new InvalidSGPAException(
                 //       "You cannot continue as an Engineering Student!Please look for an alternate career course. Best of luck!");
            else {
                SGPA = g;
                display();
            }
        } //catch (InvalidSGPAException isgpa) {
            //isgpa.printStackTrace();
        }

    } // end of setSGPA

    void display() {

        System.out.println("Your Grade details are: ");
        System.out.println("Subject " + subject1 + " Grade is " + grade1);
        System.out.println("Subject " + subject2 + " Grade is " + grade2);
        System.out.println("Subject " + subject3 + " Grade is " + grade3);

    }// end of display

    public static void main(String[] args) {

        StudentGrade stg = new StudentGrade();
        stg.setGrades('S', 'A', 'B');
        stg.setCourses("OOPS with Java", "Maths-3", "Digital Design");
        // stg.setSGPA(11);
        stg.setSGPA(0);
        // stg.setSGPA(8);

    }// end of Main

}// end of StudentGrade