#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <tr1/memory>
#include <queue>

#include "parser_t.h"
#include "tokenyzer_t.h"
#include "analyzer_t.h"

using namespace std;

namespace advcpp
{
    
//CTOR FROM
parser_t::parser_t()
{
    m_analyzer = new analyzer_t;
    m_tokenyzer = new tokenyzer_t;
}
//DTOR
parser_t::~parser_t()
{
    delete m_analyzer;
    delete m_tokenyzer;
}

//for debugging
void PrintList(list<string> _list)
{
    string st;
    list<string>::iterator Iter = _list.begin();
    for (size_t i = 0; i < _list.size(); ++i ,++Iter)
    {
        cout << *Iter << endl;
    }
    cout << endl;
}

//PARSE
queue<tr1::shared_ptr<Params> >* parser_t::Parse(const string _fileName)
{
    //open file
    ifstream file;
    file.open(_fileName.c_str(), ifstream::in);
    if(!file.is_open())
    {
        cout << "decide later what to do on fail";
        throw;
    }
    //declare needed param
    string line;
    while (getline(file, line))
    {
        list<string>& list = m_tokenyzer -> Tokenize(line);
        // PrintList(list);
        m_analyzer -> AnalyzeLine(list);
        list.clear();
    }
    file.close();
    //m_analyzer -> return container params // pseudo code
    return m_analyzer->GetParams();
}

} // namespace advcpp
