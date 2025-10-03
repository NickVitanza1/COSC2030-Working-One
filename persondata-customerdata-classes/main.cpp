//
// Nicholas Vitanza
// 10/3/25
// PersonData and CustomerData Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Base class
class PersonData {
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    // Constructors
    PersonData() 
        : lastName(""), firstName(""), address(""), city(""), state(""), zip(""), phone("") {}

    PersonData(string lName, string fName, string addr, string c, string s, string z, string ph)
        : lastName(lName), firstName(fName), address(addr), city(c), state(s), zip(z), phone(ph) {}

    // Accessors
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }

    // Mutators
    void setLastName(const string& lName) { lastName = lName; }
    void setFirstName(const string& fName) { firstName = fName; }
    void setAddress(const string& addr) { address = addr; }
    void setCity(const string& c) { city = c; }
    void setState(const string& s) { state = s; }
    void setZip(const string& z) { zip = z; }
    void setPhone(const string& ph) { phone = ph; }
};

// Derived class
class CustomerData : public PersonData {
private:
    int customerNumber;
    bool mailingList;

public:
    // Constructors
    CustomerData() : PersonData(), customerNumber(0), mailingList(false) {}

    CustomerData(string lName, string fName, string addr, string c, string s, string z, string ph, int custNum, bool mailing)
        : PersonData(lName, fName, addr, c, s, z, ph), customerNumber(custNum), mailingList(mailing) {}

    // Accessors
    int getCustomerNumber() const { return customerNumber; }
    bool isOnMailingList() const { return mailingList; }

    // Mutators
    void setCustomerNumber(int custNum) { customerNumber = custNum; }
    void setMailingList(bool mailing) { mailingList = mailing; }
};

// Demonstration
int main() {
    // Create a CustomerData object
    CustomerData customer(
        "Vitanza", 
        "Nick", 
        "123 Main St", 
        "Springfield", 
        "IL", 
        "62704", 
        "555-1234", 
        1001, 
        true
    );

    // Display customer information
    cout << "Customer Information:\n";
    cout << "Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << ", " << customer.getCity()
         << ", " << customer.getState() << " " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "Mailing List: " << (customer.isOnMailingList() ? "Yes" : "No") << endl;

    return 0;
}