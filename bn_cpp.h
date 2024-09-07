#ifndef __BIGNUM_CPP_H__
#define __BIGNUM_CPP_H__
#ifndef __cplusplus
#error If you are using C, include bn.h instead
#endif
extern "C" {
#include "bn.h"
}
#include<string>
#include<iostream>
namespace bn_cpp {
	class bn {
	public:
		::bn num;
		bn();
		bn(int x);
		bn(const bn& b);
		int to_int()const;
		bn operator+(const bn& b);
		bn operator-(const bn& b);
		bn operator*(const bn& b);
		bn operator/(const bn& b);
		bn operator%(const bn& b);
		void divmod(const bn& b,bn& div, bn& mod);
		bn operator&(const bn& b);
		bn operator|(const bn& b);
		bn operator^(const bn& b);
		bn operator<<(int nbits);
		bn operator>>(int nbits);
		bool operator<(const bn& b)const;
		bool operator>(const bn& b)const;
		bool operator==(const bn& b)const;
		bool operator<=(const bn& b)const;
		bool operator>=(const bn& b)const;
		bool operator!=(const bn& b)const;
		bool to_bool()const;
		bn operator++();
		bn operator--();
		bn operator++(int);
		bn operator--(int);
		bn pow(const bn& b)const;
		bn isqrt()const;
		bn& operator=(const bn& b);
		std::string to_hex()const;
		void from_hex(const std::string &s);
		// Additional functionality by none-None1
		std::string to_string()const;
		friend std::ostream& operator<<(std::ostream& o, const bn& b) {
			o << b.to_string();
			return o;
		}
		bn(const std::string& s);
		friend std::istream& operator>>(std::istream& i, bn& b) {
			std::string s;
			i >> s;
			b = bn(s);
			return i;
		}
	};
}
#endif
