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

#include <iostream>
#include "Port_decoder.h"

int main(int argc, char* argv[]){
    char Raw_packet[] = {0x00, 0x50};
    uint16_t port_number = PortDecoder(Raw_packet);
    std::cout << "Port Number: " << port_number << std::endl;

    return 0;
}