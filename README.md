# Welcome to HashMap

This project is homemade **HashMap** lib written in **C**
This was first implemented as a ressources in my [42sh]([https://github.com/Nrechati/42sh](https://github.com/Nrechati/42sh)) project. The idea was to implement a first **generic, scalable, easy to use, "black box" library**, while still maintaining acceptable **performance** and a **low collision rate**. The goal was also to introduce myself to this strong data structure by coding one from scratch my self.

> **Note** : 42 also forbid us to use standard lib in almost every case. Thus recoding this design pattern from scratch was my only way to use it in a school project.


## How to run

- Clone this repository  `git clone https://github.com/Nrechati/HashMap.git`
- Just `Make`

>**Note** : This project page is here to just **show the codebase** related to my HashMap. It compile just **my old libC with my HashMap** sources and give a **main** to test it. This lib was then integrated to my new homemade LibC for other project such as [42sh]([https://github.com/Nrechati/42sh]). So if you're here you cant more or less only **read this** **README** and **look at my code** to see my own implementation. Feel free to do the workaround to include sources in your own lib if needed.

## Core feature

This lib is there to provide interfaces to

- Create a Hash table
- Hash key and add to item to the table
- Remove items or free the table
- Resize itself *(Expand or Shrink depending on saturation, see more on Optimization section)*

> Part of the behavior was based on Python3 dictionary behavior which is another key-value data structure

## Additional Features

In addition to core feature *(i.e mandatory part of the subject)*, few features have been added such as :

- Basic **Multi-Threading** via `pthread`,  splitting the window according to `THREAD` define value
- **Menu** displaying allowed user **input**  and optional **Zoom** and **Iterations** values
-  Modify **iterations** count
- **Switching** live between **Fractales**
- **Modifying and Freezing Julia's zero value** based on cursor x/y
- **Reseting** view

## Usage and Function descriptions

This section will explain how to use the program *(note that all key-binds also appear in the menu inside the window)*

### Usage
Lorem Ipsum
### Function description
Lorem Ipsum
### Hash function
Lorem Ipsum


## Optimization

### Binary Shift
Lorem Ipsum

### Shrink and Expand
Lorem Ipsum

## Disclaimer

This project was done in a **single week** and is one of my **early C project @42 Paris**. In particular regarding graphic computing. But it is also one of the first I was proud to show so I decided to keep it public. I know a lot a this **C implementation could be nicer,** more optimize, and a lot of feature could have been added. **So just keep in mind this is an early student work**.
