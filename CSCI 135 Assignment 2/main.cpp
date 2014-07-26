#include <iostream>
#include <fstream>
#include <string>
#include "team.h"
using namespace std;

void loadTeams(ifstream& input, Team teams[]);
bool processScoresForWeek(ifstream& intput, Team teams[]);
int findTeam(Team teams[], string teamID);
void rankTeams(Team teams[]);
int findNextRankedTeam(const Team teams[], int i);
void swapTeams(Team teams[], int i, int j);
void outputWeeklyRankings(const Team teams[], int week, ofstream& output);

int main() {
    int week=0;
    Team teams[50];
    string teamsfilename,
           scoresfilename,
           resultsfilename;
    ifstream teamsfile,
             scoresfile;
    ofstream resultsfile;

    cout << "Enter the file name for the list of teams: ";
    cin >> teamsfilename;
    teamsfile.open(teamsfilename.c_str());
    if(teamsfile.fail()) {
        cout << "Failed to open team list file. Exiting..." << endl;
        return 1;
    }
    cout << "Enter the file name for the weekly scores: ";
    cin >> scoresfilename;
    scoresfile.open(scoresfilename.c_str());
    if(scoresfile.fail()) {
        cout << "Failed to open weekly scores file. Exiting..." << endl;
        return 1;
    }
    cout << "Enter a file name to output the results to: ";
    cin >> resultsfilename;
    resultsfile.open(resultsfilename.c_str());
    if(resultsfile.fail()) {
        cout << "Failed to open results file. Exiting..." << endl;
        return 1;
    }

    loadTeams(teamsfile, teams);
    while (processScoresForWeek(scoresfile, teams)) {
        week++;
        rankTeams(teams);
        outputWeeklyRankings(teams, week, resultsfile);
    }

    teamsfile.close();
    scoresfile.close();
    resultsfile.close();
    return 0;
}

void loadTeams(ifstream& intput, Team teams[]) {
    string name,
           id;
    int count = 0;

    while(intput >> name >> id) {
        teams[count].setInfo(name, id);
        count++;
    }
}

bool processScoresForWeek(ifstream& input, Team teams[]) {
    string team1,
           team2;
    int score1,
        score2,
        team1pos,
        team2pos;
    bool keepGoing = true,
         haveResult = false;

    while(keepGoing && input >> team1) {
        if (!haveResult) {
            haveResult = true;
        }
        if(team1[0] == '-') {
            keepGoing = false;
        } else {
            while(! isalnum(input.peek())) {
                input.ignore(1);
            }
            if (isdigit(input.peek())) {
                input >> score1;
                input >> team2;
                input >> score2;
                team1pos = findTeam(teams, team1);
                team2pos = findTeam(teams, team2);
                teams[team1pos].recordResult(score1, score2);
                teams[team2pos].recordResult(score2, score1);
            }
        }
    }
    return haveResult;
}

int findTeam(Team teams[], string teamID) {
    int position,
        numofteams = Team::getNumOfTeams();

    for (int i = 0; i < numofteams; ++i) {
        if (teams[i].getID() == teamID) {
            position = i;
        }
    }
    return position;
}

void rankTeams(Team teams[]) {
    int next,
        rank = 1,
        numofteams = Team::getNumOfTeams();

    for(int i = 0; i < numofteams; i++) {
        next = findNextRankedTeam(teams, i);
        swapTeams(teams, i, next);
        teams[i].setRank(i+1);
        if (i > 0 && teams[i].getPercentage() == teams[i-1].getPercentage()) {
            teams[i].setRank(teams[i-1].getRank());
        }
    }
}

int findNextRankedTeam(const Team teams[], int i) {
    int result = i,
        numofteams = Team::getNumOfTeams();
    double currpct = teams[i].getPercentage();
    string currname = teams[i].getName();

    for(int j = i+1; j < numofteams; j++) {
        if((teams[j].getPercentage() > currpct) || ((teams[j].getPercentage() == currpct) && (teams[j].getName() < currname))) {
            currpct = teams[j].getPercentage();
            currname = teams[j].getName();
            result = j;
        }
    }
    return result;
}

void swapTeams(Team teams[], int i, int j) {
    Team temp = teams[i];

    teams[i] = teams[j];
    teams[j] = temp;
}

void outputWeeklyRankings(const Team teams[], int week, ofstream& output) {
    int numofteams = Team::getNumOfTeams();

    output << "Rankings after week #" << week << endl;
    for(int i = 0; i < numofteams; i++) {
        output << teams[i].getRank()
               << ": "
               << teams[i].getName()
               << " ("
               << teams[i].getWins()
               << "-"
               << teams[i].getLosses()
               << "-"
               << teams[i].getTies()
               << ")\n";
    }
    output << endl;
}
