import java.util.Scanner;

public class Lab2 {
    public static void main(String[] args){
        int choice;
        int m, n;
        Scanner sc = new Scanner(System.in);
        do {
            System.err.println("\n");
            System.out.println("Perform the following methods:");
            System.out.println("1: miltiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit\n");
            choice = sc.nextInt();
            switch (choice) {
                case 1: /* add mulTest() call */
                    mulTest();
                    break;

                case 2: /* add divide() call */
                    System.out.println("Enter m: ");
                    m = sc.nextInt();
                    System.out.println("Enter n: \n");
                    n = sc.nextInt();
                    System.out.println(m+"/"+n+"="+divide(m, n)+"\n");
                    break;

                case 3: /* add modulus() call */
                    System.out.println("Enter m: ");
                    m = sc.nextInt();
                    System.out.println("Enter n: \n");
                    n = sc.nextInt();
                    System.out.println(m+"%"+n+"="+modulus(m, n)+"\n");
                    break;

                case 4: /* add countDigits() call */
                    System.out.println("Enter Positive integer number: ");
                    n = sc.nextInt();
                    m = countDigits(n);
                    if(m<0){
                        System.out.println("n : " + n +" - Error input!!");
                    }
                    else{
                        System.out.println("n : " + n +" - count = " + m);
                    }
                    break;

                case 5: /* add position() call */
                    System.out.println("Enter integer number: ");
                    n = sc.nextInt();
                    System.out.println("Enter digit to find: \n");
                    m = sc.nextInt();
                    System.err.println("Position = "+position(n, m));
                    break;

                case 6: /* add extractOddDigits() call */
                    System.out.println("Enter Positive integer number: ");
                    long x = sc.nextLong();
                    System.err.println("\nOddDigits = "+extractOddDigits(x));
                    break;
                    
                case 7: System.out.println("Program terminating ... ");
            }
        } while (choice < 7);
    }

    public static void mulTest(){
        int x, y, ans, score=0;
        Scanner sc = new Scanner(System.in);
        for(int i=0; i<5; i++){
            x = (int)(Math.random()*9)+1;
            y = (int)(Math.random()*9)+1;
            System.out.println("How much is " + x + " times " + y + "?:");
            ans = sc.nextInt();
            if(ans == x*y){
                score++;
            }
        }
        System.out.println(score + " answers out of 5 are correct\n");
    }

    public static int divide(int m, int n){
        return (int)(m/n);
    }

    public static int modulus(int m, int n){
        return (int)(m%n);
    }

    public static int countDigits(int n){
        if(n<0) return -1;
        int count=0;
        while(n!=0){
            n/=10;

            count++;
        } 
        return count;
    }

    public static int position(int n, int digit){
        int index=1;
        while(n>0){
            if(n%10==digit){
                return index;
            }
            n/=10;
            index++;
        }
        return -1;
    }

    public static long extractOddDigits(long n){
        long result=0, multiply=1;
        if(n<0) return -1;

        while(n>0){
            if((n%10)%2==1){
                result += (n%10)*multiply;
                multiply *= 10;
            }
            n/=10;
        }
        return result==0? -1 : result;
    }
}