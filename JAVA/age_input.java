import java.util.Scanner;

public class age_input {
	public static void main(String[] args) {
		int age = 25;
		Scanner ageScan = new Scanner(System.in);
		age = ageScan.nextInt();

		if(age <= 0) {
			System.out.println("Error");
		} else if(age <= 16) {
			System.out.println("Too Young");
		} else if(age < 100) {
			System.out.println("Welcome!");
		} else {
			System.out.println("Really?");
		}
	}
}
