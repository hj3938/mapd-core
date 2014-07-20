#include "parser.h"
#include "visitor/Visitor.h"
#include "translator/XMLTranslatorRA.h"
#include <iostream>
#include <string>

using namespace std;
using RA_Namespace::XMLTranslator;

int main(int argc, char ** argv) {
    RAParser parser;
    string sql;
    do {
        cout << "mapd> ";
        getline(cin,sql);
        if (sql == "q")
            break;
        RelAlgNode *parseRoot = 0;
        string lastParsed;
        int numErrors = parser.parse(sql, parseRoot,lastParsed);
        if (numErrors > 0) {
            cout << "Error at: " << lastParsed << endl;
            continue;
        }
        
        //cout << "# Errors: " << numErrors << endl;
        XMLTranslator xml;
        if (parseRoot != 0)
            parseRoot->accept(xml); 

    }
    while (1==1);
    cout << "Good-bye." << endl;
}
