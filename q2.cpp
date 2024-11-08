#include <iostream>
#include <iostream>
#include <stdexcept>
using namespace std;

class Tiny {
    char v;
    void assign(int i){
          if(i&~077) throw Bad_range();
          v = i;
       }

public:
       class Bad_range : public std::exception {
        public:
            const char* what() const throw() {
                return "Tiny value out of range";
            }
    };

    Tiny(int i = 0) { assign(i); }

    operator int() const { return v; }

    Tiny& operator=(const Tiny& other) {
        v = other.v;
        return *this;
    }

    Tiny operator+(int i) { return Tiny(v + i); }
    Tiny operator+(int i) const {
        return Tiny(v + i);
    }



    Tiny operator-(int i) { return Tiny(v - i); }


    Tiny operator+(Tiny& t) { return Tiny(v + t.v); }

    Tiny operator-(Tiny& t) { return Tiny(v - t.v); }
};

int main() {
    try {
        Tiny c1 = 2; // Perform range check
        Tiny c2 = 62; // perform range check
        Tiny c3 = c2 - c1; // c3 = 60;
        Tiny c4 = c3; // no range check required
        int i = int(c1) + int(c2); // i = 64
        c1 = c1 + c2; // range error: c1 can’t be 64
        i = int(c3) - 64; //i = -4
        c2 = c3 - 64; // range error: c2 can’t be -4
        c3 = c4; // no range check required
    }catch (Tiny::Bad_range&) {
        cerr << "Range error occurred!" << endl;
    }
}
