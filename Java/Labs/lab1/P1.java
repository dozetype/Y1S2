package Labs.lab1;
import java.util.Scanner;

public class P1 {
    public static void main(String[] args){
        Scanner user = new Scanner(System.in);
        System.out.println("Enter character: ");

        char choice = user.next().charAt(0);  // Read user input
        switch(Character.toLowerCase(choice)){
            case 'a':
                System.out.println("Action movie fan\n");
                break;
            case 'c':
                System.out.println("Comedy movie fan\n");
                break;
            case 'd':
                System.out.println("Drama movie fan\n");
                break;
            default:
                System.out.println("Invalid choice\n");
                break;
        }
    }
}
