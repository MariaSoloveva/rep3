#include "lab08.hpp"

void findStudentsgoodAtMath(std::vector<Student>& group)
{
    for (size_t i = 0; i < group.size(); ++i)
    {
        for (size_t j = 0; j < group[i].RecordBook.size(); ++j) {
            if ((group[i].RecordBook[j].Title == "Math") &&
                (group[i].RecordBook[j].Rating == Excellent))
                std::cout << "Student number " << i + 1 << " is good at Math" << std::endl;
        }
    }
}
