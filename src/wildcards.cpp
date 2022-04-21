#include <wildcards.h>

bool match(const char *first, const char * second){
    if (*first == '\0' && *second == '\0')
        return true;
 
    if (*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;
 
    if (*first == '?' || *first == *second)
        return match(first+1, second+1);

    if (*first == '*')
        return match(first+1, second) || match(first, second+1);
    return false;
}

bool stringsMatch(std::string pattern, std::string string){
    const char *s1 = pattern.c_str();
    const char *s2 = string.c_str();
    return match(s1, s2);
}
