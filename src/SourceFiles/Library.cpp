/*
 * Library.cpp
 *
 *  Created on: 9 sep. 2020
 *      Author: luisd
 */

#include "../Headers/Library.h"
#include "../Headers/Book.h"
#include "../Headers/OrderAl.h"

Library::Library() {
	// TODO Auto-generated constructor stub

}



void Library::addBook(Book b){
	this->storage.push_back(b);
}

// Variation of ordered sequential search
void Library::deleteBook(std::string title){
	// Add sort function by title:
	sortBookStorage('t',true,5);
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		if(it->getTitle() == title){
			this->storage.erase(it);
			break;
		}
	}

}


// Iterates throughout the vector  to set the order criteria in all books
void Library::setSortParameter(char c){
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		it->setOrderCriteria(c);
	}
}


void Library::printBooks(){
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		std::cout << (*it) << std::endl;
	}
}
// This one is the function that sorts the vector accroding to some criteria
// True -> ascendent order
// False -> descendant order
void Library::sortBookStorage(char c  = 't',bool asc = true, int al = 5){

	if((c == 't')||(c == 'e')||(c == 'y')||(c == 'a') || (c == 'p')){
		// Sets the same sort criteria in all the books
		setSortParameter(c);

		if (asc == true){
			//std::vector <Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::asc);
			//std::vector <Book> st = OrderAl<Book>::bubble(storage,OrderAl<Book>::asc);
			//std::vector <Book> st = OrderAl<Book>::insersion(storage,OrderAl<Book>::asc);
			//std::vector <Book> st = OrderAl<Book>::selection(storage,OrderAl<Book>::asc);
			//std::vector <Book> st = OrderAl<Book>::selection(storage,OrderAl<Book>::asc);
			switch(al){
			case 1:{
				//std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::asc);
				std::vector<Book> st = OrderAl<Book>::mergesort(storage,0,storage.size()-1,OrderAl<Book>::asc);
				setStorageVector(st);

				break;
			}
			case 2:
			{
				std::vector<Book> st = OrderAl<Book>::bubble(storage,OrderAl<Book>::asc);
				setStorageVector(st);

				break;
			}
			case 3:
			{
				std::vector<Book> st = OrderAl<Book>::insersion(storage,OrderAl<Book>::asc);
				setStorageVector(st);
				break;
			}
			case 4:
			{
				std::vector<Book> st = OrderAl<Book>::selection(storage,OrderAl<Book>::asc);
				setStorageVector(st);
				break;
			}
			case 5:
			{
				std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::asc);
				setStorageVector(st);
				break;
			}
			default:
			{
				std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::asc);
				setStorageVector(st);
				break;
			}
			}
		}else{

			switch(al){
			case 1:{
				//MergeSort
				std::vector<Book> st = OrderAl<Book>::mergesort(storage,0,storage.size()-1,OrderAl<Book>::desc);

				//std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::desc);
				setStorageVector(st);

				break;
			}
			case 2:{
				std::vector<Book> st = OrderAl<Book>::bubble(storage,OrderAl<Book>::desc);
				setStorageVector(st);

				break;
			}
			case 3:{
				std::vector<Book> st = OrderAl<Book>::insersion(storage,OrderAl<Book>::desc);
				setStorageVector(st);
				break;
			}
			case 4:{
				std::vector<Book> st = OrderAl<Book>::selection(storage,OrderAl<Book>::desc);
				setStorageVector(st);
				break;
			}
			case 5:{
				std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::desc);
				setStorageVector(st);
				break;
			}
			default:{
				std::vector<Book> st = OrderAl<Book>::quickSort(storage,0,storage.size()-1,OrderAl<Book>::desc);
				setStorageVector(st);
				break;
			}
			}
		}
	}

}








bool Library::compareYearBig(int year, Book b){
	return b.getPublicationYear() >= year;
}


bool Library::compareYearSmall(int year, Book b){
	return b.getPublicationYear() <= year;
}

void Library::printByYear(int year, bool compare(int, Book)){
	sortBookStorage('y',true);
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		if(compare(year,(*it))){
			std::cout << (*it) << std::endl;
		}
	}

}



// True -> before
// False -> After
void Library::printByYearSelection(int year, bool before){
	if(before == true){
		printByYear(year,compareYearSmall);
	}else{
		printByYear(year,compareYearBig);

	}
}


void Library::printByYearRange(int low,int high){
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		if(compareYearSmall(high,(*it))&&compareYearBig(low,(*it))){
			std::cout << (*it) << std::endl;
		}
	}
}


void Library::printByAuthor(std::string author){
	sortBookStorage('t',true);
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		if(it->getAuthor()==author){
			std::cout << (*it) << std::endl;
		}
	}
}

void Library::printByEditorial(std::string editorial){
	sortBookStorage('t',true,5);
	for(std::vector<Book>::iterator it = this->storage.begin(); it != this->storage.end(); it++){
		if(it->getEditorial()==editorial){
			std::cout << (*it) << std::endl;
		}
	}
}



void Library::setStorageVector(std::vector<Book> st){
	this->storage = st;
}



//Gui Functions:
void Library::mainMenu(){
	int option;
	do{

        std::cout << "Library Administration System:" << std::endl;
        std::cout << "Menu: " << std::endl;
        std::cout << "0. System shutdown" << std::endl;
        std::cout << "1. Register Book" << std::endl;
        std::cout << "2. Delete Book" << std::endl;
        std::cout << "3. Search By Year" << std::endl;
        std::cout << "4. Search By Author" << std::endl;
        std::cout << "5. Search By Editorial" << std::endl;
        std::cout << "6. Sort Storage" << std::endl;
        std::cout << "7. Print all book Storage" << std::endl;


        std::cin>> option;
        std::cin.ignore();
        switch (option) {
        case 1:
            std::cout << "1" << std::endl;
            generateBookUser();
            break;
        case 2:
        	deleteBookUser();
            break;
        case 3:
        	timeSearchMenu();
            break;
        case 4:
        	searchByAuthor();
			break;
        case 5:
        	searchByEditorial();
            break;
        case 6:
        	sortStorageMenu();
            break;
        case 7:
        	printBooks();
        	break;
        case 0:
            break;
        default:
        	std::cout << "Not a valid option" << std::endl;
        }
        if (option != 0) {
        	std::cout << "<< Enter >> to continue";
            std::cin.ignore();
            getchar();
        }
	}while(option!=0);
	std::cout << "System shutdown. \nThanks for using the library terminal" << std::endl;
}




void Library::timeSearchMenu(){
	int option;
	int year1,year2;
	do{

        std::cout << "Library Administration System:" << std::endl;
        std::cout << "Search By Year" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "1. Books before a certain year" << std::endl;
        std::cout << "2. Books after a certain year" << std::endl;
        std::cout << "3. Search By a time interval (years)" << std::endl;

        std::cin>> option;
        switch (option) {
        case 1:
        	year1 = requestYear();
        	printByYearSelection(year1, true);
            break;
        case 2:
        	year1 = requestYear();
        	printByYearSelection(year1, false);
            break;
        case 3:
        	std::cout << "Superior limit" << std::endl;
        	year1 = requestYear();
        	std::cout << "Inferior limit" << std::endl;
        	year2= requestYear();
        	printByYearRange(year2,year1);
        	break;
        case 0:
            break;
        default:
        	std::cout << "Not a valid option" << std::endl;
        }
        if (option != 0) {
        	std::cout << "<< Enter >> to continue";
            std::cin.ignore();
            getchar();
        }
	}while(option!=0);
	std::cout << "Returning to Main Menu" << std::endl;
}





void Library::sortStorageMenu(){
	int option;
	do{

        std::cout << "Library Administration System:" << std::endl;
        std::cout << "Sort Storage" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "1. Sort by title" << std::endl;
        std::cout << "2. Sort by publication Year" << std::endl;
        std::cout << "3. Sort by Edition" << std::endl;

        std::cin>> option;

        switch (option) {
        case 1:
        	sortOrderMenu('t');
            break;
        case 2:
        	sortOrderMenu('y');
            break;
        case 3:
        	sortOrderMenu('e');
        	break;
        case 0:
            break;
        default:
        	std::cout << "Not a valid option" << std::endl;
        }
        if (option != 0) {
        	std::cout << "<< Enter >> to continue";
            std::cin.ignore();
            getchar();
        }
	}while(option!=0);
	std::cout << "Returning to Main Menu" << std::endl;
}


void Library::sortOrderMenu(char orderCriteria){
	int option;
    std::cout << "Library Administration System:" << std::endl;
    std::cout << "Sort by:" << std::endl;
    std::cout << "1. Ascendent  order" << std::endl;
    std::cout << "2. Descendant order" << std::endl;

    std::cin>> option;

    switch(option){
    case 1:
    	//sortBookStorage(orderCriteria,true);
    	algorithmMenu(orderCriteria,true);
    	break;
    case 2:
    	//sortBookStorage(orderCriteria,false);
    	algorithmMenu(orderCriteria,false);
    	break;
    default:
    	//sortBookStorage(orderCriteria,true);
    	algorithmMenu(orderCriteria,true);
    	break;
    }
	//printBooks();
}

//(I don't understand why a common user with no knowledge in computer science would like to select this but ok)
void Library::algorithmMenu(char orderCriteria,bool asc){
	int option;
    std::cout << "Library Administration System:" << std::endl;
    std::cout << "Select an algorithm :" << std::endl;
    std::cout << "1. MergeSort" << std::endl;
    std::cout << "2. Bubble" << std::endl;
    std::cout << "3. Insertion" << std::endl;
    std::cout << "4. Selection" << std::endl;
    std::cout << "5. QuickSort" << std::endl;
    std::cin >> option;

    switch(option){
    case 1:
    	sortBookStorage(orderCriteria,asc,1);
    	break;
    case 2:
    	sortBookStorage(orderCriteria,asc,2);
    	break;
    case 3:
    	sortBookStorage(orderCriteria,asc,3);
    	break;
    case 4:
    	sortBookStorage(orderCriteria,asc,4);
    	break;
    case 5:
    	sortBookStorage(orderCriteria,asc,5);
    	break;
    default:
    	sortBookStorage(orderCriteria,asc,5);
    	break;
    }
    printBooks();
}

//std::string title,int year,int pageNumber,std::string author,std::string edition,std::string editorial
// Ask the user to fill the atributes of a book un order to register it.
void Library::generateBookUser(){
	int year,pageNumber;
	std::string title, author, edition, editorial;
	std::cout << "Enter Title" << std::endl;
    //std::cin>> title;
	getline(std::cin,title);
	std::cout << "Enter author" << std::endl;
	getline(std::cin,author);
	std::cout << "Enter edition" << std::endl;
	getline(std::cin,edition);
	std::cout << "Enter editorial" << std::endl;
	getline(std::cin,editorial);
	std::cout << "Enter year" << std::endl;
	std::cin >> year;
	std::cout << "Enter number of pages" << std::endl;
	std::cin >> pageNumber;

	Book b(title,year,pageNumber,author,edition,editorial);
	std::cout << b << std::endl;
	addBook(b);
	std::cout << "The Book was added successfully" << std::endl;

}




int Library::requestYear(){
	int year;
	std::cout << "Enter a Year:" << std::endl;
	std::cin >> year;
	return year;

}





// Ask the user for the title of the book to delete and deletes it
void Library::deleteBookUser(){
	std::string title;
	std::cout << "Enter the Title" << std::endl;
	getline(std::cin,title);
	deleteBook(title);
}




void Library::searchByAuthor(){
	std::string author;
	std::cout << "Enter the Author:" << std::endl;
	getline(std::cin,author);
	printByAuthor(author);
}


void Library::searchByEditorial(){
	std::string editorial;
	std::cout << "Enter the Editorial:" << std::endl;
	getline(std::cin,editorial);
	printByEditorial(editorial);
}


Library::~Library() {
	// TODO Auto-generated destructor stub
}

