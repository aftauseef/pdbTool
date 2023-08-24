#include <bits/stdc++.h>

using namespace std;

int stringtoint(string s){
    int n = s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(!isspace(s[i]))
           sum = sum*10 + (s[i]-'0');
    }return sum;
}

bool searchKeyword(int arr[], const string& keyword) {
    ifstream inputFile("fileName.pdb");
    ofstream activeSiteA("activeSiteA.pdb");
    ofstream activeSiteB("activeSiteB.pdb");
    ofstream activeSiteC("activeSiteC.pdb");
    ofstream activeSiteD("activeSiteD.pdb");
    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return false;
    }

    string line;
    int flag = 0;
    while (getline(inputFile, line)) {
        if (line.substr(0,4) == "ATOM") {
            if(stringtoint(line.substr(23,4))>arr[3]){
               return true;
            }
            if (stringtoint(line.substr(23,4))==arr[0]){
                activeSiteA<<line<<endl;
            }
            if (stringtoint(line.substr(23,4))==arr[1]){
                activeSiteB<<line<<endl;
            }
            if (stringtoint(line.substr(23,4))==arr[2]){
                activeSiteC<<line<<endl;
            }
            if (stringtoint(line.substr(23,4))==arr[3]){
                activeSiteD<<line<<endl;
            }
        }    
    }
    inputFile.close();
    return true;
}

int main() {
    // Get the input file name
    int res[4] = {0,0,0,0};
    cout << "Save your pdb file with the name fileName.pdb\nEnter the residue numbers of the active sites in ascending order. After having entered all the residue numbers enter a zero.\n";

    for(int i=0;i<4;i++){
        cin>>res[i];
        if(res[i]==0)
           break;
    }
    bool found = searchKeyword(res,"ATOM");
    return 0;
}