/***********************************************************************
 * Module:
 *    Stack
 * Summary:
 *    Our custom implementation of std::stack
 *
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 * Author
 *    Sam Heaven, Abram Hansen 
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <vector>

class TestStack; // forward declaration for unit tests

namespace custom
{

/**************************************************
 * STACK
 * First-in-Last-out data structure
 *************************************************/
template<class T>
class stack
{
   friend class ::TestStack; // give unit tests access to the privates
public:
  
   // 
   // Construct
   // 

   stack()                            {  }
   stack(const stack <T> &  rhs)      { container = std::move(rhs.container); }
   stack(      stack <T> && rhs)      { container = std::move(rhs.container); }
   stack(const std::vector<T> &  rhs) { container = rhs.container; }
   stack(      std::vector<T> && rhs) { container = rhs.container; }
   ~stack()                           {                      }

   //
   // Assign
   //

   //copies values
   stack <T> & operator = (const stack <T> & rhs)
   {
      this->container = rhs.container;
      return *this;
   }

   //steals values
   stack <T>& operator = (stack <T> && rhs)
   {
      container = std::move(rhs.container);
      return *this;
   }

   //swaps values
   void swap(stack <T>& rhs)
   {
      std::swap(this->container, rhs.container); 
   }

   // 
   // Access
   //

         T& top()       { return container.back(); }
   const T& top() const { return container.back(); }

   // 
   // Insert
   // 

   void push(const T& t) { container.push_back(t); }
   void push(      T&& t) { container.push_back(std::move(t)); }

   //
   // Remove
   //

   void pop() 
   { 
      if(!empty())
         container.pop_back();
   }

   //
   // Status
   //
   size_t  size () const { return container.size(); }
   bool empty   () const { return container.empty(); }
   
private:
   
  std::vector<T> container;  // underlying container
};

} // custom namespace