//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

class Solution {
public:
    int uf_find(vector<int> &uf, int i) {
  return uf[i] == -1 || uf[i] == i ? i : uf_find(uf, uf[i]);
}
bool equationsPossible(vector<string>& equations) {
  vector<int> uf('z' + 1, -1);
  for (auto s : equations)
    if (s[1] == '=') uf[uf_find(uf, s[0])] = uf_find(uf, s[3]);
  for (auto s : equations)
    if (s[1] == '!' && uf_find(uf, s[0]) == uf_find(uf, s[3])) return false;
  return true;
}
};
