package Labs.lab3;

public class Plane {
    private PlaneSeat[] seat = new PlaneSeat[12];
    private int numEmptySeat = 12;
    
    public Plane(){
        for(int i=0; i<12; i++){
            seat[i] = new PlaneSeat(i+1);
        }
    }

    private PlaneSeat[] sortSeats(){ //sort seats in ascending of customerID
        PlaneSeat[] copy = new PlaneSeat[seat.length];
        for(int i=0; i<seat.length; i++){ //copying
            copy[i] = seat[i];
        }

        PlaneSeat temp;
        for(int i=0; i<copy.length; i++){ //bubble sort
            for(int j=0; j<copy.length-i-1; j++){
                if(copy[j].getCustomerID() > copy[j+1].getCustomerID()){
                    temp = copy[j];
                    copy[j] = copy[j+1];
                    copy[j+1] = temp;
                }
            }
        }
        return copy;
    }

    public void showNumEmptySeats(){ //method to display number of empty seats
        System.out.println("There are "+ numEmptySeat +" empty seats");
    }

    public void showEmptySeats(){ //display list of empty seats
        System.out.println("The following seats are empty:");
        for(int i=0; i<seat.length; i++){
            if(!seat[i].isOccupied()){ //if not occupied. print
                System.out.println("SeatID " + (i+1));
            }
        }
    }

    public void showAssignedSeats(boolean bySeatID){
        System.out.println("The seat assignments are as follow:");
        if(bySeatID){ //checking which order
            for(int i=0; i<seat.length; i++){
                if(seat[i].isOccupied()){
                    System.out.println("SeatID "+ (i+1) +" assigned to CustomerID "+ seat[i].getCustomerID()+'.');
                }
            }
        }
        else{ //customerID ascending order
            PlaneSeat[] copy;
            copy = sortSeats();
            for(int i=0; i<copy.length; i++){
                if(copy[i].isOccupied()){
                    System.out.println("SeatID "+ copy[i].getSeatID() +" assigned to CustomerID "+ copy[i].getCustomerID()+'.');
                }
            }
        }
    }

    public void assignSeat(int seatID, int custID){ //Assign custID to empty seat
        if(!seat[seatID-1].isOccupied()){ //if not occupied
            seat[seatID-1].assign(custID);
            System.out.println("Seat Assigned!");
            numEmptySeat--;
        }
        else{
            System.out.println("Seat already assigned to a customer.");
        }
    }

    public void unAssignSeat(int seatID){ //unassigns a seat
        if(seat[seatID-1].isOccupied()){ //checking if occupied
            seat[seatID-1].unAssign();
            System.out.println("Seat Unassigned!");
            numEmptySeat++;
        }
        else{
            System.out.println("NOTHING TO REMOVE!");
        }
    }
}
