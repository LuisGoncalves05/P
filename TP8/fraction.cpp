#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
    return 0;
}

class Fraction {
    public:
        Fraction();
        Fraction(int n, int d);
        int gcd(int a, int b);
        void normalise();
        void write() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
        int get_numerator() const{
            return numerator_;
        }
        int get_denominator() const{
            return denominator_;
        }
    private:
        int numerator_;
        int denominator_;
};


Fraction::Fraction(): Fraction(0, 1) {}


Fraction::Fraction(int n, int d): numerator_(n), denominator_(d) {
    normalise();
}



Fraction Fraction::sum(const Fraction& right) {
    int den = get_denominator() * right.get_denominator();
    int num = get_numerator() * right.get_denominator() + right.get_numerator() * get_denominator();
    return Fraction(num, den);
}

Fraction Fraction::sub(const Fraction& right){
    const Fraction neg (-right.get_numerator(), right.get_denominator());
    return sum(neg);
}


Fraction Fraction::mul(const Fraction& right){
    int num = get_numerator();
    int den = get_denominator();
    num *= right.get_numerator();
    den *= right.get_denominator();
    return Fraction(num, den);
}


Fraction Fraction::div(const Fraction& right){
    const Fraction inverse (right.get_denominator(), right.get_numerator());
    return mul(inverse);
}


int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}


void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}


void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}