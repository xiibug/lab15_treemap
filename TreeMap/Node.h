#pragma once
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

template<class TK, class TV>
class TTreeMap;

template<class TK, class TV>
class TNode
{
protected:
  TK key;
  TV val;
public:
  TNode(TK k = 0, TV v = 0);
  TNode(const TNode& p);

  TK GetKey();
  TV GetVal();

  void SetKey(TK k);
  void SetVal(TV v);

  TNode& operator =(const TNode& p);

  bool operator == (TNode& p);
  bool operator > (TNode& p);
  bool operator < (TNode& p);

  friend class TTreeMap<TK, TV>;

  //גûגמה ג פאיכ
  template<class TK, class TV>
  friend ofstream& operator<<(ofstream& out, const TNode<TK, TV>& N);
};

template<class TK, class TV>
TNode<TK, TV>::TNode(TK k, TV v)
{
  key = k;
  val = v;
}

template<class TK, class TV>
TNode<TK, TV>::TNode(const TNode& p)
{
  this->key = p.key;
  this->val = p.val;
}

template<class TK, class TV>
TK TNode<TK, TV>::GetKey()
{
  return key;
}

template<class TK, class TV>
TV TNode<TK, TV>::GetVal()
{
  return val;
}

template<class TK, class TV>
void TNode<TK, TV>::SetKey(TK k)
{
  key = k;
}

template<class TK, class TV>
void TNode<TK, TV>::SetVal(TV v)
{
  val = v;
}

template<class TK, class TV>
bool TNode<TK, TV>::operator == (TNode& p)
{
  return this->key == p.key;
}

template<class TK, class TV>
bool TNode<TK, TV>::operator > (TNode& p)
{
  return this->key > p.key;
}

template<class TK, class TV>
bool TNode<TK, TV>::operator < (TNode& p)
{
  return this->key < p.key;
}

template<class TK, class TV>
TNode<TK, TV>& TNode<TK, TV>::operator =(const TNode<TK, TV>& p)
{
  this->key = p.key;
  this->val = p.val;
  return *this;
}

template<class TK, class TV>
ofstream& operator<<(ofstream& out, const TNode<TK, TV>& N)
{
  out << N.key << ": " << N.val;
  return out;
}