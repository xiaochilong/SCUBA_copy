/*
 * AAProbabilityArray.h
 *
 *  Created on: 2017??12??2??
 *      Author: notxp
 */

#ifndef DESIGNSEQ_AAPROBABILITYARRAY_H_
#define DESIGNSEQ_AAPROBABILITYARRAY_H_

#include <iostream>
#include <cmath>

namespace NSPdesignseq {
using namespace std;

class AAProbabilityArray {
private:
    double pa[20];
    double sa[20];
    double sampleNum;
public:
    AAProbabilityArray(){
        sampleNum = -1;
    }

    AAProbabilityArray(double* pa){
        for(int i=0;i<20;i++){
            double p = pa[i];
            this->pa[i] = p;
            if(p == 0)
                sa[i] = 20;
            else
                sa[i] = -log(p);
        }


        this->sampleNum = -1;
    }

    AAProbabilityArray(double* pa, double sampleNum){
        for(int i=0;i<20;i++){
            double p = pa[i];
            this->pa[i] = p;
            if(p == 0)
                sa[i] = 20;
            else
                sa[i] = -log(p);
        }
        this->sampleNum = sampleNum;
    }

    AAProbabilityArray(int* counts){
        this->sampleNum = 10;


        for(int i=0;i<20;i++){
            this->sampleNum += counts[i];

        }

        for(int i=0;i<20;i++){

            this->pa[i] = (counts[i]+0.5)/this->sampleNum;
            this->sa[i] = -log(pa[i]);
        }
    }

    double getRelP(int aa){
        double bg[20] =     {0.0839, 0.0126, 0.0593, 0.0681, 0.0409,
                    0.0735, 0.0235, 0.0576, 0.0567, 0.0940,
                    0.0167, 0.0427, 0.0463, 0.0375, 0.0517,
                    0.0588, 0.0546, 0.0713, 0.0146, 0.0358};
        double p = pa[aa];
        return p/bg[aa];
    }

    double getRelScore(int aaType) {
        if(aaType < 0 || aaType > 19){
            cerr << "invalid animo acid type" << endl;
            exit(1);
        }
        double bg[20] =     {0.0839, 0.0126, 0.0593, 0.0681, 0.0409,
                    0.0735, 0.0235, 0.0576, 0.0567, 0.0940,
                    0.0167, 0.0427, 0.0463, 0.0375, 0.0517,
                    0.0588, 0.0546, 0.0713, 0.0146, 0.0358};
        double relP = pa[aaType]/bg[aaType];
        return -log(relP);
    }

    void initProbability(double* pa){
        for(int i=0;i<20;i++){
            double p = pa[i];
            this->pa[i] = p;
            if(p == 0)
                sa[i] = 20;
            else
                sa[i] = -log(p);
        }
    }

    double getProbability(int aaType){
        if(aaType < 0 || aaType > 19){
            cerr << "invalid animo acid type" << endl;
            exit(1);
        }
        return pa[aaType];
    }

    double getScore(int aaType){
        if(aaType < 0 || aaType > 19){
            cerr << "invalid animo acid type" << endl;
            exit(1);
        }
        return sa[aaType];
    }

    void printArray(){
        for(int i=0;i<20;i++){
            double p = pa[i];
            printf("%6.3f ",p);
        }
        cout << endl;
    }

    virtual ~AAProbabilityArray();
};

} /* namespace NSPdesignseq */

#endif /* DESIGNSEQ_AAPROBABILITYARRAY_H_ */
