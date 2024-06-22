#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

#define _ConstructMsg new (clsA::MsgObjBuf())

class  clsA
{
private:
    inline static char* m_pMsgObjBuf = NULL;
    /* data */
public:
        clsA(/* args */);
    virtual ~ clsA();
    static char* MsgObjBuf();
};

    clsA:: clsA(/* args */)
{
}

    clsA::~ clsA()
{
}

char* clsA::MsgObjBuf()
{	
    if (!m_pMsgObjBuf)
        m_pMsgObjBuf = new char [500];

    return m_pMsgObjBuf;
}

class clsB: public clsA
{
    private:
    int numb;
    /* data */
public:
        clsB(/* args */){
            numb = 100;
        };
    ~clsB(){};
    int getnum() {return numb;}
};

int main() {
    clsA* a = _ConstructMsg clsB;

    int n = a->getnum();
    return 0;
}