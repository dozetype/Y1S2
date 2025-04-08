import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Borrower {
    private String name;
    private List<Book> borrowedBooks = new ArrayList<>();

    public Borrower(String name) {
        this.name = name;
    }
    public void addBook(String title, List<Book> library) {
        for(Book book : library) {
            if(book.getTitle().equals(title)) {
                borrowedBooks.add(book);
                return;
            }
        }
        System.out.println("Book Not Found");
    }

    public String getName() {
        return name;
    }
    public List<Book> getBorrowedBooks() {
        return borrowedBooks;
    }
    public void removeBook(String title) {
        for(Book book : borrowedBooks) {
            if(book.getTitle().equals(title)) {
                borrowedBooks.remove(book);
                return;
            }
        }
    }
}
