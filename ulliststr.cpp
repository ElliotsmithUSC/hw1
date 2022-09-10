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

void ULListStr::push_back(const std::string& val){
	size_++;
	if(tail_ == NULL){
		Item* newitem = new Item();
		head_ = newitem;
		tail_ = newitem;
		tail_->val[0] = val;
		head_->val[0] = val;
		tail_->first = 0;
		head_->first = 0;
		tail_->last = 0;
		head_->last = 0;
		tail_->last += 1;
	}
  else if(tail_->last==10){
    Item* newitem = new Item();
    newitem->prev = tail_;
    //tail_->next = newitem->next;
    tail_ = newitem;
		head_->next = newitem;
    tail_->val[0] = val;
    tail_->last += 1;
  }
  else if(tail_ != NULL){
		tail_->val[tail_->last] = val;
    tail_->last++;
  }
}

void ULListStr::pop_back(){
	size_--;
  if((tail_->last)-1 == tail_->first){
		if(tail_->prev == tail_){
			tail_->prev = NULL;
		}
		Item *temp = tail_->prev;
    //delete tail_;
    tail_ = temp;
  }
  else {
   tail_->last -= 1;
  }
}

void ULListStr::push_front(const std::string& val){
	size_++;
	if(head_ == NULL){
		Item* newitem = new Item();
		head_ = newitem;
		tail_ = newitem;
		head_->val[0] = val;
		tail_->val[0] = val;
		head_->first =0;
		tail_->first =0;
		head_->last =0;
		tail_->last =0;
		head_->last++;
	}
  else if(head_->first == 0 && head_->last != 0){
    Item* newitem = new Item();
    newitem->next = head_;
    head_->prev = newitem;
    head_ = newitem;
    head_->val[9] = val;
    head_->last = 10;
    head_->first = 9;
  }
  //else if(head_ != NULL && head_->first == 0 && head_->last == 0){
    //ULListStr::set(head_->last, val);
    //head_->last++;
  //}
  else if(head_ != NULL){
    head_->first--;
		head_->val[head_->first] = val;
  }
}

void ULListStr::pop_front(){
	size_--;
  if((head_->first)+1 == head_->last){
		head_->first = 0;
		head_->last = 0;
		Item *temp = head_->next;
    // delete head_;
		if(!empty()){
    	head_ = temp;
		}
  }
  else{
    head_->first += 1;
  }
}

std::string const & ULListStr::back() const{
	std::string* storage = &tail_->val[(tail_->last)-1];
	return *storage;
}

std::string const & ULListStr::front() const{
	std::string* storage = &head_->val[head_->first];
	return *storage;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
	unsigned int locationcount = 0;
	if(head_ == NULL){
		return NULL;
	}
	bool newnode = false;
	Item* tempcurrent = head_; 
	for(unsigned int i=tempcurrent->first; i <= (size_ + tempcurrent->first); i++){
		if(locationcount == loc){
			if(newnode == true){
				i--;
			}
			std::string* storage = &tempcurrent->val[i];
			return storage;
		}
		locationcount++;
		if((i == (tempcurrent->last - 1) && locationcount != loc) || i == 9){
			tempcurrent = tempcurrent->next;
			i = tempcurrent->first;
			newnode = true;
			if(loc != locationcount){
				loc--;
			}
		}
		
	}
	return NULL;
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location1");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location2");
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
	if(head_->next == head_){
		head_->next = NULL;
	}
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
