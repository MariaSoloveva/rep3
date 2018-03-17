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
        return Status[input];
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
    friend void SaveToFile(const std::wstring& filename, const FiniteStateMachine<StateType, InputType, OutputType>& finiteStateMachine1);
    friend void LoadFromFile(const std::wstring& filename, FiniteStateMachine<StateType, InputType, OutputType>& finiteStateMachine1);
};

template <class S, class I, class O>
void SaveToFile(const std::wstring& filename, const FiniteStateMachine<S, I, O>& finiteStateMachine1)
{
    const std::string filename1(filename.begin(), filename.end());
    std::fstream fl(filename1, std::ios::out);
    fl << finiteStateMachine1.Status.size() << std::endl;
    for (const auto& e : finiteStateMachine1.Status)
    {
        fl << e.first << std::endl;
        fl << static_cast<O>(e.second) << std::endl;
    }
    fl << finiteStateMachine1.Out.size() << std::endl;
    for (const auto& e : finiteStateMachine1.Out)
    {
        fl << e.first << std::endl;
        fl << e.second.size() << std::endl;
        for (const auto& a : e.second)
        {
            fl << a.first << std::endl;
            fl << static_cast<int>(a.second) << std::endl;
        }
    }
};

template <class S, class I, class O>
void LoadFromFile(const std::wstring& filename, FiniteStateMachine<S, I, O>& finiteStateMachine1)
{
    const std::string filename1(filename.begin(), filename.end());
    std::ifstream fl(filename1);
    std::string str;
    std::string strKey;
    std::string strKeyIn;
    std::getline(fl, str);
    int size = atoi(str.c_str());
    for (int i = 0; i < size; ++i)
    {
        std::getline(fl, strKey);
        std::getline(fl, str);
        finiteStateMachine1.Status[static_cast<S>(strKey)] = static_cast<O>(str);
    }
    std::getline(fl, str);
    int sizeOut = atoi(str.c_str());
    std::map<I, S> state;
    for (int i = 0; i < sizeOut; ++i)
    {
        std::getline(fl, strKeyIn);
        size = atoi(str.c_str());
        for (int j = 0; j < size; ++j)
        {
            std::getline(fl, strKey);
            std::getline(fl, str);
            state[static_cast<I>(strKey)] = static_cast<S>(str);
        }
        finiteStateMachine1.Out[static_cast<I>(strKeyIn)] = state;
    }
};
