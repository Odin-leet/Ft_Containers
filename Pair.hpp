#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>
# include <string>

namespace ft{
template < class T1, class T2>
struct pair{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	pair():first(), second(){}
	//pair():first(T1()), second(T2()) {}
	pair(const T1 &ffirst, const T2 &ssecond)
  {
    first =  ffirst;
    second = ssecond;
  }
	template<class U1, class U2>
	pair(const pair <U1, U2> &p):first(p.first),second(p.second){}
  pair& operator= (const pair& pr) {
			if (this != &pr) {
				first = pr.first;
				second = pr.second;
			}
			return *this;
		}
};

 template <class _T1, class _T2>
  bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
 { 
   return __x.first == __y.first && __x.second == __y.second; 
 }
 
 template <class _T1, class _T2>
  bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
 { 
   return __x.first < __y.first || 
          (!(__y.first < __x.first) && __x.second < __y.second); 
 }
 
 template <class _T1, class _T2>
  bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return !(__x == __y);
 }
 
 template <class _T1, class _T2>
  bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return __y < __x;
 }
 
 template <class _T1, class _T2>
  bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return !(__y < __x);
 }
 
 template <class _T1, class _T2>
  bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return !(__x < __y);
 }
template <class _T1, class _T2>
ft::pair<_T1, _T2> make_pair(_T1 _x, _T2 _y)
{
	return ft::pair <_T1, _T2>(_x, _y);
}

}
#endif /* ************************************************************ PAIR_H */