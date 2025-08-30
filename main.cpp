#include <iostream>
#include <vector>
using std::vector;
using std::string;
//River Cross Problem program inspired from the anime Dr. Stone: Science Future Part 2 Episode 5
//Made by: WhosWho
//Last edited: August 30th 2025
short int counter = 0; //Count the hints given
bool chick_across = false; //Check if the chicken is across the river
bool fox_across = false; //Check if the fox is across the river
bool corn_across = false; //Check if the corn is across the river
bool win = false; //Decide if the player won or not
vector <string> allchoices; //Take note of the choices made
vector <string> items; //Items across the river
vector <string> itemsB = {"Chicken", "Fox", "Corn"}; //Items who have not crossed the river
string r; //Choose to return with an item
string i; //The item to return with
void river();
void returning();
void above() {
    std::cout<<"                                            ";
    for (string t : items) {
        std::cout<<t<<"    ";
    }
    std::cout<<std::endl;
}

void below() {
    std::cout<<"                                            ";
    for (string t : itemsB) {
        std::cout<<t<<"    ";
    }
    std::cout<<std::endl;
}
void choice() {
        string c; //Choose to take an item across
        std::cout<<"                                What will you choose to take across the river?"<<std::endl<<std::endl;
        if (!corn_across) {
            std::cout<<"                                      The corn? [c]";
        }
        else {
            std::cout<<"                                                   ";
        }
        if (!fox_across) {
            std::cout<<"           The fox? [f]"<<std::endl<<std::endl;
        } else {
            std::cout<<std::endl<<std::endl;
        }
        if (!chick_across) {
            std::cout<<"                                               Or the chicken? [k]"<<std::endl<<std::endl;
        }
        std::cout<<"                                                     Extra: "<<std::endl;
        std::cout<<"                                    See hint [h]";
        std::cout<<"             Full solution [s]"<<std::endl<<std::endl;
        std::cout<<"- Your choice: ";
        //Validate user input
        std::cin>>c;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        while (!(c.size()==1)) {
            std::cout<<"[!] Unknown item. Try writing the correct initial as provided."<<std::endl;
            std::cout<<"- Your choice: ";
            std::cin>>c;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if (c == "c") {
             if (!corn_across) {
                allchoices.push_back("c");
                if (fox_across) {
                    win = true;
                }
                if (allchoices[0] != "c") {
                    items.push_back("Corn");
                    itemsB.erase(itemsB.begin()+1); //itemsB should be Chicken Corn, so erase corn
                    corn_across = true;
                    river();
                    if (chick_across) {
                        std::cout<<"[2] You took the corn across the river."<<std::endl<<std::endl;
                        counter = 2; //Counter is now 2
                        returning();
                    }

                } else {
                   std::cout<<"[X] Looks like you left the chicken alone with the fox. Guess what happened next..."<<std::endl;
                }

             }
             else {
                // If the corn is already cross the river, prompt the player to insert another item
                std::cout<<"[!] The corn is already across the river! Choose something else to take with you!"<<std::endl<<std::endl;
                choice();
             }
        } else if (c == "f") {
            if (!fox_across) {
                allchoices.push_back("f");
                if (corn_across) {
                    win = true;
                }
                if (allchoices[0] != "f") {
                    items.push_back("Fox");
                    if (corn_across) {
                        itemsB.erase(itemsB.begin()+1); //Fox will be now first
                    }
                    else {
                        itemsB.erase(itemsB.begin()); //Fox will be now first
                    }
                    fox_across = true;
                    river();
                    if (chick_across) {
                        std::cout<<"[2] You took the fox across the river."<<std::endl<<std::endl;
                        counter = 2; //Counter is now 2
                        returning();
                    }
                } else {
                    std::cout<<"[X] Corn? What even is that? I haven't seen it around."<<std::endl;
                }

            } else {
                // If the fox is already cross the river, prompt the player to insert another item
                std::cout<<"[!] The fox is already across the river! Choose something else to take with you!"<<std::endl<<std::endl;
                choice();
            }

        } else if (c == "k") { // If the player chooses the chicken
            if (!chick_across) {
                // And the chicken is not across, add it to the solution vector
                allchoices.push_back("k");
                items.push_back("Chicken");
                itemsB.erase(itemsB.begin()); // itemsB has Chicken first at this time
                chick_across = true;
                if (allchoices[1] == "k") {
                        items[0] = "Chicken";
                        if (fox_across) {
                            items[1] = "Fox";
                        }
                        if (corn_across) {
                            items[1] = "Corn";
                        }
                        river();
                        returning();
                }
            }
            else {
                // If the chicken is already across the river, prompt the player to insert another item
                std::cout<<"[!] The chicken is already across the river! Choose something else to take with you!"<<std::endl<<std::endl;
                choice();
            }
        } else if (c == "h") {
            switch (counter) {
                case 0:
                    std::cout<<"[?] Hint 1: Cross the river with a domestic animal"<<std::endl<<std::endl;
                    choice();
                    break;
                case 1:
                    std::cout<<"[?] Hint 2: Bring the middle or the third icon across the river"<<std::endl<<std::endl;
                    choice();
                    break;
                case 2:
                    std::cout<<"[?] Hint 3: Take the animal with wings back and swap it with the corn or the fox, then cross the river"<<std::endl<<std::endl;
                    choice();
                    break;
                case 3:
                    std::cout<<"[?] Hint 4: Take the corn or the fox back if available."<<std::endl<<std::endl;
                    choice();
                    break;
                default:
                    std::cout<<"[!] Already given all the hints. Read the full solution if you wanna review them."<<std::endl<<std::endl;
                    choice();
            }
        } else if (c == "s") {
            std::cout<<R"(
                 .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.
                / .. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \
                \ \/\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ \/ /
                 \/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\/ /
                 / /\      oo_       .-.    W  W    wWw  wWw(o)__(o)wW  Ww    .-.   \\\  ///     / /\
                / /\ \    /  _)-<  c(O_O)c (O)(O)   (O)  (O)(__  __)(O)(O)  c(O_O)c ((O)(O))    / /\ \
                \ \/ /    \__ `.  ,'.---.`,  ||     / )  ( \  (  )   (..)  ,'.---.`, | \ ||     \ \/ /
                 \/ /        `. |/ /|_|_|\ \ | \   / /    \ \  )(     ||  / /|_|_|\ \||\\||      \/ /
                 / /\        _| || \_____/ | |  `. | \____/ | (  )   _||_ | \_____/ ||| \ |      / /\
                / /\ \    ,-'   |'. `---' .`(.-.__)'. `--' .`  )/   (_/\_)'. `---' .`||  ||     / /\ \
                \ \/ /   (_..--'   `-...-'   `-'     `-..-'   (             `-...-' (_/  \_)    \ \/ /
                 \/ /                                                                            \/ /
                 / /\                                                                            / /\
                / /\ \                                                                          / /\ \
                \ \/ /         First, the traveler crosses the river with the chicken.          \ \/ /
                 \/ /          Then he goes back and crosses with the fox.                       \/ /
                 / /\          He takes the chicken back and brings the corn across.             / /\
                / /\ \         He returns for the chicken and crosses again.                    / /\ \
                \ \/ /                                                                          \ \/ /
                 \/ /                                                                            \/ /
                 / /\                                                                            / /\
                / /\ \         Like this, he managed to cross with all 3 things undamaged!      / /\ \
                \ \/ /                                                                          \ \/ /
                 \/ /                                                                            \/ /
                 / /\.--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--./ /\
                / /\ \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \.. \/\ \
                \ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `'\ `' /
                 `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--' )";
                 std::cout<<std::endl<<std::endl;
                 choice();
        } else {
            std::cout<<"[!] Unknown item. Try writing the correct initial as provided."<<std::endl<<std::endl;

            choice();
        }

}

void item() {
    std::cin>>i;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    while (!(i.size() == 1)) {
           std::cout<<"[!] Not an available item. Make sure you wrote the proper initial."<<std::endl;
            std::cout<<"- Your choice: ";
            std::cin>>i;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    if (i == "k") {
            if (chick_across) {
                    counter++;// Counter is now 3
                    //Once the chicken and fox are both across the river (2nd step)
                    if (fox_across) {
                        std::cout<<"[3] You chose to return with the chicken."<<std::endl;
                        chick_across = false;
                        itemsB.push_back("Chicken"); //itemsB should look like Corn Chicken
                        //Reverse order
                        itemsB[0] = "Chicken";
                        itemsB[1] = "Corn";
                        items.erase(items.begin());
                        allchoices.pop_back();
                        river();
                    }
                    //Once the chicken and corn are both across the river (2nd step)
                    if (corn_across) {
                        std::cout<<"[3] You chose to return with the chicken."<<std::endl;
                        chick_across = false;
                        itemsB.push_back("Chicken"); //itemsB should look like Fox Chicken
                        //Reverse order
                        itemsB[0] = "Chicken";
                        itemsB[1] = "Fox";
                        items.erase(items.begin());
                        allchoices.pop_back();
                        river();
                    }
            }
            choice();


    } else if (i == "f") {
        if (fox_across) {
            std::cout<<"You chose to return with the fox."<<std::endl;
            allchoices.pop_back();
            fox_across = false;
            items.pop_back(); //Remove Fox from above
            itemsB.push_back("Fox"); //Down should be Corn Fox, so reverse it
            itemsB[0] = "Fox";
            itemsB[1] = "Corn";
            river();
            choice();
        } else {
           std::cout<<"[!] There's no fox across the river though. Try again: ";
           item();
        }

    } else if (i == "c") {
        if (!corn_across) {
           std::cout<<"[!] There's no corn across the river though. Try again: ";
           item();
        } else {
            std::cout<<"You chose to return with the corn."<<std::endl;
            allchoices.pop_back();
            corn_across = false;
            items.pop_back(); //Remove corn from above
            itemsB.push_back("Corn"); //Add Corn below, and should be Fox Corn. Keep it as it is
            river();
            choice();
        }
    }
    else {
        std::cout<<"[!] Not an available item. Make sure you wrote the proper initial."<<std::endl;
        std::cout<<"- Your choice: ";
        item();
    }
}
void returning() {
    std::cout<<"Would you like to return something back?"<<std::endl;
    if (chick_across) {
        std::cout<<"Current options: Chicken [k]";
        if (fox_across) {
            std::cout<<", Fox[f]"<<std::endl;
        }
        if (corn_across) {
            std::cout<<", Corn[c]"<<std::endl;
        }
    }
    std::cout<<std::endl;
    //Validate user input
    std::cout<<"- Your choice [y/n]: ";
    while (!(std::cin>>r)) {
        std::cout<<"[!] Not an available command. Try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    while (!(r.size() == 1)) {
        std::cout<<"[!] Not an available command. Try again: ";
        std::cin>>r;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    if (r == "y") {
        std::cout<<"Write the initial for the respective item, as provided above: ";
        item();
    } else if (r == "n" && !win) {
        std::cout<<"You've returned back alone."<<std::endl;
        if (fox_across && chick_across) {
            std::cout<<"[!] The fox ate the chicken."<<std::endl;
            std::cout<<"[X] Seems like the fox had quite the feast... amazing choice if I dare say so myself."<<std::endl;
        }
        if (chick_across && corn_across) {
            std::cout<<"[!] The chicken ate the corn."<<std::endl;
            std::cout<<"[X] Never imagined you'd leave an innocent corn behind. It will forever haunt you for that."<<std::endl;
        }
    } else {
        returning();
    }
}
void river() {
    //Writing above
    above();
    std::cout<<R"(
               --------------------------------------------------------------------------------------
               ~~~~~~~~~~~~~~~ ~~~~~~       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             ~~~~~~

               ~~~~~~    ~~          ~~~~~~~~~~~~~~            ~~~~~~~~~~~~~~~~~~~     ~~~~       ~~
               ~~~           ~~     ~~~~~~~      ~~~~~~~~~~~~     ~~       ~~~~~~~~~~~~~~~~~~~~~

                    ~~~~~~~    ~~~~~~~~~~~~~~~~~~      ~~~     ~~~~~~~~~~~~         ~~~~~~~~

                ~~~     ~~~~~~~     ~~~     ~~~~~~~~       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       ~
               -------------------------------------------------------------------------------------)";
    std::cout<<std::endl;
    //Writing below
    below();
    std::cout<<std::endl<<std::endl;
}
class Game {
public:

    Game() {
        std::cout<<R"(
                            .-,--.                  ,--.                  .-,--.             .
                             `|__/ . .  , ,-. ,-.  | `-' ,-. ,-. ,-. ,-.   '|__/ . . ,_, ,_, |  ,-.
                             )| \  | | /  |-' |    |   . |   | | `-. `-.   ,|    | |  /   /  |  |-'
                             `'  ` ' `'   `-' '    `--'  '   `-' `-' `-'   `'    `-^ '"' '"' `' `-')";
        std::cout<<std::endl<<std::endl;
        std::cout<<"// River Cross Puzzle inspired from the anime Dr. Stone: Science Future Part 2 Episode 5"<<std::endl;
        std::cout<<"// Program by: WhosWho"<<std::endl;
        std::cout<<"// Github: github.com/whoswho32"<<std::endl;
        std::cout<<R"(
        @@@@@@@@@@@@@@@@@&#&@@@@@@@@@@          ~Y57            75Y~           @@@@@@@@@@BPPG#@@@@@#GBPYP55&@
        @@@@@@@@@@#5JJ5G5J??Y&@@@@@@@@         ?@BP##J^      ^Y##PB@7          @@@@@@@@@@#GJJYB5P5J~^~~~~~~Y@
        @@@@@@&##BJ?????????J&@@@@@@@@         Y@PJJ5B&P!^^!P&B5JJP@J          @@@@@@@@@@@GJJJ??7^~~~~~!~~~?@
        @@@@@G??7!^^^::^^~!Y&@@@@@@@@@         J@PYYYJYG#BB#GYJYYYP@J          @@@@@@@@@#5JJ??~^??~^!!~~~!7B@
        @@@@@#Y?^~!777~::::^7G@@@@@@@@         J@PYJJ???JJJJ???JJYP@J          @@@@@@@&PYJ?7^JY!5!~7!!!~!!Y@@
        @@@&BPY77?YBGJ?~.:::.:!B@@@@@@         Y@5?JGBYJJJJJJYBGJ?5@Y          @@@@@@BYJ?!^~!~77777^!?J7?J5B@
        @BJ!!!!!!7J55?7^:..:::.:Y@@@@@        7@57JY@@G?JJJJ?G@@YJ75@7         @@@@&5JJ7^^!!~?J!~7P?JYYY5B@@@
        @&####G???7~~^::::::::::.J@@@@       7@J  ^!YPYJJJJJJYPY!^  J@7        @@@#YJ7^~!!~^~!J?!?Y5YYYYYY5&@
        @@@@@&????!:: .:::.::..::.5@@@      7&&P!    :~JJJJJJ~:    !G&&7       @@@5J7~~!~^~~!7?JYYYJJYPB#B5&@
        @@@@@&Y??7^:::::::.::::::::B@@      ^P@&YYYYJ~ !JJJJ! ~JYYYY&@P^       @@&Y7~~~~~~!?JJJJJJY5B&@@@@@@@
        @@@@@@@P::::::::::::::::::.~&@       !!77!!75@7^P##P:7@57!!77!!        @@@5?!!!!?JJJJJJY5P#@@@@@@@@@@
        @@@@@@@#:~?^:::^^::::^:::!?~5@              ^@P .77  P@^               @&BPYJJJJJJJJJYPB&@@@@@@@@@@@@
        @@@@@@@@P&@B?^7GP7^:?BP7J&@@&@               7#G?!!?G#7                @GYJ55GGPPPPG#&@@@@@@@@@@@@@@@
        @@@@@@@@@@@@@#@@@@BG@@@@@@@@@@                :!Y55Y!:                 @@@#B#@@@@@@@@@@@@@@@@@@@@@@@@
        )";
        std::cout<<std::endl<<std::endl;
        std::cout<<"                                           - The premise of the puzzle -"<<std::endl;
        std::cout<<R"(
                    .---------------------------------------------------------------------------.
                    |                                                                           |
                    |                        ___  ____  _____  ____  _  _                       |
                    |                       / __)(_  _)(  _  )(  _ \( \/ )                      |
                    |                       \__ \  )(   )(_)(  )   / \  /                       |
                    |                       (___/ (__) (_____)(_)\_) (__)                       |
                    |                                                                           |
                    |                                                                           |
                    |    You're a traveler trying to bring your possessions across a river.     |
                    |    You have 3 things: corn, a fox, and a chicken.                         |
                    |    But you can only bring one thing at a time                             |
                    |                                                                           |
                    |                                                                           |
                    |    However:                                                               |
                    |                                                                           |
                    |    1. If you leave the fox and chicken behind,                            |
                    |    the fox will eat the chicken.                                          |
                    |                                                                           |
                    |    2. If you leave the corn and chicken behind,                           |
                    |    the chicken will eat the corn.                                         |
                    |                                                                           |
                    |                                                                           |
                    |    You have to make it across the river with all 3 things.                |
                    |                                                                           |
                    |                                                                           |
                    '---------------------------------------------------------------------------'
                      )";
        std::cout<<std::endl;
        river();
        choice();

 if (allchoices[0] == "k") {
    //First step towards completion
    std::cout<<"[1] You took the chicken across the river, then returned to the fox and corn."<<std::endl<<std::endl;
    chick_across = true;
    counter++; //Counter is 1 now
    river();
    choice();
}
    //Case 1: If Chicken and Fox are up and only Corn is left
if (win) {
    if (allchoices[1] == "c") {
        items.push_back("Corn");
        //Rearrange the items
        items[0] = "Chicken";
        items[1] = "Fox";
        items[2] = "Corn";
        itemsB.erase(itemsB.begin()); //Only Chicken should be left
        std::cout<<"[4] You bring the corn with you across the river."<<std::endl;
        std::cout<<"[5] Then you return for the chicken and therefore manage to successfully bring all your possessions with you!"<<std::endl<<std::endl;
        std::cout<<"                Congratulations! You managed to solve the River Cross Puzzle!"<<std::endl<<std::endl;
        river();
    }
    //Case 2: If Chicken and Corn are up and only Fox is left
    else if (allchoices[1] == "f") {
        items.push_back("Fox");
        //Rearrange the items
        items[0] = "Chicken";
        items[1] = "Fox";
        items[2] = "Corn";
        itemsB.erase(itemsB.begin()); //Only Chicken should be left
        std::cout<<"[4] You bring the fox with you across the river."<<std::endl;
        std::cout<<"[5] Then you return for the chicken and therefore manage to successfully bring all your possessions with you!"<<std::endl<<std::endl;
        std::cout<<"                Congratulations! You managed to solve the River Cross Puzzle!"<<std::endl<<std::endl;
        river();
    }

}
}
};
int main()
{
    Game start;
}
