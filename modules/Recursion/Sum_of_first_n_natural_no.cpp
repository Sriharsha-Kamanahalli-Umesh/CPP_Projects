#include <iostream>

int SumNNaturalNo(int n) {
    if(n==0) {
        return 0;
    }
    return SumNNaturalNo(n-1) + n;
}

//Using Static variable
int SumNNaturalNoWithStatic(int n) {
    static int sum = 0;
    if(n==0) {
        return 0;
    }
    sum = SumNNaturalNo(n-1) + n;
    return sum;
}

//Using print No in ascending order
void PrintAscending(int n) {
    if(n==0) {
        return;
    }
    PrintAscending(n-1);
    std::cout << n << " ";
}

//Using print No in descending order
void PrintDescending(int n) {
    if(n==0) {
        return;
    }
    std::cout << n << " ";
    PrintDescending(n-1);
    
}

//Factorial of a number
int Factorial(int n) {
    if(n==1) {
        return 1;
    }
    return Factorial(n-1)*n;
    
}

int main() {
    int n=6;
    int sum = SumNNaturalNo(n);
    int sum1 = SumNNaturalNoWithStatic(n);

    std::cout<< " Sum is:" << sum <<"\n";

    std::cout<< " Sum With Static variable:" << sum <<"\n";

    PrintAscending(n);

    std::cout<<"\n";
    PrintDescending(n);

    int fact = Factorial(n);
    std::cout<<"\n";
    std::cout<< " Factorial:" << fact <<"\n";
}