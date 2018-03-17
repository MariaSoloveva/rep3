#include <iostream>
#include <stdexcept>
#include "fsm.hpp"


struct MyEx
{
    const char* message;
    explicit MyEx(const char* m)
            : message(m)
    { }

    const char* what() const
    {
        return message;
    }
};

#define EXPECT_TRUE(x) if (!(x)) { throw MyEx(#x); }
#define EXPECT_FALSE(x) if ((x)) { throw MyEx(#x); }
#define EXPECT_EXCEPTION(x) try { (x); throw MyEx(#x); } catch(std::exception&) { }

enum class Action
{
    Finding,
    Attaking,
    FindingAid,
    Killed
};

int main()
{
    FiniteStateMachine<std::string, std::string, Action> fa;

    std::map<std::string, std::string> m1 = {
            {"I've found it", "attacks"}
    };

    std::map<std::string, std::string> m2 = {
            {"killed the purpose", "looking for the purpose of"},
            {"there are few lives", "looking for a first aid kit"}
    };

    std::map<std::string, std::string> m3 = {
            {"I've found it", "looking for the purpose of"},
            {"ended life", "killed"}
    };

    std::map<std::string, std::string> m4;
    fa.AddState("looking for the purpose of", Action::Finding, m1)
            .AddState("Attaking", Action::Attaking, m2)
            .AddState("looking for a first aid kit", Action::FindingAid, m3)
            .AddState("killed", Action::Killed, m4);

    fa.SetState("looking for the purpose of");

    EXPECT_TRUE(fa("I've found it") == Action::Attaking);
    /*EXPECT_TRUE(fa("killed the purpose") == Action::Finding);
    EXPECT_TRUE(fa("I've found it") == Action::Attaking);
    EXPECT_TRUE(fa("there are few lives") == Action::FindingAid);
    // из состояния 'ищет аптечку' нет перехода по входу "убил цель"
    // поэтому генерируем исключение
    EXPECT_EXCEPTION(fa("killed the purpose"));
    EXPECT_TRUE(fa("I've found it") == Action::Finding);
    EXPECT_TRUE(fa("I've found it") == Action::Attaking);
    EXPECT_TRUE(fa("there are few lives") == Action::FindingAid);
    EXPECT_TRUE(fa("ended life") == Action::Killed);

    EXPECT_EXCEPTION(fa("I've found it"));

    SaveToFile("fa", fa);

    FiniteStateMachine<std::string, std::string, Action> copy;
    LoadFromFile("fa", copy);


    EXPECT_TRUE(copy("I've found it") == Action::Attaking);
    EXPECT_TRUE(copy("killed the purpose") == Action::Finding);
    EXPECT_TRUE(copy("I've found it") == Action::Attaking);
    EXPECT_TRUE(copy("there are few lives") == Action::FindingAid);
    EXPECT_EXCEPTION(copy("killed the purpose"));
    EXPECT_TRUE(copy("I've found it") == Action::Finding);
    EXPECT_TRUE(copy("I've found it") == Action::Attaking);
    EXPECT_TRUE(copy("there are few lives") == Action::FindingAid);
    EXPECT_TRUE(copy("ended life") == Action::Killed);
    EXPECT_EXCEPTION(copy("I've found it"));*/
}
