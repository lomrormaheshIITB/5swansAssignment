#ifndef FB_ENCODER_CPP_
#define FB_ENCODER_CPP_


#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>

#include "../flatbuffers/include/flatbuffers/flatbuffers.h"
using namespace std;

enum gender {Male, Female};

typedef Person {
    char Name[20];
    int Age;
    float Weight;
    gender Gender;

    Person(const string& name, int age, float weight, gender gen){
        strncpy(Name, name.c_str(), sizeof(Name)-1);
        Name[sizeof(Name)-1] = '\0'; /* Ensure null-terminated string*/
        Age = age;
        Weight = weight;
        Gender = gen;
    }
} Person;


typedef struct Group {
    char GroupName[20];
    float AverageAge;
    float AverageWeight;
    vector<string> Names;

    Group(const string& gname, float avgAge, float avgW, vector<string> pnames) {
        strncpy(GroupName, gname.c_str(), sizeof(GroupName)-1);
        GroupName[sizeof(GroupName)-1] = '\0'; /* Ensure null-terminated string */
        AverageAge = avgAge;
        AverageWeight = avgW;
        Names.reserve(pnames.size());
        for(int i=0; i<pnames.size(); i++)
            Names[i] = pnames[i];
    }
} Group;

int main(int /*argc*/, const char* /*argv*/[]) {
    // Build a serialized buffer algorithmically:
    flatbuffers::FlatBufferBuilder builder;
}


#endif /* FB_ENCODER_CPP_ */