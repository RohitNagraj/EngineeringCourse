package prog10.studentPkg;

import prog10.Student;

public class RegisterStudent implements Student {

    String name, branch;
    int credits;

    public String getName() {
        System.out.print("Hello! ");
        return name;
    }

    public String getBranch() {
        System.out.print("Your Branch registered is ");
        return branch;
    }

    public void setName(String s) {
        name = s;
    }

    public void setBranch(String b) {
        branch = b;
    }

    public int getCredits() {
        System.out.print("Your Credits registered is ");
        return credits;
    }

    public void setCredits(int c) {
        try {

            if (c > 30)
                throw new CreditLimitException("Credits cannot be more than 30");
            else if (c < 15)
                throw new CreditLimitException("Credits cannot be less than 15");
            else {
                credits = c;
                System.out.print(getName() + "\n");
                System.out.println("You registered successfully!");
                System.out.print(getBranch() + "\n");
                System.out.print(getCredits() + "\n");
            }

        } catch (CreditLimitException cle) {
            System.out.println("Student " + name + " of " + branch + " registered wrongly!");
            cle.printStackTrace();
        }
    } // end setCredits

    public static void main(String args[]) {

        RegisterStudent st1 = new RegisterStudent();
        st1.setName("Hermione Ganger");
        st1.setBranch("Information Science");
        st1.setCredits(25);
        RegisterStudent st2 = new RegisterStudent();
        st2.setName("Ron Wesley");
        st2.setBranch("Computer Science");
        st2.setCredits(12);
        RegisterStudent st3 = new RegisterStudent();
        st3.setName("Draco Malfoy");
        st3.setBranch("Computer Applications");
        st3.setCredits(32);
    }

}// end class RegisterStudent