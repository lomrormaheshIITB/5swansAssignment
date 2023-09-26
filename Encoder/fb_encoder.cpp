#ifndef FB_ENCODER_CPP_
#define FB_ENCODER_CPP_


#include <iostream>
#include <vector>
#include <string>

#include "../flatbuffers/client_generated.h"

using namespace std;
using namespace MyNamespace;

// enum Gender : int8_t {
//     Male = 0, 
//     Female = 1
// };

typedef struct Person {
    char name[20];
    int age;
    float weight;
    Gender gender;

    Person(const string& p_name, int p_age, float p_weight, Gender p_gender){
        strncpy(name, p_name.c_str(), sizeof(name)-1);
        name[sizeof(name)-1] = '\0'; /* Ensure null-terminated string*/
        age = p_age;
        weight = p_weight;
        gender = p_gender;
    }
} Person;


typedef struct Group {
    char groupName[20];
    float avgAge;
    float avgWeight;
    vector<string> names;

    Group(const string& g_groupname, float g_avgAge, float g_avgWeight, vector<string> g_names) {
        strncpy(groupName, g_groupname.c_str(), sizeof(groupName)-1);
        groupName[sizeof(groupName)-1] = '\0'; /* Ensure null-terminated string */
        avgAge = g_avgAge;
        avgWeight = g_avgWeight;
        names.reserve(g_names.size());
        for(int i=0; i<g_names.size(); i++)
            names[i] = g_names[i];
    }
} Group;

void PersonToBinary() {
    flatbuffers::FlatBufferBuilder builder;
    auto person_name = builder.CreateString("Ram");
    auto person_age = 21;
    auto person_weight = 76.5;
    auto person_gender = Gender::Gender_Male;

    auto orc = CreateClient(builder, person_name, person_age, person_weight, person_gender, 0, false);
    builder.Finish(orc);

    printf("The FlatBuffer for Client Person is successfully created!\n");
}

void GroupToBinary() {
    flatbuffers::FlatBufferBuilder builder;
    auto group_name = builder.CreateString("FightClub");
    auto group_age = 24.5;
    auto group_w = 66;
    auto member_vec = builder.CreateVectorOfStrings({"Ram", "Shyam", "Raghuveer"});

    auto orc = CreateClient(builder, group_name, group_age, group_w, Gender_Male, member_vec, true);
    builder.Finish(orc);

    printf("The FlatBuffer for Client Group is successfully created!\n");
}


int main(int /*argc*/, const char* /*argv*/[]) {
    PersonToBinary();
    
}


#endif /* FB_ENCODER_CPP_ */