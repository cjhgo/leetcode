#include<iostream>
#include<vector>
#include<string>
#include <list>
#include <unordered_map>
using namespace std;
static const auto x=[](){
  std::ios::sync_with_stdio(false);
  std:cin.tie(nullptr);
  return nullptr;
}();

typedef std::pair<int,int> cache_item_type;
typedef std::list<cache_item_type> cache_type;
typedef std::unordered_map <int,cache_type::iterator> cache_map_type;

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
      if(not cache_map.count(key)) return -1;      
      auto ele = cache_map[key];
      cache.splice(cache.begin(), cache, ele);
      int value = (*ele).second;
      return value;
    }
    
    void put(int key, int value) 
    {
      if(cache_map.count(key))
      {    
        auto ele = cache_map[key];
        (*ele).second=value;
        cache.splice(cache.begin(), cache, ele);
        return;
      }
      if( cache.size() == capacity)
      {
        auto last = cache.back();
        int oldkey = last.first;
        cache_map.erase(oldkey);
        cache.pop_back();
      }
      cache.emplace_front(key,value);
      cache_map[key] = cache.begin();
    }
};
int main(int argc, char const *argv[])
{
  LRUCache cache ( 2/* capacity */ );

  std::cout<<std::endl<<cache.get(1);       // returns 1
  cache.put(3, 3);    // evicts key 2
  std::cout<<std::endl<<cache.get(2);       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cache.put(3, 4);    // evicts key 1
  std::cout<<std::endl<<cache.get(1);       // returns -1 (not found)
  std::cout<<std::endl<<cache.get(3);       // returns 4
  std::cout<<std::endl<<cache.get(4);       // returns 4
  return 0;
}