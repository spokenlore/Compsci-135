#include <string>
#include "team.h"
using namespace std;

int Team::numofteams = 0;

Team::Team() {
    name = "";
    ID = "";
    wins = 0;
    losses = 0;
    ties = 0;
    percentage = 0.0;
}

void Team::setInfo(string newname, string newID) {
    name = newname;
    ID = newID;
    numofteams++;
}

string Team::getName() const { return name; }

string Team::getID() const { return ID; }

int Team::getWins() const { return wins; }

int Team::getLosses() const { return losses; }

int Team::getTies() const { return ties; }

double Team::getPercentage() const { return percentage; }

int Team::getRank() const { return rank; }

void Team::setRank(int newrank) { rank = newrank; }

int Team::getTotalGames() const { return ties + losses + wins; }

void Team::recordResult(int ourscore, int theirscore) {
    if (ourscore > theirscore) {
        wins++;
    } else if (ourscore == theirscore) {
        ties++;
    } else {
        losses++;
    }
    updatePercentage();
}

void Team::updatePercentage() {
    if (getTotalGames() > 0) {
        percentage = (wins + (0.5 * ties))/getTotalGames();
    }
    else {
        percentage = 0.0;
    }
}

int Team::getNumOfTeams() { return numofteams; }
