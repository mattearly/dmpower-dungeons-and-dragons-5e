# dmpower

A Dungeons & Dragons 5th edition toolkit intended for Dungeon Master's use. Its primary use is to hasten game prep and on the fly assistance. Runs in your terminal window and prompts all available options.

This is something I wrote in college while learning C++ and Computer Science.

## Core Feature

### 5th Edition Characters (PCs or NPCs)

- All 12 core PHB + DMG classes fully available. 
- 22 different races including all core subraces. 
- Meticulously programmed level class trees. 
- Integrated level up system supports levels 1 to 20. 
- Random name suggestions.
- Common starter stat rolling options (3d6, 4d6 drop lowest, point buy). 
- All core backgrounds + custom background option
- All skills
- Enough languages to shake a stick at.
- All core feats. 
- Average HP for both npcs + pcs(pcs start with max first level HP in most common rule)
- Spell slots for your current level and spec.
- Save/Load campaigns (which is basically a set of characters).
- Character Editor for leveling up existing characters.
- DM Power: Edit stats (min=1, max=30), give feats, give skills, change name, change alignment.

#### Limitations

- Character Builder doesn't handle equipment, spell memorization choices, multiclassing, or personality traits. NPC classes (warrior, expert, aristocrat) from the DMG are also not included.

## Other Features

### Loot and Randomizers

- Randomized Loot (based on the charts in the DM Guide). Hoard loot is pretty fun to role, and great for populating lairs/dungeons/poi's.
- Spellbook Generator to assist with the DM's nightmare that is populating an NPC Wizard Spellbook.
- Scrolls auto-generate to spells.

### More Various Tools

- Random Name Generator. Names from [Kisment's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf). Custom Editable [config file](data/lists/lists/names.dat).
- XP Calculator.
- Insult Generator. Has clean and dirty mode. Easily adapted to new words by editing the settings file [data/lists/insults-dirty.dat](data/lists/insults-dirty.dat) or [data/lists/insults-clean.dat](data/lists/insults-clean.dat) - just note that if you change the number of words in that file, it must be adjusted in the code as well, you'll find the number of words hardcoded in [src/gen_insult.cpp](src/gen_insult.cpp) (to be improved later to be more adaptable and automatic for varying sizes like the name generator already does).
- Random Encounters. Difficulty Generator that accounts for all party member levels and group size, generates an appropriate Challenge Rating even for the oddest of groups. Seeded from -2 to +2 representing _Very Easy_, _Easy_, _Normal_, _Hard_, _Very Hard_. I'm not sure that this is all that useful yet, I would like to add in mob group generators based on location.
- Charts. There always seems to be at least one player interested in using poison. Madness can be useful in many cases (causing scenarios, things for the PC's to deal with, etc).
  - Level Up chart
  - Poison Prices chart
  - Madness chart
  - Diseases chart
  - Player problem resolution flowchart walkthrough (based off of and credits to the creator for the idea [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

## Building dmpower

#### Dependencies

- make `make`
- C++14 `g++`
- boost filesystem `libboost-filesystem-dev`

### Run on Linux

1. `git clone https://github.com/mattearly/dmpower` clone this repo (or go to releases and pick a version, or clone however you are comfortable cloning. I would suggest forking if you are going to work on it and make pull requests.)
2. `cd dmpower` change directory to where you downloaded the files
3. `make run` use this make command to build the program and run it after the build finishes. This is the same as just using `make` and then `./dmpower` afterwords.

Use `make help` to see other options.

Install dependencies if something fails to build, error messages should tell you what you need and it is likely one of the above dependencies.

### Run on Windows

Use [Cygwin](https://www.cygwin.com/), or [WSL](https://msdn.microsoft.com/commandline/wsl/about), or mingw, or Powershell. Pretty much anything you can get the dependencies on it will work with.

- If you are using Cygwin, you will need the packages `gcc-core`, `make`, `libboost-devel`, and of course `git` for the git clone command, then it should work just like the linux build and run above.
- In case of using the Powershell terminal, you will need to activate the ansi color escape with this command:
  - `Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1`
  - [more discussion on this topic](https://stackoverflow.com/questions/51680709/colored-text-output-in-powershell-console-using-ansi-vt100-codes)

### Run on Mac

About the same as Linux afaik. May need homebrew for boost libraries.

#### Some Screenshots

*Screenshots taken on Windows Cygwin64 with green default text and black background. Your experience will vary depending on your terminal settings.*

[screenshots imgur link](https://imgur.com/a/S3t73rI)

## Sources

### Books

- [Player's Handbook](http://dnd.wizards.com/products/tabletop-games/rpg-products/rpg_playershandbook)
- [Dungeon Master's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/dungeon-masters-guide)
- [Sword Coast Adventurer's Guide](http://dnd.wizards.com/products/tabletop-games/rpg-products/sc-adventurers-guide)
- [Volo's Guide to Monsters](http://dnd.wizards.com/products/tabletop-games/rpg-products/volos-guide-to-monsters)
- [Wayfinder's Guide to Eberron](https://www.dmsguild.com/product/247882/wayfinders-guide-to-eberron-5e)
- [The Tortle Package](https://www.dmsguild.com/product/221716/Tortle-Package-5e)
- [Elemental Guide of Evil](https://www.dmsguild.com/product/145542/Elemental-Evil-Players-Companion-5e)

### Internet

- [Kismet's Name List](http://www.dnd.kismetrose.com/MyCharacterNameList.html)
- [Resolving Basic Behavioral Problems in your Tabletop RPG Group: A Flowchart](https://www.reddit.com/r/rpg/comments/3avp57/resolving_basic_behavioral_problems_in_your/)

## Notes

### Legal

This project and I are not affiliated with Wizards of the Coast or Hasbro. This project was something I personally made to assist with my DMing. Due to the nature of the game data being used for this software, dmpower is not to be used for any form of profit or sale.

### Development

In development branch named buildXX.

Master branch has latest release.

New versions are tagged with release notes when pushed to master, see the [tags/releases](https://github.com/mattearly/dmpower/releases) for all versions with release notes.

## Special Thanks

For those getting involved in the project and helping out at times! It does mean a lot. Thanks. -Matt
