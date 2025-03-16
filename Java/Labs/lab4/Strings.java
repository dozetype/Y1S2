package Labs.lab4;

import java.util.Scanner;

public class Strings {
    public static void main (String[] args){
		Comparable[] intList;
		int size;
		Scanner scan = new Scanner(System.in);
		System.out.print ("\nHow many Strings do you want to sort? ");
		size = scan.nextInt();
        scan.nextLine(); //removing newline character after nextInt()
		intList = new Comparable[size];
		System.out.println ("\nEnter the String...");
		for (int i = 0; i < size; i++){
			intList[i] = scan.nextLine();
        }
        // Sorting.selectionSort(intList);
        Sorting.insertionSort(intList);
        System.out.println ("\nYour Strings in sorted order...");
		for (int i = 0; i < size; i++)
			System.out.print(intList[i] + " ");
		System.out.println();
	}
}
