
import java.io.*;

public class test {
    public static void main(String[] args){
        try{
            BufferedWriter obj = new BufferedWriter(new FileWriter("sampleFile.csv"));
            obj.write("empName, empDesig, empAge\n");
            obj.write("empName, empDesig, empAge\n");
            obj.write("empName, empDesig, empAge\n");
            obj.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
