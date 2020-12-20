#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Symbols.h"
#include "BinInst.h"
using namespace std;

stringstream cleanStream(istream& stream){
    stringstream os;
    for(string line;getline(stream, line); ){
        string newLine = "";
        int m = 0;
        for(m = 0; m < line.size(); m++){
            if((line[m] >= '!' && line[m] <= 'Z') || (line[m] >= 'a' && line[m] <= 'z') || line[m] == '_' || line[m] == '|')
            newLine += line[m];
        }
        line = newLine;
        size_t pos = line.find('/');
        if(pos != std::string::npos)    line.erase(pos);
        line += '\n';
        if(line.length() > 1)   os << line;
    }
    return os;
}

stringstream initSymbols(istream& str){
    stringstream cleanStream;
    int i = 0, j = 16;
    string line, symbol;
    while(getline(str, line)){
        string newLine = "";
        int m = 0;
        for(m = 0; m < line.size(); m++){
            if((line[m] >= '!' && line[m] <= 'Z') || (line[m] >= 'a' && line[m] <= 'z') || line[m] == '_' || line[m] == '|')
            newLine += line[m];
        }
        line = newLine;
        if(line.find('(') != string::npos){
            symbol = line.substr(1, line.length() - 2);
            if(symbols.find(symbol) == symbols.end())   symbols[symbol] = i--;
        }
        i++;
    }
    str.clear();
    str.seekg(0);
    while(getline(str, line)){
        if(line[0] == '@'){
            cleanStream << line << '\n';
            std::string symbol = line.substr(1, line.length() - 1);
            if(isdigit(line[1]))                        continue;
            if(symbols.find(symbol) == symbols.end())   symbols[symbol] = j++;
        }
        else if(line.find('(') == string::npos)         cleanStream << line << '\n';  
    }
    return cleanStream;
}
int main(int args, char ** arg){
    int val;
    BinInst *inst;
    AInst *aInst;
    CInst *cInst;
    inst = new BinInst;
    string fileName, outFileName;
    stringstream modifiedStream;
    if(args <= 1){
        cout << "Enter a file name: ";
        cin >> fileName;
    }
    else if (args > 2)  {
        cout << "Too many arguments.(only one argument fileName should be provided)\n";
        return 0;
    }
    else fileName = arg[1];
    ifstream inputFile(fileName);
    fileName.erase(fileName.find('.'));
    outFileName = fileName+".hack";
    ofstream outputFile(outFileName);
    modifiedStream = cleanStream(inputFile);
    modifiedStream.seekg(0);
    modifiedStream = initSymbols(modifiedStream);
    modifiedStream.seekg(0);
    cout << "Converting...\n";
    while(!modifiedStream.eof()){
        getline(modifiedStream,inst->data);
        inst->removeComments(inst->data);
        if( inst->data == "" || inst->data[0] == '\n')  continue;
        inst->removeSpaces(inst->data);
        inst->cleanLine(inst->data);
        if(inst->data[0] == '@'){
            int val;
            string var;
            aInst = new AInst;
            if(isdigit(inst->data[1]))  val = aInst->getInt(inst->data);
            else{
                var = inst->data.substr(1, inst->data.length()-1);
                val = symbols.find(var)->second;
            }
            aInst->convertToBin(val);
            outputFile << aInst->binary << '\n';
            delete aInst;
            aInst = nullptr;
        }
        else {
            cInst = new CInst;
            cInst->tokenize(inst->data);
            cInst->generateBinary();
            outputFile << cInst->getBinary() << '\n';
            delete cInst;
            cInst = nullptr;
        }
    }
    delete inst;
    inst = nullptr;
    inputFile.close();
    outputFile.close();
    cout << outFileName << " has created successfully. \n";
    return 0;
}