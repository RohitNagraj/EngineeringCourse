import java.lang.Math;
import java.util.Scanner;

class Circle {
    double radius;

    Circle() {
        radius = 0;
    }

    Circle(double r) {
        radius = r;
    }

    double circleArea() {
        return (Math.PI * radius * radius);
    }
}

class Sector extends Circle {
    double angle;

    Sector(double r, double a) {
        radius = r;
        angle = a;
    }

    double sectorArea() {
        return (0.5 * radius * radius * angle);
    }
}

class Segment extends Circle {
    double length;

    Segment(double r, double l) {
        radius = r;
        length = l;
    }

    double segmentArea() {
        double h = radius - Math.pow(Math.pow(radius, 2) - Math.pow((length / 2), 2), 0.5);
        return ((h / (6 * length)) * ((3 * h * h) + (4 * length * length)));
        // Used a different formula cause the one given wasn't working
    }
}

public class Q8_Inheritance {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r, a, l;
        int choice;

        while (true) {

            System.out.println("1. Area of circle");
            System.out.println("2. Area of sector");
            System.out.println("3. Area of segment");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
            case 1:
                System.out.print("Enter radius:");
                r = sc.nextDouble();
                Circle c = new Circle(r);
                System.out.println("The area of the circle is: " + c.circleArea());
                break;

            case 2:
                System.out.print("Enter radius: ");
                r = sc.nextFloat();
                System.out.print("Enter angle: ");
                a = sc.nextDouble();
                Sector s = new Sector(r, a);
                System.out.println("The area of sector is: " + s.sectorArea());
                break;

            case 3:
                System.out.print("Enter radius: ");
                r = sc.nextDouble();
                System.out.print("Enter length of sector: ");
                l = sc.nextDouble();
                Segment sg = new Segment(r, l);
                System.out.println("The area of segment is: " + sg.segmentArea());
                break;

            case 4:
                System.exit(0);

            default:
                System.out.println("Wrong choice");
            }
        }
    }
}
