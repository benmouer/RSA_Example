/*Benjamin Mouer
 * CSC 222
 * HW 1
 */




#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <math.h>
#include <functional>
#include <algorithm>
using namespace std;

int sign(int a, int b, int c);
bool verify(int w, int y, int z, int q);

int main() {


    //I/O commands to get user to input data and get results
    int N, e, d, M;
    int sigma;
    cout << "Be ready to input your message (int)..." << endl;
    cout << "input message, $M$" << endl;
    cin >> M;
    cout << "input secret key, $d$" << endl;
    cin >> d;
    cout << "input $N$" << endl;
    cin >> N;


    sigma = sign(M, d, N);
    cout<< "your $sigma$ = " << sigma << endl;


    cout << "would you like to verify the digitally signed message?" << endl << "Be ready to input the public Key...";
    cout << "input $N$" << endl;
    cin >> N;
    cout << "input $e$" << endl;
    cin >> e;
    cout << "input $sigma$" << endl;
    cin >> sigma;
    cout << "input original message, $M$" << endl;
    cin >> M;


    //outputs results
    bool ver = verify(sigma, N, e, M);
    if (ver){
        cout << "this message is verified" << endl;
    } else{
        cout << "WARNING: This message is NOT verified" << endl;
    }



}

//uses the sign function since this process also needs to perform Modular exponentation
bool verify(int sigma, int N, int e, int M) {
    int num = sign(sigma, e, N);
    return (num == M);
}


//This method is used to sign the message, it uses the alogrithm discussed in class to perform modular exponentation with low complexity.
int sign(int a, int b, int n){
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % n; // multiplying with base
        }
        y = (y * y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}






