//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------

Dict symbols(wchar_t* text)
{
     Dict alph;
     for(int i = 0; i < wcslen(text); i++)
     {
         alph.Add(text[i]);
     }
     alph.sort();
     return alph;
}

float* GetProbabilities(Dict alph)
{
    int count = 0;
    for(int i = 0; i < alph.size; i++)
    {
       count += alph.data[i].value;
    }
    float* probabilities = new float[alph.size];
    for(int i = 0; i < alph.size; i++)
    {
      probabilities[i] = (float)alph.data[i].value/count;
    }
    return probabilities;
}

float* init_otrezok(float* prob, int n)
{
    float* otr = new float[n];
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            otr[i] = prob[i];
        }
        else
        if(i != n-1)
        {
            otr[i] = otr[i-1] + prob[i];
        }
        else
        {
            otr[i] = 1;
        }
    }
    return otr;
}

float* Get_otrezok(float left, float right, float* prob, int n)
{
    float *otr = new float[n];
    for(int i = 0; i < n; i++)
    {
        otr[i] = left + (right-left)*prob[i];
    }
    return otr;
}


float encoding(wchar_t* msg)
{
    String s = String(msg) + "`";
    msg = s.w_str();
    Dict alph = symbols(msg);
    float right = 1, left = 0;
    float* probabilities = GetProbabilities(alph);
    float* otrezok = init_otrezok(probabilities, alph.size);
    int i = 0;
    while(msg[i]!='\0')
    {
        int idx = alph.FindPos(msg[i]);
        if(idx != 0)
               left = otrezok[idx-1];
        right = otrezok[idx];
        otrezok = Get_otrezok(left, right, otrezok, alph.size);
        i++;
    }
    left = otrezok[0];
    right = otrezok[alph.size-1];
    return right;
}

float normalize_code(float &code, float left, float right)
{
    code = (float)(code - left)/(right-left);
    return code;
}

String decode(float code, Dict alph)
{
    float* probabilities = GetProbabilities(alph);
    float* otrezok = init_otrezok(probabilities, alph.size);
    String s = "";
    wchar_t c = L'k';
    float left = 0, right = 1;
    while(c != L'`')
    {
        int j = 0;
        for(; code > otrezok[j]; j++)
        {

        }
        if(j != 0)
        {
           left = otrezok[j-1];
        }
        right = otrezok[j];
        c = alph[j];
        if(c!=L'`');
            s += c;
        otrezok = Get_otrezok(left, right, otrezok, alph.size);
    }
    return s;
}

#pragma package(smart_init)
