#include "Task3.hpp"


Task3::Task3()
{
    std::cout << "Enter string: ";
    std::cin >> m_String;
}


void Task3::Execute()
{
    size_t count = m_String.size();
    for (size_t i = 0; i < count; i++)
    {
        m_List.Append(m_String[i]);
    }
    
    m_List.MakeCircle();

    if (m_List.isPalindrome())
        std::cout << "Given string is palindrome." << std::endl;
    else
        std::cout << "Given string is not palindrome." << std::endl;
}
