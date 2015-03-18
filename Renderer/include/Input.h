#ifndef _INPUT_H_
#define _INPUT_H_

#include <functional>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

#define Uint8 int

class Input
{
  typedef pair <function<void()>, string> functie;
  unordered_map <Uint8, vector<functie>> hash_kbdkey_func;
 public:
  Input ()
    {
    }

  void operator += (pair<Uint8, functie> delegate)
  {
    hash_kbdkey_func[delegate.first].push_back (delegate.second);
  }

  void operator -= (pair <Uint8, string> delegate)
  {
    Uint8 key = delegate.first;
    string name = delegate.second;
    for (auto it = hash_kbdkey_func[key].begin(); it != hash_kbdkey_func[key].end(); ++it)
      {
	if  ((*it).second == name)
	  hash_kbdkey_func[key].erase(it);
      }
  }

  void Invoke (Uint8 key)
  {
    for (auto &it : hash_kbdkey_func[key])
      it.first();
  }
};

#endif /* _INPUT_H_ */
