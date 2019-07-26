#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}();

typedef std::pair<int,int> cache_item_type;
typedef std::list<cache_item_type> cache_type;
typedef std::map <int,cache_type::iterator> cache_map_type;

class LRUCache 
{
private:
    int capacity;
    cache_type cache;
    cache_map_type cache_map;
public:
    LRUCache(int capacity_):capacity(capacity_){};
    int get(int key) 
    { 
      if( cache.size() == 0 || cache_map.find(key) == cache_map.end()) return -1;
      auto ele = cache_map[key];      
      if(ele == cache.end()) return -1;
      int value = (*ele).second;
      cache.erase(ele);
      cache.push_front({key,value});
      cache_map[key] = cache.begin();
      return value;
    }
    
    void put(int key, int value) 
    {
      if(cache_map.find(key) != cache_map.end() && cache_map[key] != cache.end())
      {
        auto ele = cache_map[key];
        cache.erase(ele);
        cache.push_front({key,value});
        cache_map[key] = cache.begin();
        return;
      }
      if( cache.size() < capacity)
      {
        cache.push_front({key,value});
        cache_map[key] = cache.begin();
      }
      else if( cache.size() == capacity)
      {
        auto last = cache.back();
        int oldkey = last.first;
        cache_map[oldkey]=cache.end();
        cache.pop_back();
        cache.push_front({key,value});
        cache_map[key] = cache.begin();
      }
    }
};
int main(int argc, char const *argv[])
{
  LRUCache cache ( 10 /* capacity */ );

  // std::cout<<std::endl<<cache.get(2);
  // cache.put(2, 6);
  // std::cout<<std::endl<<cache.get(1);
  // cache.put(1, 5);
  // cache.put(1, 2);
  // std::cout<<std::endl<<cache.get(1);
  // std::cout<<std::endl<<cache.get(2);
  // cache.put(10, 13);
cache.put(3, 17);
cache.put(6, 11);
cache.put(10, 5);
cache.put(9, 10);
cache.get(13);
cache.put(2, 19);
cache.get(2);
cache.get(3);
cache.put(5, 25);
cache.get(8);
cache.put(9, 22);
cache.put(5, 5);
cache.put(1, 30);
cache.get(11);
cache.put(9, 12);
cache.get(7);
cache.get(5);
cache.get(8);
cache.get(9);
cache.put(4, 30);
cache.put(9, 3);
cache.get(9);
cache.get(10);
cache.get(10);
cache.put(6, 14);
cache.put(3, 1);
cache.get(3);
cache.put(10, 11);
cache.get(8);
cache.put(2, 14);
cache.get(1);
cache.get(5);
cache.get(4);
cache.put(11, 4);
cache.put(12, 24);
cache.put(5, 18);
cache.get(13);
cache.put(7, 23);
cache.get(8);
cache.get(12);
cache.put(3, 27);
cache.put(2, 12);
cache.get(5);
cache.put(2, 9);
cache.put(13, 4);
cache.put(8, 18);
cache.put(1, 7);
cache.get(6);
cache.put(9, 29);
cache.put(8, 21);
cache.get(5);
cache.put(6, 30);
cache.put(1, 12);
cache.get(10);
cache.put(4, 15);
cache.put(7, 22);
cache.put(11, 26);
cache.put(8, 17);
cache.put(9, 29);
cache.get(5);
cache.put(3, 4);
cache.put(11, 30);
cache.get(12);
cache.put(4, 29);
cache.get(3);
cache.get(9);
cache.get(6);
cache.put(3, 4);
cache.get(1);
cache.get(10);
cache.put(3, 29);
cache.put(10, 28);
cache.put(1, 20);
cache.put(11, 13);
cache.get(3);
cache.put(3, 12);
cache.put(3, 8);
cache.put(10, 9);
cache.put(3, 26);
cache.get(8);
cache.get(7);
cache.get(5);
cache.put(13, 17);
cache.put(2, 27);
cache.put(11, 15);
cache.get(12);
cache.put(9, 19);
cache.put(2, 15);
cache.put(3, 16);
cache.get(1);
cache.put(12, 17);
cache.put(9, 1);
cache.put(6, 19);
cache.get(4);
cache.get(5);
cache.get(5);
cache.put(8, 1);
cache.put(11, 7);
cache.put(5, 2);
cache.put(9, 28);
cache.get(1);
cache.put(2, 2);
cache.put(7, 4);
cache.put(4, 22);
cache.put(7, 24);
cache.put(9, 26);
cache.put(13, 28);
cache.put(11, 26);

  // std::cout<<std::endl<<cache.get(1);       // returns 1
  // cache.put(3, 3);    // evicts key 2
  // std::cout<<std::endl<<cache.get(2);       // returns -1 (not found)
  // cache.put(4, 4);    // evicts key 1
  // std::cout<<std::endl<<cache.get(1);       // returns -1 (not found)
  // std::cout<<std::endl<<cache.get(3);       // returns 3
  // std::cout<<std::endl<<cache.get(4);       // returns 4

  return 0;
}