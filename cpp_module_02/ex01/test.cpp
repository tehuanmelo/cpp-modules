#include <iostream>
#include <string>

class Book
{
private:
    std::string Title;
    std::string Author;
    float *Rate;
    int RatesCounter;
public:
    Book() {
        Title = "No title";
        Author = "No Author";
        RatesCounter = 0;
        Rate = nullptr;
    }

    Book(std::string title, std::string author) {
        Title = title;
        Author = author;
        RatesCounter = 2;
        Rate = new float[RatesCounter];
        Rate[0] = 3.5;
        Rate[1] = 2.6;
    }
    
    ~Book() {
        delete []Rate;
        Rate = nullptr;
    }

    Book(const Book& origin) {
        Title = origin.Title;
        Author = origin.Author;
        RatesCounter = origin.RatesCounter;
        Rate = new float[RatesCounter];
        for (int i = 0; i < RatesCounter; i++)
            Rate[i] = origin.Rate[i];
    }

    Book &operator= (const Book& origin) {
        if (this != &origin) {
            Title = origin.Title;
            Author = origin.Author;
            RatesCounter = origin.RatesCounter;
            delete []Rate;
            Rate = new float[RatesCounter];
            for (int i = 0; i < RatesCounter; i++)
                Rate[i] = origin.Rate[i];
        }
        return *this;
    }


    void printBook() {
        std::cout << "Title: " << Title << std::endl;
        std::cout << "Author: " << Author << std::endl;
        float totalRate = 0.0;
        for (int i = 0; i < RatesCounter; i++)
            totalRate += Rate[i];
        std::cout << "Rate: " << totalRate/RatesCounter << std::endl;
    }
};

int main() {
    Book book1("The secrets of a milionaire mind", "J. Harv");
    book1.printBook();
    Book book2(book1);
    book2.printBook();
    Book book3=book2;
    book3.printBook();
    Book book4;
    book4.printBook();
    book1 = book4;
    book1.printBook();
}




