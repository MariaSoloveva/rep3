void findStudentsgoodAtMath(std::vector<Student>& students)
{
    for (auto s : students)
    {
        auto it = std::find_if(s.RecordBook.begin(), s.RecordBook.end(), ratingExcellentAtMath);
        if (it != s.RecordBook.end())
        {
            std::cout << "Student number " << std::distance(s.RecordBook.begin(), it) + 1 << " is good at Math" << std::endl;
            break;
        }
    }
}
