package Labs.lab3;

public class PlaneSeat {
    private int seatID;
    private int customerID;
    private boolean assigned;

    public PlaneSeat(int seatID){
        this.seatID = seatID;
    }

    public int getSeatID(){
        return this.seatID;
    }

    public int getCustomerID(){
        return this.customerID;
    }

    public boolean isOccupied(){
        return this.assigned;
    }

    public void assign(int custID){
        this.customerID = custID;
        this.assigned = true;
    }

    public void unAssign(){
        this.customerID = -1;
        this.assigned = false;
    }
}
