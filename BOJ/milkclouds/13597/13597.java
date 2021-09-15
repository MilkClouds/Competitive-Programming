import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt(), b = scan.nextInt();
		if(a < b) System.out.print(b);
        else (a > b) System.out.print(a);
	}
}
