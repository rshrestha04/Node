/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
#include "node2.hpp"
#include <cassert>

namespace csis3700{

    template <typename ValueType>
    class sequence{
        public:
            
            class iterator{
            public:
                iterator(main_savitch_6B::node<ValueType>* initial = nullptr){current = initial; previous= nullptr; }
                
                ValueType& operator *( ) const { return current->data( ); }
                
                iterator& operator ++( ) { 
                    previous=current;
                    current = current->link( );
                    return *this;
                 }
                
                iterator operator ++(int){
                    iterator original = *this;
                    previous=current;
                    current = current->link( );
                    return original;      	  
                }
            
                bool operator ==(const iterator other) const{
                    return current == other.current; 
                }
                 bool operator !=(const iterator other) const{
                    return current != other.current; 
                }
                 
                 void discard(main_savitch_6B::node<ValueType>* &head){
                     if(current==head){
                        current=current->link();
                        head=current;
                        return;
                    }
                     main_savitch_6B::node<ValueType>* cursor = current;
                     previous->set_link(current->link());
                     delete cursor;
                     return;
                     
                 }
                
            private:
                main_savitch_6B::node<ValueType>* current;
                main_savitch_6B::node<ValueType>* previous;
            };
            
          
            
            sequence<ValueType>::iterator begin(){return iterator(head);}
            
            sequence<ValueType>::iterator end(){return iterator();}
            
            void erase(sequence<ValueType>::iterator it){
                it.discard(head);
                used--;
                return;
            }
              
             
             
             
             
             
            sequence(){
                head=nullptr;
                used=0;
            }
            
            ~sequence();
            
            
            sequence(const sequence& other);
            
            std::size_t size() const {return used;}
            ValueType& at(std::size_t i);
            const ValueType& at(std::size_t i) const;
            void add(const ValueType& value);
            
            ValueType& operator[](std::size_t i);
            const ValueType& operator[](std::size_t i) const;
            bool empty()const ;
            void insert(std::size_t index,const ValueType& value);
            void remove(std::size_t index);
            void operator +=(const sequence& other);
            void operator =(const sequence& other);
            
            
        
        
        
        
        private:
            main_savitch_6B::node<ValueType> *head;         //list head pointer
            std::size_t used;                   //number of nodes on the list
             main_savitch_6B::node<ValueType>* att(std::size_t i);
            const main_savitch_6B::node<ValueType>* att(std::size_t i) const;
    
    };
    
   
     
    
    
    template <typename ValueType> 
    sequence<ValueType>::sequence(const sequence& other){
    
        main_savitch_6B:: node<ValueType>* cursor= nullptr;
        for (const main_savitch_6B::node<ValueType>* other_cursor=other.head;
            other_cursor!=nullptr;
            other_cursor= other_cursor->link()){
            main_savitch_6B::node<ValueType>* cursor1= new main_savitch_6B::node<ValueType>(other_cursor->data());
            if(cursor==nullptr){
                head=cursor1;
            }
            else cursor->set_link(cursor1);
            
            cursor= cursor1;
        }
        used=other.used;
        
    }
    
     template<typename ValueType>
    sequence<ValueType>::~sequence(){
        
        while(head!=NULL){
            main_savitch_6B:: node<ValueType>* cursor = head->link();
            delete head;
            head=cursor;
        }
        used=0;
        
    }
      
    
    template <typename ValueType> 
    main_savitch_6B::node<ValueType>* sequence<ValueType>::att(std::size_t i){
        main_savitch_6B::node<ValueType> *cursor =new main_savitch_6B::node<ValueType>();
        cursor=head;
        for(int x=0;x<i;x++){
           cursor= cursor->link(); 
        }
        
        return cursor;
        
    }
    
    template <typename ValueType>
    const main_savitch_6B::node<ValueType>* sequence<ValueType>::att(std::size_t i)const{
        main_savitch_6B::node<ValueType> *cursor =new main_savitch_6B::node<ValueType>();
        cursor=head;
        for(int x=0;x<i;x++){
           cursor= cursor->link(); 
        }
        
        return cursor;
        
    }
    
    template <typename ValueType> 
    ValueType& sequence<ValueType>::at(std::size_t i){
        assert(used > i);
        main_savitch_6B::node<ValueType> *location =new main_savitch_6B::node<ValueType>();
        location =att(i);
        return location->data();
        
    }
    
    template <typename ValueType> 
    const ValueType& sequence<ValueType>::at(std::size_t i) const{
        assert(used>i);
        const main_savitch_6B::node<ValueType> *location =new main_savitch_6B::node<ValueType>();
        location =att(i);
        return location->data();
        
    }
    
    
    template<typename ValueType>
    ValueType& sequence<ValueType>::operator[](std::size_t i){
        main_savitch_6B::node<ValueType> *location =new main_savitch_6B::node<ValueType>();
        location =att(i);
        return location->data();
        
    }
    
     template<typename ValueType>
    const ValueType& sequence<ValueType>::operator[](std::size_t i)const {
        const main_savitch_6B::node<ValueType> *location =new main_savitch_6B::node<ValueType>();
        location =att(i);
        return location->data();
        
    }
    
    
    template <typename ValueType> 
    void sequence<ValueType>::add(const ValueType& value){
        if (used==0){
            head =new main_savitch_6B::node<ValueType>();
            head->set_data(value);
            used++;
       
            return;
        }
         main_savitch_6B::node<ValueType> *cursor =new main_savitch_6B::node<ValueType>();
        cursor->set_data(value);
        used++;
        cursor->set_link(nullptr);

        main_savitch_6B::node<ValueType> *cursor1 =head;
        while(cursor1->link() !=nullptr){
            cursor1=cursor1->link();
        }
        cursor1->set_link(cursor);
        return; 
    }
    
    template <typename ValueType> 
    bool sequence<ValueType>::empty()const{
        return head==nullptr;
    }
    
    template <typename ValueType> 
    void sequence<ValueType>::insert(std::size_t index,const ValueType& value){
    assert(index<=used);  
     
    main_savitch_6B::node<ValueType>* cursor = new main_savitch_6B::node<ValueType>();
    cursor->set_data(value);
    used++;
    cursor->set_link(nullptr);
    if (index==0){
        cursor->set_link(head);
        head=cursor;
        return;
    }
    main_savitch_6B::node<ValueType>* cursor1=head;
    for(int x=0;x<index-1;x++){
        cursor1=cursor1->link();
    }
    cursor->set_link(cursor1->link());
    cursor1->set_link(cursor);
    return;
    
    }
    template <typename ValueType>
    void sequence<ValueType>::remove(std::size_t index){
        assert(index<used);
        
        main_savitch_6B::node<ValueType>* cursor =head;
        if (index==0){
            head=cursor->link();
            used--;
            delete cursor; 
            return ;
        }
        for(int x=0;x<index-1;x++){
            cursor=cursor->link();
        }
        main_savitch_6B::node<ValueType>* cursor1=cursor->link();
        cursor->set_link(cursor1->link());
        used--;
        delete cursor1;
         
    }
    
    template <typename ValueType>
    void sequence<ValueType>::operator +=(const sequence<ValueType>& other){
        
        if (head==nullptr){
            sequence<ValueType> answer(other);
            head=answer.head;
            answer.head = nullptr;   // making the pointer of copy point to null avoids deleting the same file twice 
            
            used=other.used;
            return;
        }
        
        if (other.empty()){
            return;
        }
        
        main_savitch_6B::node<ValueType>* cursor = head;
        
        
        
        while (cursor->link()!=nullptr){
            cursor=cursor->link();
        }
        
        sequence<ValueType> answer(other);
        cursor->set_link(answer.head);
        answer.head=nullptr;
        used+= other.used;
        
        return;
        
        
        
    }
    
    template <typename ValueType>
    sequence<ValueType> operator +(const sequence<ValueType>& s1, const sequence<ValueType>& s2){
    
        sequence<ValueType> answer;
        answer+=s1;
        answer+=s2;
        return answer;
        
    }
    template <typename ValueType>
    void sequence<ValueType>::operator =(const sequence<ValueType>& other){
        if (this==&other) return;
        sequence<ValueType> answer(other);
        delete head;
        head=nullptr;
        head= answer.head;
        answer.head=nullptr;
        used= other.used;
        return;
    }
    
    
    
    

}

#endif /* SEQUENCE_H */

