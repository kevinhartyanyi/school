#include <iostream>
#include <functional>
#include <numeric>
#include "msmview.h"
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
#include "msmview.h"

struct string_size_less
{

  bool operator()( const std::string& lhs,
                   const std::string& rhs ) const
  {
    return lhs.size() < rhs.size();
  }

};

const int max = 1000;

int main()
{
  int your_mark = 1;
  
  std::multiset<int> a;
  std::multiset<int> b;
  a.insert( 1 );
  a.insert( 7 );
  a.insert( 4 );
  b.insert( 4 );
  b.insert( 3 );

  std::multiset<std::string> s;
  std::multiset<std::string> t;
  s.insert( "C++" );
  s.insert( "Pascal" );
  s.insert( "Haskell" );
  t.insert( "C" );
  t.insert( "Ada" );

  std::multiset<int> x;
  std::multiset<int> y;
  for( int i = 0 ; i < max; ++i )
  {
    x.insert( i );
    y.insert( i );
  }

  bool c = x.count( max / 3 ) == 2;
  if ( !c )
  {
    multisets_merge_view<int> mvi( a, b );
    multisets_merge_view<int> mvm( x, y );
    multisets_merge_view<std::string> mvs( s, t );

    c = x.count( max / 3 ) == 2 && 3 == s.size() &&
        0 == s.count( "Pascal" ) && 1 == t.count( "Pascal" ) &&
        0 == x.count( max - 1 ) && 1 == s.count( "C" ) &&
        0 == a.count( 7 ) && 0 == b.count( 3 );
  }
  if ( c && 1 == x.count( max / 3 ) && 1 == s.count( "Pascal" ) &&
       0 == s.count( "C" ) && 2 == t.size() && 1 == x.count( max - 1 ) &&
       1 == a.count( 7 ) && 1 == b.count( 3 ) )
  {
    your_mark = b.size();
  }
  
  /* 3-as
  if ( c )
  {
    const multisets_merge_view<int> mvi( a, b );
    const multisets_merge_view<int> mvm( x, y );
    const multisets_merge_view<std::string> mvs( s, t );

    if ( 5 == mvi.size() && 2 == mvi.count( 4 ) && 0 == mvi.count( max ) &&
         5 == mvs.size() && 1 == mvs.count( "C++" ) && 2 * max == mvm.size() )
    {
      your_mark = mvi.count( 3 ) + mvm.count( max - 1 );
    }
  }
  */
  /* 4-es
  std::multiset<int, std::greater<int> > ga;
  std::multiset<int, std::greater<int> > gb;

  ga.insert( 0 );
  ga.insert( max );
  gb.insert( max );

  std::multiset<std::string, string_size_less> sa;
  std::multiset<std::string, string_size_less> sb;

  sa.insert( "C++" );
  sa.insert( "Haskell" );
  sb.insert( "Ada" );
  sb.insert( "SQL" );
  sb.insert( "LISP" );
  if ( c )
  {
    const multisets_merge_view<std::string, string_size_less> mvs( sa, sb );
    const multisets_merge_view<int, std::greater<int> > mvi( ga, gb );

    if ( 2 == sa.count( "C++" ) && 1 == sb.count( "C++" ) && 1 == gb.count( 0 ) &&
         1U * your_mark == sb.size() && ga.size() == ga.count( max ) && 3 == mvi.size() )
    {
      your_mark = mvs.count( "C++" ) + mvs.count( "Fortran" );
    }
  }
  */
  /* 5-os
  if ( c )
  {
    multisets_merge_view<std::string, string_size_less> mvs( sa, sb );
    multisets_merge_view<int, std::greater<int> > mvi( ga, gb );

    multisets_merge_view<std::string, string_size_less>::const_iterator it =
      std::find( mvs.begin(), mvs.end(), "Haskell" );
    if ( it != mvs.end() && "Haskell" == *it &&
         mvs.end() == std::find( mvs.begin(), mvs.end(), "ABAP" ) &&
         2 == std::count( mvi.begin(), mvi.end(), max ) &&
         &( *mvi.begin() ) == &( *(ga.begin() ) ) )
    {
      your_mark = std::distance( mvs.begin(), mvs.end() );
    }
  }
  */
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}