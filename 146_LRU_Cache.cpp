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
      //cache不存在这个key
      if(not cache_map.count(key)) return -1;

      auto ele = cache_map[key];
      //cache中存在这个key,根据key得到对应的链表节点,插入到front
      cache.splice(cache.begin(), cache, ele);
      return (*ele).second;
    }
    
    void put(int key, int value) 
    {

      if(cache_map.count(key))
      {//cache中已经存在这个key了,更新value,然后promote对应的链表节点
        auto ele = cache_map[key];
        (*ele).second=value;
        cache.splice(cache.begin(), cache, ele);
        return;
      }
      if( cache.size() == capacity)
      {//cache已满,把最后一个删掉,既要从map中删,也要从list中删
        auto last = cache.back();
        int oldkey = last.first;
        cache_map.erase(oldkey);
        cache.pop_back();
      }
      //在front创建一个key,value,map保存key和对应的iterator
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