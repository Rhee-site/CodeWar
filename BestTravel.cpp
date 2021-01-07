#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls);
    static void combination(vector<int>ls, vector<int>&Distance, int k, int index, int depth, vector<int>&VecnResult);
};

void BestTravel::combination(vector<int>ls, vector<int>&Distance, int k, int index, int depth, vector<int>&VecnResult){
  if(k == 0){
    int nTemp = 0;
    for(int i = 0; i < Distance.size(); i++)
      nTemp += Distance[i];
    VecnResult.push_back(nTemp);
  }
  else if(depth == ls.size())
    return;
  else{
    Distance[index] = ls[depth];
    combination(ls, Distance, k - 1, index + 1, depth +1, VecnResult);
    combination(ls, Distance, k, index, depth +1, VecnResult);    
  }
}

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls){
  int nResult = 0;
  int nChooseCount = 0;
  int nDistanceCount = ls.size();
  
  if(k > nDistanceCount)
    return -1;
  else if(k == nDistanceCount){
    for(vector<int>::iterator iter = ls.begin(); iter != ls.end();){
      nResult += *iter;
      iter++;
    }
    if(nResult > t)
      return -1;
    else
      return nResult;
  }
  else{
    vector<int> Distance(k);
    vector<int> VecnResult;
    combination(ls, Distance, k, 0, 0, VecnResult);
    
    sort(VecnResult.begin(), VecnResult.end());
    
    for(int index = 0; index < VecnResult.size(); index++){
      if(t >= VecnResult[index])
        if(nResult <= VecnResult[index])
          nResult = VecnResult[index];
    }
    
    if(!nResult)
      nResult = -1;
    return nResult;
  }
}