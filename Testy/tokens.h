#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3

enum KeywordCode {LD, ST, RST};

struct Keyword {
    enum KeywordCode eCode;
    char cString[MAX_KEYWORD_STRING_LTH + 1];
};

extern struct Keyword asKeywordList[MAX_KEYWORD_NR];

union TokenValue {
    enum KeywordCode eKeyword;
    unsigned int uiNumber;
    char *pcString;
};

enum TokenType {KEYWORD, NUMBER, STRING};

struct Token {
    enum TokenType eType;
    union TokenValue uValue;
};

extern struct Token asToken[MAX_TOKEN_NR];

unsigned char ucFindTokensInString(char *pcString);
enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode);
void DecodeTokens(void);
void DecodeMsg(char *pcString);

