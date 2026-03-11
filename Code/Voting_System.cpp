#include <iostream>
#include <string>

using namespace std;

int main() {
    // Step 1: Start the program & Setup variables
    const int numCandidates = 3;
    string candidates[numCandidates] = {"Candidate A", "Candidate B", "Candidate C"};
    
    // This array acts as our vote counter. All start at 0.
    int voteCounts[numCandidates] = {0, 0, 0}; 
    
    int numVoters;

    // Menu Header
    cout << "---- Simple Voting System ----\n\n";

    // Step 3: Ask the user to enter the number of voters
    cout << "Enter the total number of voters: ";
    cin >> numVoters;

    // Step 4 & 5: Accept votes one by one and store them
    for (int i = 0; i < numVoters; i++) {
        cout << "\n--- Voter " << i + 1 << " ---\n";
        
        // Step 2: Display the list of candidates
        for (int j = 0; j < numCandidates; j++) {
            cout << j + 1 << ". " << candidates[j] << "\n";
        }

        int choice;
        cout << "Enter your vote (1-" << numCandidates << "): ";
        cin >> choice;

        // Validate the input to ensure it matches a candidate
        if (choice >= 1 && choice <= numCandidates) {
            // Arrays are 0-indexed in C++, so choice '1' updates index '0'
            // Step 6: Count votes for each candidate
            voteCounts[choice - 1]++; 
        } else {
            cout << "Invalid choice! This vote is wasted.\n";
        }
    }

    // Step 7: Display vote count for each candidate
    cout << "\n--- RESULTS ---\n";
    for (int i = 0; i < numCandidates; i++) {
        cout << candidates[i] << ": " << voteCounts[i] << " votes\n";
    }

    // Step 8: Declare the winning candidate
    int highestVotes = 0;
    int winnerIndex = 0;
    bool isTie = false;

    for (int i = 0; i < numCandidates; i++) {
        if (voteCounts[i] > highestVotes) {
            highestVotes = voteCounts[i];
            winnerIndex = i;
            isTie = false; // Reset tie status if we find a new clear winner
        } else if (voteCounts[i] == highestVotes && highestVotes != 0) {
            isTie = true; // Flag if there's a tie for the top spot
        }
    }

    cout << "\n";
    if (highestVotes == 0) {
        cout << "Winner: No votes were cast successfully.\n";
    } else if (isTie) {
        cout << "Winner: It's a tie!\n";
    } else {
        cout << "Winner: " << candidates[winnerIndex] << "\n";
    }

    // Step 9: End the program
    return 0;
}