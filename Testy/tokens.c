#include "tokens.h"
#include "string_conversion.h"

#define NULL '\0'
#define DELIMITER_CHAR ' '

struct Keyword asKeywordList[MAX_KEYWORD_NR]=
{
    {RST, "reset"},
    {LD, "load"},
    {ST, "store"}
};

struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;


unsigned char ucFindTokensInString(char *pcString){
    unsigned char ucCharCounter = 0;
    unsigned char ucCurrentChar = 0;
    unsigned char ucCurrentToken = 0;
	
    enum TokenFinderState {TOKEN, DELIMITER};
    enum TokenFinderState eTokenFinderState = DELIMITER;

    for (ucCharCounter = 0; ; ucCharCounter++){
			ucCurrentChar = pcString[ucCharCounter];
			
			switch (eTokenFinderState){

					case DELIMITER:
							if (ucCurrentChar == NULL){
									return ucCurrentToken;
							}
							else if (ucCurrentChar == DELIMITER_CHAR){
									eTokenFinderState = DELIMITER;
							}
							else {
									asToken[ucCurrentToken].uValue.pcString = (pcString + ucCharCounter);
									ucCurrentToken++;
									eTokenFinderState = TOKEN;
							}
							break;

					case TOKEN:
							if (ucCurrentChar == NULL || ucCurrentToken == MAX_TOKEN_NR){
									return ucCurrentToken;
							}
							else if (ucCurrentChar == DELIMITER_CHAR){
									eTokenFinderState = DELIMITER;
							}
							else{
									eTokenFinderState = TOKEN;
							}
							break;

        }

    }

}

enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode){
	unsigned char ucKeywordCounter;
	
	for (ucKeywordCounter = 0; ucKeywordCounter < MAX_KEYWORD_NR; ucKeywordCounter++){
		if (EQUAL == eCompareString(pcStr, asKeywordList[ucKeywordCounter].cString)){
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}

void DecodeTokens(void){
	unsigned char ucTokenCounter;
	struct Token *psCurrentToken;
	
	for (ucTokenCounter = 0; ucTokenCounter < ucTokenNr; ucTokenCounter++){
		psCurrentToken = &asToken[ucTokenCounter];
		
		if (OK == eStringToKeyword(psCurrentToken->uValue.pcString, &psCurrentToken->uValue.eKeyword)){
			psCurrentToken->eType = KEYWORD;
		}
		else if (OK == eHexStringToUInt(psCurrentToken->uValue.pcString, &psCurrentToken->uValue.uiNumber)){
			psCurrentToken->eType = NUMBER;
		}
		else{
			psCurrentToken->eType = STRING;
		}
	}
	
}

void DecodeMsg(char *pcString){
	ucTokenNr = ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeTokens();
	
}
