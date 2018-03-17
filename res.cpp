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
    FiniteStateMachine<std::wstring, std::wstring, Action> fa;

    std::map<std::wstring, std::wstring> m1 = {
            {L"I've found it", L"attacks"}
    };

    std::map<std::wstring, std::wstring> m2 = {
            {L"killed the purpose", L"looking for the purpose of"},
            {L"there are few lives", L"looking for a first aid kit"}
    };

    std::map<std::wstring, std::wstring> m3 = {
            {L"I've found it", L"looking for the purpose of"},
            {L"ended life", L"killed"}
    };

    std::map<std::wstring, std::wstring> m4;
    fa.AddState(L"looking for the purpose of", Action::Finding, m1)
            .AddState(L"Attaking", Action::Attaking, m2)
            .AddState(L"looking for a first aid kit", Action::FindingAid, m3)
            .AddState(L"killed", Action::Killed, m4);

    fa.SetState(L"looking for the purpose of");

    EXPECT_TRUE(fa(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(fa(L"killed the purpose") == Action::Finding);
    EXPECT_TRUE(fa(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(fa(L"there are few lives") == Action::FindingAid);
    // из состояния 'ищет аптечку' нет перехода по входу "убил цель"
    // поэтому генерируем исключение
    EXPECT_EXCEPTION(fa(L"killed the purpose"));
    EXPECT_TRUE(fa(L"I've found it") == Action::Finding);
    EXPECT_TRUE(fa(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(fa(L"there are few lives") == Action::FindingAid);
    EXPECT_TRUE(fa(L"ended life") == Action::Killed);

    EXPECT_EXCEPTION(fa(L"I've found it"));

    SaveToFile(L"fa", fa);

    FiniteStateMachine<std::wstring, std::wstring, Action> copy;
    LoadFromFile(L"fa", copy);


    EXPECT_TRUE(copy(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(copy(L"killed the purpose") == Action::Finding);
    EXPECT_TRUE(copy(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(copy(L"there are few lives") == Action::FindingAid);
    EXPECT_EXCEPTION(copy(L"killed the purpose"));
    EXPECT_TRUE(copy(L"I've found it") == Action::Finding);
    EXPECT_TRUE(copy(L"I've found it") == Action::Attaking);
    EXPECT_TRUE(copy(L"there are few lives") == Action::FindingAid);
    EXPECT_TRUE(copy(L"ended life") == Action::Killed);
    EXPECT_EXCEPTION(copy(L"I've found it"));
}
