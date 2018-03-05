bool compare(char* s, char* cur, char* prev);
bool isMatch(char* s, char* p) {
    char* tmp = s;
    char* prev = p;
    char* cur = p;
    bool ret = false;
    
    ret = compare(tmp, cur, prev);

    return ret;
}

bool compare(char* s, char* cur, char* prev)
{
    char* tmp = s;
    bool ret = false;
    
    if(*tmp == *cur) {
        if (*(tmp + 1)) {
            if(*(cur + 1)) {
               ret = compare(tmp + 1, cur + 1, cur); 
            } else {
                return false;
            }
        } else {
            if (*(cur + 1)) {
                if (*(cur + 2) == '*' && !(*(cur + 3)))
                    return true;
                return false;
            } else {
                return true;
            }
        }
    } else if (*cur == '.') {
        if (*(tmp + 1)) {
            if(*(cur + 1)) {
               ret = compare(tmp + 1, cur + 1, cur); 
            } else {
                return false;
            }
        } else {
            if (*(cur + 1)) {
                if (*(cur + 2) == '*' && !(*(cur + 3)))
                    return true;
                return false;
            } else {
                return true;
            }
        }
    } else if (*cur == '*') {
        ret = compare(tmp, cur + 1, cur);
        if (ret)
            return;
        
        if (*prev == '.') {
            if (*(cur + 1)) {
                while(*(cur + 1) != *tmp) {
                    if (*(tmp + 1)) {
                        tmp++;
                    } else {
                        return false;
                    }
                }
                ret = compare(tmp, cur + 1, cur);
                return ret;
            } else {
                return true;
            }
        }
        if (*tmp == *prev) {
            while (*(tmp) == *prev) {
                ret = compare(tmp + 1, cur + 1, cur);
                if (ret)
                    break;
                if (*(tmp + 1)) {
                    tmp++;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    } else {
        if (*(cur + 1) == '*') {
            ret = compare(tmp, cur + 2, cur + 1);
        } else {
            ret = false;
        }
    }
    return ret;
}
