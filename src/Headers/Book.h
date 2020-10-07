/*
 * Book.h
 *
 *  Created on: 4 sep. 2020
 *      Author: luisd
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
class Book {
public:
	// Constructor
	Book() = default;
	// title publication year, pagenumber,author,edition,editorial
	Book(std::string,int,int,std::string,std::string,std::string);


	// Getters
	std::string getTitle();
	std::string getAuthor();
	int getPublicationYear();
	int getNumberOfPages();
	std::string getEdition();
	std::string getEditorial();





	//Setters
	void setOrderCriteria (char stuff);



	// Sobrecarga de Operadores para ordenar por titulo
	bool operator<(Book & book);
	bool operator>(Book&book);
	friend std::ostream & operator<<(std::ostream & os, const Book&book);




private:
	std::string title;
	int publicationYear;
	int pageNumber;
	std::string edition;
	std::string editorial;
	std::string author;
	char orderCriteria;

};

#endif /* BOOK_H_ */
