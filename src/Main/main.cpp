//============================================================================
// Name        : BookApplication.cpp
// Author      : LuisDarioHinojosa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../Headers/Book.h"
#include "../Headers/Library.h"

/*Following Object Oriented Programming Standards, i dont consider this method´s functionality to be part of a library,
 * so i included here.
 */


int main() {
	std::cout << "Main" << std::endl;
	// Generate some of my  books to test application more easily
	Book b1("Origen",2017,500, "Dan Brown","A","Planeta");
	Book b2("SuperIntelligence",2014,500, "Nick Bostrom","B","Oxford Diary");
	Book b3("The clash of civilizations",1992,500,"Huntington","C","Planeta");
	Book b4("Fisica 1",1997,900,"Resnick","C","MC Graw Hill");
	Book b5("Sapiens",2015,500,"Yuval Noah Harari","A","Harper Collins");
	Book b6("Vida 3.0",2018,500,"Max Tegmark","B","Pinguin Random House");
	Book b7("Da Vinci Code",2003,500,"Dan Brown","A","Planeta");
	Book b8("Tools And Weapons",2018,400,"Brad Smith","A","Hodder And Stroughton");
	Book b9("El Laberinto de la Soledad",1950,400,"Octavio Paz","Vigesimo Tercera","Catedra Letras Hispanicas");
	Book b10("Homo Deus: Breve storia del futuro",2019,400,"Yuval Noah Harari","Terza","Editore Bompiani");
	Book b11("Madame Bobary",1856,400,"Gustave Flaubert"," No dice (como la 5000)","Grupo Editorial Tomo");
	Book b12("El Samurai Solitario: La vida de Miyamoto Musashi",2004,400,"William Scott Wilson","D","Arkano Books");
	Book b13("Las cruzadas",2003,400,"Geoffrey Hidley","Marzo-2010","Grupo B de Bolsillo");
	Book b14("Machiavelli: Le tecniche del potere",2005,400,"Giuglio Sordenini","No dice","Distal");


	Library al;

	//Load Books into library Object
	al.addBook(b1);
	al.addBook(b3);
	al.addBook(b2);
	al.addBook(b4);
	al.addBook(b5);
	al.addBook(b6);
	al.addBook(b7);
	al.addBook(b8);
	al.addBook(b9);
	al.addBook(b10);
	al.addBook(b11);
	al.addBook(b12);
	al.addBook(b13);
	al.addBook(b14);
	//al.sortBookStorage('y',false,5);
	//al.printBooks();

	//al.sortBookStorage('t',true,5);
	//al.printBooks();
	// LIBRARY GUI
	al.mainMenu();

	std::cout << "Finish" << std::endl;


	return 0;
}
