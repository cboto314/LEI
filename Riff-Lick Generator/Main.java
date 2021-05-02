import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		ComposerBot c = new ComposerBot();
		
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);   
		char strat = sc.next().charAt(0);
		int seed = sc.nextInt();
		
		c.Strategy(strat,seed);

	}

}
