#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string title;
    string author;
    string ISBN;
    float* prices;
    int numEditions;
};

Book createBook()
{
    Book b;

    cout << "\nEnter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    cout << "Enter ISBN Number: ";
    getline(cin, b.ISBN);

    cout << "Enter number of editions: ";
    cin >> b.numEditions;

    b.prices = new float[b.numEditions];

    cout << "Enter prices for each edition:\n";
    for (int i = 0; i < b.numEditions; i++) {
        cout << "Edition " << i + 1 << ": ";
        cin >> b.prices[i];
    }
    cin.ignore();
    return b;
}

void displayBook(const Book& b)
{
    cout << "\n----- Book Details -----\n";
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "ISBN: " << b.ISBN << endl;
    cout << "Number of editions: " << b.numEditions << endl;
    cout << "Prices: ";
    for (int i = 0; i < b.numEditions; i++)
    {
        cout << b.prices[i];
        if (i != b.numEditions - 1) cout << ", ";
    }
    cout << endl;
}

float calculateAveragePrice(const Book& b)
{
    float sum = 0;
    for (int i = 0; i < b.numEditions; i++) {
        sum += b.prices[i];
    }
    return sum / b.numEditions;
}

void deleteBook(Book& b)
{
    delete[] b.prices;
    b.prices = nullptr;
}

int main()
{
    int numBooks;
    cout << "Enter number of books: ";
    cin >> numBooks;
    cin.ignore();
    Book* books = new Book[numBooks];

    for (int i = 0; i < numBooks; i++)
    {
        cout << "\n--- Enter details for Book " << i + 1 << " ---\n";
        books[i] = createBook();
    }

    for (int i = 0; i < numBooks; i++)
    {
        displayBook(books[i]);
        float avg = calculateAveragePrice(books[i]);
        cout << "Average Price: " << avg << endl;
    }

    for (int i = 0; i < numBooks; i++)
    {
        deleteBook(books[i]);
    }
    delete[] books;
    return 0;
}
