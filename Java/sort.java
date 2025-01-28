import java.util.Scanner;

public class sort {
    // int list[];
    int fk = 0;

    public sort(int num) { //constructor
        // this.list = list;
        this.fk = num;
    }

    // public void main(int[] list) {
    //     System.out.println("hello---------------");
    //     // bubble(list);
    //     // for(int i=0; i<list.length; i++){
    //     //     System.out.println(list[i]);
    //     // }
    //     System.out.printf("%.2f \n", 19.779);
    //     String stringA = " Wild";

    //     String stringB = " Irish ";

    //     String stringC = "Rose";

    //     String result = stringA.trim() + stringB + stringC.trim();
    //     System.out.println(result);
    // }

    public void bubble(){
        // for(int i=0; i<list.length; i++){
        //     for(int j=0; j<list.length-1; j++){
        //         if(list[i] < list[j]){
        //             int temp = list[j];
        //             list[j] = list[i];
        //             list[i] = temp;
        //         }
        //     }
        // }
        fk+=3;
    }

    public sort copyObj(){
        sort copy = new sort(fk);
        return copy;
    }
}
