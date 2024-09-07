#include "bn_cpp.h"
#include<string>
#include<algorithm>
bn_cpp::bn::bn() {
	bignum_init(&num);
}
bn_cpp::bn::bn(int x) {
	bignum_from_int(&num, x);
}
bn_cpp::bn::bn(const bn_cpp::bn &b) {
	bignum_assign(&num, (::bn*) & b.num);
}
bn_cpp::bn& bn_cpp::bn::operator=(const bn_cpp::bn& b) {
	bignum_assign(&num, (::bn*) &b.num);
	return *this;
}
int bn_cpp::bn::to_int()const {
	return bignum_to_int((::bn*) &num);
}
bn_cpp::bn bn_cpp::bn::operator+(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_add(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator-(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_sub(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator*(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_mul(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator/(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_div(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator%(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_mod(&num, (::bn*) &b.num, &c.num);
	return c;
}
void bn_cpp::bn::divmod(const bn_cpp::bn& b, bn_cpp::bn& div, bn_cpp::bn& mod) {
	bignum_divmod(&num, (::bn*) &b.num, &div.num, &mod.num);
}
bn_cpp::bn bn_cpp::bn::operator&(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_and(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator|(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_or(&num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator^(const bn_cpp::bn& b) {
	bn_cpp::bn c;
	bignum_xor(&num, (::bn*) (bn*) & b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator<<(int nbits) {
	bn_cpp::bn c;
	bignum_lshift(&num, &c.num,nbits);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator>>(int nbits) {
	bn_cpp::bn c;
	bignum_rshift(&num, &c.num,nbits);
	return c;
}
bool bn_cpp::bn::operator<(const bn_cpp::bn&b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) < 0;
}
bool bn_cpp::bn::operator<=(const bn_cpp::bn& b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) <= 0;
}
bool bn_cpp::bn::operator>(const bn_cpp::bn& b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) > 0;
}
bool bn_cpp::bn::operator>=(const bn_cpp::bn& b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) >= 0;
}
bool bn_cpp::bn::operator==(const bn_cpp::bn& b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) == 0;
}
bool bn_cpp::bn::operator!=(const bn_cpp::bn& b)const {
	return bignum_cmp((::bn*) &num, (::bn*) &b.num) != 0;
}
bool bn_cpp::bn::to_bool()const {
	return !bignum_is_zero((::bn*) &num);
}
bn_cpp::bn bn_cpp::bn::operator++() {
	bignum_inc(&num);
	return *this;
}
bn_cpp::bn bn_cpp::bn::operator--() {
	bignum_dec(&num);
	return *this;
}
bn_cpp::bn bn_cpp::bn::operator++(int) {
	bn_cpp::bn c(*this);
	bignum_inc(&num);
	return c;
}
bn_cpp::bn bn_cpp::bn::operator--(int) {
	bn_cpp::bn c(*this);
	bignum_dec(&num);
	return c;
}
bn_cpp::bn bn_cpp::bn::pow(const bn_cpp::bn& b)const {
	bn_cpp::bn c;
	bignum_pow((::bn*) &num, (::bn*) &b.num, &c.num);
	return c;
}
bn_cpp::bn bn_cpp::bn::isqrt()const {
	bn_cpp::bn c;
	bignum_isqrt((::bn*) &num, &c.num);
	return c;
}
std::string bn_cpp::bn::to_hex()const {
	char temp[1024];
	bignum_to_string((::bn*) &num, temp, 1024);
	return std::string(temp);
}
void bn_cpp::bn::from_hex(const std::string& s) {
	bignum_from_string(&num, (char*) s.c_str(), s.size());
}
std::string bn_cpp::bn::to_string()const {
	std::string result;
	bn_cpp::bn temp = *this;
	while (temp.to_bool()) {
		result += char(48 + (temp % bn_cpp::bn(10)).to_int());
		temp = temp / bn_cpp::bn(10);
	}
	if (result.empty()) result = "0";
	reverse(result.begin(), result.end());
	return result;
}
bn_cpp::bn::bn(const std::string& s) {
	bignum_init(&num);
	for (char c : s) {
		(*this) = (*this) * bn_cpp::bn(10) + bn_cpp::bn(c - 48);
	}
}
