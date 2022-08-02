//---------------------------------------------------------------------------

#pragma hdrstop

#include "Dict.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Dict::Dict()
{

}

bool Dict::HasKey(wchar_t key)
{
    for(int i = 0; i < keys.size(); i++)
    {
        if(key == keys[i])
               return true;
    }
    return false;
}

void Dict::Add(wchar_t key, int val)
{
    if(!HasKey(key))
    {
        Node temp;
        temp.key = key;
        temp.value = val;
        data.push_back(temp);
        keys.push_back(key);
        values.push_back(val);
        size++;
    }

}

void Dict::Add(wchar_t key)
{
     if(!HasKey(key))
     {
         Node temp = {key, 1};
         data.push_back(temp);
         keys.push_back(key);
         values.push_back(1);
         size++;
     }
     else
     {
         for(int i = 0; i < data.size(); i++)
         {
             if(data[i].key == key)
             {
                 data[i].value++;
                 values[i]++;
                 break;
             }
         }
     }
}

int Dict::FindPos(wchar_t key)
{
    for(int i = 0; i < this->size; i++)
    {
        if(data[i].key == key)
           return i;
    }
    return -1;
}

void Dict::sort()
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j].value < data[j + 1].value) {
                Node temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
