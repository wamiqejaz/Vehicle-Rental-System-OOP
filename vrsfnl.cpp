#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h> 
using namespace std;

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear the console screen
void clearScreen() {
    system("cls");
}

// USER CLASS (BASE CLASS) 
class User {
protected:
    string username;
    string password;
    string email;
    string phone;
    int userID;

public:
    User() : username(""), password(""), email(""), phone(""), userID(0) {}

    User(string uname, string pass, string mail, string ph, int id)
        : username(uname), password(pass), email(mail), phone(ph), userID(id) {
    }

    virtual ~User() {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    int getUserID() const { return userID; }

    void setUsername(string uname) { username = uname; }
    void setPassword(string pass) { password = pass; }
    void setEmail(string mail) { email = mail; }
    void setPhone(string ph) { phone = ph; }
    void setUserID(int id) { userID = id; }

    virtual void displayInfo() const {
        cout<<"User ID: " << userID <<endl;
        cout<<"Username: " << username <<endl;
        cout<<"Email: " << email <<endl;
        cout<<"Phone: " << phone <<endl;
    }

    virtual bool login(string uname, string pass) {
        return (username == uname && password == pass);
    }
};

// BOOKING CLASS 
class Booking {
private:
    int bookingID;
    int customerID;
    int vehicleID;
    string customerName;
    string vehicleDetails;
    int rentDays;
    double totalRent;
    string bookingDate;
    string returnDate;
    string status; // Active, Completed, Cancelled

public:
    Booking() : bookingID(0), customerID(0), vehicleID(0), customerName(""), vehicleDetails(""),
        rentDays(0), totalRent(0.0), bookingDate(""), returnDate(""), status("Active") {
    }

    Booking(int bID, int cID, int vID, string cName, string vDetails,
        int days, double rent, string bDate, string rDate)
        : bookingID(bID), customerID(cID), vehicleID(vID), customerName(cName),
        vehicleDetails(vDetails), rentDays(days), totalRent(rent), bookingDate(bDate),
        returnDate(rDate), status("Active") {
    }

    int getBookingID() const { return bookingID; }
    int getCustomerID() const { return customerID; }
    int getVehicleID() const { return vehicleID; }
    string getCustomerName() const { return customerName; }
    string getVehicleDetails() const { return vehicleDetails; }
    int getRentDays() const { return rentDays; }
    double getTotalRent() const { return totalRent; }
    string getBookingDate() const { return bookingDate; }
    string getReturnDate() const { return returnDate; }
    string getStatus() const { return status; }

    void setBookingID(int bID) { bookingID = bID; }
    void setCustomerID(int cID) { customerID = cID; }
    void setVehicleID(int vID) { vehicleID = vID; }
    void setCustomerName(string cName) { customerName = cName; }
    void setVehicleDetails(string vDetails) { vehicleDetails = vDetails; }
    void setRentDays(int days) { rentDays = days; }
    void setTotalRent(double rent) { totalRent = rent; }
    void setBookingDate(string bDate) { bookingDate = bDate; }
    void setReturnDate(string rDate) { returnDate = rDate; }
    void setStatus(string stat) { status = stat; }

    void displayBookingInfo() const {
        setColor(11); // Cyan color for heading
        cout<<"\n=== BOOKING DETAILS ===" <<endl;
        setColor(7);
        cout<<"Booking ID: " << bookingID <<endl;
        cout<<"Customer: " << customerName << " (ID: " << customerID << ")" <<endl;
        cout<<"Vehicle: " << vehicleDetails << " (ID: " << vehicleID << ")" <<endl;
        cout<<"Rental Days: " << rentDays <<endl;
        cout<<"Total Rent: Rs." << totalRent <<endl;
        cout<<"Booking Date: " << bookingDate <<endl;
        cout<<"Return Date: " << returnDate <<endl;
        cout<<"Status: " << status <<endl;
    }

    void generateBill() const {
        cout<<"\n" << string(50, '=') <<endl;
        cout<<"           VEHICLE RENTAL BILL" <<endl;
        cout<<string(50, '=') <<endl;
        cout<<"Booking ID: " << bookingID <<endl;
        cout<<"Customer: " << customerName <<endl;
        cout<<"Vehicle: " << vehicleDetails <<endl;
        cout<<"Rental Period: " << bookingDate << " to " << returnDate <<endl;
        cout<<"Number of Days: " << rentDays <<endl;
        cout<<"Rate per Day: Rs." << (totalRent / rentDays) <<endl;
        cout<<string(30, '-') <<endl;
        cout<<"Total Amount: Rs." << totalRent <<endl;
        cout<<string(50, '=') <<endl;
        cout<<"Thank you for choosing our service!" <<endl;
    }
};

// VEHICLE CLASS (BASE CLASS) 
class Vehicle {
protected:
    int vehicleID;
    string brand;
    string model;
    string registrationNo;
    double rentPerDay;
    bool isAvailable;
    string vehicleType;

public:
    Vehicle() : vehicleID(0), brand(""), model(""), registrationNo(""),
        rentPerDay(0.0), isAvailable(true), vehicleType("") {
    }

    Vehicle(int id, string br, string mod, string regNo, double rent, string type)
        : vehicleID(id), brand(br), model(mod), registrationNo(regNo),
        rentPerDay(rent), isAvailable(true), vehicleType(type) {
    }

    virtual ~Vehicle() {}

    int getVehicleID() const { return vehicleID; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getRegistrationNo() const { return registrationNo; }
    double getRentPerDay() const { return rentPerDay; }
    bool getAvailability() const { return isAvailable; }
    string getVehicleType() const { return vehicleType; }

    void setVehicleID(int id) { vehicleID = id; }
    void setBrand(string br) { brand = br; }
    void setModel(string mod) { model = mod; }
    void setRegistrationNo(string regNo) { registrationNo = regNo; }
    void setRentPerDay(double rent) { rentPerDay = rent; }
    void setAvailability(bool status) { isAvailable = status; }
    void setVehicleType(string type) { vehicleType = type; }

    virtual void displayVehicleInfo() const {
        setColor(10); // Green color for vehicle information heading
        cout<<"\nVehicle ID: " << vehicleID <<endl;
        setColor(7);
        cout<<"Type: " << vehicleType <<endl;
        cout<<"Brand: " << brand <<endl;
        cout<<"Model: " << model <<endl;
        cout<<"Registration: " << registrationNo <<endl;
        cout<<"Rent per Day: Rs." << rentPerDay <<endl;
        cout<<"Status: " << (isAvailable ? "Available" : "Booked") <<endl;
    }

    virtual double calculateRent(int days) const {
        return rentPerDay * days;
    }

    virtual void displaySpecialFeatures() const = 0; // Pure virtual function
};

class Car : public Vehicle {
private:
    int seats;
    bool hasAC;
    string fuelType;

public:
    Car() : Vehicle(), seats(4), hasAC(false), fuelType("Petrol") {
        vehicleType = "Car";
    }

    Car(int id, string br, string mod, string regNo, double rent,
        int st, bool ac, string fuel)
        : Vehicle(id, br, mod, regNo, rent, "Car"), seats(st), hasAC(ac), fuelType(fuel) {
    }

    int getSeats() const { return seats; }
    bool hasAirCondition() const { return hasAC; }
    string getFuelType() const { return fuelType; }
    void setSeats(int st) { seats = st; }
    void setAC(bool ac) { hasAC = ac; }
    void setFuelType(string fuel) { fuelType = fuel; }

    void displayVehicleInfo() const override {
        setColor(14); // Yellow color for Car heading
        cout<<"\n=== CAR DETAILS ===" <<endl;
        setColor(7);
        Vehicle::displayVehicleInfo();
        displaySpecialFeatures();
    }

    void displaySpecialFeatures() const override {
        cout<<"Seats: " << seats <<endl;
        cout<<"Air Conditioning: " << (hasAC ? "Yes" : "No") <<endl;
        cout<<"Fuel Type: " << fuelType <<endl;
    }

    double calculateRent(int days) const override {
        double baseRent = Vehicle::calculateRent(days);
        if (hasAC) {
            baseRent += (days * 5.0);
        }
        return baseRent;
    }
};

class Bike : public Vehicle {
private:
    int engineCC;
    bool hasHelmet;
    string bikeType;

public:
    Bike() : Vehicle(), engineCC(150), hasHelmet(true), bikeType("Standard") {
        vehicleType = "Bike";
    }

    Bike(int id, string br, string mod, string regNo, double rent,
        int cc, bool helmet, string type)
        : Vehicle(id, br, mod, regNo, rent, "Bike"), engineCC(cc), hasHelmet(helmet), bikeType(type) {
    }

    int getEngineCC() const { return engineCC; }
    bool hasHelmetIncluded() const { return hasHelmet; }
    string getBikeType() const { return bikeType; }
    void setEngineCC(int cc) { engineCC = cc; }
    void setHelmet(bool helmet) { hasHelmet = helmet; }
    void setBikeType(string type) { bikeType = type; }

    void displayVehicleInfo() const override {
        setColor(13); // Light magenta for Bike heading
        cout<<"\n=== BIKE DETAILS ===" <<endl;
        setColor(7);
        Vehicle::displayVehicleInfo();
        displaySpecialFeatures();
    }

    void displaySpecialFeatures() const override {
        cout<<"Engine CC: " << engineCC <<endl;
        cout<<"Helmet Included: " << (hasHelmet ? "Yes" : "No") <<endl;
        cout<<"Bike Type: " << bikeType <<endl;
    }

    double calculateRent(int days) const override {
        double baseRent = Vehicle::calculateRent(days);
        if (days > 7) {
            baseRent *= 0.9; // 10% discount for more than 7 days
        }
        return baseRent;
    }
};

class Truck : public Vehicle {
private:
    double loadCapacity;
    int doors;
    bool hasGPS;

public:
    Truck() : Vehicle(), loadCapacity(1.0), doors(4), hasGPS(false) {
        vehicleType = "Truck";
    }

    Truck(int id, string br, string mod, string regNo, double rent,
        double capacity, int dr, bool gps)
        : Vehicle(id, br, mod, regNo, rent, "Truck"), loadCapacity(capacity), doors(dr), hasGPS(gps) {
    }

    double getLoadCapacity() const { return loadCapacity; }
    int getDoors() const { return doors; }
    bool hasGPSSystem() const { return hasGPS; }
    void setLoadCapacity(double capacity) { loadCapacity = capacity; }
    void setDoors(int dr) { doors = dr; }
    void setGPS(bool gps) { hasGPS = gps; }

    void displayVehicleInfo() const override {
        setColor(9); // Blue for Truck heading
        cout<<"\n=== TRUCK DETAILS ===" <<endl;
        setColor(7);
        Vehicle::displayVehicleInfo();
        displaySpecialFeatures();
    }

    void displaySpecialFeatures() const override {
        cout<<"Load Capacity: " << loadCapacity << " tons" <<endl;
        cout<<"Doors: " << doors <<endl;
        cout<<"GPS System: " << (hasGPS ? "Yes" : "No") <<endl;
    }

    double calculateRent(int days) const override {
        double baseRent = Vehicle::calculateRent(days);
        if (loadCapacity > 2.0) {
            baseRent += (days * 10.0);
        }
        return baseRent;
    }
};

// ADMIN CLASS 
class Admin : public User {
private:
    string department;

public:
    Admin() : User(), department("Management") {}

    Admin(string uname, string pass, string mail, string ph, int id, string dept)
        : User(uname, pass, mail, ph, id), department(dept) {
    }

    string getDepartment() const { return department; }
    void setDepartment(string dept) { department = dept; }

    void displayInfo() const override {
        setColor(12); // Red for admin info heading
        cout<<"\n=== ADMIN INFORMATION ===" <<endl;
        setColor(7);
        User::displayInfo();
        cout<<"Department: " << department <<endl;
    }

    // New method to edit username and password
    void editCredentials() {
        string newUsername, newPassword;
        cout<<"Enter new username: ";
        cin >> newUsername;
        cout<<"Enter new password: ";
        cin >> newPassword;

        setUsername(newUsername);
        setPassword(newPassword);

        setColor(10);
        cout<<"Credentials updated successfully!" <<endl;
        setColor(7);
    }
};

// CUSTOMER CLASS 
class Customer : public User {
private:
    string address;
    int bookingCount;

public:
    Customer() : User(), address(""), bookingCount(0) {}

    Customer(string uname, string pass, string mail, string ph, int id, string addr)
        : User(uname, pass, mail, ph, id), address(addr), bookingCount(0) {
    }

    string getAddress() const { return address; }
    int getBookingCount() const { return bookingCount; }
    void setAddress(string addr) { address = addr; }
    void incrementBookingCount() { bookingCount++; }
    void decrementBookingCount() { if (bookingCount > 0) bookingCount--; }

    void displayInfo() const override {
        setColor(10); // Green for customer info heading
        cout<<"\n=== CUSTOMER INFORMATION ===" <<endl;
        setColor(7);
        User::displayInfo();
        cout<<"Address: " << address <<endl;
        cout<<"Total Bookings: " << bookingCount <<endl;
    }
};

// FILE MANAGER CLASS 
class FileManager {
private:
    static string CUSTOMERS_FILE;
    static string VEHICLES_FILE;
    static string BOOKINGS_FILE;

public:
    static bool saveCustomers(const Customer customers[], int count) {
        ofstream file(CUSTOMERS_FILE, ios::app);
        if (!file) {
            setColor(4);
            cout<<"Error: Could not open customers file for writing!" <<endl;
            setColor(7);
            return false;
        }
        for (int i = 0; i < count; i++) {
            file << customers[i].getUsername() << ","
                << customers[i].getPassword() << ","
                << customers[i].getEmail() << ","
                << customers[i].getPhone() << ","
                << customers[i].getUserID() << ","
                << customers[i].getAddress() <<endl;
        }
        file.close();
        return true;
    }

    static int loadCustomers(Customer customers[], int maxSize) {
        ifstream file(CUSTOMERS_FILE);
        if (!file) {
            return 0;
        }
        int count = 0;
        string line;
        while (count < maxSize && getline(file, line)) {
            stringstream ss(line);
            string username, password, email, phone, idStr, address;
            if (!getline(ss, username, ',')) continue;
            if (!getline(ss, password, ',')) continue;
            if (!getline(ss, email, ',')) continue;
            if (!getline(ss, phone, ',')) continue;
            if (!getline(ss, idStr, ',')) continue;
            if (!getline(ss, address)) continue;
            if (idStr.empty()) continue;
            try {
                int id = stoi(idStr);
                customers[count++] = Customer(username, password, email, phone, id, address);
            }
            catch (...) {
                continue;
            }
        }
        file.close();
        return count;
    }

    static bool saveVehicles(Vehicle* vehicles[], int count) {
        ofstream file(VEHICLES_FILE, ios::app);
        if (!file) {
            setColor(4);
            cout<<"Error: Could not open vehicles file for writing!" <<endl;
            setColor(7);
            return false;
        }
        for (int i = 0; i < count; i++) {
            file << vehicles[i]->getVehicleType() << ","
                << vehicles[i]->getVehicleID() << ","
                << vehicles[i]->getBrand() << ","
                << vehicles[i]->getModel() << ","
                << vehicles[i]->getRegistrationNo() << ","
                << vehicles[i]->getRentPerDay() << ","
                << (vehicles[i]->getAvailability() ? "1" : "0") << ",";
            if (vehicles[i]->getVehicleType() == "Car") {
                Car* car = dynamic_cast<Car*>(vehicles[i]);
                file << car->getSeats() << ","
                    << (car->hasAirCondition() ? "1" : "0") << ","
                    << car->getFuelType() <<endl;
            }
            else if (vehicles[i]->getVehicleType() == "Bike") {
                Bike* bike = dynamic_cast<Bike*>(vehicles[i]);
                file << bike->getEngineCC() << ","
                    << (bike->hasHelmetIncluded() ? "1" : "0") << ","
                    << bike->getBikeType() <<endl;
            }
            else if (vehicles[i]->getVehicleType() == "Truck") {
                Truck* truck = dynamic_cast<Truck*>(vehicles[i]);
                file << truck->getLoadCapacity() << ","
                    << truck->getDoors() << ","
                    << (truck->hasGPSSystem() ? "1" : "0") <<endl;
            }
        }
        file.close();
        return true;
    }

    static int loadVehicles(Vehicle* vehicles[], int maxSize) {
        ifstream file(VEHICLES_FILE);
        if (!file) {
            return 0;
        }
        int count = 0;
        string line;
        while (count < maxSize && getline(file, line)) {
            stringstream ss(line);
            string type, idStr, brand, model, regNo, rentStr, availStr;
            if (!getline(ss, type, ',')) continue;
            if (!getline(ss, idStr, ',')) continue;
            if (!getline(ss, brand, ',')) continue;
            if (!getline(ss, model, ',')) continue;
            if (!getline(ss, regNo, ',')) continue;
            if (!getline(ss, rentStr, ',')) continue;
            if (!getline(ss, availStr, ',')) continue;
            if (type.empty() || idStr.empty() || rentStr.empty() || availStr.empty()) continue;
            try {
                int id = stoi(idStr);
                double rent = stod(rentStr);
                bool availability = (availStr == "1");
                if (type == "Car") {
                    string seatsStr, acStr, fuelType;
                    if (!getline(ss, seatsStr, ',')) continue;
                    if (!getline(ss, acStr, ',')) continue;
                    if (!getline(ss, fuelType)) continue;
                    int seats = stoi(seatsStr);
                    bool hasAC = (acStr == "1");
                    vehicles[count] = new Car(id, brand, model, regNo, rent, seats, hasAC, fuelType);
                    vehicles[count]->setAvailability(availability);
                    count++;
                }
                else if (type == "Bike") {
                    string ccStr, helmetStr, bikeType;
                    if (!getline(ss, ccStr, ',')) continue;
                    if (!getline(ss, helmetStr, ',')) continue;
                    if (!getline(ss, bikeType)) continue;
                    int engineCC = stoi(ccStr);
                    bool hasHelmet = (helmetStr == "1");
                    vehicles[count] = new Bike(id, brand, model, regNo, rent, engineCC, hasHelmet, bikeType);
                    vehicles[count]->setAvailability(availability);
                    count++;
                }
                else if (type == "Truck") {
                    string capacityStr, doorsStr, gpsStr;
                    if (!getline(ss, capacityStr, ',')) continue;
                    if (!getline(ss, doorsStr, ',')) continue;
                    if (!getline(ss, gpsStr)) continue;
                    double loadCapacity = stod(capacityStr);
                    int doors = stoi(doorsStr);
                    bool hasGPS = (gpsStr == "1");
                    vehicles[count] = new Truck(id, brand, model, regNo, rent, loadCapacity, doors, hasGPS);
                    vehicles[count]->setAvailability(availability);
                    count++;
                }
            }
            catch (...) {
                continue;
            }
        }
        file.close();
        return count;
    }

    static bool saveBookings(Booking bookings[], int count) {
        ofstream file(BOOKINGS_FILE, ios::app);
        if (!file) {
            setColor(4);
            cout<<"Error: Could not open bookings file for writing!" <<endl;
            setColor(7);
            return false;
        }
        for (int i = 0; i < count; i++) {
            file << bookings[i].getBookingID() << ","
                << bookings[i].getCustomerID() << ","
                << bookings[i].getVehicleID() << ","
                << bookings[i].getCustomerName() << ","
                << bookings[i].getVehicleDetails() << ","
                << bookings[i].getRentDays() << ","
                << bookings[i].getTotalRent() << ","
                << bookings[i].getBookingDate() << ","
                << bookings[i].getReturnDate() << ","
                << bookings[i].getStatus() <<endl;
        }
        file.close();
        return true;
    }

    static int loadBookings(Booking bookings[], int maxSize) {
        ifstream file(BOOKINGS_FILE);
        if (!file) {
            return 0;
        }
        int count = 0;
        string line;
        while (count < maxSize && getline(file, line)) {
            stringstream ss(line);
            string bIDStr, cIDStr, vIDStr, cName, vDetails, daysStr, totalRentStr, bDate, rDate, status;
            if (!getline(ss, bIDStr, ',')) continue;
            if (!getline(ss, cIDStr, ',')) continue;
            if (!getline(ss, vIDStr, ',')) continue;
            if (!getline(ss, cName, ',')) continue;
            if (!getline(ss, vDetails, ',')) continue;
            if (!getline(ss, daysStr, ',')) continue;
            if (!getline(ss, totalRentStr, ',')) continue;
            if (!getline(ss, bDate, ',')) continue;
            if (!getline(ss, rDate, ',')) continue;
            if (!getline(ss, status)) continue;
            if (bIDStr.empty()) continue;
            try {
                int bID = stoi(bIDStr);
                int cID = stoi(cIDStr);
                int vID = stoi(vIDStr);
                int days = stoi(daysStr);
                double totalRent = stod(totalRentStr);
                bookings[count] = Booking(bID, cID, vID, cName, vDetails, days, totalRent, bDate, rDate);
                bookings[count].setStatus(status);
                count++;
            }
            catch (...) {
                continue;
            }
        }
        file.close();
        return count;
    }
};

// Define static file names
string FileManager::CUSTOMERS_FILE = "customers.txt";
string FileManager::VEHICLES_FILE = "vehicles.txt";
string FileManager::BOOKINGS_FILE = "bookings.txt";

// Rental System Class
class RentalSystem {
private:
    static const int MAX_CUSTOMERS = 100;
    static const int MAX_ADMINS = 1;
    static const int MAX_VEHICLES = 50;
    static const int MAX_BOOKINGS = 200;

    Customer customers[MAX_CUSTOMERS];
    Admin admins[MAX_ADMINS];
    Vehicle* vehicles[MAX_VEHICLES];
    Booking bookings[MAX_BOOKINGS];

    int customerCount;
    int adminCount;
    int vehicleCount;
    int bookingCount;

    int nextCustomerID;
    int nextVehicleID;
    int nextBookingID;

    int currentUserID;

public:
    bool isCustomerLoggedIn;
    bool isAdminLoggedIn;

    RentalSystem() : customerCount(0), adminCount(0), vehicleCount(0), bookingCount(0),
        nextCustomerID(1001), nextVehicleID(2001), nextBookingID(3001),
        currentUserID(-1), isAdminLoggedIn(false), isCustomerLoggedIn(false) {
        for (int i = 0; i < MAX_VEHICLES; i++) {
            vehicles[i] = nullptr;
        }
        loadAllData();
    }

    ~RentalSystem() {
        saveAllData();
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
    }

    void loadAllData() {
        customerCount = FileManager::loadCustomers(customers, MAX_CUSTOMERS);

        adminCount = 0;
        admins[0] = Admin("admin", "admin123", "admin@rental.com", "1234567890", 1, "Management");
        adminCount = 1;

        vehicleCount = FileManager::loadVehicles(vehicles, MAX_VEHICLES);
        bookingCount = FileManager::loadBookings(bookings, MAX_BOOKINGS);

        updateNextIDs();

        setColor(10);
        cout<<"System initialized successfully!" <<endl;
        setColor(7);
    }

    void saveAllData() {
        FileManager::saveCustomers(customers, customerCount);
        FileManager::saveVehicles(vehicles, vehicleCount);
        FileManager::saveBookings(bookings, bookingCount);
    }

    void updateNextIDs() {
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getUserID() >= nextCustomerID) {
                nextCustomerID = customers[i].getUserID() + 1;
            }
        }
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getVehicleID() >= nextVehicleID) {
                nextVehicleID = vehicles[i]->getVehicleID() + 1;
            }
        }
        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].getBookingID() >= nextBookingID) {
                nextBookingID = bookings[i].getBookingID() + 1;
            }
        }
    }

    bool adminLogin() {
        clearScreen();
        string username, password;
        setColor(14);
        cout<<"\n=== ADMIN LOGIN ===" <<endl;
        setColor(7);
        cout<<"Username: ";
        cin >> username;
        cout<<"Password: ";
        cin >> password;

        for (int i = 0; i < adminCount; i++) {
            if (admins[i].login(username, password)) {
                currentUserID = admins[i].getUserID();
                isAdminLoggedIn = true;
                isCustomerLoggedIn = false;
                setColor(10);
                cout<<"\nAdmin login successful!" <<endl;
                cout<<"Welcome, " << admins[i].getUsername() << "!" <<endl;
                setColor(7);
                return true;
            }
        }

        setColor(4);
        cout<<"Invalid admin credentials!" <<endl;
        setColor(7);
        return false;
    }

    bool customerLogin() {
        clearScreen();
        string username, password;
        setColor(14);
        cout<<"\n=== CUSTOMER LOGIN ===" <<endl;
        setColor(7);
        cout<<"Username: ";
        cin >> username;
        cout<<"Password: ";
        cin >> password;

        for (int i = 0; i < customerCount; i++) {
            if (customers[i].login(username, password)) {
                currentUserID = customers[i].getUserID();
                isCustomerLoggedIn = true;
                isAdminLoggedIn = false;
                setColor(10);
                cout<<"\nCustomer login successful!" <<endl;
                cout<<"Welcome back, " << customers[i].getUsername() << "!" <<endl;
                setColor(7);
                return true;
            }
        }

        setColor(4);
        cout<<"Invalid customer credentials!" <<endl;
        setColor(7);
        return false;
    }

    bool customerSignup() {
        clearScreen();
        if (customerCount >= MAX_CUSTOMERS) {
            setColor(4);
            cout<<"System is at maximum customer capacity!" <<endl;
            setColor(7);
            return false;
        }

        string username, password, email, phone, address;
        cin.ignore();
        setColor(14);
        cout<<"\n=== CUSTOMER SIGNUP ===" <<endl;
        setColor(7);
        cout<<"Username: ";
        getline(cin, username);

        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getUsername() == username) {
                setColor(4);
                cout<<"Username already exists! Please choose another." <<endl;
                setColor(7);
                return false;
            }
        }

        cout<<"Password: ";
        getline(cin, password);
        cout<<"Email: ";
        getline(cin, email);
        cout<<"Phone: ";
        getline(cin, phone);
        cout<<"Address: ";
        getline(cin, address);

        customers[customerCount] = Customer(username, password, email, phone, nextCustomerID, address);
        customerCount++;
        nextCustomerID++;

        saveAllData();

        setColor(10);
        cout<<"\nSignup successful! You can now login with your credentials." <<endl;
        setColor(7);
        return true;
    }

    void logout() {
        currentUserID = -1;
        isAdminLoggedIn = false;
        isCustomerLoggedIn = false;
        setColor(11);
        cout<<"Logged out successfully!" <<endl;
        setColor(7);
    }

    void addVehicle() {
        if (vehicleCount >= MAX_VEHICLES) {
            setColor(4);
            cout<<"Vehicle inventory is full!" <<endl;
            setColor(7);
            return;
        }

        int choice;
        string brand, model, regNo;
        double rent;

        clearScreen();
        setColor(14);
        cout<<"\n=== ADD NEW VEHICLE ===" <<endl;
        setColor(7);
        cout<<"Select Vehicle Type:" <<endl;
        cout<<"1. Car" <<endl;
        cout<<"2. Bike" <<endl;
        cout<<"3. Truck" <<endl;
        cout<<"Choice: ";
        cin >> choice;
        cin.ignore();

        cout<<"Brand: ";
        getline(cin, brand);
        cout<<"Model: ";
        getline(cin, model);
        cout<<"Registration Number: ";
        getline(cin, regNo);
        cout<<"Rent per Day (Rs.): ";
        cin >> rent;
        cin.ignore();

        Vehicle* newVehicle = nullptr;

        switch (choice) {
        case 1: {
            int seats;
            bool hasAC;
            string fuelType;
            int acChoice;

            cout<<"Number of Seats: ";
            cin >> seats;
            cout<<"Has Air Conditioning? (1=Yes, 0=No): ";
            cin >> acChoice;
            hasAC = (acChoice == 1);
            cin.ignore();
            cout<<"Fuel Type: ";
            getline(cin, fuelType);

            newVehicle = new Car(nextVehicleID, brand, model, regNo, rent, seats, hasAC, fuelType);
            break;
        }
        case 2: {
            int engineCC;
            bool hasHelmet;
            string bikeType;
            int helmetChoice;

            cout<<"Engine CC: ";
            cin >> engineCC;
            cout<<"Helmet Included? (1=Yes, 0=No): ";
            cin >> helmetChoice;
            hasHelmet = (helmetChoice == 1);
            cin.ignore();
            cout<<"Bike Type: ";
            getline(cin, bikeType);

            newVehicle = new Bike(nextVehicleID, brand, model, regNo, rent, engineCC, hasHelmet, bikeType);
            break;
        }
        case 3: {
            double capacity;
            int doors;
            bool hasGPS;
            int gpsChoice;

            cout<<"Load Capacity (tons): ";
            cin >> capacity;
            cout<<"Number of Doors: ";
            cin >> doors;
            cout<<"Has GPS? (1=Yes, 0=No): ";
            cin >> gpsChoice;

            hasGPS = (gpsChoice == 1);

            newVehicle = new Truck(nextVehicleID, brand, model, regNo, rent, capacity, doors, hasGPS);
            break;
        }
        default:
            setColor(4);
            cout<<"Invalid choice!" <<endl;
            setColor(7);
            return;
        }

        vehicles[vehicleCount] = newVehicle;
        vehicleCount++;
        nextVehicleID++;

        saveAllData();

        setColor(10);
        cout<<"\nVehicle added successfully!" <<endl;
        setColor(7);
        newVehicle->displayVehicleInfo();
    }

    void viewAllVehicles() {
        clearScreen();
        if (vehicleCount == 0) {
            setColor(4);
            cout<<"No vehicles in the system!" <<endl;
            setColor(7);
            return;
        }

        setColor(14);
        cout<<"\n=== ALL VEHICLES ===" <<endl;
        setColor(7);
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->displayVehicleInfo();
            cout<<string(40, '-') <<endl;
        }
    }

    void deleteVehicle() {
        if (vehicleCount == 0) {
            setColor(4);
            cout<<"No vehicles to delete!" <<endl;
            setColor(7);
            return;
        }

        int vehicleID;
        setColor(14);
        cout<<"\n=== DELETE VEHICLE ===" <<endl;
        setColor(7);
        cout<<"Enter Vehicle ID to delete: ";
        cin >> vehicleID;

        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getVehicleID() == vehicleID) {
                for (int j = 0; j < bookingCount; j++) {
                    if (bookings[j].getVehicleID() == vehicleID && bookings[j].getStatus() == "Active") {
                        setColor(4);
                        cout<<"Cannot delete vehicle - it has active bookings!" <<endl;
                        setColor(7);
                        return;
                    }
                }

                cout<<"Vehicle to be deleted:" <<endl;
                vehicles[i]->displayVehicleInfo();

                char confirm;
                cout<<"Are you sure you want to delete this vehicle? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    delete vehicles[i];
                    for (int k = i; k < vehicleCount - 1; k++) {
                        vehicles[k] = vehicles[k + 1];
                    }
                    vehicleCount--;
                    saveAllData();
                    setColor(10);
                    cout<<"Vehicle deleted successfully!" <<endl;
                    setColor(7);
                }
                else {
                    cout<<"Deletion cancelled." <<endl;
                }
                return;
            }
        }

        setColor(4);
        cout<<"Vehicle with ID " << vehicleID << " not found!" <<endl;
        setColor(7);
    }

    void viewAllCustomers() {
        clearScreen();
        if (customerCount == 0) {
            setColor(4);
            cout<<"No customers registered!" <<endl;
            setColor(7);
            return;
        }

        setColor(14);
        cout<<"\n=== ALL CUSTOMERS ===" <<endl;
        setColor(7);
        for (int i = 0; i < customerCount; i++) {
            customers[i].displayInfo();
            cout<<string(40, '-') <<endl;
        }
    }

    void viewAllBookings() {
        clearScreen();
        if (bookingCount == 0) {
            setColor(4);
            cout<<"No bookings in the system!" <<endl;
            setColor(7);
            return;
        }

        setColor(14);
        cout<<"\n=== ALL BOOKINGS ===" <<endl;
        setColor(7);
        for (int i = 0; i < bookingCount; i++) {
            bookings[i].displayBookingInfo();
            cout<<string(50, '-') <<endl;
        }
    }

    // Customer bookings view
    void viewMyBookings() {
        if (!isCustomerLoggedIn) {
            setColor(4);
            cout<<"You must be logged in as customer to view your bookings." <<endl;
            setColor(7);
            return;
        }

        int count = 0;
        clearScreen();
        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].getCustomerID() == currentUserID) {
                bookings[i].displayBookingInfo();
                cout<<string(50, '-') <<endl;
                count++;
            }
        }

        if (count == 0) {
            setColor(14);
            cout<<"You have no bookings." <<endl;
            setColor(7);
        }
    }

    void generateBillForBooking() {
        if (!isCustomerLoggedIn) {
            setColor(4);
            cout<<"You must be logged in as customer to generate a bill." <<endl;
            setColor(7);
            return;
        }

        clearScreen();
        int bookingID;
        cout<<"Enter Booking ID to generate bill: ";
        cin >> bookingID;

        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].getBookingID() == bookingID && bookings[i].getCustomerID() == currentUserID) {
                bookings[i].generateBill();
                return;
            }
        }

        setColor(4);
        cout<<"Booking ID not found for your account." <<endl;
        setColor(7);
    }

    void cancelBooking() {
        if (!isCustomerLoggedIn) {
            setColor(4);
            cout<<"You must be logged in as customer to cancel a booking." <<endl;
            setColor(7);
            return;
        }

        clearScreen();
        int bookingID;
        cout<<"Enter Booking ID to cancel: ";
        cin >> bookingID;

        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].getBookingID() == bookingID && bookings[i].getCustomerID() == currentUserID) {
                if (bookings[i].getStatus() != "Active") {
                    setColor(4);
                    cout<<"Booking is not active and cannot be cancelled." <<endl;
                    setColor(7);
                    return;
                }

                bookings[i].setStatus("Cancelled");
                // Make the vehicle available again
                for (int j = 0; j < vehicleCount; j++) {
                    if (vehicles[j]->getVehicleID() == bookings[i].getVehicleID()) {
                        vehicles[j]->setAvailability(true);
                        break;
                    }
                }
                // Decrement customer's booking count
                for (int k = 0; k < customerCount; k++) {
                    if (customers[k].getUserID() == currentUserID) {
                        customers[k].decrementBookingCount();
                        break;
                    }
                }

                saveAllData();

                setColor(10);
                cout<<"Booking cancelled successfully." <<endl;
                setColor(7);
                return;
            }
        }
        setColor(4);
        cout<<"Booking ID not found for your account." <<endl;
        setColor(7);
    }

    // Implement booking logic with manual date entry
    void bookVehicle() {
        if (!isCustomerLoggedIn) {
            setColor(4);
            cout<<"You must be logged in as customer to book vehicles." <<endl;
            setColor(7);
            return;
        }

        clearScreen();
        setColor(14);
        cout<<"\n=== AVAILABLE VEHICLES ===" <<endl;
        setColor(7);
        bool anyAvailable = false;
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getAvailability()) {
                vehicles[i]->displayVehicleInfo();
                cout<<string(40, '-') <<endl;
                anyAvailable = true;
            }
        }

        if (!anyAvailable) {
            setColor(4);
            cout<<"No vehicles available for booking currently." <<endl;
            setColor(7);
            return;
        }

        int vehicleID;
        cout<<"Enter Vehicle ID to book: ";
        cin >> vehicleID;

        Vehicle* selectedVehicle = nullptr;
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getVehicleID() == vehicleID && vehicles[i]->getAvailability()) {
                selectedVehicle = vehicles[i];
                break;
            }
        }

        if (selectedVehicle == nullptr) {
            setColor(4);
            cout<<"Invalid vehicle ID or vehicle not available." <<endl;
            setColor(7);
            return;
        }

        int rentDays;
        cout<<"Enter number of rental days: ";
        cin >> rentDays;
        if (rentDays <= 0) {
            setColor(4);
            cout<<"Invalid rental period." <<endl;
            setColor(7);
            return;
        }

        cin.ignore();

        string bookingDate;
        string returnDate;

        cout<<"Enter booking date (YYYY-MM-DD): ";
        getline(cin, bookingDate);
        cout<<"Enter return date (YYYY-MM-DD): ";
        getline(cin, returnDate);

        if (bookingDate.empty() || returnDate.empty()) {
            setColor(4);
            cout<<"Invalid dates entered."<<endl;
            setColor(7);
            return;
        }

        double totalRent = selectedVehicle->calculateRent(rentDays);

        int custIndex = -1;
        for (int i = 0; i < customerCount; i++) {
            if (customers[i].getUserID() == currentUserID) {
                custIndex = i;
                break;
            }
        }
        if (custIndex == -1) {
            setColor(4);
            cout<<"Customer record not found!" <<endl;
            setColor(7);
            return;
        }

        if (bookingCount >= MAX_BOOKINGS) {
            setColor(4);
            cout<<"Booking capacity full! Cannot book more vehicles." <<endl;
            setColor(7);
            return;
        }

        bookings[bookingCount] = Booking(nextBookingID, currentUserID, vehicleID, customers[custIndex].getUsername(),
            selectedVehicle->getModel(), rentDays, totalRent, bookingDate, returnDate);

        bookings[bookingCount].setStatus("Active");
        selectedVehicle->setAvailability(false);

        bookingCount++;
        nextBookingID++;
        customers[custIndex].incrementBookingCount();

        saveAllData();

        setColor(10);
        cout<<"\nBooking successful! Booking details:" <<endl;
        setColor(7);
        bookings[bookingCount - 1].displayBookingInfo();
    }

    // New admin menu option to edit username and password
    void adminEditCredentials() {
        if (!isAdminLoggedIn) {
            setColor(4);
            cout<<"Admin not logged in." <<endl;
            setColor(7);
            return;
        }

        for (int i = 0; i < adminCount; i++) {
            if (admins[i].getUserID() == currentUserID) {
                admins[i].editCredentials();
                // No file save since no admin file, but keep data until program exit
                return;
            }
        }
    }
};
int main() {
    RentalSystem rentalSystem;
    int choice;

    while (true) {
        try {
            setColor(11);
            cout<<"\n+-----------------------------+" <<endl;
            cout<<"|    VEHICLE RENTAL SYSTEM    |" <<endl;
            cout<<"+-----------------------------+" <<endl;
            cout<<"| 1. Admin Login              |" <<endl;
            cout<<"| 2. Customer Login           |" <<endl;
            cout<<"| 3. Customer Signup          |" <<endl;
            cout<<"| 4. Exit                     |" <<endl;
            cout<<"+-----------------------------+" <<endl;
            cout<<"Choose an option: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw "Input must be a number!";
            }

            if (choice < 0) {
                throw "Negative numbers are not allowed!";
            }

            switch (choice) {
            case 1:
                if (rentalSystem.adminLogin()) {
                    int adminChoice;
                    while (rentalSystem.isAdminLoggedIn) {
                        cout<<"\n+-----------------------------+" <<endl;
                        cout<<"|          ADMIN MENU         |" <<endl;
                        cout<<"+-----------------------------+" <<endl;
                        cout<<"| 1. View All Customers       |" <<endl;
                        cout<<"| 2. View All Vehicles        |" <<endl;
                        cout<<"| 3. Add Vehicle              |" <<endl;
                        cout<<"| 4. View All Bookings        |" <<endl;
                        cout<<"| 5. Delete Vehicle           |" <<endl;
                        cout<<"| 6. Edit Credentials         |" <<endl;
                        cout<<"| 7. Logout                   |" <<endl;
                        cout<<"+-----------------------------+" <<endl;
                        cout<<"Choose an option: ";

                        if (!(cin >> adminChoice) || adminChoice < 0) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw "Invalid admin menu input!";
                        }

                        switch (adminChoice) {
                        case 1: rentalSystem.viewAllCustomers(); break;
                        case 2: rentalSystem.viewAllVehicles(); break;
                        case 3: rentalSystem.addVehicle(); break;
                        case 4: rentalSystem.viewAllBookings(); break;
                        case 5: rentalSystem.deleteVehicle(); break;
                        case 6: rentalSystem.adminEditCredentials(); break;
                        case 7: rentalSystem.logout(); break;
                        default: cout<<"Invalid choice!" <<endl; break;
                        }
                    }
                }
                break;

            case 2:
                if (rentalSystem.customerLogin()) {
                    int customerChoice;
                    while (rentalSystem.isCustomerLoggedIn) {
                        cout<<"\n+-----------------------------+" <<endl;
                        cout<<"|        CUSTOMER MENU        |" <<endl;
                        cout<<"+-----------------------------+" <<endl;
                        cout<<"| 1. View All Vehicles        |" <<endl;
                        cout<<"| 2. Book a Vehicle           |" <<endl;
                        cout<<"| 3. View My Bookings         |" <<endl;
                        cout<<"| 4. Generate Bill            |" <<endl;
                        cout<<"| 5. Cancel Booking           |" <<endl;
                        cout<<"| 6. Logout                   |" <<endl;
                        cout<<"+-----------------------------+" <<endl;
                        cout<<"Choose an option: ";

                        if (!(cin >> customerChoice) || customerChoice < 0) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw "Invalid customer menu input!";
                        }

                        switch (customerChoice) {
                        case 1: rentalSystem.viewAllVehicles(); break;
                        case 2: rentalSystem.bookVehicle(); break;
                        case 3: rentalSystem.viewMyBookings(); break;
                        case 4: rentalSystem.generateBillForBooking(); break;
                        case 5: rentalSystem.cancelBooking(); break;
                        case 6: rentalSystem.logout(); break;
                        default: cout<<"Invalid choice!" <<endl; break;
                        }
                    }
                }
                break;

            case 3:
                rentalSystem.customerSignup();
                break;

            case 4:
                setColor(10);
                cout<<"Exiting the system. Thank you!" <<endl;
                setColor(7);
                return 0;

            default:
                cout<<"Invalid main menu option!" <<endl;
                break;
            }
        }
        catch (const char* msg) {
            setColor(4);
            cout<<"Error: " << msg <<endl;
            setColor(7);
        }
        catch (...) {
            setColor(4);
            cout<<"An unexpected error occurred!" <<endl;
            setColor(7);
        }
    }
    return 0;
}