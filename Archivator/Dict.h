//---------------------------------------------------------------------------

#ifndef DictH
#define DictH
#include <vector>
using namespace std;
//---------------------------------------------------------------------------

struct Node
{
    wchar_t key;
    int value;
};
class Dict
{
      public:
      Dict();
      vector<wchar_t> keys;
      vector<int> values;
      vector<Node> data;
      int size = 0;

      wchar_t& operator[](int index)
      {
         return data[index].key;
      }
      bool HasKey(wchar_t key);
      void Add(wchar_t key, int val);
      void Add(wchar_t key);
      int FindPos(wchar_t key);
      void sort();
};
#endif
