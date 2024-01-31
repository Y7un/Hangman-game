#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string chooseWord() {
    vector<string> words = { "programming","hangman","computer","cplusplus","engineer"};
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

string displayWords(const string& word, const vector<char>& guessedLetters) {
    string display;
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
        {
            display += letter;
        }
        else
        {
            display += '_';
        }
    }
    return display;
}

bool isGuessCorrect(char guess, const string& word) {
    return(word.find(guess) != string::npos);
}

int main()
{
    const int maxAttempt = 6;
    int attemptsLeft = maxAttempt;

    string selectedWord = chooseWord();
    vector<char> guessedLetters;

    cout << "Welcome to hangman game!\n";

    while (attemptsLeft > 0) {
        cout << "Word: " << displayWords(selectedWord, guessedLetters) << endl;
        cout << "Attempts left: " << attemptsLeft << endl;

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        if (isGuessCorrect(guess, selectedWord)) {
            cout << "Correct guess!\n";
        }
        else {
            cout << "Incorrect guess.Try Again.\n";
            attemptsLeft--;
        }

        guessedLetters.push_back(guess);

        if (displayWords(selectedWord, guessedLetters) == selectedWord) {
            cout << "Congratulations! You've guessed the correct word!: " << selectedWord << endl;
            break;
        }

        if (attemptsLeft == 0) {
            cout << "Sorry, you have ran out of attempts.The word was: " << selectedWord << endl;
        }

        return 0;
    }
}



