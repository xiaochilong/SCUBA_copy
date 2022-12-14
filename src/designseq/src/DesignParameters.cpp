/*
 * DesignParameters.cpp
 *
 *  Created on: 2017年12月2日
 *      Author: notxp
 */

#include "designseq/DesignParameters.h"

namespace NSPdesignseq {

DesignParameters::DesignParameters() {
    this->wtS1 = 1.0;
    this->wtS2Local = 0.5;
    this->wtS2Nonlocal = 1.0;
    this->wtS2EE = 0.5;

    this->wtCorePacking = 0.72;
    this->wtSurfPacking = 0.05;
    this->packSigma = 0.07;
    this->packSAI0 = 0.65;

    this->nonHBondPolarWeight = 0.6;
    this->repWeight = 1.0;
    this->ref[0] = 0.4;
    this->ref[1] = 0;
    this->ref[2] = -0.1;
    this->ref[3] = 0.2;
    this->ref[4] = 0;
    this->ref[5] = 0;
    this->ref[6] = -0.3;
    this->ref[7] = 0.2;
    this->ref[8] = 0;
    this->ref[9] = 0.2;
    this->ref[10] = 0;
    this->ref[11] = -0.2;
    this->ref[12] = 0.4;
    this->ref[13] = -0.3;
    this->ref[14] = -0.2;
    this->ref[15] = -0.2;
    this->ref[16] = 0;
    this->ref[17] = 0.2;
    this->ref[18] = 0;
    this->ref[19] = 0;



    string path = NSPdataio::datapath()+"abacus2/";
    string refFile = path + "ref/hecRef9";
    readHECRef(refFile);

    std::string refLocalFile = path + "ref/localRef";
    readRefELocal(refLocalFile);

    this->wtRotEnergy = 1.0;
    this->vdwLamda1 = 0.095;
    this->vdwLamda2 = 0.28;
    this->rvdwRatio = 1.0;
    this->hbLamda1 = 0.1;
    this->hbLamda2 = 0.15;
    this->wdNP_NP = -1.3;
    this->wdP_NP = -0.7;
    this->wdP_P = 0.0;
    this->wdHB = -1.5;
    this->hbAngleFactor = 0.5;
    this->aroWD = -1.4;
    this->nb1Rescale = 1.5;

}

DesignParameters::DesignParameters(int tag){
    if(tag == 2){
        //packing parameter
        this->wtS1 = 1.0;
        this->wtS2Local = 0.4;
        this->wtS2Nonlocal = 0.7;
        this->wtS2EE = 0.4;
        this->nonHBondPolarWeight = 0.6;
        this->repWeight = 1.0;
        this->wtCorePacking = 1.0;
        this->wtSurfPacking = 1.0;
        this->packSigma = 0.1;
        this->packSAI0 = 0.7;

        this->wtRotEnergy = 1.0;
        this->vdwLamda1 = 0.095;
        this->vdwLamda2 = 0.28;
        this->rvdwRatio = 1.0;

        this->hbLamda1 = 0.1;
        this->hbLamda2 = 0.15;
        this->wdNP_NP = -1.3;
        this->wdP_NP = -0.5;
        this->wdP_P = 0.0;
        this->wdHB = -1.5;
        this->hbAngleFactor = 0.15;
        this->aroWD = -1.3;
        this->nb1Rescale = 1.5;

        string path = NSPdataio::datapath()+"abacus2/";
        string refFile = path + "ref/hecRef9";
        readHECRef(refFile);
    }
    else{
        cout << "undefined parameter id" << endl;
        abort();
    }
}

DesignParameters::DesignParameters(string& paraFile){
    this->wtS1 = 1.0;
    this->wtS2Local = 0.5;
    this->wtS2Nonlocal = 1.0;
    this->wtS2EE = 0.5;

    this->wtCorePacking = 0.72;
    this->wtSurfPacking = 0.05;
    this->packSigma = 0.07;
    this->packSAI0 = 0.65;

    this->nonHBondPolarWeight = 0.6;
    this->repWeight = 1.0;


    this->wtRotEnergy = 1.0;
    this->vdwLamda1 = 0.095;
    this->vdwLamda2 = 0.28;
    this->rvdwRatio = 1.0;
    this->hbLamda1 = 0.1;
    this->hbLamda2 = 0.15;
    this->wdNP_NP = -1.3;
    this->wdP_NP = -0.7;
    this->wdP_P = 0.0;
    this->wdHB = -1.5;
    this->hbAngleFactor = 0.5;
    this->aroWD = -1.4;
    this->nb1Rescale = 1.5;


    string path = NSPdataio::datapath()+"abacus2/";
    string refFile = path + "ref/hecRef9";
    readHECRef(refFile);

    std::string refLocalFile = path + "ref/localRef";
    readRefELocal(refLocalFile);

    ifstream input;
    input.open(paraFile.c_str(), ios::in);
    if(! input.is_open()){
        cout << "fail to open file: " << paraFile << endl;
    }
    string s;
    vector<string> spt;
    while(getline(input,s)){
        splitString(s, " ", &spt);
        if(spt[0] == "CoreWT")
            this->wtCorePacking = atof(spt[1].c_str());
        else if(spt[0] == "SurfWT")
            this->wtSurfPacking = atof(spt[1].c_str());
        else if(spt[0] == "S2Local")
            this->wtS2Local = atof(spt[1].c_str());
        else if(spt[0] == "S2NonLocal")
            this->wtS2Nonlocal = atof(spt[1].c_str());
        else if(spt[0] == "NBPolarWT")
            this->nonHBondPolarWeight = atof(spt[1].c_str());
        else if(spt[0] == "Sai0")
            this->packSAI0 = atof(spt[1].c_str());
        else if(spt[0] == "sigma")
            this->packSigma = atof(spt[1].c_str());
        else if(spt[0] == "hbWD")
            this->wdHB = atof(spt[1].c_str());
        else if(spt[0] == "WD")
            this->wdNP_NP = atof(spt[1].c_str());
        else if(spt[0] == "aroWD")
            this->aroWD = atof(spt[1].c_str());
        else if(spt[0] == "lamda1")
            this->vdwLamda1 = atof(spt[1].c_str());
        else if(spt[0] == "lamda2")
            this->vdwLamda2 = atof(spt[1].c_str());
        else if(spt[0] == "REF"){
            string refFile = path + "ref/" + spt[1];
            readHECRef(refFile);
        }
        else if (spt[0] == "LocalREF") {
            std::string refLocalFile = path + "ref/" + spt[1];
            readRefELocal(refLocalFile);
        }
        else if (spt[0] == "RvdwRatio") {
            this->rvdwRatio = atof(spt[1].c_str());
        }
    }
}

DesignParameters::~DesignParameters() {
    // TODO Auto-generated destructor stub
}

} /* namespace NSPdesignseq */
