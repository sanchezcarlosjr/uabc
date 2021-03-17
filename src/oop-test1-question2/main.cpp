/*
      3. Realizar un programa que considere lo siguiente (Se evaluará el envío adecuado de parámetros a las funciones: por valor, apuntador referencia) [40 puntos]:
        Defina la estructura Libro que permita almacenar: nombre, ISBN (id) y año de publicación.
        Enel programa principal (main()),declarar una variable tipo arreglo de 5 estructuras Libro.
        Implementarla función registraLibro() que reciba como parámetro el arreglo de la estructura Libro, y permita al usuario proporcionar nombre y precio del libro.
        Implementar la función datosLibro() que reciba como parámetro el arreglo de la estructura Libro y el ISBN del libro consultar, la función debe imprimir todos los datos del libro o indicar libro no registrado.
        Implementar la función inventarioLibros() que reciba como parámetro el arreglo de la estructura Libro e imprima los datos de los libros registrados.
            ISBN __ Publicación _________Nombre
            12456 1605 Don Quijote
            88745 1954 El señor de los anillos
            88567 2008 Los Juegos del Hambre
        Created by Carlos Sanchez
        Created at 05/02/21
*/

#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

struct Book {
    string name;
    string isbn;
    int price;
    int year;
};

// Rellena la base de datos de libros
void registerBooks(Book books[]) {
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << "\n";
        books[i].name = print<string>("What is his name? ");
        books[i].price = print<int>("What is his price? ");
        books[i].isbn = print<string>("What is his isbn? ");
        books[i].year = print<int>("What is his year? ");
    }
}

void showBook(Book book) {
    cout << book.name << "\t"
         << book.price << "\t"
         << book.isbn << "\t"
         << book.year << "\n";
}

// Implementar la función datosLibro()
void searchBooks(Book books[], string isbn) {
    int j = 0;
    while (j < 5) {
        if (books[j].isbn == isbn) {
            cout << "NAME \t" << "PRICE \t" << "ISBN \t" << "YEAR \t \n";
            showBook(books[j]);
            return;
        }
        j++;
    }
    cout << "isbn not found";
}

// Implementar la función inventarioLibros()
void showBooks(Book books[]) {
    cout << "NAME \t" << "PRICE \t" << "ISBN \t" << "YEAR \t \n";
    for (int i = 0; i < 5; i++) {
        showBook(books[i]);
    }
}

int main() {
    Book books[5];
    registerBooks(books);
    int option = 3;
    do {
        option =  print<int>("\n\nOptions: 1. Search a book 2. Stock 3. Exit. \n >> ");
        switch (option) {
            case 1: searchBooks(books, print<string>("What is ISBN? "));
                break;
            case 2: showBooks(books);
                break;
        }}while(option != 3);
    cout << "See you soon!";
    return 0;
}