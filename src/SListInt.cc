//========================================================================
// SListInt.cc
//========================================================================
// Implementation for SListInt

#include "SListInt.h"

#include <cassert>
#include <cstdio>

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt() {
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt() {
  while (m_head_p != nullptr) {
    Node* temp_p = m_head_p->next_p;

    //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // Delete the node
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    assert(false && "Replace this with destructor code");
  }
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt(const SListInt& lst) {
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while (curr_p != nullptr) {
    push_front(curr_p->value);
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SListInt Swap
//------------------------------------------------------------------------

void SListInt::swap(SListInt& lst) {
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement swap
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  assert(false && "Replace this with your swap code");
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=(const SListInt& lst) {
  SListInt tmp(lst);  // create temporary copy of given list
  swap(tmp);          // swap this list with temporary list
  return *this;       // destructor called for temporary list
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front(int v) {
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement push_front
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  assert(false && "Replace this with your push_front code");
}

//------------------------------------------------------------------------
// SListInt::size
//------------------------------------------------------------------------

int SListInt::size() const {
  int n = 0;

  Node* curr_p = m_head_p;
  while (curr_p != nullptr) {
    n++;
    curr_p = curr_p->next_p;
  }

  return n;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int SListInt::at(int idx) const {
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  assert(false && "Replace this with your at code");
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int& SListInt::at(int idx) {
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement at
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  assert(false && "Replace this with your at code");
}

//------------------------------------------------------------------------
// SListInt::reverse_v1
//------------------------------------------------------------------------
// Pseudocode for this algorithm:
//
//  def reverse( x, n ):
//    for i in 0 to n/2:
//      lo = i
//      hi = (n-1) - i
//      swap( x[lo], x[hi] )
//

void SListInt::reverse_v1() {
  //''' LAB TASK '''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  // Implement reverse_v1
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  assert(false && "Replace this with your reverse_v1 code");
}

//------------------------------------------------------------------------
// SListInt::reverse_v2
//------------------------------------------------------------------------
// Steps for this algorithm:
//
//  1. Create temporary singly linked list
//  2. Push front all values from this list onto temporary list
//  3. Swap this list with the temporary list
//

void SListInt::reverse_v2() {
  // Step 1. Create temporary list
  SListInt lst;

  // Step 2. Push front all values from this list onto temporary list
  Node* curr_p = m_head_p;
  while (curr_p != nullptr) {
    lst.push_front(curr_p->value);
    curr_p = curr_p->next_p;
  }

  // Step 3. Swap this list with temporary list
  swap(lst);
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const {
  Node* curr_p = m_head_p;
  while (curr_p != nullptr) {
    std::printf("%d ", curr_p->value);
    curr_p = curr_p->next_p;
  }
  std::printf("\n");
}
