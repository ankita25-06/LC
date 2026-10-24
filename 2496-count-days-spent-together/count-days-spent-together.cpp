class Solution {
public:
    int dateToDay(string date) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrAlice = dateToDay(arriveAlice);
        int depAlice = dateToDay(leaveAlice);
        int arrBob = dateToDay(arriveBob);
        int depBob = dateToDay(leaveBob);
        
        int latestArrival = max(arrAlice, arrBob);
        int earliestDeparture = min(depAlice, depBob);
        
        if (latestArrival <= earliestDeparture) {
            return earliestDeparture - latestArrival + 1;
        }
        return 0;
    }
};