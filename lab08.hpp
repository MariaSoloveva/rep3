#include <map>
#include <string>
#include <vector>


// Task 1
void saveToFile(const std::string& filename, std::vector<std::string>& data);
void loadFromFile(const std::string& filename, std::vector<std::string>& data);


// Task 2
struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};

void saveToFile(const std::string& filename, const std::vector<Book>& data);
void loadFromFile(const std::string& filename, Groups& groups);


// Task 3
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile(const std::string& filename, const Groups& groups);
void loadFromFile(const std::string& filename, Groups& groups);
