//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit1.h"
#include <fstream>
#include <comutil.h>
//---------------------------
//------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm9 *Form9;
vector<float> arr;
vector<Dict> alphabets;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm9::Button1Click(TObject *Sender)
{

   if(OpenDialog1->Execute())
   {
       Label1->Caption = "Загрузка файла...";
       TStringList *SL = new TStringList;
       SL->LoadFromFile(OpenDialog1->FileName);
       Memo1->Lines = SL;
   }

   Label1->Caption = "Сжатие...";
   for(int i = 0; i < Memo1->Lines->Count; i++)
   {
       arr.push_back(encoding(Memo1->Lines->Strings[i].w_str()));
       alphabets.push_back(symbols((Memo1->Lines->Strings[i] + "`").w_str()));
       ProgressBar1->Position = 100 * i / (2 * Memo1->Lines->Count);
   }
    const char* PATH = "D:\\test\\compressed.zpp";
    ofstream out(PATH,ios::binary|ios::out);
    Label1->Caption = "Запись в файл...";
    for(int i = 0; i < arr.size(); i++)
    {
     out.write((char*)&arr[i],sizeof arr[i]);
     ProgressBar1->Position += 100 * 1 / (2 * arr.size());
    }
    ProgressBar1->Position = 100;
    Label1->Caption = "Готово!";
    out.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button2Click(TObject *Sender)
{
     Label1->Caption = "Состояние";
     ProgressBar1->Position = 0;
     if(OpenDialog1->Execute())
     {
         ifstream in(OpenDialog1->FileName.c_str(), ios::binary|ios::in);
         vector<float> codes;
         int j = 0;
         Label1->Caption = "Загрузка файла...";
         while(!in.eof())
         {
             float m;
             in.read((char*)&m,sizeof m);
             codes.push_back(m);
             ProgressBar1->Position = 100*j/(2*Memo1->Lines->Count);
             ++j;
         }
         Label1->Caption = "Декодирование...";
         TStringList *sl = new TStringList;
         for(int i = 0; i < codes.size()-1; i++)
         {
             wchar_t* s = decode(codes[i], alphabets[i]);
             String str = String(s);
             sl->Add(str);
         }
         Label1->Caption = "Запись в файл...";
         String path = OpenDialog1->FileName;
             path[path.Length()] = 't';
             path[path.Length() - 1] = 'x';
             path[path.Length() - 2] = 't';
             Memo1->Lines = sl;
             Memo1->Lines->SaveToFile(path);
         Label1->Caption = "Готово!";
         ProgressBar1->Position = 100;
     }


}
//---------------------------------------------------------------------------

