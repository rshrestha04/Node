/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "catch.hpp"
#include "sequence.hpp"
using namespace csis3700;
using namespace std;

TEST_CASE("checking add","[sequence]"){
    sequence<int> a;
    a.add(1);
    a.add(2);
     a.add(3);
   REQUIRE(a.at(0)==1);
   REQUIRE(a.at(1)==2);
}

TEST_CASE("checking nullptr","[sequence]"){
    sequence<int> a;
    REQUIRE(a.empty()==true);
    a.add(1);
    a.add(2);
     a.add(3);
   REQUIRE(a.at(0)==1);
   REQUIRE(a.at(1)==2);
   REQUIRE(a.empty()==false);
   REQUIRE(a.size()==3);
}

TEST_CASE("checking insert ","[sequence]"){
    sequence<int> id;
    id.add(12);
    id.add(13);
    id.add(14);
    id.add(20);
    id.add(16);
    id.insert(1,11);
    REQUIRE(id.at(1)==11);
    REQUIRE(id.at(0)==12);
    REQUIRE(id.at(2)==13);
    REQUIRE(id.at(3)==14);
    REQUIRE(id.size()==6);
    id.insert(0,0);
    
    REQUIRE(id.at(0)==0);
    REQUIRE(id.at(1)==12);
    REQUIRE(id.at(2)==11);
    REQUIRE(id.at(3)==13);
    REQUIRE(id.size()==7);
    
    
}


TEST_CASE("checking remove","[sequence]"){
    sequence<int> id;
    id.add(12);
    id.add(13);
    id.add(14);
    id.add(20);
    id.add(16);
    id.remove(1);
    REQUIRE(id.at(0)==12);
    REQUIRE(id.at(1)==14);
     REQUIRE(id.at(2)==20);
     REQUIRE(id.size()==4);
     id.remove(0);
     REQUIRE(id.at(0)==14);
    REQUIRE(id.at(1)==20);
     REQUIRE(id.at(2)==16);
    REQUIRE(id.size()==3);
    
    
}

TEST_CASE("checking operator +=","[sequence]"){
    sequence<int> exm;
    exm.add(12);
    exm.add(24);
    exm.add(36);
    exm.add(48);
    exm.add(60);
    sequence<int> exm2;
    exm2.add(2);
    exm2.add(4);
    exm2.add(6);
    exm2.add(8);
    exm2.add(10);
    exm2.add(12);
    exm+=exm2;
    REQUIRE(exm.size()==11);
    REQUIRE(exm.at(0)==12);
    REQUIRE(exm.at(1)==24);
    REQUIRE(exm.at(2)==36);
    REQUIRE(exm.at(3)==48);
    REQUIRE(exm.at(4)==60);
    REQUIRE(exm.at(5)==2);
    REQUIRE(exm.at(6)==4);
    REQUIRE(exm.at(7)==6);
    REQUIRE(exm.at(8)==8);
    REQUIRE(exm.at(9)==10);
    REQUIRE(exm.at(10)==12);
    REQUIRE(exm2.at(0)==2);
    REQUIRE(exm2.at(1)==4);
    REQUIRE(exm2.at(2)==6);
    REQUIRE(exm2.at(3)==8);
    REQUIRE(exm2.at(4)==10);
    REQUIRE(exm2.at(5)==12);
}

TEST_CASE("checking operator += with 0 size","[sequence]"){
    sequence<int> exm2;
    sequence<int> dummy;
    exm2.add(2);
    exm2.add(4);
    exm2.add(6);
    exm2.add(8);
    exm2.add(10);
    exm2.add(12);
    dummy+= exm2;
    REQUIRE(dummy.at(0)==2);
    REQUIRE(dummy.at(1)==4);
    REQUIRE(dummy.at(2)==6);
    REQUIRE(dummy.at(3)==8);
    REQUIRE(dummy.at(4)==10);
    REQUIRE(dummy.at(5)==12);

}

TEST_CASE ("= operator","[sequence]"){
    sequence<int> eg;
    eg.add(3);
    eg.add(6);
    eg.add(9);
    eg.add(12);
    eg.add(15);
    eg.add(18);
    sequence<int> eg1;
    eg1.add(0);
    eg1.add(31);
    eg1.add(3);
    eg1.add(6);
    sequence<int> eg2;
    eg2=eg;
    REQUIRE(eg2.at(0)==3);
    REQUIRE(eg2.at(1)==6);
    REQUIRE(eg2.at(2)==9);
    REQUIRE(eg2.at(3)==12);
    REQUIRE(eg2.at(4)==15);
    REQUIRE(eg2.at(5)==18);
    REQUIRE(eg2.size()==6);
    eg2=eg1;
    REQUIRE(eg2.at(0)==0);
    REQUIRE(eg2.at(1)==31);
    REQUIRE(eg2.at(2)==3);
    REQUIRE(eg2.at(3)==6);
    REQUIRE(eg2.size()==4);
    
}
 
 

TEST_CASE("copy constructor","[sequence]"){
    sequence<int> eg;
    eg.add(3);
    eg.add(6);
    eg.add(9); 
    eg.add(12);
    eg.add(15);
    eg.add(18);
    sequence<int> eg1(eg);
    REQUIRE(eg1.at(0)==3);
    REQUIRE(eg1.at(1)==6);
    REQUIRE(eg1.at(2)==9);
    REQUIRE(eg1.at(3)==12);
    REQUIRE(eg1.at(4)==15);
    REQUIRE(eg1.at(5)==18);
    REQUIRE(eg1.size()==6);
    
    
}


TEST_CASE ("+ operator","[sequence]"){
    sequence<int> eg;
    eg.add(3);
    eg.add(6);
    eg.add(9);
    eg.add(12);
    eg.add(15);
    eg.add(18);
    sequence<int> eg1;
    eg1.add(0);
    eg1.add(31);
    eg1.add(3);
    eg1.add(6);
    sequence<int> eg2;
    eg2=eg+eg1;
    REQUIRE(eg2.at(0)==3);
    REQUIRE(eg2.at(1)==6);
    REQUIRE(eg2.at(2)==9);
    REQUIRE(eg2.at(3)==12);
    REQUIRE(eg2.at(4)==15);
    REQUIRE(eg2.at(5)==18);
   
    REQUIRE(eg2.at(6)==0);
    REQUIRE(eg2.at(7)==31);
    REQUIRE(eg2.at(8)==3);
    REQUIRE(eg2.at(9)==6);
    REQUIRE(eg2.size()==10);
    
    
    
}


TEST_CASE("testing iterator","[sequence]"){
    sequence<int> al;
    al.add(0);
    al.add(10);
    al.add(15);
    al.add(20);
    int sum=0;
    for(auto it=al.begin();it!=al.end();++it){
        sum+= *it;
    }
    
    REQUIRE(sum==45);
    
    al.erase(++al.begin());
    REQUIRE(al.at(0)==0);
    REQUIRE(al.at(1)==15);
    REQUIRE(al.at(2)==20);
    REQUIRE(al.size()==3);
    
    for(auto it=al.begin();it!=al.end();it++){
        al.erase(it);
        
    }
    
    REQUIRE(al.size()==0);
    
    
  
}

TEST_CASE("testing []","[sequence]"){
    sequence<int> a;
    a.add(0);
    a.add(10);
    a.add(15);
    a.add(20);
    REQUIRE(a[0]==0);
    
}

TEST_CASE("testing const","[sequence]"){
  sequence<int> a;
    a.add(0);
    a.add(10);
    a.add(15);
    a.add(20);
    const sequence<int> b =a;
    REQUIRE(b.at(1)==10);
    REQUIRE(b.size()==4);
    
}

TEST_CASE("testing const []","[sequence]"){
  sequence<int> a;
    a.add(0);
    a.add(10);
    a.add(15);
    a.add(20);
    const sequence<int> b =a;
    REQUIRE(b[1]==10);
    REQUIRE(b.size()==4);
    
}


TEST_CASE("testing other than int data ","[sequence]"){
    sequence<string> a;
    a.add("ronish");
    a.add("deepil");
    a.add("sekhar");
    
    REQUIRE(a.size()==3);
    REQUIRE(a.at(0)=="ronish");
    auto it=a.begin();
    REQUIRE(*(it++)=="ronish");
    REQUIRE(*it=="deepil");
    a.remove(0);
    REQUIRE(a.at(0)=="deepil");
    REQUIRE(a.at(1)=="sekhar");
    REQUIRE(a.size()==2);
    
    
}

 

 
 
