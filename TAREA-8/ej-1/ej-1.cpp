#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(stack<char> pila, string text) {
    bool palindrome = true;
    cout << "Ingrese una cadena de texto: ";
    getline(cin, text);

    for(int i = 0; i < text.length(); i++) {
        pila.push(text[i]);
    }

    for(int i = 0; i < text.length(); i++) {
        if(text[i] != pila.top()) {
            palindrome = false;
            break;
        }
        pila.pop();
    }

    return palindrome;
}

int main() {
    stack<char> pila;
    string text;
    bool palindrome = false;
    palindrome = isPalindrome(pila, text);

    if(palindrome) {
        cout << "La cadena es un palíndromo" << endl;
    } else {
        cout << "La cadena no es un palíndromo" << endl;
    }
    

    return 0;

}