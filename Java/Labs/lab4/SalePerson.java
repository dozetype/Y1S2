package Labs.lab4;


public class SalePerson implements Comparable{
    private String firstName;
    private String lastName;
    private int totalSale;

    public SalePerson(String lastName, String firstName, int totalSale){
        this.lastName = lastName;
        this.firstName = firstName;
        this.totalSale = totalSale;
    }

    public String toString(){
        return String.format("%s, %s, %d", lastName, firstName, totalSale);
    }

    public boolean equals(SalePerson o){
        if(o.getFirstName()==this.firstName && o.getLastName()==this.lastName){
            return true;
        }
        return false;
    }

    public int compareTo(Object o){
        if(this.getTotalSale() < ((SalePerson) o).getTotalSale()){ //if this.TotalSales more than o
            return -1;
        }
        else if(this.getTotalSale() > ((SalePerson) o).getTotalSale()){
            return 1;
        }
        else{
            if(this.getLastName().compareTo(((SalePerson) o).getLastName()) > 0){ //if this.lastName bigger than o.lastName
                return 1;
            }
            else{
                return -1;
            }
        }
    }

    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public int getTotalSale(){
        return this.totalSale;
    }
}
