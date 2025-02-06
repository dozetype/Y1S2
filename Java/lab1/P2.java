package lab1;
import java.util.Scanner;

public class P2 {
    public static void main(String[] args){
        int salary, merit;
        System.out.println("salary: ");
        Scanner s = new Scanner(System.in);
        salary = s.nextInt();
        System.out.println("Merit: ");
        merit = s.nextInt();
        char grade = grading(salary, merit);
        System.out.println("Grade "+grade);

    }

    public static char grading(int salary, int merit){
        if(salary<=649){
            if(salary>=600&&salary<=649){
                if(merit>=10){
                    return 'B';
                }
                else{
                    return 'C';
                }
            }
            else{
                return 'C';
            }
        }
        else if(salary>=650&&salary<=799){
            if(salary>=700&&salary<=799){
                if(merit>=20){
                    return 'A';
                }
                else{
                    return 'B';
                }
            }
            else{
                return 'B';
            }
        }
        else{
            return 'A';
        }
    }
}
