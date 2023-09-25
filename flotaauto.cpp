#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//Declarare clasa Car , definire automobil
class Car {
private:
string brand; //Marca
string type;  //Tipul
int seats;   //Numarul de locuri
int availability; // Disponibilitatea automobilului

public:
 // Constructorul clasei Car care primește parametrii necesari pentru inițializarea obiectului.
Car(const string& brand, const string& type, int seats, int availability)
: brand(brand), type(type), seats(seats), availability(availability) {}


// Getter and Setter methods
string getBrand() const {
    return brand;
}

string getType() const {
    return type;
}

int getSeats() const {
    return seats;
}

int getAvailability() const {
    return availability;
}

void setBrand(const string& newBrand) {
    brand = newBrand;
}

void setType(const string& newType) {
    type = newType;
}

void setSeats(int newSeats) {
    seats = newSeats;
}

void setAvailability(int newAvailability) {
    availability = newAvailability;
}
};
//Clasa Reservation contine informatii despre nume utilizator, data inceput/sfarsit si index
class Reservation {
private:
string username;  // Numele utilizatorului 
string startDate;  // Data de început a rezervării
string endDate;  // Data de sfârșit a rezervării
int carIndex; // Indexul mașinii rezervate

public:
 // Constructorul clasei Reservation care primește parametrii necesari pentru inițializarea obiectului.
Reservation(const string& username, const string& startDate, const string& endDate, int carIndex)
: username(username), startDate(startDate), endDate(endDate), carIndex(carIndex) {}

// Getter and Setter methods
string getUsername() const {
    return username;
}

string getStartDate() const {
    return startDate;
}

string getEndDate() const {
    return endDate;
}

int getCarIndex() const {
    return carIndex;
}

void setUsername(const string& newUsername) {
    username = newUsername;
}

void setStartDate(const string& newStartDate) {
    startDate = newStartDate;
}

void setEndDate(const string& newEndDate) {
    endDate = newEndDate;
}

void setCarIndex(int newCarIndex) {
    carIndex = newCarIndex;
}
};

class CarRentalSystem {
private:
vector<Car> cars; // Vectorul de masini disponibile
vector<Reservation> reservations; // Vectorul de rezervari

public:
void readCars() {
ifstream file("cars.txt"); // Deschiderea fisierului "cars.txt" pentru citire
if (!file) {
cout << "\e[0;32m";
cout << "Eroare la deschiderea fisierului\n";
cout << "\e[0m";
exit(1);
}
    string brand, type;
    int seats, availability;
     // Citirea informatiilor despre masini din fisier
    while (file >> brand >> type >> seats >> availability) {
        Car car(brand, type, seats, availability);
        
        if(brand=="0"){
            break;
        }
        cars.push_back(car);
    }
    string username, startDate, endDate;
    int carIndex;
    // Citirea informatiilor despre rezervari din fisier
    while (file >> username >> startDate >> endDate >> carIndex){
        Reservation reservation(username, startDate, endDate, carIndex);
       
        reservations.push_back(reservation);
    }
    
    file.close();
}


void saveData() const {
    ofstream file("cars.txt");
    if (!file) {
        cout << "\e[0;31m";
        cout << "Eroare la deschiderea fisierului\n";
        cout << "\e[0m";
        return;
    }
    
    // Salvarea detaliilor despre masini
    for (const Car& car : cars) {
        file << car.getBrand() << " " << car.getType() << " " << car.getSeats() << " " << car.getAvailability() << endl;
    }
    file << "0 0 0 0" << endl;
    // Salvarea detaliilor despre rezervari
    for (const Reservation& reservation : reservations) {
        file << reservation.getUsername() << " " << reservation.getStartDate() << " " << reservation.getEndDate() << " " << reservation.getCarIndex() << endl;
    }

    file.close();
    cout << "\e[0;32m";
    cout << "Datele au fost salvate cu succes!\n";
    cout << "\e[0m";
}
//functie pentru afisare rezervari
void printReservations() const {
    for (const Reservation& reservation : reservations) {
        cout << "Utilizator: " << reservation.getUsername() << endl;
        cout << "Data de inceput: " << reservation.getStartDate() << endl;
        cout << "Data de sfarsit: " << reservation.getEndDate() << endl;
        cout << "Masina: " << cars[reservation.getCarIndex()].getBrand() << " " << cars[reservation.getCarIndex()].getType() << endl;
        cout << "---------------------------" << endl;
    }
}
//functie pentru afisarem masini
void printCars() const {
    for (const Car& car : cars) {
        if(car.getAvailability()!=0){
        cout << car.getBrand() << " " << car.getType() << " " << car.getSeats() << " " << car.getAvailability() << endl;
        }

    }
}
//functie pentru adaugare masina
void addCar() {
    cout << "\e[0;33m";
    cout << "Introdu marca: ";
    cout << "\e[0m";
    string brand;
    cin >> brand;

    cout << "\e[0;33m";
    cout << "Introdu modelul: ";
    cout << "\e[0m";
    string type;
    cin >> type;

    cout << "\e[0;33m";
    cout << "Introdu numarul de locuri: ";
    cout << "\e[0m";
    int seats;
    cin >> seats;

    int availability = 1;

    Car car(brand, type, seats, availability);
    cars.push_back(car);
}
//functia pentru cautare masina
void searchCar(){
string brand, type;
    cout << "\e[0;33m";
    cout << "Introdu marca masinii pe care doresti sa o cauti: ";
    cout << "\e[0m";
    cin >> brand;

    cout << "\e[0;33m";
    cout << "Introdu modelul masinii pe care doresti sa o cauti: ";
    cout << "\e[0m";
    cin >> type;

    bool carFound = false;
        for (Car& car : cars) {
            if (car.getBrand() == brand && car.getType() == type) {
                cout << "\e[0;33m";
                cout << "Am gasit masina : " << car.getBrand() << " " << car.getType() << endl;
                cout << "\e[0m";
                carFound = true;
                break;
            }
        }

        if (!carFound) {
            cout << "\e[0;31m";
            cout << "Masina nu a fost gasita!\n";
            cout << "\e[0m";
        }
    }

//functia pentru updatare masina
void updateCar() {
    string brand, type;
    cout << "\e[0;33m";
        cout << "Introdu marca masinii pe care doresti sa o actualizezi: ";
        cout << "\e[0m";
        cin >> brand;

        cout << "\e[0;33m";
        cout << "Introdu modelul masinii pe care doresti sa o actualizezi: ";
        cout << "\e[0m";
        cin >> type;

        bool carFound = false;
        for (Car& car : cars) {
            if (car.getBrand() == brand && car.getType() == type) {
                //Introducere noi date:
                cout << "\e[0;33m";
                cout << "Introdu noile informatii pentru masina " << car.getBrand() << " " << car.getType() << endl;
                cout << "\e[0m";

                cout << "\e[0;33m";
                cout << "Introdu noua marca: ";
                cout << "\e[0m";
                string newBrand;
                cin >> newBrand;
                car.setBrand(newBrand);

                cout << "\e[0;33m";
                cout << "Introdu noul model: ";
                cout << "\e[0m";
                string newType;
                cin >> newType;
                car.setType(newType);

                cout << "\e[0;33m";
                cout << "Introdu noul numar de locuri: ";
                cout << "\e[0m";
                int newSeats;
                cin >> newSeats;
                car.setSeats(newSeats);

                cout << "\e[0;32m";
                cout << "Masina a fost actualizata cu succes!\n";
                cout << "\e[0m";

                carFound = true;
                break;
            }
        }

        if (!carFound) {
            cout << "\e[0;31m";
            cout << "Masina nu a fost gasita!\n";
            cout << "\e[0m";
        }
    }
//functia pentru stergere masina
    void deleteCar() {
        string brand, type;

        cout << "\e[0;33m";
        cout << "Introdu marca masinii pe care doresti sa o stergi: ";
        cout << "\e[0m";
        cin >> brand;

        cout << "\e[0;33m";
        cout << "Introdu modelul masinii pe care doresti sa o stergi: ";
        cout << "\e[0m";
        cin >> type;

        bool carFound = false;
        for (auto it = cars.begin(); it != cars.end(); ++it) {
            if (it->getBrand() == brand && it->getType() == type) {
                cars.erase(it);
                cout << "\e[0;32m";
                cout << "Masina a fost stearsa cu succes!\n";
                cout << "\e[0m";
                carFound = true;
                break;
            }
        }

        if (!carFound) {
            cout << "\e[0;31m";
            cout << "Masina nu a fost gasita!\n";
            cout << "\e[0m";
        }
    }
//functia pentru rezervare masina 
    void makeReservation() {
        string username, startDate, endDate;
        int carIndex;

        cout << "\e[0;33m";
        cout << "Introdu numele utilizatorului: ";
        cout << "\e[0m";
        cin >> username;

        cout << "\e[0;33m";
        cout << "Introdu data de inceput a rezervarii (format: ZZ/LL/AAAA): ";
        cout << "\e[0m";
        cin >> startDate;

        cout << "\e[0;33m";
        cout << "Introdu data de sfarsit a rezervarii (format: ZZ/LL/AAAA): ";
        cout << "\e[0m";
        cin >> endDate;

        cout << "\e[0;33m";
        cout << "Introdu indexul masinii pe care doresti sa o rezervi (0 - " << cars.size() - 1 << "): ";
        cout << "\e[0m";
        cin >> carIndex;

        if (carIndex >= 0 && carIndex < cars.size()) {
            Car& car = cars[carIndex];
            
            Reservation reservation(username, startDate, endDate, carIndex);
            car.setAvailability(0);
            reservations.push_back(reservation);

            cout << "\e[0;32m";
            cout << "Rezervarea a fost efectuata cu succes!\n";
            cout << "\e[0m";
        } else {
            cout << "\e[0;31m";
            cout << "Indexul masinii este invalid!\n";
            cout << "\e[0m";
        }
    }
//functia pentru anulare rezervare
    void cancelReservation() {
        string username, startDate, endDate;

        cout << "\e[0;33m";
        cout << "Introdu numele utilizatorului: ";
        cout << "\e[0m";
        cin >> username;

        cout << "\e[0;33m";
        cout << "Introdu data de inceput a rezervarii (format: ZZ/LL/AAAA): ";
        cout << "\e[0m";
        cin >> startDate;

        cout << "\e[0;33m";
        cout << "Introdu data de sfarsit a rezervarii (format: ZZ/LL/AAAA): ";
        cout << "\e[0m";
        cin >> endDate;

        bool reservationFound = false;
        for (auto it = reservations.begin(); it != reservations.end(); ++it) {
            if (it->getUsername() == username && it->getStartDate() == startDate && it->getEndDate() == endDate) {
                int carIndex=it->getCarIndex();
                if(carIndex>=0 && carIndex <cars.size()){
                    Car& car = cars[carIndex];
                    car.setAvailability(1);


                }
                reservations.erase(it);
                cout << "\e[0;32m";
                cout << "Rezervarea a fost anulata cu succes!\n";
                cout << "\e[0m";
                reservationFound = true;
                break;
            }
        }

        if (!reservationFound) {
            cout << "\e[0;31m";
            cout << "Rezervarea nu a fost gasita!\n";
            cout << "\e[0m";
        }
    }
};

//MENIU principal
int main(int argc, char* argv[]) {
    CarRentalSystem rentalSystem;
    rentalSystem.readCars();

    int choice;

    do {
        cout << "\e[0;32m";
        cout << "\nMenu:\n";
        cout << "\e[0m";
        cout << "\e[0;36m";
        cout << "1. Adauga masina\n";
        cout << "2. Actualizeaza masina\n";
        cout << "3. Sterge masina\n";
        cout << "4. Cauta masina\n";
        cout << "5. Fa o rezervare\n";
        cout << "6. Anuleaza rezervarea\n";
        cout << "7. Afiseaza masinile disponibile\n";
        cout << "8. Afiseaza toate rezervarile\n";
        cout << "9. Salveaza\n";
        cout << "10. Inchide\n";
        cout << "\e[0m";
        cout << "\e[0;35m";
        cout << "Introdu alegerea: ";
        cout << "\e[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                rentalSystem.addCar();
                break;
            case 2:
                system("cls");
                rentalSystem.updateCar();
                break;
            case 3:
                system("cls");
                rentalSystem.deleteCar();
                break;
            case 4:
                system("cls");
                rentalSystem.searchCar();
                break;   
            case 5:
                system("cls");
                rentalSystem.makeReservation();
                break;
            case 6:
                system("cls");
                rentalSystem.cancelReservation();
                break;
            case 7:
                system("cls");
                rentalSystem.printCars();
                break;
            case 8:
                system("cls");
                rentalSystem.printReservations();
                break;
            case 9:
                system("cls");
                rentalSystem.saveData();
                break;
            case 10:
                break;
            default:
                cout << "\033[0;31m";
                cout << "Alegere invalida, va rugam sa specificati un numar valid\n";
                cout << "\033[0m";
                break;
        }
    } while (choice != 10);

    return 0;
}







