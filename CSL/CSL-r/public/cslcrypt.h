/*
** Shijie Zhang, 2019
*/

////////////////////////////////////////////////////////////////////////////////

#ifndef __CSL_CRYPT_H__
#define __CSL_CRYPT_H__

#include <string>
#include <ctime>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define shift(x, n) (((x) << (n)) | ((x) >> (32 - (n)))) //右移的时候，高位一定要补零，而不是补充符号位
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

////////////////////////////////////////////////////////////////////////////////

class Cslcrypt
{
public:
    string md5_get(string str);
    string md5_salt_get(const string& str);

private:
    static string salt_insert(const string& source, const string& salt);
    static string salt_generate();
    void mainLoop(unsigned int M[]);
    unsigned int *add(string str);
    string changeHex(int a);

    //strBaye的长度
    unsigned int strlength;
    //A,B,C,D的临时变量
    unsigned int atemp;
    unsigned int btemp;
    unsigned int ctemp;
    unsigned int dtemp;
    //常量ti unsigned int(abs(sin(i+1))*(2pow32))
    const unsigned int k[64] = {
            0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
            0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8,
            0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193,
            0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51,
            0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
            0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905,
            0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681,
            0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60,
            0xbebfbc70, 0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
            0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244,
            0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
            0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314,
            0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
    //向左位移数
    const unsigned int s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
                                12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
                                4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
                                15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
    const char str16[17] = "0123456789abcdef";
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////