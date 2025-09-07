#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

void ULListStr::push_back(const std::string& val)
{
  if(size_ == 0)
  {
      Item* newItem = new Item();
      newItem->prev = nullptr;
      newItem->next = nullptr;
      newItem->first = 0;
      newItem->last = 1;
      newItem->val[0] = val;
      head_ = newItem;
      tail_ = newItem;
  }
  else
  {
    Item* temp = tail_;
    if (temp->last == ARRSIZE)
    {
      Item* newItem = new Item();
      newItem->prev = temp;
      newItem->next = nullptr;
      newItem->first = 0;
      newItem->last = 1;
      newItem->val[0] = val;
      temp->next = newItem;
      tail_ = newItem;
    }
    else
    {
      temp->val[temp->last] = val;
      ++temp->last;
    }
  }
  ++size_;
}

void ULListStr::pop_back()
{
  Item* temp = tail_;
  temp->val[temp->last-1].clear();
  --temp->last;
  --size_;

  if (temp->last - temp->first == 0)
  {
    Item* old = tail_;
    tail_ = temp->prev;
    if(tail_ != nullptr)
    {
      tail_->next = nullptr;
    }
    else
    {
      head_ = nullptr;
    }
    delete old;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(size_ == 0)
  {
      Item* newItem = new Item();
      newItem->prev = nullptr;
      newItem->next = nullptr;
      newItem->first = ARRSIZE - 1;
      newItem->last = ARRSIZE;
      newItem->val[ARRSIZE-1] = val;
      head_ = newItem;
      tail_ = newItem;
  }
  else
  {
    Item* temp = head_;
    if (temp->first == 0)
    {
      Item* newItem = new Item();
      newItem->prev = nullptr;
      newItem->next = temp;
      newItem->first = ARRSIZE - 1;
      newItem->last = ARRSIZE;
      newItem->val[ARRSIZE-1] = val;
      temp->prev = newItem;
      head_ = newItem;
    }
    else
    {
      temp->val[temp->first-1] = val;
      --temp->first;
    }
  }
  ++size_;
}

void ULListStr::pop_front()
{
  Item* temp = head_;
  temp->val[temp->first].clear();
  ++temp->first;
  --size_;

  if (temp->last - temp->first == 0)
  {
    Item* old = head_;
    head_ = temp->next;
    if (head_ != nullptr)
    {
      head_->prev = nullptr;
    }
    else
    {
      tail_ = nullptr;
    }
    delete old;
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t counter = 0;
  std::string* ptr = nullptr;
  Item* temp = head_;

  while (counter <= loc)
  {
    for (size_t i = temp->first; i < temp->last; i++)
    {
      if (counter == loc)
      {
        ptr = &(temp->val[i]);
        return ptr;
      }
      ++counter;
    }
    temp = temp->next;
  }

  return ptr;
}