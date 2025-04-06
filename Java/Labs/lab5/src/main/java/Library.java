import java.util.*;
import java.util.stream.Collectors;

public class Library<T>{
    private List<Book> books = new ArrayList<>();
    private Set<T> genres = new HashSet<>();
    private Map<String, ArrayList<String>> authors = new HashMap<>();
    private List<T> borrowers = new ArrayList<>();

    public void addItem(String title, String author, String genre, int publicationYear){
        books.add(new Book(title, author, genre, publicationYear));
        System.out.println("Library contains "+books.size()+" books.");
    }

    public void printBooks(){
        for(Book book : books){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printGenreFilter(String filter){
        List<Book> filteredNames = books.stream()
                .filter(name->name.getGenre().startsWith(filter)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printAuthorFilter(String filter){
        List<Book> filteredNames = books.stream()
                .filter(name->name.getAuthor().startsWith(filter)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void printSearch(String search){
        List<Book> filteredNames = books.stream()
                .filter(name->name.getTitle().startsWith(search)) // Filter names starting with "A"
                .toList();
        for(Book book : filteredNames){
            System.out.println("{\"title\": \""+book.getTitle()+"\", \"author\": \""+book.getAuthor()+"\", \"genre\" :\""+book.getGenre()+"\", \"publicationYear\": "+ book.getPublicationYear()+"}");
        }
    }

    public void sortBooks(){
        books.sort( (a, b) -> { return -1 * a.getTitle().compareTo(b.getTitle()); } );
        System.out.println("Sorted Order by Title:");
        for(Book book : books){
            System.out.println("\""+book.getTitle()+"\"");
        }
    }
}
