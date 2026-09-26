#include <iostream>
#include <string>

using namespace std;
// Takes two integers: the base and the power

int power(int x, int y){
    int result = 1;
    for(int i = 0; i < y; i++){
        result = result * x;
    }
    return result;
}

int main(){
    // Accept data(numbers) from users find the length
    string userInput;
    cout << "Enter a number: ";
    cin >> userInput;
    string number_holder = userInput;
    int length_of_userInput = userInput.length();
    int converted_userInput = stoi(number_holder);
    int summation_of_the_digit_powers = 0;
    while(converted_userInput > 0){
        int last_digit_of_converted_userInput = converted_userInput % 10;
        converted_userInput /= 10;
        summation_of_the_digit_powers += power(last_digit_of_converted_userInput, length_of_userInput);
    }
    if(to_string(summation_of_the_digit_powers) == userInput){
        cout << "This is an ARMSTRONG NUMBER." << endl;
    }
    else cout << "This is not an ARMSTRONG NUMBER." << endl;
    return 0;
}