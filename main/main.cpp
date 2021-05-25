#include <iostream>
#include "TreeMap.h"

int main()
{
  ofstream fout("output.txt");
  TTreeMap<int, double> tree;
  tree.Add(5, 5);
  tree.Add(4, 4);
  tree.Add(11, 11);
  tree.Add(10, 10);
  tree.Add(12, 12);
  tree.Add(7, 7);
  tree.Add(6, 6);
  tree.Add(8, 8);
  fout << tree;
  fout.close();
  ifstream fin("output.txt");
  string s;
  string sum;
  while (getline(fin, s))
  {
    sum += s;
  }
  cout << sum;
  fin.close();
}