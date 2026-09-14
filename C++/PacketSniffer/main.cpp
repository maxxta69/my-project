// #include <iostream>

// class BankAccount {

//     private:
//         int accountNumber;
//         double balance;

//     public:
//         BankAccount(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {};

//         double GetBalance(){
//             return balance;
//         }

//         void deposit(double amount){
//             if(amount > 0)
//                 this->balance += amount;
//             else {
//                 std::cout << "ERROR: Amount must be greater than 0" << std::endl;
//             }
//         }

//         ~BankAccount(){
//             std::cout << "Account closed successfully to the terminal!" << std::endl;
//         }
// };

// class SavingsAccount: public BankAccount {

//     private:
//         double InterestRate;

//     public:
//         SavingsAccount(int accNumber, double balance, double rate) : BankAccount(accNumber, balance), InterestRate(rate) {};

//         void ApplyInterest(){
//             double interest = GetBalance() * InterestRate;
//             deposit(interest);
//         }
// };

// int main(){

//     SavingsAccount acc1(2002, 1000, 0.05);

//     SavingsAccount *ptrAcc1 = &acc1;

//     ptrAcc1->deposit(200);
//     ptrAcc1->ApplyInterest();
//     double balance = ptrAcc1->GetBalance();

//     std::cout
//         << "Balance: " << balance << std::endl;

//     return 0;
// }

// #include <iostream>

// class Vehicle {

//     private:
//         std::string brand;
//         int speed;

//     public:
//         Vehicle(std::string brand, int speed) : brand(brand), speed(speed) {};

//         int GetSpeed(){
//             return this->speed;
//         }

//         void Accelerate(int amount){
//             this->speed += amount;
//         }
        
//         void Decelerate(int amount){
//             this->speed -= amount;
//         }

//         ~Vehicle(){
//             std::cout << this->brand << " vehicle dismantled..." << std::endl;
//         }
// };

// class Car: public Vehicle{

//     private:
//         int NumberOfDoors;

//     public:
//         Car(std::string brand, int speed, int doors) : Vehicle(brand, speed), NumberOfDoors(doors) {};

//         void PrintCarDetails(){
//             std::cout << "Number of Doors: " << this->NumberOfDoors << std::endl;
//             std::cout << "Speed: " << GetSpeed() << std::endl;
//         }
// };

// int main(){
//     Car car1("Honda", 10, 4);
//     Car *carPtr = &car1;

//     carPtr->Accelerate(20);
//     carPtr->PrintCarDetails();
// }

// #include <iostream>

// int main(int argc, char* argv[]){

// #ifdef __linux__
//     std::cout << "This block of code is meant to run on Linux operating system. \n";
// #elif _WIN32
//     std::cout<< "This block of code is meant to run on Windows(32) Operating system \n";
// #elif _APPLE_
//     std::cout<< "This block of code is meant to run on Apple Operating system \n";
// #else
// std::cout<< "ERROR: No operating system detected!";
// #endif

// return 0;
// }

// #include <iostream>
// #ifdef __linux__
//     #include <sys/socket.h>
//     #include <arpa/inet.h>
//     #include <unistd.h>
// #else
//     #include <winsock2.h>
//     #include <ws2tcpip.h>
//     #pragma comment(lib, w2_32.lib)
// #endif

// int main (int argc, char* argv[]){
//     char raw_packet[] = {0x00, 0x00, 0x00, 0x50};

//     int* int_pointer = reinterpret_cast<int *>(raw_packet);
//     std::cout << "Raw Packet: " << int_pointer << "\n";
//     int translated_packet = ntohl(*int_pointer);
//     std::cout << "Translated packet: " << translated_packet << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <string>

// using std::endl, std::string;

// class BankAccount {
//     private:
//         string account_name;
//         int account_number;
//         double balance;
//     public:
//         BankAccount(int account_number = 0000, double balance = 50, string account_name = "User") : account_number(account_number), balance(balance), account_name(account_name) {};

//         void Deposit(int amount){
//             if(amount > 0){
//                 balance += amount;
//             }
//             else{
//                 std::cout << "ERROR: Amount should be more than 0" << endl;
//             }
//         }

//         double GetBalance(){
//             return balance;
//         }

//         int GetAccountNumber(){
//             return account_number;
//         }

//         string GetAccountName(){
//             return account_name;
//         }

//         ~BankAccount(){
//             std::cout << "Bank account was successfully terminated and everything is now cool" << std::endl;
//         }
// };

// int main(int argc, char* argv[]){
//     BankAccount account1;

//     string accountName = account1.GetAccountName();

//     int accountNumber = account1.GetAccountNumber();
//     double accountBalance = account1.GetBalance();

//     std::cout << "Account Name: " << accountName << "\n";

//     return 0;
// }

// #include <iostream>

// int main(int argc, char* argv[]){

//     std::cout << "Enter a number: ";
//     int x{};
//     std::cin >> x;
//     std::cout << "You entered " << x << std::endl;
//     return 0;
// }


// #include <iostream>

// using std::string;

// class Item{
//     protected:
//         string name{};

//     public:
//         Item(string name) : name(name) {};

//         string GetName()
//         {
//             return name;
//         }
//     virtual void Use(){
//         std::cout << "[" << name << "] Was used." << std::endl;
//     }
// };

// class Weapon:public Item{
//     private:
//         int damage;

    
// };

// int main(int argc, char* argv[]){


//     return 0;
// }

// #include <iostream>

// class BankAccount{
//     private:
//         double balance{};

//     public:
//         BankAccount(double initialBalance) : balance(initialBalance) {};

//         double GetBalance(){
//             return balance;
//         }

//         void Deposit(double& amount){
//             if (amount > 0)
//             {
//                 balance += amount;
//                 amount = 0;
//             }
//             else{
//                 std::cout << "ERROR: Amount must be greater than 0" << std::endl;
//             }
//         }

//         void Withdraw(double& amount){
//             if(amount > 0 && amount < balance){
//                 balance -= amount;
//                 amount = 0;
//             }
//             else{
//                 std::cout << "ERROR: Insufficient balance!" << std::endl;
//             }
//         }
//         ~BankAccount(){
//             std::cout << "Bank account classes terminated successfully!" << std::endl;
//         }
// };

// int main(int argc, char *argv[]){
//     BankAccount acc1(100);

//     double deposit = 50.0;
//     acc1.Deposit(deposit);
//     std::cout << "Amount: " << deposit << '\n';
//     std::cout << "Balance: " << acc1.GetBalance() << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <string>

// // using std::string, std::endl;

// class Weapon {
//     protected:
//         std::string name;
//         int damage;

//     public:
//         Weapon(std::string name, int damage) : name(name), damage(damage) {};

//         virtual void attack(){
//             std::cout << name << " deals " << damage << " damage\n";
//         }
//         virtual ~Weapon() {};
// };

// class SwordWeapon : public Weapon {
//     public:
//         SwordWeapon(std::string name, int damage) : Weapon(name, damage) {};
//         void attack()
//         {
//             std::cout << name << " slashes for " << damage << " damage\n";
//         }

// };

// class BowWeapon : public Weapon {
//     public:
//         BowWeapon(std::string name, int damage) : Weapon(name, damage) {};
//         void attack(){
//             std::cout << name << " shoots arrow for " << damage << " damage\n";
//         }
// };

// int main(){
//     Weapon* weapons[2];
//     weapons[0] = new SwordWeapon("Iron Sword", 25);
//     weapons[1] = new BowWeapon("Longbow", 15);

//     for (int i = 0; i < 2; i++){
//         weapons[i]->attack();
//     }

//     for (int i = 0; i < 2; i++){
//         // delete[] weapons[i]; //Right method
//         // weapons[i]->~Weapon(); // Wrong method
//     }

//     return 0;
// }

// ===================== THE SNIFFER CODE PART =============

#include "sniffer.h"

int main(int argc, char* argv[]){
    std::cout << "[*] Initializing packet sniffer..." << std::endl;

    int socket_fd = open_raw_socket();
    if (socket_fd == -1){
        return 1;
    }
    char buffer[65536];
    std::cout << "[*] Listening for live network packets... Press Ctrl+C to cancel" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    while(true) {
        int packet_size = recv(socket_fd, buffer, sizeof(buffer), 0);

        if(packet_size < 0){
            std::cerr << "[-] Failed to recieve packet data." << std::endl;
            break;
        }

        process_packet(buffer, packet_size);
    }

    close(socket_fd);
    return 0;
}