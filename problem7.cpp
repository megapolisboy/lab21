#include<iostream>
#include<fstream>

using namespace std;

char* get_file_name_by_index(int book_index){
    switch(book_index){
        case 1:
            return "book1";
        case 2:
            return "book2";
        case 3:
            return "book3";
        case 4:
            return "book4";
        default:
            return "book5";
    }
}

int number_of_books(int book_index) {
    int number_of_books = 0;
    char *title = get_file_name_by_index(book_index);
    ifstream in(title, ios::binary);
    in.read((char *) &number_of_books, sizeof(number_of_books));
    in.close();
    return (number_of_books - '0');
}

bool give_book(int book_index){
    int number_of_books = 0;
    char* title = get_file_name_by_index(book_index);
    ifstream in(title,ios::binary);
    in.read((char*)&number_of_books, sizeof(number_of_books));
    in.close();
    if(number_of_books - '0' >= 1) {
        number_of_books--;
        ofstream out(title, ios::binary);
        out.clear();
        out.write((char *) &number_of_books, sizeof(number_of_books));
        out.close();
        return true;
    } else {
        return false;
    }

}

void receive_book(int book_index){
    int number_of_books = 0;
    char* title = get_file_name_by_index(book_index);
    ifstream in(title,ios::binary);
    in.read((char*)&number_of_books, sizeof(number_of_books));
    in.close();
    number_of_books++;
    ofstream out(title, ios::binary);
    out.clear();
    out.write((char *) &number_of_books, sizeof(number_of_books));
    out.close();
}

int main(){
    cout << "Welcome to E-Library. We have the following books: \n Book 1 - 'Pride and Prejudicies' \n Book 2 - 'The little Prince' \n Book 3 - 'Harry Potter' \n Book 4 - 'The Hobbit' \n Book 5 - 'Hamlet'\n";
    int book_index;
    cout << "Which book would you like to choose? (1 to 5): ";
    cin >> book_index;
    cout << "What would you like to do? Enter 1 to check the number of books remaining, 2 to take a book, 3 to return it to the library: ";
    int operation;
    cin >> operation;
    if(operation == 1){
        cout << number_of_books(book_index) << " books left";
    } else if(operation == 2){
        if(give_book(book_index)){
            cout << "Grab your book!";
        } else {
            cout << "Sorry, no books left";
        }
    } else if(operation == 3){
        receive_book(book_index);
        cout << "Book is received, thanks";
    }
}

