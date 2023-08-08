#include <math.h>

using namespace std;

typedef long long ll;

class Fraction {
public:
	Fraction();
	Fraction(ll);
	Fraction(ll, ll);
	~Fraction();

	friend std::ostream& operator << (std::ostream&, const Fraction&);
	Fraction operator+(Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator*(Fraction&);
	Fraction operator/(Fraction&);
	bool operator==(Fraction&);

	ll find_gcd(ll, ll);
	ll get_num();
	ll get_den();

private:
	ll num, den, gcd, signal;
};

Fraction Fraction::operator*(Fraction& other) {
	ll new_num, new_den;
	ll new_signal;

	new_num = num*other.num;
	new_den = den*other.den;
	new_signal = this->signal*other.signal;


	ll gcd = find_gcd(new_num, new_den);

	return Fraction(new_signal*new_num/gcd, new_den/gcd);
}

Fraction Fraction::operator/(Fraction& other) {
	Fraction new_fraction(other.den, other.num);

	return (*this)*new_fraction;
}

bool Fraction::operator==(Fraction& other) {
	ll new_num, new_den;

	new_num = this->num*other.den;
	new_den = other.num*(this->den);
	return (new_num == new_den);

}

Fraction Fraction::operator+(Fraction& other) {
	ll new_num, new_den;

	new_den = this->den*other.den;
	new_num = this->signal*num*other.den + other.signal*other.num*den;

	ll new_gcd = find_gcd(new_num, new_den);

	return Fraction(new_num/new_gcd, new_den/new_gcd);

}


Fraction Fraction::operator-(Fraction& other) {
	Fraction new_fraction = Fraction(-other.num, other.den);

	return (*this)+new_fraction;
}


ll Fraction::get_num() {
	return num;
}

ll Fraction::get_den() {
	return this->den;
}

Fraction::Fraction() {
	num = 1;
	den = 1;
	signal = 1;
}

Fraction::Fraction(ll num) {
	this->num = abs(num);
	this->den = 1;
	if (num >= 0) signal = 1;
	else signal = -1;
}

Fraction::Fraction(ll num, ll den) {
	if (num/den >= 0) signal = 1;
	else signal = -1;

	this->gcd = find_gcd(abs(num), abs(den));
	this->num = abs(num)/gcd;
	this->den = abs(den)/gcd;
}

Fraction::~Fraction() {
}

std::ostream& operator << (std::ostream& stream, const Fraction& fraction) {
	
	stream << fraction.signal*fraction.num << " / " << fraction.den;

	return stream;
}


ll Fraction::find_gcd(ll num, ll den) {
	ll bigger, lower;

	if (num == den) return 1;

	if (num > den) {
		bigger = num;
		lower = den;
	}else {
		bigger = den;
		lower = num;
	}

	while (bigger % lower != 0) {
		ll remain = bigger % lower;
		bigger = lower;
		lower = remain;

	}

	return lower;
}

































