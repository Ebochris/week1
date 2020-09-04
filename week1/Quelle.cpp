// Your First C++ Program

#include <iostream>
#include <fstream>

typedef struct mitarbeiter {
    char name[24];
    int id;
}typeMitarbeiter;

/*void printName1(typeMitarbeiter ma1) {
    std::cout << "Name: " << ma1.name;
}
void printName2(typeMitarbeiter ma2) {
    std::cout << "Name: " << ma2.name;

}void printID1(typeMitarbeiter ma1) {
    std::cout << "ID: " << ma1.id;
}
void printID2(typeMitarbeiter ma2) {
    std::cout << "ID: " << ma2.id;
}

int main() {
   // typeMitarbeiter ma1 = { "Stefan", 34 };
    //printName1(ma1);
   // printID1(ma1);
   // typeMitarbeiter ma2 = { "Friedrich",33 };
   // printName2(ma2);
   // printID2(ma2);*/
int main() {

typeMitarbeiter one = { "Stefan", 34 };
typeMitarbeiter two = { "Friedrich", 33 };

    //Daten in Datei schreiben
    std::fstream mytextfile;
    mytextfile.open("mitarbeiter.txt", std::ios::out);
    mytextfile << "Name |   ID\n";
    mytextfile.close();

    //Daten einer Datei hinzufügen
    mytextfile.open("mitarbeiter.txt", std::ios::app);
    mytextfile << one.name << " |   " << one.id << "\n";
    mytextfile << two.name << " |   " << two.id << "\n";
    mytextfile.close();


    //Daten einer Datei lesen
    char zeile[256];
    mytextfile.open("mitarbeiter.txt", std::ios::in);
    while (!mytextfile.eof()) {
        mytextfile.getline(zeile, sizeof(zeile));
        std::cout << zeile << "\n";
    }
}