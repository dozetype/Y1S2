import java.util.Scanner;

public class LibrarySystem {
    public static void main(String[] args) {
        Library library = new Library();
        int choice=0;
        Scanner sc = new Scanner(System.in);
        do {
            try {
                System.out.println("Enter a Number:");
                System.out.println("1. Adding Books to the Library");
                System.out.println("2. Filtering Books by Genre");
                System.out.println("3. Filtering Books by Author");
                System.out.println("4. Searching Books by Keyword");
                System.out.println("5. Sorting Books by Title");
                System.out.println("7: quit");
                choice = Integer.parseInt(sc.nextLine());
                switch (choice) {
                    case 1: /* add mulTest() call */
//                        System.out.println("Enter Book Title: ");
//                        String title = sc.nextLine();
//                        System.out.println("Enter Book Author: ");
//                        String author = sc.nextLine();
//                        System.out.println("Enter Book Genre: ");
//                        String genre = sc.nextLine();
//                        System.out.println("Enter Book Publication Year: ");
//                        int publicationYear = Integer.parseInt(sc.nextLine());
                        library.addItem("1984", "George Orwell", "Fiction", 1949);
                        library.addItem("A Brief History of Time", "Stephen Hawking", "Science", 1988);
                        break;
                    case 2: //list out all books
                        library.printBooks();
                        sc.nextLine(); //used to wait for input
                        break;
                    case 3: //Only list out books with author name
                        String filter = sc.nextLine();
                        library.printAuthorFilter(filter);
                        sc.nextLine(); //used to wait for input
                        break;
                    case 4: //Sort books in library
                        library.sortBooks();
                        sc.nextLine(); //used to wait for input
                        break;
                    case 7:
                        System.out.println("Program terminating ... ");
                }
            }
            catch (NumberFormatException e) {
                System.out.println("ERROR! Enter a number!");
            }
        } while (choice < 7);
    }
}
