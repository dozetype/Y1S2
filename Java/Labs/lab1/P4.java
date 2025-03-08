package Labs.lab1;
import java.util.Scanner;
public class P4 {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Int");
        int layers = s.nextInt();
        for(int i=1; i<=layers; i++){
            for(int j=0; j<i; j++){
                if((j+i)%2==1){
                    System.out.print("AA");
                }
                else{
                    System.out.print("BB");
                }
            }
            System.out.println("");
        }
    }
}
