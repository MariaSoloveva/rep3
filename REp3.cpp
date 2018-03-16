#ifndef LAB_03_FSM_MARIASOLOVEVA_FSM_HPP
#define LAB_03_FSM_MARIASOLOVEVA_FSM_HPP

#include <map>
#include <vector>
#include <fstream>

template <class StateType, class InputType, class OutputType>
class FiniteStateMachine
{
    std::map<StateType, OutputType> Status;
    StateType Now;
    std::map<InputType, std::map<InputType, StateType>> Out;
public:
    FiniteStateMachine() = default;
    ~FiniteStateMachine() = default;
    FiniteStateMachine& AddState(const StateType& state,
                                 const OutputType& output,
                                 const std::map<InputType, StateType>& table)
    {
        Status[state] = output;
        Out[state] = table;
        return *this;
    }
    void SetState(const StateType& state)
    {
        if (Status.find(state) == Status.end())
            throw std::runtime_error("ERROR");
        Now = state;
    }
    OutputType operator()(const InputType& input)
    {
        if (Status.find(input) == Status.end())
            throw std::runtime_error("ERROR");
        return Out[input];
    }
    void ChangeOutput(const StateType& state, const OutputType& newOut)
    {
        if (Status.find(state) == Status.end())
            throw std::runtime_error("ERROR");
        Now = state;
    }

    void ChangeAction(const StateType& state, const InputType& input, const StateType& newState)
    {
        if (Status.find(state) == Status.end() && Out[state].end() &&
                Status.find(newState) == Status.end())
            throw std::runtime_error("ERROR");
        Out[state][input] = newState;
    }
};

template <class S, class I, class O>
void SaveToFile(const std::wstring& filename, const FiniteStateMachine<S, I, O>& finiteStateMachine1)
{
    const std::string filename1(filename.begin(), filename.end());
    std::fstream fl(filename1, std::ios::out);
    //fl << finiteStateMachine1.size() << std::endl;
    for (const auto& e : groups)
    {
        fl << e.first << std::endl;
        fl << e.second.size() << std::endl;
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            fl << e.second[i].Name << std::endl;
            fl << e.second[i].Year << std::endl;
            fl << e.second[i].RecordBook.size() << std::endl;
            for (const auto& a : e.second[i].RecordBook)
            {
                fl << a.first << std::endl;
                fl << a.second << std::endl;
            }
        }
        std::cout << std::endl;
    }
};

template <class S, class I, class O>
void LoadFromFile(const std::wstring& filename, FiniteStateMachine<S, I, O>&)
{

};

#endif //LAB_03_FSM_MARIASOLOVEVA_FSM_HPP
