package Labs.lab1;
import java.util.Scanner;

public class P3 {
    public static void main(String[] args){
        int start, end, increment;
        Scanner s = new Scanner(System.in);


        System.out.println("Starting: ");
        start = s.nextInt();
        System.out.println("Ending: ");
        end = s.nextInt();
        System.out.println("Increment: ");
        increment = s.nextInt();
        if(start<end){
            System.out.println("US$" + "\t" + "S$");
            System.out.println("--------------");
            for(int i=start; i<=end; i+=increment){
                System.out.println(i + "\t" + i*1.82);
            }
        }
        else{
            System.out.println("Error input!!");
        }

        //////////////////////////////////////////////////////
        System.out.println("Starting: ");
        start = s.nextInt();
        System.out.println("Ending: ");
        end = s.nextInt();
        System.out.println("Increment: ");
        increment = s.nextInt();
        if(start<end){
            System.out.println("US$" + "\t" + "S$");
            System.out.println("--------------");
            while(start<=end){
                System.out.println(start + "\t" + start*1.82);
                start+=increment;
            }
        }
        else{
            System.out.println("Error input!!");
        }
        /////////////////////////////////////////////////////////
        System.out.println("Starting: ");
        start = s.nextInt();
        System.out.println("Ending: ");
        end = s.nextInt();
        System.out.println("Increment: ");
        increment = s.nextInt();
        if(start<end){
            System.out.println("US$" + "\t" + "S$");
            System.out.println("--------------");
            do{
                System.out.println(start + "\t" + start*1.82);
                start+=increment;
            }while(start<=end);
        }
        else{
            System.out.println("Error input!!");
        }
    }
}
