#include <iostream>
using namespace std;


// Global program function declarations
string getDonorFieldName ();
string getFundFieldNames ();
int getTotalFunds ();
void getShortQuery(string f, int t);
void getLongQuery(string d, string f, int t);



// Main Program begins
int main () {

    string donorField, fundNames;
    int numberOfFunds;
    char donorNeeded;

    cout << "Do you need the donor field in your query? (y/n)" << endl;
    cin >> donorNeeded;
    cin.ignore();

    if (donorNeeded == 'y') {
        donorField = getDonorFieldName();
        fundNames = getFundFieldNames();
        numberOfFunds = getTotalFunds();

        getLongQuery(donorField, fundNames, numberOfFunds);
    }

    if (donorNeeded == 'n') {
        fundNames = getFundFieldNames();
        numberOfFunds = getTotalFunds();

        getShortQuery(fundNames, numberOfFunds);
    }

    

    return 0;
}



// Global program function definitions

string getDonorFieldName () {
    string df;
    cout << "Exacly how is the donor field named?" << endl;
    getline(cin,df);
    return df;
}

string getFundFieldNames () {
    string fn;
    cout << "Exacly how are the fund fields named? (Exluding digits)" << endl;
    getline(cin,fn);
    return fn;
}

int getTotalFunds () {
    int nof;
    cout << "How many fund fields exist in the data?" << endl;
    cin >> nof;
    return nof;
}

void getLongQuery (string d, string f, int t) {

    for (int n = 1; n <= t; n++) {
        cout << "IIF ([" << f << n << "] IS NULL,\"\",[" << d << "] & \"_\" & [" << f << n << "] & \".pdf, \") &" << endl;
    }

}

void getShortQuery (string f, int t) {

    for (int n = 1; n <= t; n++) {
        cout << "IIF ([" << f << n << "] IS NULL,\"\",[" << f << n << "] & \".pdf, \") &" << endl;
    }

}