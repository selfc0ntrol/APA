{\rtf1\ansi\ansicpg1251\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 HelveticaNeue-Bold;\f1\fnil\fcharset0 HelveticaNeue;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab560
\pard\pardeftab560\partightenfactor0

\f0\b\fs34 \cf0 Metoda 1 - recursivitatea\
\pard\pardeftab560\slleading20\qj\partightenfactor0

\f1\b0\fs24 \cf0 #include <iostream>\
#include <chrono>\
using namespace std::chrono;\
using namespace std;\
auto start = high_resolution_clock::now();\
int fib1(int n)\
\{\
    if(n < 2)\
    \{\
        return n;\
    \}\
    else\
    \{\
        return fib1(n - 1) + fib1(n - 2);\
    \}\
\}\
    int main()\
    \{\
        int n = 30;\
        cout<<fib1(n) << endl;\
        auto stop = high_resolution_clock::now();\
        auto duration = duration_cast<microseconds>(stop - start);\
        cout << "Timpul: " << duration.count() << " ms" << endl;\
    \}\
\pard\pardeftab560\slleading20\pardirnatural\partightenfactor0
\cf0 \
\pard\pardeftab560\partightenfactor0

\f0\b\fs34 \cf0 Metoda 2 - programarea dinamica \
\pard\pardeftab560\slleading20\partightenfactor0

\f1\b0\fs24 \cf0 #include <iostream>\
#include <chrono>\
using namespace std::chrono;\
using namespace std;\
auto start = high_resolution_clock::now();\
int fib2(int n)\
\{\
    int i = 1;\
    int j = 0;\
\
        for(int k = 1; k <= n; k++)\
        \{\
            j = i + j;\
            i = j - i;\
        \}\
        return j;\
\}\
\
    int main()\
    \{\
        int n = 30;\
        cout<<fib2(n) << endl;\
        auto stop = high_resolution_clock::now();\
        auto duration = duration_cast<microseconds>(stop - start);\
        cout << "Timpul: " << duration.count() << " ms" << endl;\
    \}\
\pard\pardeftab560\slleading20\pardirnatural\partightenfactor0
\cf0 \
\pard\pardeftab560\partightenfactor0

\f0\b\fs34 \cf0 Metoda 3 -Tehnica divide et impera\
\pard\pardeftab560\slleading20\partightenfactor0

\f1\b0\fs24 \cf0 #include <iostream>\
#include <chrono>\
using namespace std::chrono;\
using namespace std;\
auto start = high_resolution_clock::now();\
int fib3(int n)\
\{\
    int i = 1;\
    int j = 0;\
    int k = 0;\
    int h = 1;\
    int t;\
\
        while(n > 0)\
        \{\
            if(n % 2 != 0)\
            \{\
                t = j * h;\
                j = i * h + j * k + t;\
                i = i * k + t;\
            \}\
            t = h * h;\
            h = 2 * k * h + t;\
            k = k * k + t;\
            n = n / 2;\
        \}\
        return j;\
\}\
\
    int main()\
    \{\
        int n = 9;\
        cout<<fib3(n) << endl;\
        auto stop = high_resolution_clock::now();\
        auto duration = duration_cast<microseconds>(stop - start);\
        cout << "Timpul: " << duration.count() << " ms" << endl;\
    \}}