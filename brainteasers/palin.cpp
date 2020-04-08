#include <iostream>
#include <cstdlib>

void Palindrome(int i){
    int temp = 0;
    int k = i;
    while(k > 0){
        temp = temp * 10 + k % 10;   
        k = k/10;
    }    
    if (temp == i){
        std::cout << "Yes, this is a palindromic number.";
    } else{
        std::cout << "No, this is not a palindromic number.";
    }
}

int main()
{    
    int input;
    std::cout << "Input a number to check if it's a palindromic number: ";
    std::cin >> input;
    Palindrome(input);
    return 0;
}
