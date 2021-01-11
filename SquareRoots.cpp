#include <string>
#include <string.h>

using namespace std;

bool IsPrimeNumber(int n){
  if(n <= 1)
    return false;
  
  for(int index = 2; index <= sqrt(n); index++){
    if((n % index) == 0)
      return false;
  }
  return true;
}

vector<int> Prime_Factorization(int n){
  vector<int> VecnResult;
  int nTemp = 2;
  while(n != 1){
    if(n % nTemp == 0){
      VecnResult.push_back(nTemp);
      n /= nTemp;
    }
    else
      nTemp++;
  }
  return VecnResult;
}

std::string simplify(int n)
{
    //your code here   
  string strResult;
  
  cout << n << endl;
  
  if(n == 1)
    return to_string(n);
  
  if(IsPrimeNumber(n)){
    strResult = "sqrt ";
    strResult += to_string(n);
  }
  else{
    vector<int> VecnTemp = Prime_Factorization(n);
    
    vector<int> VecnFirst;
    vector<int> VecnSecond;
    
    int nTarget = VecnTemp.front();
    int nCheckCount = 1;
    int nCount = VecnTemp.size();
    
    for(int index = 1; index < nCount; index++){
      if(nTarget == VecnTemp[index]){
        nCheckCount++;
        if(nCheckCount == 2){
          VecnFirst.push_back(VecnTemp[index]);
          nCheckCount = 0;
        }
      }
      else{
        if(nCheckCount == 1)
          VecnSecond.push_back(nTarget);
        nTarget = VecnTemp[index];
        nCheckCount = 1;
      }
    }
    
    if(nCheckCount == 1)
      VecnSecond.push_back(nTarget);
    
    if(VecnFirst.size()){
      int nFirst = VecnFirst.front();
      int nFirstCount = VecnFirst.size();
      for(int index = 1; index < nFirstCount; index++)
        nFirst *= VecnFirst[index];
      strResult += to_string(nFirst);
    }
   
    if(VecnSecond.size()){
      if(strResult.empty())
        strResult += "sqrt ";
      else
        strResult += " sqrt ";
      int nSecond = VecnSecond.front();
      int nSecondCount = VecnSecond.size();
      for(int index = 1; index < nSecondCount; index++)
        nSecond *= VecnSecond[index];
      strResult += to_string(nSecond);
    }
  }
  
  return strResult;
}

int desimplify(std::string s)
{
    //your code here
  int nResult = 0;
  
  vector<string> VecstrSplit;
  char * strBuffer = new char [1024];
  strcpy(strBuffer, s.c_str());
  char *tok = strtok(strBuffer, " ");
  while (tok != nullptr) {
    VecstrSplit.push_back(string(tok));
    tok = strtok(nullptr, " ");
  }
  delete [] strBuffer;
  delete [] tok;
  
  if(VecstrSplit.size() == 1)
    nResult = pow(stoi(VecstrSplit[0]), 2);
  else if(VecstrSplit.size() == 2)
    nResult = stoi(VecstrSplit[1]);
  else if(VecstrSplit.size() == 3){
    nResult += pow(stoi(VecstrSplit[0]), 2);
    nResult *= stoi(VecstrSplit[2]);
  }
  
  return nResult;
}