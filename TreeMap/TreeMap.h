#pragma once
#include "Node.h"
#include <queue>

using namespace std;

template <class TK, class TV>
class TTreeNode : public TNode<TK, TV>
{
protected:

public:
  TTreeNode* l;
  TTreeNode* r;

  TTreeNode(TK k = 0, TV v = 0);
  TTreeNode(const TTreeNode& p);
};

template <class TK, class TV>
TTreeNode<TK, TV>::TTreeNode(TK k, TV v) : TNode<TK, TV>::TNode(k, v)
{
  l = NULL;
  r = NULL;
}

template <class TK, class TV>
TTreeNode<TK, TV>::TTreeNode(const TTreeNode& p) : TNode<TK, TV>::TNode(p)
{
  l = NULL;
  r = NULL;
}

template <class TK, class TV>
class TTreeMapIter;

template <class TK, class TV>
class TTreeMap
{
protected:
  int count;

public:
  TTreeNode<TK, TV>* root;
  TTreeMap();
  TTreeMap(const TTreeMap<TK, TV>& p);
  virtual ~TTreeMap();

  virtual TV& operator[](TK i);

  virtual TV Find(TK k);
  virtual void Delete(TK k);
  virtual void Add(TK k, TV v);

  template<class TK1, class TV1>
  friend ofstream& operator<<(ofstream& out, const TTreeMap<TK1, TV1>& T);
};

template <class TK, class TV>
TTreeMap<TK, TV>::TTreeMap()
{
  count = 0;
  root = 0;
}

template <class TK, class TV>
TTreeMap<TK, TV>::TTreeMap(const TTreeMap<TK, TV>& p)
{
  count = p.count;
  if (p.root != 0)
  {
    root = new TTreeNode<TK, TV>(*(p.root));
    queue<TTreeNode<TK, TV>*> q;
    q.push(p.root);

    queue<TTreeNode<TK, TV>*> q2;
    q2.push(root);

    while (!q.empty())
    {
      TTreeNode<TK, TV>* cur1 = q.front();
      TTreeNode<TK, TV>* cur2 = q2.front();

      q.pop();
      q2.pop();

      if (cur1->l != 0)
      {
        TTreeNode<TK, TV>* t = new TTreeNode<TK, TV>(*(cur1->l));
        cur2->l = t;

        q.push(cur1->l);
        q2.push(cur2->l);

      }
      if (cur1->r != 0)
      {
        TTreeNode<TK, TV>* t = new TTreeNode<TK, TV>(*(cur1->r));
        cur2->r = t;

        q.push(cur1->r);
        q2.push(cur2->r);
      }
    }
  }
}

template <class TK, class TV>
TTreeMap<TK, TV>:: ~TTreeMap()
{
  if (root != 0)
  {
    queue<TTreeNode<TK, TV>*> q;
    q.push(root);
    while (!q.empty())
    {
      if (q.front()->l != 0)
        q.push(q.front()->l);
      if (q.front()->r != 0)
        q.push(q.front()->r);
      delete q.front();
      q.pop();
    }
  }
}

template <class TK, class TV>
TV& TTreeMap<TK, TV>::operator[](TK i)
{
  TTreeNode<TK, TV>* res(root);
  while (res)
  {
    if (res->GetKey() == i)
      return res->val;
    if (i < res->GetKey() && res->l)
      res = res->l;
    else res = res->r;
  }

  TTreeNode<TK, TV>* t = new TTreeNode<TK, TV>(i, 0);
  if (i < res->GetKey())
    res->l = t;
  else
    res->r = t;
}

template <class TK, class TV>
TV TTreeMap<TK, TV>::Find(TK k)
{
  TTreeNode<TK, TV>* res(root);
  while (res)
  {
    if (res->GetKey() == k)
      return res->GetVal();
    if (k < res->GetKey())
      res = res->l;
    else res = res->r;
  }
  throw - 1;
}

template <class TK, class TV>
void TTreeMap<TK, TV>::Delete(TK k)
{
  TTreeNode<TK, TV>* res(root);
  TTreeNode<TK, TV>* pred = 0;
  bool isleft = false;
  while (true)
  {
    if (res->GetKey() == k)
    {
      if (res == root)
      {
        this->~TTreeMap();
        return;
      }
      if (!res->l && !res->r)
      {
        if (isleft)
          pred->l = 0;
        else
          pred->r = 0;
        delete res;
        return;
      }
      if (res->l && res->r)
      {
        TTreeNode<TK, TV>* left = res->l;
        TTreeNode<TK, TV>* right = res->r;
        while (right->l)
        {
          right = right->l;
        }
        right->l = left;
        if (isleft)
          pred->l = res->r;
        else
          pred->r = res->r;
        delete res;
        return;
      }
      if (res->l || res->r)
      {
        if (res->l)
        {
          if (isleft)
            pred->l = res->l;
          else
            pred->r = res->l;
        }
        else
        {
          if (isleft)
            pred->l = res->r;
          else
            pred->r = res->r;
        }
        return;
      }
      throw - 1;
    }
    pred = res;
    if (k < res->GetKey() && res->l)
    {
      res = res->l;
      isleft = true;
    }
    else
    {
      res = res->r;
      isleft = false;
    }
  }
  throw - 1;
}

template <class TK, class TV>
void TTreeMap<TK, TV>::Add(TK k, TV v)
{

    if (root == 0)
    {
        root = new TTreeNode<TK, TV>(k, v);
        count++;
        return;
    }

    TTreeNode<TK, TV>* cur = root;

    while (true)
    {
        if (cur->GetKey() == k)
            return;
        if (k > cur->GetKey())
        {
            if (cur->r == 0)
            {
                cur->r = new TTreeNode<TK, TV>(k, v);
                count++;
                return;
            }
            else
                cur = cur->r;
        }
        else if (k < cur->GetKey())
        {
            if (cur->l == 0)
            {
                cur->l = new TTreeNode<TK, TV>(k, v);
                count++;
                return;
            }
            else
                cur = cur->l;
        }
    }
}


template<class TK1, class TV1>
inline ofstream& operator<<(ofstream& out, const TTreeMap<TK1, TV1>& T)
{
  struct obhod
  {
    TTreeNode<TK1, TV1>* n;
    bool l;
    bool r;
    obhod(TTreeNode<TK1, TV1>* _n, bool _l, bool _r):n(_n), l(_l), r(_r) {}
  };
  int count = 0;
  stack<obhod> tree;
  obhod ob(T.root, false, false);
  tree.push(ob);
  while (!tree.empty())
  {
    if (!tree.top().l && !tree.top().r)
    {
      for (int i = 0; i < count; i++)
        out << ' ';
      out << *tree.top().n << endl;
    }

    if (!tree.top().l)
    {
      tree.top().l = true;
      if (tree.top().n->l != 0)
      {
          obhod o(tree.top().n->l, false, false);
        tree.push(o);
        count++;
      }
    }
    else if (!tree.top().r)
    {
      tree.top().r = true;
      if (tree.top().n->r != 0)
      {
          obhod o(tree.top().n->r, false, false);
        tree.push(o);
        count++;
      }
    }
    else
    {
      count--;
      tree.pop();
    }
  }
  return out;
}
