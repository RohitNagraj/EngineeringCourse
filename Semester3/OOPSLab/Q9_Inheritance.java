
//This code can be visualized at http://pythontutor.com/visualize.html#mode=edit by selecting 
//Java 8 as the language and replacing input statements with some values, eg replace 
//sc.nextint() with 10. 

import java.util.Scanner;

abstract class Vehicle {
    int yearOfManufacture;

    Vehicle() {
        yearOfManufacture = 0;
    }

    abstract int getData();

    abstract void putData(int x);
}

class TwoWheeler extends Vehicle { // Entends the abstract class and defines both abstract methods
    TwoWheeler() {

    }

    int getData() {
        return yearOfManufacture;
    }

    void putData(int x) {
        yearOfManufacture = x;
    }
}

final class FourWheeler extends Vehicle { // Final implies the class cannot be extended
    FourWheeler() {

    }

    int getData() {
        return yearOfManufacture;
    }

    void putData(int x) {
        yearOfManufacture = x;
    }
}

class MyTwoWheeler extends TwoWheeler {

    MyTwoWheeler() {

    }

    void putData(int x) {
        super.putData(x); // super refers to TwoWheeler class and its putData is called.
    }
}

public class Q9_Inheritance {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        MyTwoWheeler myScooter = new MyTwoWheeler();

        System.out.print("Enter the year of manufacture of Scooter: ");
        myScooter.putData(sc.nextInt());

        System.out.print("\nThe data stored in myScooter instance is: " + myScooter.getData());

        FourWheeler myCar = new FourWheeler();
        System.out.print("Enter the year of manufacture of car: ");
        myCar.putData(sc.nextInt());

        System.out.print("\nThe data stored in myCar instance is: " + myCar.getData());
    }
}