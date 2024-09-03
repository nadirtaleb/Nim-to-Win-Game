#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the heaps
void displayHeaps(const vector<int>& heaps) {
    char heapName = 'A';
    for (int heap : heaps) {
        cout << heapName << ": ";
        for (int j = 0; j < heap; j++) {
            cout << "O ";
        }
        cout << endl;
        heapName++;
    }
    cout << endl;
}

// Function to check if the game is over
bool isGameOver(const vector<int>& heaps) {
    for (int heap : heaps) {
        if (heap > 0) {
            return false;
        }
    }
    return true;
}

// Function to play a turn
void playTurn(vector<int>& heaps, const string& playerName) {
    displayHeaps(heaps);
    char chosenHeap;
    int removedObjects;

    cout << playerName << ", choose a heap (A, B, C, etc.): ";
    cin >> chosenHeap;
    cout << playerName << ", how many objects to remove from heap " << chosenHeap << "? ";
    cin >> removedObjects;

    int heapIndex = chosenHeap - 'A';
    if (removedObjects > 0 && removedObjects <= heaps[heapIndex]) {
        heaps[heapIndex] -= removedObjects;
    } else {
        cout << "Invalid move. Try again." << endl;
        playTurn(heaps, playerName); // Recursive call for invalid move
    }
}

// Function for the computer's turn in PC vs. user mode
void computerTurn(vector<int>& heaps) {
    // Simple strategy: remove from the first non-empty heap
    for (int i = 0; i < heaps.size(); i++) {
        if (heaps[i] > 0) {
            heaps[i]--; // Remove one object
            cout << "Computer removed 1 object from heap " << char('A' + i) << endl;
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation

    int choice;
    cout << "Choose an option:\n"
         << "1- Two players (user vs. user)\n"
         << "2- Two players (PC vs. user)\n"
         << "3- Exit\n";
    cin >> choice;

    if (choice == 1 || choice == 2) {
        string player1, player2;
        cout << "Enter Player 1's name: ";
        cin >> player1;

        if (choice == 1) {
            cout << "Enter Player 2's name: ";
            cin >> player2;
        } else {
            player2 = "Computer";
        }

        vector<int> heaps;

        if (choice == 1) {
            int totalTokens;
            cout << "Enter the total number of tokens: ";
            cin >> totalTokens;

            // Distribute tokens randomly to 5 piles
            heaps.resize(5, 0);
            while (totalTokens > 0) {
                int pile = rand() % 5;
                heaps[pile]++;
                totalTokens--;
            }
        } else {
            int numHeaps;
            cout << "Enter the number of heaps: ";
            cin >> numHeaps;

            heaps.resize(numHeaps, 0);
            for (int i = 0; i < numHeaps; i++) {
                heaps[i] = (1 << i); // 2^i tokens in heap i
            }
        }

        // Game loop
        while (!isGameOver(heaps)) {
            playTurn(heaps, player1);
            if (isGameOver(heaps)) {
                cout << "Game over! " << player1 << " wins!" << endl;
                break;
            }

            if (choice == 1) {
                playTurn(heaps, player2);
            } else {
                computerTurn(heaps);
            }

            if (isGameOver(heaps)) {
                cout << "Game over! " << player2 << " wins!" << endl;
                break;
            }
        }
    } else if (choice == 3) {
        cout << "Exiting the game." << endl;
    } else {
        cout << "Invalid choice. Please run the game again." << endl;
    }

    return 0;
}
