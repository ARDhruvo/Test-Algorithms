/*
 * Author @ARDhruvo
 * Initial Completion Date: 05/12/25
 *
 * Upgrade Ideas:
 * - Add score tracker
 * - Add boss after every 10 waves
 * - Add seed updater for every boss
 * - Add powerups
 */

#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl

map<int, string> choice = {{0, "Scissors"}, {1, "Rock"}, {2, "Paper"}, {3, "Scissors"}};
stack<int> seed;

int wave = 1;

// Starting Game:

void botSeed()
{
    cout << "Current Seed: ";
    for (int i = 0; i < 10; i++)
    {
        int bot = rand() % 3;
        cout << bot;
        seed.push(bot);
    }
    paragraph;
}

// Waves:

int botChoice()
{
    int choice = seed.top();
    seed.pop();
    return choice;
}

void win()
{
    cout << "You win!" << endl;
    wave++;
    paragraph;
    return;
}

void lose()
{
    cout << "You lose!" << endl;
    while (!seed.empty())
    {
        seed.pop();
    }
    paragraph;
    return;
}

void playGame()
{
    wave = 1;
    botSeed();

    while (!seed.empty())
    {
        cout << "Wave " << wave << endl;
        paragraph;

        cout << "Pick your choice:\n1 = Rock\n2 = Paper\n3 = Scissors" << endl;
        int playerChoice = 0;
        cin >> playerChoice;
        paragraph;

        int bot = botChoice();

        cout << "You chose: " << choice[playerChoice] << endl;
        cout << "Bot chose: " << choice[bot] << endl;
        paragraph;

        if (choice[playerChoice] == choice[bot])
        {
            cout << "Its a draw!" << endl;
            bot = rand() % 3;
            seed.push(bot);
        }
        else if ((playerChoice < bot) || (playerChoice == 2 && bot == 0) || (playerChoice == 3 && bot == 1))
        {
            lose();
            return;
        }
        else
        {
            win();
        }
    }
}

int main()
{
    bool play = true;
    srand(time(0));

    while (play)
    {
        playGame();
        cout << "Continue?\nType in\n1 = Yes\n2 = No" << endl;
        int cont;
        cin >> cont;
        paragraph;
        if (cont == 2)
        {
            break;
        }
        paragraph;
    }
}
