#ifndef BININST_H
#define BININAT_H
#include <bits/stdc++.h>
#define RegSize 16
using namespace std;
class BinInst {
public:
    string data;
    BinInst(){}
    BinInst(const BinInst& reg){
        for (int i = 0; i < RegSize; i++)
            this->data[i] = reg.data[i];
    }
    void removeComments(string lineOfCode){ 
        int len = lineOfCode.length();
        data.erase(0,data.length());
        bool comment = false; 
        for(int i=0; i<len; i++){ 
            if(comment == true && lineOfCode[i] == '\n') 
                comment = false;  
            else if(comment)    continue;
            else if(lineOfCode[i] == '/' && lineOfCode[i+1] == '/') 
                comment = true, i++;
            else  data.push_back(lineOfCode[i]); 
        }
    }
    void removeSpaces(string str){ 
        string temp;
        for(int i=0, j=0; i<str.length(); i++){
            if (str[i] == ' ')
                continue;
        temp.push_back(str[i]);
        }
        data = temp;
    }
    void cleanLine(string &line){
        string newLine = "";
        int i = 0;
        for(i = 0; i < line.size(); i++){
            if((line[i] >= '!' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || line[i] == '_' || line[i] == '|')
            newLine += line[i];
        }
        line = newLine;
    }
    friend ostream& operator << (ostream&, BinInst&);
};

class AInst: public BinInst{
public:
    string binary;
    AInst(){
        for(int i=0; i<RegSize;i++)
            binary.push_back('0');
    }
    int getInt(string &str){
        string temp;
        for(int i=1, j=0; i<str.length(); i++){
            if(str[i] == ' ')   continue;
            temp += str[i];
        }
        return stoi(temp);
    }
    void convertToBin(int val){
        int rem;
        int i = 15;
        while(val > 0){
            rem = val%2;
            binary[i--]=48+rem;
            val /= 2;
        }
        for(;i>=0;i--)
            binary[i] = '0';
    }  
};
class CInst: public BinInst{
    string dest, comp, jump, binary;
    string dToken, cToken, jToken;
public:
    CInst(string dest="000",string comp="0000000", string jump="000"){
        this->dest = dest;
        this->comp = comp;
        this->jump = jump;
        this->binary = "111" + comp + dest + jump;
    }
    string getBinary() const{
        return binary;
    }
    
    void cleanLine(string &line){
        string newLine = "";
        int i = 0;
        for(i = 0; i < line.size(); i++){
            if((line[i] >= '!' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || line[i] == '_' || line[i] == '|')
            newLine += line[i];
        }
        line = newLine;
    }

    string* tokenize(string line){
        string* result = new std::string[3];
        string temp;
        size_t i, j;
        if((temp = line.substr(0, (i = line.find('=')))) != line){
            result[0] = temp;
            i++;
        }
        else
            i = 0;
        if(!result[0].empty())
            result[1] = line.substr(i, (line.find(';')-2));
        else
            result[1] = line.substr(i, (line.find(';')));
        j = line.find(';');
        if(j != std::string::npos)
            result[2] = line.substr(j+1);
        for (size_t i = 0; i < 3; i++)
            cleanLine(result[i]);
        if(!result[0].empty()) this->dest = DEST[result[0]];
        if(!result[1].empty()) this->comp = COMP[result[1]];
        if(!result[2].empty()) this->jump = JUMP[result[2]];
        return result;
    }
    void generateBinary(){
        this->binary = "111" + comp + dest + jump;
    }
};
#endif
