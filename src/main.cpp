/**
____________________________________________________________________________
>
>  https://github.com/bytePro17124/DM-Power-Core-Version
>
>  Program Created by Matthew Jay Early | @matthewjearly | matthewjearly@gmail.com
>  
>  Copyright (c) 2015-2017 Early Athens Tech Giants LLC. All rights reserved.
>
____________________________________________________________________________
**/

#include "campaign.h"
#include "gen_reward.h"
#include "gen_name.h"
#include "gen_insult.h"
#include "gen_encounter.h"
#include "gen_experience.h"
#include "charts.h"
#include <fstream>
#include <cstdlib>

using namespace std;

void load_file(bool &, string &, Campaign &);
void save_file(bool &, string &, const Campaign &);

int main()
{
    bool loadSuccess = 0;
    string loadedFile = "";
    simpleClearScreen();
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "|" << YELLOW << "Dungeon Master POWER " << RESET << "- " << RED << "Dungeons & Dragons " << RESET << "- " << CYAN << "5e Core Version" << RESET << "|" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    cout << "| * Design & Code by:  " << GREEN << "matthewjearly@gmail.com" << RESET << "              |" << endl;
    cout << "| * Repo:  " << GREEN << "github.com/mattearly/DM-Power-Core-Version" << RESET << "       |" << endl;
    cout << "|-----------------------------------------------------------|" << endl;
    int choice = 0;
    Campaign mygame;
    load_file(loadSuccess, loadedFile, mygame);
    do
    {
        cout << YELLOW << "\n---------- MAIN MENU ----------\n"
             << RESET
             << "1. Characters\n"
             << "2. Magic Item and Loot Generators\n"
             << "3. Charts\n"
             << "4. Experience Calculator\n"
             << "5. Name Generator\n"
             << "6. Random Encounter\n"
             << "7. NPC Insult\n"
             << "8. Save Current\n"
             << "9. Save & Quit\n"
             << "10. Quit without Saving\n"
             << YELLOW << "-------------------------------\n"
             << RESET
             << endl;
        choice = getNumber("Choice: ", 1, 10);

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
            mygame.pc_menu();
            break;
        case 2:
        {
            Magic_Items gen;
            gen.treasure_menu();
        }
        break;
        case 3:
        {
            Charts chart;
            chart.showChartMenu();
        }
        break;
        case 4:
        {
            Gen_Experience gen;
            float rewardXP = gen.xpgenerator();
            cout << "EXP for Each Party Member = " << GREEN << rewardXP << RESET << "\n\n";
        }
        break;
        case 5:
        {
            CharacterName randomName;
            simpleClearScreen();
            cout << "Here is a name: " << randomName.grabRandomName() << "\n\n";
        }
        break;
        case 6:
        {
            Encounter encounter;
            simpleClearScreen();
            cout << encounter.Gen_Encounter();
            pressEnterToContinue();
        }
        break;
        case 7:
        {
            Insult insult;
            simpleClearScreen();
            cout << "Maybe this will make the PCs mad: " << insult.laydownheat() << "\n\n";
        }
        break;
        case 8:
            save_file(loadSuccess, loadedFile, mygame);
            break;
        case 9:
            save_file(loadSuccess, loadedFile, mygame);
            cout << "Exiting Program.\n";
            break;
        case 10:
            cout << "Exiting Program.\n";
        default:
            break;
        }
    } while (choice < 9);
    return EXIT_SUCCESS;
}

void load_file(bool &ls, string &lf, Campaign &game)
{
    string file;
    ifstream thefile;
    cout << "\n|----------------- press enter to skip load ----------------|\n"
         << endl;
    cout << "Load File: ";
    getline(cin, file, '\n');
    thefile.open(("saves/" + file + ".save").c_str());
    if (thefile.is_open())
    {
        bool success = game.retrieveCharacter(thefile);

        simpleClearScreen();
        if (success)
        {
            cout << "File '" << file << "' loaded.\n\n";
        }
        else
        {
            cout << "The file named '" << file << "' doesn't seem to have much data or is invalid\n\n";
        }
        ls = true;
        lf = file;
        thefile.close();
    }
    else
    {
        simpleClearScreen();
        cout << "No file named '" << file << "'. Starting new file.\n\n";
    }
}

void save_file(bool &ls, string &lf, const Campaign &game)
{
    string file;
    ofstream os;
    if (ls == false)
    {
        cout << "Save As: ";
        getline(cin, file, '\n');
    }
    else
    {
        file = lf;
    }
    //save into file after above is complete
    os.open(("saves/" + file + ".save").c_str());
    if (os.is_open())
    {
        game.dumpCharacter(os);
        cout << "All data saved in file -> " << file << endl;
        ls = true;
        lf = file;
        os.close();
    }
    else
    {
        cout << "Save failed.\n";
    }
}
