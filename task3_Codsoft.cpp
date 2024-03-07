#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    Book(const string& title, const string& author, int id) : title(title), author(author), id(id) {}

    const string& getTitle() const {
        return title;
    }

    const string& getAuthor() const {
        return author;
    }

    int getId() const {
        return id;
    }

private:
    string title;
    string author;
    int id;
};

class Borrower {
public:
    Borrower(const string& name, int id) : name(name), id(id) {}

    const string& getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

private:
    string name;
    int id;
};

class Transaction {
public:
    Transaction(const Book& book, const Borrower& borrower, const string& dueDate)
        : book(book), borrower(borrower), dueDate(dueDate) {}

    const Book& getBook() const {
        return book;
    }

    const Borrower& getBorrower() const {
        return borrower;
    }

    const string& getDueDate() const {
        return dueDate;
    }

private:
    Book book;
    Borrower borrower;
    string dueDate;
};

class Library {
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addBorrower(const Borrower& borrower) {
        borrowers.push_back(borrower);
    }

    void borrowBook(const Book& book, const Borrower& borrower, const string& dueDate) {
        Transaction transaction(book, borrower, dueDate);
        transactions.push_back(transaction);
    }

    void displayBooks() const {
        cout << "Books in the library:" << endl;
        for (const Book& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ID: " << book.getId() << endl;
        }
        cout << endl;
    }

    void displayBorrowers() const {
        cout << "Borrowers in the library:" << endl;
        for (const Borrower& borrower : borrowers) {
            cout << "Name: " << borrower.getName() << ", ID: " << borrower.getId() << endl;
        }
        cout << endl;
    }

    void displayTransactions() const {
        cout << "Transactions in the library:" << endl;
        for (const Transaction& transaction : transactions) {
            const Book& book = transaction.getBook();
            const Borrower& borrower = transaction.getBorrower();
            cout << "Borrower: " << borrower.getName() << ", Book: " << book.getTitle() << ", Due Date: " << transaction.getDueDate() << endl;
        }
        cout << endl;
    }

private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
};

int main() {
    Library library;

    // Add books
    Book book1("Book 1", "Author 1", 1);
    Book book2("Book 2", "Author 2", 2);
    Book book3("Book 3", "Author 3", 3);
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Add borrowers
    Borrower borrower1("Borrower 1", 1);
    Borrower borrower2("Borrower 2", 2);
    Borrower borrower3("Borrower 3", 3);
    library.addBorrower(borrower1);
    library.addBorrower(borrower2);
    library.addBorrower(borrower3);

    // Borrow books
    library.borrowBook(book1, borrower1, "2024-03-07");
    library.borrowBook(book2, borrower2, "2024-03-08");
    library.borrowBook(book3, borrower3, "2024-03-09");

    // Display books, borrowers, and transactions
    library.displayBooks();
    library.displayBorrowers();
    library.displayTransactions();

    return 0;
}