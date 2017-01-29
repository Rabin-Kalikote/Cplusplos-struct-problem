// Solution to struct challenge.
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>      


using namespace std;

struct mybook {
  string title;
  string author;
  string type;
  int price;
} book;

void menu();
void addbook();
void takebook();
void takerandombook();
void searchbook();
void deleteBook(int takespot);

//Creating array to hold books.
mybook bookshelf[10];


int main (){
	
	//declaring variable to hold users' choice.
	int userchoice = 0;
	
	
	
	//starts the programme.
	cout << endl <<"      WELCOME!" << endl <<endl;
	cout <<" Press 1 to continue: ";
	cin >> userchoice;
	system("CLS");
	
	while (userchoice != 5){
		
	
	system("CLS");		
	menu(); // displays the menu.
	
	//asking for choice number.
	cout <<endl<< " Enter your choice number: ";
	cin >> userchoice;
	
	if (userchoice == 1){
		addbook();
		}
		
	else if (userchoice == 2){
		takebook();
		}
		
	else if (userchoice == 3){
		takerandombook();
		}
		
	else if (userchoice == 4){
		searchbook();
		}
		
	else if (userchoice == 5){
		cout << endl << " You have closed the program" << endl;
	    cout << "   Good Bye!" <<endl;
	    break;
		}
		
	else{
		cout << endl << " Invalid choice" <<endl;
		}
		
	cout <<endl << " Press 1 to continue: ";
	cin >> userchoice;
	}
	
	return 0;	
}

void menu(){
	cout << endl << "   Make your choice" << endl;
	cout << "   ================" << endl << endl;
	cout << "  1. Add a book" << endl;
	cout << "  2. Take a book" << endl;
	cout << "  3. Take a random book" << endl;
	cout << "  4. Search for book" << endl;
	cout << "  5. Quit" << endl;
}

void addbook(){
	system("CLS");
	mybook addbook;
	cout << endl << " Add the title: ";
	cin >> addbook.title;
	cout << endl <<" Add the author: ";
	cin >> addbook.author;
	cout << endl <<" Add the type of book: ";
	cin >> addbook.type;
	cout << endl <<" Add the price of book: ";
	cin >> addbook.price;
	
	// loop controller.
	int i = 0;
	
	while(i != 10){
		if (bookshelf[i].title == "") {
			bookshelf[i].title = addbook.title;
			bookshelf[i].author = addbook.author;
			bookshelf[i].type = addbook.type;
			bookshelf[i].price = addbook.price;
			cout << endl <<" Book is added to (" << i << ") spot." << endl;
			break;  // Once it gets the empty spot, it stores and breaks.
		}
		else{
		}
		i = i+1;
	}
	if(i==10){
		cout << endl << " Sorry.. Bookshelf is full!" << endl;	
	}
} 

void takebook(){
	system("CLS");

	int takespot = 0;
	cout << endl << " Which spot contain the book that you wanna take? ";
	cin >> takespot;
	if (bookshelf[takespot].title != ""){
		deleteBook(takespot); // calls the function that take book.
		cout << endl << " Book from spot "<< takespot << " is removed." << endl;
	}
	else{
		cout << endl << " Nothing was in sopt (" << takespot << ")." << endl;
	}
}

void takerandombook(){
	system("CLS");
			
			srand (time(NULL));
			int takespot = rand() % 9 + 1;
			
			cout << endl << " Generated random number is (" << takespot << ")." << endl;
			
		if (bookshelf[takespot].title != "") {
			deleteBook(takespot); // calls the function that take book.
			cout << endl << " Book from spot "<< takespot << " is removed." << endl;
		}
		else{
			cout << endl << " Spots selected by random numbers is empty! " << endl;
		}	
}

void searchbook(){
	system("CLS");

	string search;
	int searchlen = 0;
	
	cout << endl <<" Enter title that you need to search: "; 
	cin >> search;
	searchlen = search.length();
	
	// Holds the similar content if found. 
	struct holder {
  	string holdcontent;
 	int holdspot;
	};
	
	holder box[10];
	
			int spot = 0;
			while (spot != 10){
				string grabber;
			if(bookshelf[spot].title != ""){
				
				int i = 0;
				while (i < searchlen ){
				grabber = grabber + bookshelf[spot].title[i];
				i = i + 1;
				}
				
				if( grabber == search){
					box[spot].holdspot = spot;
					box[spot].holdcontent = bookshelf[spot].title;
					
				}
				else{}
			}
			else{}
			spot = spot + 1;	 	
		}
		
		if (box[0].holdcontent != ""){
		int printer = 0;
			while(printer != 10){
				if (box[printer].holdcontent != ""){
					cout << endl <<" There is (" << box[printer].holdcontent << ") in spot (" << box[printer].holdspot << ")." << endl;
				}
				else{}
				printer = printer + 1;
			}
		}
		else{
			cout << " Sorry! No matches found. " << endl;
		}
}

void deleteBook(int takespot){
	bookshelf[takespot].title = "";
	bookshelf[takespot].author = "";
	bookshelf[takespot].type = "";
	bookshelf[takespot].price = 0;
}





