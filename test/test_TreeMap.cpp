
#include <fstream>
#include <../gtest/gtest.h>
#include "TreeMap.h"

TEST(TTreeMap, can_create_treemap)
{
  TTreeMap<int, double> tree;
  ASSERT_NO_THROW(tree);
}

TEST(TTreeMap, can_add_elem)
{
  TTreeMap<int, double> e;
  e.Add(2, 2);
  e.Add(1, 1);
  e.Add(3, 3);
  ofstream fout("output.txt");
  fout << e;
  fout.close();
  ifstream fin("output.txt");
  string s;
  string sum;
  while (getline(fin, s))
  {
    sum += s;
  }
  string exps = "2: 2 1: 1 3: 3";
  EXPECT_EQ(exps, sum);
}

TEST(TTreeMap, can_find_elem)
{
  TTreeMap<int, double> e;
  e.Add(2, 2);
  e.Add(1, 1);
  e.Add(3, 3);
  vector<double> v;
  v.push_back(e.Find(1));
  v.push_back(e.Find(3));
  v.push_back(e.Find(2));
  vector<double> expv;
  expv.push_back(1);
  expv.push_back(3);
  expv.push_back(2);
  EXPECT_EQ(expv, v);
}

TEST(TTreeMap, can_index_elem)
{
  TTreeMap<int, double> e;
  e.Add(2, 2);
  e.Add(1, 1);
  e.Add(3, 3);
  vector<double> v;
  v.push_back(e[1]);
  v.push_back(e[3]);
  v.push_back(e[2]);
  vector<double> expv;
  expv.push_back(1);
  expv.push_back(3);
  expv.push_back(2);
  EXPECT_EQ(expv, v);
}

TEST(TTreeMap, can_delete_elem)
{
  TTreeMap<int, double> e;
  e.Add(5, 5);
  e.Add(4, 4);
  e.Add(9, 9);
  e.Add(7, 7);
  e.Add(6, 6);
  e.Add(8, 8);
  e.Add(11, 11);
  e.Add(10, 10);
  e.Add(12, 12);
  e.Delete(9);
  ofstream fout("output.txt");
  fout << e;
  fout.close();
  ifstream fin("output.txt");
  string s;
  string sum;
  while (getline(fin, s))
  {
    sum += s;
  }
  string exps = "5: 5 4: 4 11: 11  10: 10   7: 7    6: 6    8: 8  12: 12";
  EXPECT_EQ(exps, sum);
}