/*
 * Library.h
 *
 *  Created on: 9 sep. 2020
 *      Author: luisd
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <vector>
#include <string>
#include "../Headers/Book.h"
#pragma once
class Library {
public:
	Library();
	virtual ~Library();
	/*
	Even if the print method must come from another class (PrintableLibrary that must inherit from Print class),
	i decided to implement it here because i dont have a lot of time to do this programming assigment (i have a lot of final proyects).
	 */
	void printBooks();
	void addBook(Book b);
	void deleteBook(std::string title);

	// Evaluates if the parameters are acceptable and iterates thoough the vector in order to set the orderCriteria
	void setSortParameter(char);

	// Settter: Since the OrderAl Class does not work with pointers, i will have to set the storage vector many times
	void setStorageVector(std::vector<Book>);


	// Receives a char order criteria, if compatible sorts the vector sets the sort parameter and sorts the vector
	// True -> ascendent order
	// False -> descendant order
	void sortBookStorage(char,bool,int);


	// Compare Year
	static bool compareYearBig(int,Book);
	static bool compareYearSmall(int,Book);

	// Prints all books that satisfy a comparative threshold function by year
	void printByYear(int ,bool(*)(int,Book));


	// Prints all books either before or after a certain year depending on the selected parameter
	// True -> before
	// False -> After
	void printByYearSelection(int, bool);

	// Prints all Books published between a year range including the limits
	void printByYearRange(int,int);


	// Print By Author: Shows all books published by one Author sorted by title
	void printByAuthor(std::string);


	// Print By Editorial: The same but with another attribute
	void printByEditorial(std::string);


	// GUI FUNCTIONS:

	//Main Menu
	void mainMenu();

	//Time SearchMenu
	void timeSearchMenu();

	// Menu for sorting the books by different Criteria

	// receibes a char correspoding to the sort Criteria. Theuser choses either assending or descening order
	void sortOrderMenu(char);

	void sortStorageMenu();

	void algorithmMenu(char, bool);


	//User generates a book
	void generateBookUser();

	// Delete Book User
	void deleteBookUser();


	// Ask the user for author and shows pertinent Books
	void searchByAuthor();


	// Search by author is
	void searchByEditorial();

	//Auxiliar function for requesting a year
	int requestYear();




private:
	std::vector<Book> storage;
};




#endif /* LIBRARY_H_ */
