//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>
#include <cassert>
#include "SListInt.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement constructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement destructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
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

  reverse();
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

  reverse();

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
// SListInt::at
//------------------------------------------------------------------------

int SListInt::at( size_t idx ) const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  return 0;
}

//------------------------------------------------------------------------
// SListInt::reverse
//------------------------------------------------------------------------

void SListInt::reverse()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
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
