import java.util.Scanner;

class Q7_PersonalClass {

	public String name, education;
	public int age, yearsOfExperience, noOfLoans, loanAmount, salary, basic, da, hra;

	Q7_PersonalClass(String name, String education, int age, int yearsOfExperience, int noOfLoans, int loanAmount,
			int basic, int da, int hra) {
		this.name = name;
		this.education = education;
		this.age = age;
		this.yearsOfExperience = yearsOfExperience;
		this.noOfLoans = noOfLoans;
		this.loanAmount = loanAmount;
		this.basic = basic;
		this.da = da;
		this.hra = hra;
		this.salary = basic + da + hra;
	}

	boolean isEligible() {
		if (age >= 18 && yearsOfExperience > 2 && noOfLoans < 3 && salary > 20000)
			return true;
		else
			return false;
	}

	double taxPay() {
		if (salary < 250000)
			return 0;

		else if (salary >= 250000 && salary < 500000)
			return ((salary - 250000) * 0.05);

		else if (salary >= 500000 && salary < 1000000)
			return (12500 + (salary - 500000) * 0.2);

		else
			return (12500 + 100000 + ((salary - 1000000) * 0.3));

	}

	boolean isEligiblePromotion() {
		if (age > 25 && yearsOfExperience > 5)
			return true;
		else
			return false;
	}

	void display() {
		System.out.println("Name: " + name);
		System.out.println("Age: " + age);
		System.out.println("Education: " + education);
		System.out.println("Years of experience: " + yearsOfExperience);
		System.out.println("No. of loans: " + noOfLoans);
		System.out.println("Loan amount: " + loanAmount);
		System.out.println("Salary: " + salary);
		System.out.println("Basic: " + basic);
		System.out.println("DA: " + da);
		System.out.println("HRA: " + hra);
	}

	public static void main(String args[]) {
		String name, education;
		int age, yearsOfExperience, noOfLoans, loanAmount, basic, da, hra, n, counter;
		boolean flag = false;

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the no. of Employees: ");
		n = sc.nextInt();

		Q7_PersonalClass personalDetails[] = new Q7_PersonalClass[n];
		counter = 0;

		while (true) {
			flag = false;
			System.out.println("1. New profile");
			System.out.println("2. Check eligibility for loan of an employee");
			System.out.println("3. Calculate tax amount to be paid");
			System.out.println("4. Check eligibility from promotion of an employee");
			System.out.println("5. Display an employee's data");
			System.out.println("6. Exit");
			System.out.print("Enter your choice: ");
			int choice = sc.nextInt();

			switch (choice) {
			case 1:
				if (counter == n) {
					System.out.println("No more employees can be added");
					break;
				}
				System.out.print("Name: ");
				name = sc.next();

				System.out.print("Age: ");
				age = sc.nextInt();

				System.out.print("Education: ");
				education = sc.next();

				System.out.print("Years of experience: ");
				yearsOfExperience = sc.nextInt();

				System.out.print("No. of loans: ");
				noOfLoans = sc.nextInt();

				System.out.print("Loan amount: ");
				loanAmount = sc.nextInt();

				System.out.print("Basic: ");
				basic = sc.nextInt();

				System.out.print("DA: ");
				da = sc.nextInt();

				System.out.print("HRA: ");
				hra = sc.nextInt();

				personalDetails[counter++] = new Q7_PersonalClass(name, education, age, yearsOfExperience, noOfLoans,
						loanAmount, basic, da, hra);
				System.out.println("Profile added successfully\n\n");
				break;

			case 2:
				System.out.print("Enter employee name: ");
				name = sc.next();

				for (int i = 0; i < counter; i++) {
					if (name.equals(personalDetails[i].name)) {
						System.out.println("The loan eligibility is: " + personalDetails[i].isEligible() + "\n\n");
						flag = true;
						break;
					}
				}
				if (flag == false)
					System.out.println("Employee not found\n\n");
				break;

			case 3:
				System.out.print("Enter employee name: ");
				name = sc.next();

				for (int i = 0; i < counter; i++) {
					if (name.equals(personalDetails[i].name)) {
						System.out.println("The tax amount to be paid is: " + personalDetails[i].taxPay() + "\n\n");
						flag = true;
						break;
					}
				}

				if (flag == false)
					System.out.println("Employee not found\n\n");
				break;

			case 4:
				System.out.print("Enter employee name: ");
				name = sc.next();

				for (int i = 0; i < counter; i++) {
					if (name.equals(personalDetails[i].name)) {
						System.out.println("The employee is eligible for promotion: "
								+ personalDetails[i].isEligiblePromotion() + "\n\n");
						flag = true;
						break;
					}
				}

				if (flag == false)
					System.out.println("Employee not found\n\n");
				break;

			case 5:
				System.out.print("Enter employee name: ");
				name = sc.next();

				for (int i = 0; i < counter; i++) {
					if (name.equals(personalDetails[i].name)) {
						System.out.println("The employee details are: ");
						personalDetails[i].display();
						System.out.print("\n\n");
						flag = true;
						break;
					}
				}

				if (flag == false)
					System.out.println("Employee not found\n\n");
				break;

			case 6:
				System.exit(0);
				break;

			default:
				System.out.println("Wrong choice");
				break;
			}
		}
	}
}
