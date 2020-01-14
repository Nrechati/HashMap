# Welcome to HashMap

This project is homemade **HashMap** lib written in **C**

This was first implemented as a ressources in my [42sh]([https://github.com/Nrechati/42sh](https://github.com/Nrechati/42sh)) project. The idea was to implement a first **generic, scalable, easy to use, "black box" library**, while still maintaining acceptable **performance** and a **low collision rate**. The goal was also to introduce myself to this strong data structure by coding one from scratch my self.

>  **Note** : 42 also forbid us to use standard lib in almost every case. Thus recoding this design pattern from scratch was my only way to use it in a school project.

## How to run

- Clone this repository `git clone https://github.com/Nrechati/HashMap.git`

- Just `Make`

>**Note** : This project page is here to just **show the codebase** related to my HashMap. It compile just **my old libC with my HashMap** sources and give a **main** to test it. This lib was then integrated to my new homemade LibC for other project such as [42sh]([https://github.com/Nrechati/42sh]). So if you're here you cant more or less only **read this**  **README** and **look at my code** to see my own implementation. Feel free to do the workaround to include sources in your own lib if needed.

## Core feature

This lib is there to provide interfaces to

- Create a Hash table

- Hash key and add new item to the table

- Remove items or free the table

- Resize itself *(Expand or Shrink depending on saturation, see more on Optimization section)*

> Part of the behavior was based on Python3 dictionary behavior which is another key-value data structure

## Features Description

This section aim to give a quick understanding of named feature in previous section.

- **Create Hash Table** : This will be done at initialization. The functions used to perform this will return an array of linked list head to handle collisions (more on this later). You specify a starting size for the array, and the lib instantiate it and give back a **t_hash** with the tab, his current saturation (should be 0 at start), and the size.

- **Hash key and add an item** : This is the main feature of every key-value data structure. This consist for going through a hash function which will always give the same index in the table for a given key. To add a key, the lib will hash the new key and assign the value of this key in the given table index. But as the hash function is a rather simple one, this lib has to handle collision *(i.e different key having the same hash index)*. This is why the table is an array of linked list head, so we can add to an index's list several values and going threw a short linked list in the worst case is acceptable.
- **Removing item and/or free the table** : This feature is handled via several function allowing and easy way to remove any key-value while handling freeing the data and keep the table clean. This is done by allowing the user to give his own callback to free his data as pointer in the functions handling this feature. Functions are also created to wipe the entire table both the data in it and the hash map structure.
- **Resizing** : The goal of this feature is to allow the hash table to scale right in any situation while remaining memory efficient. The details about this are in the *Optimization* section. But the general idea is that the table will grow if too much saturated and shrink if taking to much memory.

## Usage and Function descriptions

This section will explain how to use the program *(note that all key-binds also appear in the menu inside the window)*

### Usage

This section will go over standard function the user should call to use the hash map lib.

- **init** :  	Use **`t_hash ft_hmap_init(size_t size)`** to init your hash table with a given `size`
- **add** :	Use **`int  ft_hmap_insert(t_hash *hashmap, char *key, void *data)`** to add a new key to any initialized table.
- **access** : Use **`void *ft_hmap_getdata(t_hash *hashmap, char *key)`** to get the value stored for any given key
- **remove** : Use **`int  ft_hmap_remove(t_hash *hashmap, char *key, void (*del)(void *))`** to remove any given key of the table. the **`del`** function is for you give the right function to free your data if needed.
- **wipe table** : Use **`void  ft_hmap_free_content(t_hash *hashmap, void (*del)(void *))`** to wipe all the hash table content. Again, using a **`del`** function to handle specific data free needs.
- **print & debug** : The **`ft_hmap_print.c`** file contains several functions allowing different type of print for debugging and showing the table state.

>**ft_hmap_hits** : is another function used by the lib to know how many times a key has been accessed.

### Hash function

The hash function used for this library is **Jenkins one at a time** hash function. For more in depth explanation look at [Wikipedia](https://en.wikipedia.org/wiki/Jenkins_hash_function).  I choose this function because I wanted a rather *simple* hash with good performance and low collisions. My choice is more or less the result of some documentation and benchmark of several functions.

> **Note :** See **ft_hash_str.c** file to see my implementation of this.

## Optimization

### Shrink and Expand

As told before in this documentation, the hash table is able to shrink and expand to stay memory efficient.

- **Expand** : If when a new key is added, the hash table is filled at more than 70%, a new doubled-sized table will be created, all keys-values, re-hashed and put in the new table, and the old one wiped and freed.
- **Shrink** : If when a key is removed, the hash table is filled at less than 30%, the opposite is done : create and fill a new table with a 2-divided size and wipe/free the old one.

### Binary Shift

Even if this might not be useful or even optimal as compiler does a lot regarding that, this project introduced me a lot more to optimisation and binary shift, so I wanted to go further. As the *Shrink / Expand* table saturation check is a cost, I wanted to perform % check on the table. So I decided to not check 70 or 30% (i.e. 70 **/100** and 30 **/100**), but **/128** (*i.e. `2^7`*). This allow to check saturation via binary shift operations and not `*100` and `/100` every time. As said, maybe not useful, but i liked the idea.

## Disclaimer

This project was done in a **single week** and is my **first own library**. I had the need of an Hash map lib for my unix shell project *(see [42sh](https://github.com/Nrechati/42sh) project)*, so I built one. But since, I started to use it in a lot of project because I just find it to be a really strong data structure is some cases. I know a lot a this **C implementation could be nicer,** more optimize, and a lot of feature could have been added. **So just keep in mind this is an early student work**.
