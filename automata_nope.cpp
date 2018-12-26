#include <iostream>
#include <string.h>
#define max 13

using namespace std;

class Number {
        string nomor;
        int panjang;
    public:
        Number(char*);
        Number(string);
        ~Number();

        bool check();
};

Number::Number(string x) {
	nomor = x;
	
	panjang = nomor.length();
}

Number::Number(char *number) {
    nomor = number;
    
    panjang = nomor.length();
}

Number::~Number() {
    if(check()) cout << " Automata diterima" << endl;
    else cout << " Automata ditolak" << endl;
}

bool Number::check() {
    bool state_satu, state_dua, not_error;
    not_error = false;
    
    state_satu = (nomor[0] == '0');
    state_dua = (nomor[1] != '0' && nomor[1] != '1');

    int i = 2;
    while((state_satu && state_dua) && (panjang <= max && i < panjang)) {
        if((int)nomor[i] >= 48 && (int)nomor[i] <= 57) not_error = true;
        else return false;

        i++;
    }

    return not_error;
}

int main(int argc, char *argv[]) {
    
    string nomor;
	cout << " Masukan nomor HP : "; cin >> nomor;

	Number automata(nomor);
	
    return 0;
}
