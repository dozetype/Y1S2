public class sort{
    public static void main(String[] args){
        A a2 = new C1();
        a2.print("Line2");
    }
    public static void print(String s){
        System.out.println(s);
    }
}
class A {
    public A(){
        System.out.print("Good");
    }
    public void print(Object o){ //changing between Object type and String makes no sense
        System.out.print("A");
    }
}

class C1 extends A{
    public C1(){
        System.out.print("Great");
    }
    public void print(String s){ //It seem that the subclass has higher priority and string also has the priority
        System.out.println("C1kjhkhkh");//However A gets called even thou it is superclass and is using object type
    }
}