//cache design Learning Example
//(c) java-blog.com
// 06/08/2015
// Cache cannot be a stack or a queue as deleting can be based on any criterion 

package com.cacheDesgin;

import java.util.LinkedHashMap;
import java.util.Map;

public class LinkedHashMapExample {
    private final static int CACHE_MAX_SIZE = 100;
    private LinkedHashMap<String, Integer> cache;

    @SuppressWarnings("serial")
    public LinkedHashMapExample() {
        this.cache = new LinkedHashMap<String, Integer>(CACHE_MAX_SIZE, 0.75f, true){
              protected boolean removeEldestEntry(
		Map.Entry<String, Integer> eldest) {
		   //Remove the eldest entry if cache exceeds MAX
		   return size() > CACHE_MAX_SIZE;
		}
     }
}

public Integer getIdForName(String name){
     Integer id = cache.get(name);

     if(id!=null)
	return id;

     else {
	id = getIdForNameFromExternal(name);
	cache.put(name, id);
	return id;	
     }
}

private Integer getIdForNameFromExternal(String name){
    return 1; 
}

}
