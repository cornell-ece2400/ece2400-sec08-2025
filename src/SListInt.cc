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

  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement destructor
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
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

  reverse();
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  // Check for self assignment
  if ( this != &lst ) {

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

  }
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

  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int SListInt::at( size_t idx ) const
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  Node* curr_p = m_head_p;
  for ( size_t i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return curr_p->value;
}

//------------------------------------------------------------------------
// SListInt::reverse
//------------------------------------------------------------------------

void SListInt::reverse()
{
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  // 1. Iterate through the list to count the number of items

  size_t size   = 0;
  Node*  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size++;
    curr_p = curr_p->next_p;
  }

  // 2. Allocate a new array of integers on the heap with size items

  int* tmp = new int[size];

  // 3. Iterate through the list and copy each item to the array

  size_t idx = 0;
  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    tmp[idx] = curr_p->value;
    curr_p   = curr_p->next_p;
    idx++;
  }

  // 4. Iterate through the list and copy each item from the
  //    array in reverse order

  idx    = 0;
  curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    curr_p->value = tmp[size-idx-1];
    curr_p        = curr_p->next_p;
    idx++;
  }

  // 5. Delete the temporary array

  delete[] tmp;
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

