#include <iostream>
#include <string>
#include <iomanip>
#include "Symbols.h"
#include "BinInst.h"
using namespace std;

int main(int args, char ** arg){
    int val;
    BinInst *inst;
    AInst *aInst;
    CInst *cInst;
    inst = new BinInst;
    string fileName, outFileName;
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
    cout << "Converting...\n";
    while(!inputFile.eof()){
        getline(inputFile,inst->data);
        inst->removeComments(inst->data);
        if( inst->data == "" || inst->data[0] == '\n')    continue;
        inst->removeSpaces(inst->data);
        if(inst->data[0] == '@'){
            aInst = new AInst;
            aInst->convertToBin(aInst->getInt(inst->data));
            outputFile << aInst->binary << '\n';
            delete aInst;
            aInst = nullptr;
        }
        else{
            string* str;
            cInst = new CInst;
            str = cInst->tokenize(inst->data);
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