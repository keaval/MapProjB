#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <time.h>
#include <map>

using namespace std;

#define maxeFloat 10000000.0f


#define mountainHeight 45000.0     //Scales Mountain Size by this amount
#define pointRadii 420.5           //Increases the number of places (quadratically)
#define crustNu 11                //Number of large, big mountain forming crusts
#define screenW 5000               //Resulting image width(pixels)
#define screenH 2500               //Resulting image height(pixels)
#define screenMargin 10            //White margin arround the image width(pixels)           
#define waterCrust 0.5             //Chance of given crust to be an oceanic one
#define waterationCrustMult 5      //Ratio between crusts and subcrusts
#define crustRandomHeightMax 1000  //Scales the height of minicrusts
#define oceanDepth -8000            //Average depth of oceanic crust
#define oceanSubDepth -400          //Average depth of oceanic subcrust of land crust
#define landSubDepth 2500           //Average height of land subcrust of land crust

#define crustRandomHeightNumA 200  //Number of crusts, when randomization of crusts height is carried out
#define crustRandomHeightNumB 100 
#define crustRandomHeightNumC 60 
#define crustRandomHeightNumD 40 

#define mountCoefPlacingNum 400  //Number of crusts, when places take mountain coef from their crusts
#define mountCoefPlacingPlaceVariation 3.0f //When placing a coef, will add random divided by this for each place 

#define mountDegreeSize 1.0f //Pows the mount force to find mountain height 

#define subCrustSeaMountDivide 7  //lowers mountains, spawned in oceanic subcrust
#define crustSeaMountDivide 7     //lowers mountains, spawned in oceanic crust

#define mountCoefMult 4.5f //divides mount coef by this
#define mountCoefSubMult 1.5f //divides mount coef by this to check if too small
#define mountForceToSpawn 0.97f //if lower, deletes a mount

#define conservativeHeight 0.15f    //Preserves the places height during height stabilisation
#define upStabilisation 6  //Increases the stabilization intake from higher places 
#define stabilisationSpeed 0.3f  //Chnages the rate of stabilisation

#define seaPreserve 150

#define horWindMult 1.5f
#define verWindMult 0.5f


#define townNu 1000                //Number of towns in the world

class cons
{
};

