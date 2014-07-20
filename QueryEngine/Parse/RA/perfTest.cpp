#include "parser.h"
#include "visitor/Visitor.h"
#include "translator/XMLTranslatorRA.h"
#include <iostream>
#include <string>
#include <boost/timer/timer.hpp>

using namespace std;

RelAlgNode *parse_root = 0;

int main(int argc, char ** argv) {
    /*
    string sql ("select x, avg(y), avg(t) from tweets where x > 100 group by x;");
    for (int i = 0; i != 100000; ++i) {
        ASTNode *parseRoot = 0;
        parser.parse(sql,parseRoot);
    }
    */
    string sql;
    do {
        cout << "mapd> ";
        getline(cin,sql);
        if (sql == "q")
            break;
        string lastParsed;
        RAParser parser;
        const boost::timer::nanosecond_type oneSecond(1000000000LL);
        boost::timer::cpu_timer cpuTimer;
        for (int i = 0; i != 100000; ++i) {
            RelAlgNode *parseRoot = 0;
            parser.parse(sql,parseRoot,lastParsed);
        }
        double hostElapsedTime = double(cpuTimer.elapsed().user) / oneSecond * 1000000.0 /* microseconds */ / 100000.0 /*numQueries*/;
        cout << "Query took: " << hostElapsedTime << " microseconds." <<  endl;
        /*
        ASTNode *parseRoot = 0;
        parser.parse(sql, parseRoot);
        */
        /* 
        XMLTranslator xml;
        if (parseRoot != 0)
            parseRoot->accept(xml); 
        */

    }
    while (1==1);
}
