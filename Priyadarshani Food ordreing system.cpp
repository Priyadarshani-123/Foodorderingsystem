#include <iostream>
#include <vector>
#include <ctime> // Include the time library for the current time
using namespace std;

const string ADMIN_PASSWORD = "cafe"; // Replace with your actual admin password

// Define a struct to represent a menu item
struct MenuItem {
    int code;
    string name;
    int price;
};
// Define the menu items
vector<MenuItem> menu = {
    {1, "Pizza", 120},
    {2, "Samosa", 15},
    {3, "Coffee", 45},
};


// Function to display the menu
void displayMenu() {
    cout << "\t<<Hello Welcome to Hunger Cafeteria>>" << endl;
    cout << "\n\n\tHere you can choose your code...!!" << endl;
    cout << "\n\n\t\tMenu" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Code\tName\t\tPrice" << endl;
    cout << "----------------------------------------" << endl;
    for (auto item : menu) {
     cout << item.code << "\t" << item.name << "\t\t" << item.price << endl;
    }
}
void user()
{
    int code, quantity, totalBill = 0;
    string name, phone;

    // Get user's name and phone number
    cout << "Please enter your name: ";
    getline(cin, name); // Use getline() to read the entire name including spaces
    cout << "Please enter your phone number: ";
    cin >> phone;

    // Get the current time
    time_t now = time(0);

    // Allow customer to choose menu items and quantity
    do {
        cout<<"(1 for Pizza)"<<endl;
        cout<<"(2 for Samosa)"<<endl;
        cout<<"(3 for Coffee)"<<endl;
        cout<<"(0 to exit)"<<endl;
        cout << "Enter code your : "<<endl; 
        cin >> code;
        if (code == 0) {
            break;
        }
        cout << "Enter quantity: ";
        cin >> quantity;
        switch (code) {
            case 1:
                totalBill += quantity * menu[0].price; 
                break;
            case 2:
                totalBill += quantity * menu[1].price; 
                break;
            case 3:
                totalBill += quantity * menu[2].price; 
                break;
            default:
                cout << "Invalid code. Please enter a valid code." << endl;
                continue;
        }
        cout << "Total bill so far: " << totalBill << endl;

        // Allow customer to cancel order
         cout << "Would you like to cancel your order? "<<endl;
        cout<< "Press 'y' to cancel"<<endl;
        cout<<"Press 'n' to No"<<endl;
        char cancel;
        cin >> cancel;
        if (cancel == 'y' || cancel == 'Y') {
            
            cout << "Order cancelled. Total bill so far: " << totalBill << endl;
        }
    } while (code != 0);
    
    if (code == 0 && totalBill > 0) {
        cout << "Thank you, " << name << "! Enjoy your meal." << endl;
    }
    
    // Get final bill and customer information......................................................................................................
    now = time(0);
    string dt = ctime(&now);
    cout << "Final bill: " << totalBill << endl;
    cout << "Date and time: " << dt;
    cout << "Customer Name: " << name << endl;
    cout <<"Customer phone number: "<<phone<<endl;
}

void admin()
{
    string pass;
    cout << "Enter password: ";
    cin >> pass;

    if (pass == ADMIN_PASSWORD) {
        cout << "Welcome, admin!" << endl;

        // TODO: Add admin options here

    } else {
        cout << "Incorrect password. Access denied." << endl;
    }
    
    
}


int main() {
    // Display the menu
    
    displayMenu();
    user();
    
    while (true) {
        // Display the menu
        

        // Prompt the user to choose an option
        cout << "\nSelect an option:" << endl;
        cout << "1. Order food" << endl;
        cout << "2. Login as admin" << endl;
        cout << "3. Exit" << endl;

        int option;
        cin >> option;

        switch (option) {
            case 1:
                user();
                break;
            case 2:
                admin();
                break;
            case 3:
                return 0;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}