#include <string>
#include <sstream>
#include <cmath>
using namespace std;

std::string simplify(int n)
{
    int i = sqrt(n);
    for(; i >= 1; --i)
        if(n % (i * i) == 0)
            break;
        
    int j = n / (i * i);

    if(j == 1)
        return to_string(i);

    if(i == 1)
        return "sqrt " + to_string(j);

    return to_string(i) + " sqrt " + to_string(j);
}

int desimplify(const std::string& s)
{
    string strTemp;
    stringstream strStreamTemp;

    int  i = 1;
    while(strStreamTemp >> strTemp)
        if(strTemp != "sqrt")
            i *= pow(stoi(strTemp), 2);

    if(s.find("sqrt") != EOF)
        return i / stoi(strTemp);
    
    return i;
}