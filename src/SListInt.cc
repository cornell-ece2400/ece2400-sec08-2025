//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>
#include "SListInt.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;

    //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // Delete the node
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt( const SListInt& lst )
{
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now ahve all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Handle self-assignment correctly!
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  // Delete all nodes in this list.

  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }

  // Iterate through each element of the given lst and use push_front
  // to add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now ahve all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();

  return *this;
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front( int v )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SListInt::size
//------------------------------------------------------------------------

int SListInt::size() const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement size
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return 0;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int* SListInt::at( int idx )
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return nullptr;
}

//------------------------------------------------------------------------
// SListInt::reverse_v1
//------------------------------------------------------------------------

void SListInt::reverse_v1()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v1
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Pseudocode for this algorithm:
  //
  //  def reverse( x, n ):
  //    for i in 0 to n/2:
  //      lo = i
  //      hi = (n-1) - i
  //      swap( x[lo], x[hi] )
  //
}

//------------------------------------------------------------------------
// SListInt::reverse_v2
//------------------------------------------------------------------------

void SListInt::reverse_v2()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v2
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Steps for this algorithm:
  //
  //  1. Use the size member function to find number items in list
  //  2. Allocate a new array of integers on the heap with size items
  //  3. Iterate through list and copy each item to the array
  //  4. Iterate through list and copy each item from array in reverse order
  //  5. Delete temporary array
  //
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    printf("%d ",curr_p->value);
    curr_p = curr_p->next_p;
  }
  printf("\n");
}

