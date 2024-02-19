#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename ,  vector<string> &names , vector<int> &scores , vector<char> &grades)
{
    ifstream file(filename);
    string textline;
    char n[100];
    while (getline(file,textline))
    {
        int a,b,c;
        sscanf(textline.c_str(),"%[^:]: %d %d %d",n,&a,&b,&c);
        int t = a+b+c;
        scores.push_back(t);
        names.push_back(n);
        grades.push_back(score2grade(t));
    }
    
}

void getCommand(string &command, string &key){
    string ans;
    char a[20],b[20];
    cout << "Please input your command: ";
    getline(cin,ans);
    sscanf(ans.c_str(),"%s %[^:]",a,b);
    command = a;
    key = b;
}

void searchName(vector<string> &names,vector<int> &scores,vector<char> &grades,string key){
    cout << "---------------------------------\n";
    string name[names.size()] ;
    int o = 0;
    for(unsigned int i = 0; i < names.size(); i++){
        name[i]= toUpperStr(names[i]);
        if(name[i] == key){
            cout << names[i] << "'s " << "score" << " = " << scores[i] << endl;
            cout << names[i] << "'s " << "grade" << " = " << grades[i] << endl;
            o = 1;
        }
    }
    if(o == 0){
        cout << "Cannot found." << endl;
    }
    cout << "---------------------------------\n";
}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    cout << "---------------------------------\n";;
    int o = 0;
    for(unsigned int i = 0; i < names.size(); i++){
        if(grades[i] == key.c_str()[0]){
            cout << names[i] << " (" << scores[i] << ")" << endl;
            o = 1;
        }
    }
    if(o == 0){
        cout << "Cannot found." << endl;
    }
    cout << "---------------------------------\n";

}



int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
