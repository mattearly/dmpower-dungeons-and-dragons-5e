//
//  name_gen.cpp
//  DM-Power
//
//  Created by Matthew Early on 6/22/15.
//  Copyright (c) 2015 athenstechgiants. All rights reserved.
//

#include "name_gen.h"
#include <fstream>

using namespace std;

string CharacterName::grabRandomName() {

    ifstream fileOfNames;
    string tmpName;
    fileOfNames.open("names.dat");
    if (fileOfNames.is_open()) {
        auto chosenSeed = randomNumber(1, 7732);
        for (auto i = 1; i < chosenSeed; i++) {
            fileOfNames.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(fileOfNames, tmpName, '\n');
    }
    return tmpName;

}