using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int numDrank = 0;
        int numEmpty = 0;
        while(numBottles > 0) {
            //Drink a water bottle
            numBottles--;
            numDrank++;
            numEmpty++;

            //Check if we have enough empty bottles for an exchange
            if(numEmpty == numExchange) {
                numBottles++;
                numExchange++;
                numEmpty = 0;
            }
        }
        return numDrank;
    }
};  