using namespace std;

class Fraction {
    public:
        Fraction(): Fraction(0, 1) {};
        Fraction(int numerator, int denominator);
        int gcd(int a, int b);
        void normalise();
        void write() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
        int denominator() const { return denominator_; }
        int numerator() const { return numerator_; }
    private:
        int numerator_;
        int denominator_;
};

#include "fraction_aux.h"

Fraction::Fraction(int numerator, int denominator): 
numerator_(numerator), denominator_(denominator) {
    this->normalise();
}

Fraction Fraction::sum(const Fraction& right) {
    int old_denominator = denominator_;

    numerator_ *= right.denominator_;
    denominator_ *= right.denominator_;

    numerator_ += right.numerator_ * old_denominator;

    this->normalise();
    return *this;
}

Fraction Fraction::sub(const Fraction& right) {
    this->sum({-right.numerator_, right.denominator_});
    return *this;
}

Fraction Fraction::mul(const Fraction& right) {
    numerator_ *= right.numerator_;
    denominator_ *= right.denominator_;
    this->normalise();
    return *this;
}

Fraction Fraction::div(const Fraction& right) {
    this->mul({right.denominator_, right.numerator_});
    return *this;
}
