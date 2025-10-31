#include <random>

class Dice {
public:
    int roll() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 6);
        return dist(gen);
    }

    int getFaceValue(){
	return faceValue;
    }

    int setFaceValue(int val){
	    if(val>0 && val <7){
	    	faceValue = val;
	    }
};
