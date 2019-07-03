#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include "setmulti.h"
#include <string>
#include "setmulti.h"
#include <functional>

struct string_size_less
{

  bool operator()( const std::string& a,
                   const std::string& b ) const
  {
    return a.length() < b.length();
  }

};

const int max = 1000;

int main()
{
  int your_mark = 1;
  std::set<int> si;
  for( int i = 0; i < max; ++i )
  {
    si.insert( i );
  }

  set_multi_util<int> us( si );
  for( int i = 0; i <= max; ++i )
  {
    us.insert( i );
  }

  std::set<std::string> st;
  st.insert( "C++" );
  st.insert( "Ada" );
  st.insert( "Pascal" );
  set_multi_util<std::string> ust( st );
  ust.insert( "Ada" );
  ust.insert( "Ada" );
  ust.insert( "Ada" );
  ust.insert( "Pascal" );
  const set_multi_util<std::string> cust( ust );


  if ( 4 == ust.count( "Ada" ) && 0 == ust.count( "C" ) &&
       1 == ust.count( "C++" ) && 1 == si.count( max ) &&
       2 == cust.count( "Pascal" ) && 1 == si.count( 1 ) &&
       2 == us.count( max / 2 ) && 1 == us.count( max ) &&
       1 == st.count( "Ada" ) && 1 == st.count( "Pascal" ) &&
       max + 1 == si.size() && 3 == st.size() )
  {
    your_mark = us.count( your_mark );
  }
  /* 3-as
  ust.erase_one_element( "Ada" );
  ust.erase_one_element( "Ada" );
  ust.erase_one_element( "C++" );
  ust.insert( "Python" );
  ust.insert( "Python" );
  ust.erase( "Python" );

  us.erase( 0 );
  us.erase_one_element( 1 );

  if ( 1 == si.count( max / 2 ) && 2 == us.count( max / 2 ) &&
       2 == ust.count( "Ada" ) && 0 == st.count( "Python" ) &&
       0 == ust.count( "Python" ) && 0 == st.count( "C++" ) &&
       0 == ust.count( "C++" ) && 4 == ust.size() &&
       1 == si.count( 1 ) && 1 == us.count( 1 ) && 0 == si.count( 0 ) )
  {
    your_mark = st.begin()->size();
  }
  */
  /* 4-es
  ust.insert( "Ada" );
  ust.insert( "C++" );
  ust.insert( "C++" );
  ust.insert( "Python" );
  ust.insert( "Python" );
  ust.insert( "Fortran" );
  ust.insert( "Fortran" );
  ust.insert( "Haskell" );
  ust.insert( "Objective-C" );
  ust.insert( "Objective-C" );
  ust.insert( "Cobol" );
  ust.erase( st.find( "Fortran" ), st.find( "Objective-C" ) );
  ust.erase( st.find( "Cobol" ) );
  ust.erase( st.find( "Python" ) );

  us.erase( si.find( 1 ), si.find( max / 2 ) );
  us.erase( si.find( max / 2 ) );

  if ( 0 == ust.count( "Cobol" ) && 2 == ust.count( "C++" ) &&
       0 == ust.count( "Haskell" ) && 3 == ust.count( "Ada" ) &&
       0 == ust.count( "Fortran" ) && 0 == us.count( max / 3 ) &&
       0 == si.count( max / 2 ) && 2 == us.count( max - 1 ) )
  {
    your_mark = st.size();
  }
  */
  /* 5-os
  std::set<int, std::greater<int> > g;
  set_multi_util<int, std::greater<int> > ug ( g );

  ug.insert( max );

  std::set<std::string, string_size_less> a;
  std::set<std::string, string_size_less> b;
  a.insert( "C++" );
  a.insert( "Perl" );
  b.insert( "Algol" );
  b.insert( "Haskell" );

  set_multi_util<std::string, string_size_less> ua( a );
  set_multi_util<std::string, string_size_less> ub( b );
  ub.erase( "Fortran" );
  ua.swap( ub );

  if ( 1 == ua.size() && 1 == ua.count( "Scala" ) &&
       1 == ub.count( "Ada" ) && 0 == ub.count( "C" ) &&
       1 == ug.count( max ) && 1 == ug.size() && 1 == a.count( "C/C++" ) )
  {
    your_mark = a.begin()->size();
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}