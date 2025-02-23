#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Player class definition
class Player {
private:
    int number;
    string surname;
    string firstName;
    int height; 
    double weight;
    int points;
    int yearOfBirth;
    int gamesPlayed;
    int gamesWon;
    int gamesTied;

public:
    
    Player()
        : number(0), height(0), weight(0.0), points(0), yearOfBirth(0), gamesPlayed(0), gamesWon(0), gamesTied(0) {}

    
    friend istream& operator>>(istream& in, Player& player) {
        cout << "Enter player number (unique): ";
        in >> player.number;
        cout << "Enter surname: ";
        in >> player.surname;
        cout << "Enter first name: ";
        in >> player.firstName;
        cout << "Enter height (cm): ";
        in >> player.height;
        cout << "Enter weight (kg): ";
        in >> player.weight;
        cout << "Enter year of birth: ";
        in >> player.yearOfBirth;
        player.points = 0; // Initialize points to 0
        player.gamesPlayed = 0;
        player.gamesWon = 0;
        player.gamesTied = 0;
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Player& player) {
        out << player.firstName << " " << player.surname << ", " << player.yearOfBirth << ", " 
            << player.height << "cm, " << player.weight << "kg, participated in " 
            << player.gamesPlayed << " combat games: " << player.gamesWon << " x won, " 
            << player.gamesTied << " x tie = " << player.points << " points";
        return out;
    }

    // Comparison height and weight
    friend bool operator>=(const Player& p1, const Player& p2) {
        if (p1.height >= p2.height && p1.weight >= p2.weight) return true;
        return false;
    }

    // Update player stats
    void updateStats(int result) {
        gamesPlayed++;
        if (result == 10) gamesWon++;
        else if (result == 5) gamesTied++;
        points += result;
    }

    
    string getName() const { return firstName + " " + surname; }

    int getGamesPlayed() const { return gamesPlayed; }

    int getPoints() const {return points;}
};

// Menu 
void displayMenu() {
    cout << "\nCombat Game Management Menu:\n"
         << "1. Create playe\n"
         << "2. Manag combat game\n"
         << "3. Display all players\n"
         << "4. Display winner\n"
         << "5. Exit programm\n"
         << "Enter your choice: ";
}

// Find player by number
Player* findPlayer(vector<Player*>& players, int number) {
    for (Player* player : players) {
        if (player->getName().find(to_string(number)) != string::npos) {
            return player;
        }
    }
    return nullptr;
}

int main() {
    vector<Player*> players;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            if (players.size() < 6) {
                Player* newPlayer = new Player();
                cin >> *newPlayer;
                players.push_back(newPlayer);
                cout << "Player created successfuly!\n";
            } else {
                cout << "Maximum players reached, Cannot create more players.\n";
            }
            break;
        }
        case 2: {
            int num1, num2, result;
            cout << "Enter the number of Player 1: ";
            cin >> num1;
            cout << "Enter the number of Player 2: ";
            cin >> num2;

            Player* player1 = findPlayer(players, num1);
            Player* player2 = findPlayer(players, num2);

            if (player1 && player2 && player1 != player2) {
                if (player1->getGamesPlayed() < 3 && player2->getGamesPlayed() < 3) {
                    cout << "Enter fight result (10 = Player 1 wins, 5 = Tie, 0 = Player 2 wins): ";
                    cin >> result;

                    if (result == 10 || result == 5 || result == 0) {
                        player1->updateStats(result);
                        player2->updateStats((result == 10) ? 0 : (result == 5 ? 5 : 10));

                        if (result == 10) cout << player1->getName() << " wins!\n";
                        else if (result == 5) cout << "It's a tie!\n";
                        else cout << player2->getName() << " wins!\n";

                        if (*player1 >= *player2) {
                            cout << player1->getName() << " is taller and/or heavier than " << player2->getName() << ".\n";
                        } else {
                            cout << player2->getName() << " is taller and/or heavier than " << player1->getName() << ".\n";
                        }
                    } else {
                        cout << "Invalid result entered.\n";
                    }
                } else {
                    cout << "One or both players have already participated in 3 games.\n";
                }
            } else {
                cout << "Invalid player numbers.\n";
            }
            break;
        }
        case 3: {
            cout << "Player Data:\n";
            for (Player* player : players) {
                cout << *player << endl;
            }
            break;
        }
        case 4: {
            Player* winner = nullptr;
            for (Player* player : players) {
                if (!winner || player->getPoints() > winner->getPoints()) {
                    winner = player;
                }
            }
            if (winner) {
                cout << "The winner is:\n" << *winner << endl;
            } else {
                cout << "No players available.\n";
            }
            break;
        }
        case 5: {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    for (Player* player : players) {
        delete player;
    }

    return 0;
}
