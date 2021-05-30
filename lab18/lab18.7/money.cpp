#include "Money.h"
Money::Money(void) {
	rub = kop = 0;
}


Money::Money(long R, int K) {
	rub = R;
	kop = K;
}
Money::Money(const Money& m) {
	rub = m.rub;
	kop = m.kop;
}
Money& Money::operator = (const Money& m) {
	rub = m.rub;
	kop = m.kop;
	return*this;
}
ostream& operator<<(ostream& out, const Money& m)
{
	out << m.rub << "," << m.kop;
	return out;
} istream& operator>>(istream& in, Money& m)
{
	cout << "\n\n������� �������� ����� : "; in >> m.rub;
	while (m.rub < 0) { cout << "\n������� �������� ����� : "; in >> m.rub; }
	cout << "������� �������� ������� : "; in >> m.kop;
	while (m.kop < 0) { cout << "������� �������� ������� : "; in >> m.kop; }
	if (m.kop > 100)
	{
		m.rub += 1;
		m.kop = m.kop % 100;
	}
	cout << endl;
	return in;
}
Money Money::operator-(const Money& m)
{
	int f = rub * 100 + kop;
	int s = m.rub * 100 + m.kop;
	f = abs (f-s);
	Money temp(f / 100, f % 100);
	return temp;
}