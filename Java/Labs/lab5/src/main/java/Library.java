import java.util.*;
import java.util.stream.Collectors;

public class Library{
    private List<Book> books = new ArrayList<>();
    private Map<String, ArrayList<String>> authors = new HashMap<>();


    public void addItem(String title, String author, String genre, int publicationYear){
        books.add(new Book(title, author, genre, publicationYear));
        System.out.println("Library contains "+books.size()+" books.");
    }

    public void printBooks(){
        for(Book book : books){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printGenreFilter(String filter){ //list all book with genre
        System.out.println("List of books: ");
        List<Book> filteredNames = books.stream()
                .filter(name->name.getGenre().startsWith(filter)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printGenreRecommend(String filter){ //list all book with genre
        List<Book> filteredNames = books.stream()
                .filter(name->name.getGenre().startsWith(filter)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("Recommendation: \"Try '"+ book.getTitle() +"' by " + book.getAuthor() +"\".");
        }
    }

    public void printAuthorFilter(String filter){ //list all author starting with
        System.out.println("List of books: ");
        List<Book> filteredNames = books.stream()
                .filter(name->name.getAuthor().startsWith(filter)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printSearch(String search){ //list all books that startwith this title
        System.out.println("List of books: ");
        List<Book> filteredNames = books.stream()
                .filter(name->name.getTitle().contains(search)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void sortBooks(){
        books.sort( (a, b) -> { return 1 * a.getTitle().compareTo(b.getTitle()); } ); //ascending order
        System.out.println("Sorted Order by Title:");
        for(Book book : books){
            System.out.println("\""+book.getTitle()+"\"");
        }
    }

    public List<Book> getBooks() {
        return books;
    }
}
