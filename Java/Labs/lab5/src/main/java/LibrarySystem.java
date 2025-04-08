import java.util.*;

public class LibrarySystem {
    public static void main(String[] args) {
        Library library = new Library();
        List<Borrower> borrowers = new ArrayList<>();
        int choice=0;
        Scanner sc = new Scanner(System.in);
        do {
            try {
                System.out.println("\nEnter a Number:");
                System.out.println("1. Adding Books to the Library");
                System.out.println("2. List All Books");
                System.out.println("3. Filtering Books by Genre");
                System.out.println("4. Filtering Books by Author");
                System.out.println("5. Searching Books by Keyword");
                System.out.println("6. Sorting Books by Title");
                System.out.println("7. Providing Recommendations");
                System.out.println("8. Add Borrower to the Library");
                System.out.println("9. Borrower Return Book");
                System.out.println("10: quit");
                choice = Integer.parseInt(sc.nextLine());
                switch (choice) {
                    case 1:
                        /*
//                        String input = sc.nextLine();
//                        String[] parts = input.split(", ");
//                        String title = parts[0].split(":")[1].trim();
//                        String author = parts[1].split(":")[1].trim();
//                        String genre = parts[2].split(":")[1].trim();
//                        String year = parts[3].split(":")[1].trim();
                        */
                        library.addItem("1984", "George Orwell", "Fiction", 1949);
                        library.addItem("A Brief History of Time", "Stephen Hawking", "Science", 1988);
//                        System.out.println("Enter Book Title: ");
//                        String title = sc.nextLine();
//                        System.out.println("Enter Book Author: ");
//                        String author = sc.nextLine();
//                        System.out.println("Enter Book Genre: ");
//                        String genre = sc.nextLine();
//                        System.out.println("Enter Book Publication Year: ");
//                        int publicationYear = Integer.parseInt(sc.nextLine());
//                        library.addItem(title, author, genre, publicationYear);
                        library.addItem("A Beautiful Mind", "Sylvia Nasar", "Biography", 1998);
                        break;
                    case 2: //list out all books
                        library.printBooks();
                        break;
                    case 3:
                        System.out.print("Genre: ");
                        library.printGenreFilter(sc.nextLine());
                        break;
                    case 4: //Only list out books with author name
                        System.out.print("Author: ");
                        library.printAuthorFilter(sc.nextLine());
                        break;
                    case 5: //Print books with title starting with
                        System.out.println("Keyword: ");
                        library.printSearch(sc.nextLine());
                        break;
                    case 6: //Sort books in library
                        library.sortBooks();
                        break;
                    case 7:
                        System.out.println("Category: ");
                        library.printGenreRecommend(sc.nextLine());
                        break;
                    case 8:
                        System.out.println("Borrower Name: ");
                        borrowers.add(new Borrower(sc.nextLine()));
                        System.out.println("Borrow a book: ");
                        int curr = borrowers.size()-1;
                        borrowers.get(curr).addBook(sc.nextLine(), library.getBooks());
                        System.out.println("Borrower details: ");
                        System.out.print("{\"name\": \""+ borrowers.get(curr).getName() +"\", \"borrowedBooks\": [");
                        for(Book book : borrowers.get(curr).getBorrowedBooks()) {
                            System.out.print(book.getTitle());
                        }
                        System.out.println("]}");
                        break;
                    case 9:
                        System.out.println("Borrower Name: ");
                        String borrowerName = sc.nextLine();
                        for (Borrower borrower : borrowers) {
                            if (borrower.getName().equals(borrowerName)) {
                                System.out.println("Return book: ");
                                borrower.removeBook(sc.nextLine());
                                System.out.println("Borrower details: ");
                                System.out.print("{\"name\": \""+ borrower.getName() +"\", \"borrowedBooks\": [");
                                for(Book book : borrower.getBorrowedBooks()) {
                                    System.out.print(book.getTitle());
                                }
                                System.out.println("]}");
                            }
                        }
                        break;
                    case 10:
                        System.out.println("Program terminating ... ");
                }
            }
            catch (NumberFormatException e) {
                System.out.println("ERROR! Enter a number!");
            }
        } while (choice < 11);
    }
}