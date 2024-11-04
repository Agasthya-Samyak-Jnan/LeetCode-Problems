#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-browser-history/
// Difficulty : Medium 

/* BASIC USAGE OF DOUBLY-LINKED LIST */

// Using Seperate Objects for Page and Browser History Maintainer.
// Page Object (Doubly-Linked List Node)
class Page {
public:
    string url;
    Page* prev, *next;
    
    Page (string url) { 
        prev = next = nullptr; 
        this->url = url;
    }
    
    Page (string url, Page* prev) {
        this->prev = prev;
        this->url = url;
        next = nullptr;
    }  
};

// Browser Object (Head Node)
class BrowserHistory {
public:
    Page* page;
    
    BrowserHistory(string homepage) {
        this->page = new Page(homepage);
    }
    
    void visit(string url) {
        page->next = new Page(url,page);
        page = page->next;
    }
    
    string back(int steps) {
        while (page->prev && steps) {
            page = page->prev;
            steps--;
        }
        return page->url;
    }
    
    string forward(int steps) {
        while (page->next && steps) {
            page = page->next;
            steps--;
        }
        return page->url;
    }
};

// Using BrowserHistory Object itself as Node for Doubly-Linked List.
class BrowserHistory {
public:
    BrowserHistory* page, *prev, *next;
    string url;
    
    BrowserHistory(string homepage) {
        this->page = this;
        this->url = homepage;
        prev = next = nullptr;
    }
    
    BrowserHistory(string homepage, BrowserHistory* prev) {
        this->page = this;
        this->url = homepage;
        this->prev = prev;
        next = nullptr;
    }
    
    void visit(string url) {
        page->next = new BrowserHistory(url,page);
        page = page->next;
    }
    
    string back(int steps) {
        while (page->prev && steps) {
            page = page->prev;
            steps--;
        }
        return page->url;
    }
    
    string forward(int steps) {
        while (page->next && steps) {
            page = page->next;
            steps--;
        }
        return page->url;
    }
};
