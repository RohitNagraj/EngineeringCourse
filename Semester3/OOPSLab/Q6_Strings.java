import java.util.Scanner;
import java.util.Arrays;

class Q6_Strings {
	private static int countWord(String s, String word) {
		int counter = 0;
		while (s.contains(word)) {
			int index = s.indexOf(word);
			s = s.substring(index + word.length(), s.length());
			counter++;
		}
		return counter;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s, k;
		int choice, z;

		System.out.print("Enter a string: ");
		s = sc.nextLine();
		while (true) {
			System.out.println("\n\n--------------------  MENU  --------------------");
			System.out.println("1. Extract a portion of the string");
			System.out.println("2. Count the occurances of a particular word");
			System.out.println("3. Replace a substring in the string");
			System.out.println("4. Sort the string");
			System.out.println("5. Compare two strings");
			System.out.println("6. Concatinate two strings");
			System.out.println("7. Exit");
			System.out.print("Enter your choice: ");
			choice = sc.nextInt();
			sc.nextLine();

			switch (choice) {
			case 1:
				System.out.print("Enter the length of the extraction: ");
				z = sc.nextInt();
				System.out.println("The resulting string is: " + s.substring(0, z));
				break;
			case 2:
				System.out.print("Enter the word to be searched for: ");
				k = sc.next();
				System.out.println("The number of occurances are: " + countWord(s, k));
				break;
			case 3:
				System.out.print("Enter the string to be replaced: ");
				k = sc.next();
				System.out.print("Enter the string that replaces it: ");
				String str = sc.next();
				System.out.println("The modified string is: " + s.replaceFirst(k, str));
				break;
			case 4:
				String[] splits = s.split(" ");
				Arrays.sort(splits);
				System.out.println("The sorted string is: ");
				for (String asset : splits) {
					System.out.print(asset + " ");
				}
				break;
			case 5:
				System.out.print("Enter a string to be compared: ");
				k = sc.nextLine();
				System.out.println("The string is same: " + s.equalsIgnoreCase(k));
				break;
			case 6:
				System.out.print("Enter a string to be concatinated: ");
				k = sc.next();
				k = s + k;
				System.out.println("The concatinated string is: " + k);
				break;
			case 7:
				System.exit(0);
			default:
				System.out.println("Wrong choice");
				break;
			}
		}
	}
}