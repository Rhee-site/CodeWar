#include <algorithm>

using namespace std;

class BestTravel
{
public:
    static int chooseBestSum(int nLimitTravelDistance, int nCityCount, const vector<int>& VecnEachCityDistance);
}

int BestTravel::chooseBestSum(int nLimitTravelDistance, int nCityCount, const vector<int>& VecnEachCityDistance){
    int nTotalCityCount = VecnEachCityDistance.size();
    
    if(nTotalCityCount < nCityCount)
        return -1;
    
    int nResult = 0;
    string strBitMask(nCityCount, 1);
    strBitMask.resize(nTotalCityCount, 0);

    do{
        int nSum = 0;
        for(int index = 0; index < nTotalCityCount; index++)
            if(strBitMask[index])
                nSum += VecnEachCityDistance[index];
        if(nSum <= nLimitTravelDistance && nSum > nResult)
            nResult = nSum;
    }while(prev_permutation(strBitMask.begin(), strBitMask.end());

    if(nResult > 0)
        return nResult;
    return -1;
}