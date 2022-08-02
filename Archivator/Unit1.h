//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include "Dict.h"
#include <vcl.h>
//---------------------------------------------------------------------------
Dict symbols(wchar_t* text);
float encoding(wchar_t* msg);
float* GetProbabilities(Dict alph);
wchar_t* decode(float code, Dict alph);
#endif
