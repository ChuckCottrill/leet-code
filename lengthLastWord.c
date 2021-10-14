
int
lengthOfLastWord(char* s) {
        int size = strlen(s);
        int wordlen = 0;
        int last = size-1;
        for ( ; last >= 0; ) {
            if (s[last] == ' ') {
                last--;
            } else {
                break;
            }
        }
        for ( ; last >= 0; last-- ) {
            if (s[last]==' ') {
                break;
            }
            wordlen++;
        }
        return wordlen;
}

