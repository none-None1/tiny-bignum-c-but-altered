# tiny-bignum-c-but-altered
For readme of tiny-bignum-c, see [here](https://github.com/kokke/tiny-bignum-c).

This is a wrapper and extension of tiny-bignum-c for C++, it is created because not overriding operators for bignums is painful.

This defines the class `bn` in the namespace `bn_cpp` (in order to differentiate it from the original `bn` struct), which provides all the operators supported by tiny-bignum-c. It also provides these functions: (In the following code, `bn` means the `bn` class in the namespace `bn_cpp`)
```cpp
// Constructors
bn(); // Initialize to zero
bn(int x); // Initialize from int
bn(const bn&b); // Copy constructor
bn(const std::string&s); // Initialize from decimal string (added by none-None1)
// Wrappers of tiny-bignum-c
int to_int()const;
bool to_bool()const; // false for zero, true for nonzero
std::string to_hex()const; // Convert to hexadecimal string
bn pow(const bn&b)const;
bn isqrt()const;
// Functions added by none-None1
std::string to_string();
friend ostream& operator<<(ostream&o,const bn&b);
friend istream& operator>>(istream&i,bn&b);
```
There is also a test program `testcpp.cpp`, that tests two bignums.

## Build
Run the `build.bat` batch file to build because none-None1 doesn't know how to write Makefiles. It uses MinGW but you can manually build using other compilers.

After that, link the static libraries created in your program, and that's it.

*Note: C++11 support is required for the compiler.*
## License
Like tiny-bignum-c, all material in this repository is in the public domain.

