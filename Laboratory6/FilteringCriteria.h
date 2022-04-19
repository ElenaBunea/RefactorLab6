#pragma once
#include "DynamicArray.h"
#include "Offer.h"

// you can add all your filtering classes in this module
class FilteringCriteria
{
public:
    DynamicArray filter(const DynamicArray& da);
private:

};

class FilterPrice :public FilteringCriteria {
public:
    DynamicArray filter(const DynamicArray& da);
private:
    float price;
};

class FilterType :public FilteringCriteria {
public:
    DynamicArray filter(const DynamicArray& da);
private:
    string type;
};

class FilterAnd :public FilterPrice, public FilterType {
    DynamicArray filter(const DynamicArray& da);

};

/*
class FilteringCriteria
{
    virtual DynamicArray filter(DynamicArray &da);
};*/