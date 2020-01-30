/*
 * @AUTHOR PMARINA (PRIDHVI MYNENI)
 * @VERSION 10.23.2019
 * 
 * FIBONACCI, IMPLEMENTED RECURSIVELY, USING THE GREEDY ALGORITHM OF RUNTIME 2**N (THOUGH THE INTERNET CLAIMS GOLDEN_RATIO**N)
 * 
 * I PLEDGE MY HONOR THAT I HAVE ABIDED BY THE STEVENS HONOR SYSTEM -- PRIDHVI MYNENI
*/
#include<iostream>

int getNthTermFibonacci(int n){
    if(n <  1){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    else{
        return getNthTermFibonacci(n-1) + getNthTermFibonacci(n-2);
    }
}

int altMain(void){
    for(int i = 0; i<46; i++){
        std::cout << "The " << i+1 << " term of the Fibonacci sequence is: " << getNthTermFibonacci(i)<<std::endl;
    }
}

int main(void){
    return altMain(); //Computes only the first 46 numbers because otherwise integer overflow, assuming int = uint_32.
    int userInput = -1;
    std::cout<<"Please enter the index of the term of the fibonacci sequence you would like to find (index starts at 1): ";
    std::cin>>userInput;
    userInput--;
    if(userInput<1-1){
        std::cout<<"This program begins counting fibonacci numbers at index = 1. Please try again later."<<std::endl;
        return 1;
    }
    std::cout << "The " << userInput+1 << " term of the Fibonacci sequence is: " << getNthTermFibonacci(userInput)<<std::endl;
    return 0;
}