/*
 * Book.cpp
 *
 *  Created on: 4 sep. 2020
 *      Author: luisd
 */

#include "../Headers/Book.h"
#include "../Headers/OrderAl.h"
#include <iostream>

// title publication year, pagenumber,author,edition,editorial
Book::Book(std::string title,int year,int pageNumber,std::string author,std::string edition,std::string editorial)
:author(author),title(title),publicationYear(year),pageNumber(pageNumber),edition(edition),editorial(editorial),orderCriteria('n')
{

}

//  Gettters
std::string Book::getTitle(){
	return this->title;
}



std::string Book::getAuthor(){
	return this->author;
}


int Book::getPublicationYear(){
	return this->publicationYear;
}

std::string Book::getEdition(){
	return this->edition;
}

std::string Book::getEditorial(){
	return this->editorial;
}

// Setter
// values -> e (edition), y (year), t(title)
void Book::setOrderCriteria(char stuff){
	if((stuff == 't')||(stuff == 'e')||(stuff == 'y')||(stuff == 'a')||(stuff=='p')){
		this->orderCriteria = stuff;
	}
	else{
		std::cout << "Invalid Argument. \nSetting default setting: t" << std::endl;
		this->orderCriteria = 't';
	}
}

//Operator overload

bool Book::operator<(Book & book){
	if(this->orderCriteria == 't'){
		return this->title < book.getTitle();
	}
	else if(this->orderCriteria == 'e'){
		return this->edition < book.getEdition();
	}
	else if (this->orderCriteria == 'y'){
		return this->publicationYear < book.getPublicationYear();
	}


	else if(this->orderCriteria == 'a'){
		return this->author < book.getAuthor();
	}
	else if (this->orderCriteria == 'p'){
		return this->editorial < book.getEditorial();
	}
}

/*
 * Accepeted Parameters
 * t -> title
 * y -> year
 * e -> edition
 * a -> author
 * p -> editorial
 */
bool Book::operator>(Book & book){
	if(this->orderCriteria == 't'){
		return this->title > book.getTitle();
	}
	else if(this->orderCriteria == 'e'){
		return this->edition > book.getEdition();
	}
	else if (this->orderCriteria == 'y'){
		return this->publicationYear > book.getPublicationYear();
	}

	else if(this->orderCriteria == 'a'){
		return this->author > book.getAuthor();
	}
	else if (this->orderCriteria == 'p'){
		return this->editorial > book.getEditorial();
	}
}





std::ostream & operator<<(std::ostream & os, const Book&book){
	os << "Title: " << book.title << " |Author: " << book.author << " |Edition: " <<book.edition<< " |Publication Year: " << book.publicationYear << " |Editorial: " << book.editorial <<std::endl;
}



