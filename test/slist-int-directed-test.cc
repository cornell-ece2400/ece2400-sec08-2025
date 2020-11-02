//========================================================================
// list-int-directed-test.cc
//========================================================================
// This file contains directed tests for ListInt-related functions.

#include <stdlib.h>

#include "ece2400-stdlib.h"
#include "SListInt.h"

//------------------------------------------------------------------------
// test_case_1_push_front
//------------------------------------------------------------------------
// A simple test case that tests push front

void test_case_1_push_front()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  int ref[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_2_reverse
//------------------------------------------------------------------------
// A simple test case that tests reverse

void test_case_2_reverse()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);
  lst.reverse();

  int ref[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//------------------------------------------------------------------------
// test_case_3_copy
//------------------------------------------------------------------------
// A simple test case that tests copying lists

void test_case_3_copy()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the copy constructor

  SListInt lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_4_assign
//------------------------------------------------------------------------
// A simple test case that tests assigning lists

void test_case_4_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst0;
  lst0.push_front(12);
  lst0.push_front(11);
  lst0.push_front(10);

  // Call the default constructor

  SListInt lst1;

  // Call the assignment operator

  lst1 = lst0;

  // Reverse list 0 to make sure it does not change list 1

  lst0.reverse();

  // Verify list 0

  int ref0[] = { 12, 11, 10 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst0.at(i), ref0[i] );
  }

  // Verify list 1

  int ref1[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst1.at(i), ref1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_5_self_assign
//------------------------------------------------------------------------
// A corner test case to check self assignment works.

void test_case_5_self_assign()
{
  std::printf( "\n%s\n", __func__ );

  SListInt lst;
  lst.push_front(12);
  lst.push_front(11);
  lst.push_front(10);

  // Call the assignment operator

  lst = lst;

  // Verify list

  int ref[] = { 10, 11, 12 };
  for ( size_t i = 0; i < 3; i++ ) {
    ECE2400_CHECK_INT_EQ( lst.at(i), ref[i] );
  }
}

//'''' LAB TASK ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
// Add more directed tests
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
// Add at least one more test case for push_front and one more directed
// test case for reverse.

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : std::atoi( argv[1] );

  if ( ( __n <= 0 ) || ( __n == 1 ) ) test_case_1_push_front();
  if ( ( __n <= 0 ) || ( __n == 2 ) ) test_case_2_reverse();
  if ( ( __n <= 0 ) || ( __n == 3 ) ) test_case_3_copy();
  if ( ( __n <= 0 ) || ( __n == 4 ) ) test_case_4_assign();
  if ( ( __n <= 0 ) || ( __n == 5 ) ) test_case_5_self_assign();

  printf( "\n" );
  return __failed;
}
