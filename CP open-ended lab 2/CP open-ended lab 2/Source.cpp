#include <iostream>
#include <string>
using namespace std;

struct Book {
	string title;
	string author;
	int pbyear;
	string genre;
};

void input(Book intbooks[]) {
	for (int i = 0; i < 6; i++) {
		cout << "Enter title of your book:";
		getline (cin, intbooks[i].title);
		cout << "\nEnter the author:";
		getline(cin, intbooks[i].author);
		cout << "\nEnter publishing year:";
		cin >> intbooks[i].pbyear;
		cout << "\nEnter the genre:";
		cin >> intbooks[i].genre;
		cout << endl;
		cin.ignore();
	}
}

void category(Book intbooks[], Book fiction[], Book nonfiction[]) {
	int fcount = 0, ncount = 0;
	for (int i = 0; i < 6; i++) {
		if (intbooks[i].genre == "Fiction" || intbooks[i].genre == "FICTION" || intbooks[i].genre == "fiction") {
			fiction[fcount++] = intbooks[i];
		}
		else {
			nonfiction[ncount++] = intbooks[i];
		}
	}
}

Book findEarliestBook(Book intbooks[], Book fiction[], Book nonfiction[]) {
	Book earliestBook = intbooks[0];
	for (int i = 0; i < 6; i++) {
		if (fiction[i].pbyear < earliestBook.pbyear) {
			earliestBook = fiction[i];
		}
		if (nonfiction[i].pbyear < earliestBook.pbyear) {
			earliestBook = nonfiction[i];
		}
	}
	return earliestBook;
}

void displayBookDetails(Book intbooks[], Book fiction[], Book nonfiction[], Book earliestBook) {
	for (int i = 0; i < 6; i++) {
		if (intbooks[i].genre == "Fiction" || intbooks[i].genre == "FICTION" || intbooks[i].genre == "fiction") {
			cout << "Details of Fiction Books:\n";
			cout << "Title: " << fiction[i].title << endl;
			cout << "Author: " << fiction[i].author << endl;
			cout << "Publication year: " << fiction[i].pbyear << endl;
			cout << "Genre: " << fiction[i].genre << endl;
		}
		else {
			cout << "\nDetails of Non-Fiction Books:\n";
			cout << "Title: " << nonfiction[i].title << endl;
			cout << "Author: " << nonfiction[i].author << endl;
			cout << "Publication year: " << nonfiction[i].pbyear << endl;
			cout << "Genre: " << nonfiction[i].genre << endl;
		}
	}
	cout << "\nEarliest published book: " << earliestBook.title << " by " << earliestBook.author << endl;
}

int main() {
	Book intbooks[6];
	Book fiction[6];
	Book nonfiction[6];

	input(intbooks);
	category(intbooks, fiction, nonfiction);
	Book earliestBook = findEarliestBook(intbooks, fiction, nonfiction);
	displayBookDetails(intbooks, fiction, nonfiction, earliestBook);

	return 0;
}