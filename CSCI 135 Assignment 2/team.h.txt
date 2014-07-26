#ifndef TEAM_H
#define TEAM_H

#include <string>
using namespace std;


class Team {
  private:
    string name;
    string ID;
    int wins;
    int losses;
    int ties;
    double percentage;
    int rank;
    static int numofteams;
  public:
    Team();
    void setInfo(string newname, string newID);
    string getName() const;
    string getID() const;
    int getWins() const;
    int getLosses() const;
    int getTies() const;
    double getPercentage() const;
    int getRank() const;
    int getTotalGames() const;
    void setRank(int newrank);
    void recordResult(int ourscore, int oppscore);
    void updatePercentage();
    static int getNumOfTeams();
};

#endif
