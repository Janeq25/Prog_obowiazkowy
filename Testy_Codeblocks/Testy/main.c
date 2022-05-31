#include <stdio.h>
#include "string_conversion.h"
#include "tokens.h"

void TestOf_CopyString(void){
	printf("CopyString\n\n ");

	printf("Test 1 - ");
	// poprawne użycie
	char acSrc1[] = "abcd";
	char acDest1[5];
	CopyString(acSrc1, acDest1);
	if (eCompareString(acSrc1, acDest1) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 2 - ");
	// pierwszy ciąg krótszy
	char acSrc2[] = "ab";
	char acDest2[5];
	CopyString(acSrc2, acDest2);
	if (eCompareString(acSrc2, acDest2) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 3 - ");
	// pierwszy ciąg pusty
	char acSrc3[] = "";
	char acDest3[5];
	CopyString(acSrc3, acDest3);
	if (eCompareString(acSrc3, acDest3) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_CompareString(void){
	printf("CompareString\n\n ");

	printf("Test 1 - ");
	// taka sama długość, znaki takie same
	char acStr11[] = "abcd";
	char acStr12[] = "abcd";
	if (eCompareString(acStr11, acStr12) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
	// taka sama długość znaki róźne
	char acStr21[] = "abcd";
	char acStr22[] = "efgh";
	if (eCompareString(acStr21, acStr22) == DIFFRENT) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 3 - ");
	// pierwszy ciąg pusty
	char acStr31[] = "";
	char acStr32[] = "abcd";
	if (eCompareString(acStr31, acStr32) == DIFFRENT) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 4 - ");
	// drugi ciąg pusty
	char acStr41[] = "abcd";
	char acStr42[] = "";
	if (eCompareString(acStr41, acStr42) == DIFFRENT) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 5 - ");
	// oba ciągi puste
	char acStr51[] = "";
	char acStr52[] = "";
	if (eCompareString(acStr51, acStr52) == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 6 - ");
	// pierwszy ciąg dłuższy od drugiego
	char acStr61[] = "abcdef";
	char acStr62[] = "abcd";
	if (eCompareString(acStr61, acStr62) == DIFFRENT) printf("OK\n\n "); else printf("Error\n\n ");

	printf("Test 7 - ");
	// drugi ciąg dłuższy od pierwszego
	char acStr71[] = "abcd";
	char acStr72[] = "abcdef";
	if (eCompareString(acStr71, acStr72) == DIFFRENT) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_AppendString(void){
    printf("AppendString\n\n ");

    printf("Test 1 - ");
    // poprawne użycie, ciągi takie same
    char acDest1[9] = "abcd";
    AppendString("efgh", acDest1);
    if (eCompareString(acDest1, "abcdefgh") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    // pierszy ciąg pusty
    char acDest2[9] = "";
    AppendString("efgh", acDest2);
    if (eCompareString(acDest2, "efgh") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 3 - ");
    // drugi ciąg pusty
    char acDest3[9] = "abcd";
    AppendString("", acDest3);
    if (eCompareString(acDest3, "abcd") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_ReplaceCharactersInString(void){
    printf("ReplaceCharactersInString\n\n ");

    printf("Test 1 - ");
    // poprawne użycie funkcji, różne znaki
    char acStr1[10] = "aAbcad";
    ReplaceCharactersInString(acStr1, 'a', 'A');
    if (eCompareString(acStr1, "AAbcAd") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    // zamiana spacji na null
    char acStr2[10] = "Abc ad";
    ReplaceCharactersInString(acStr2, ' ', '\0');
    if (eCompareString(acStr2, "Abc") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_UintToHexString(void){
    printf("UIntToHexString\n\n ");

    printf("Test 1 - ");
    // poprawne użycie z cyframi z granic przedziałów
    unsigned int uiNumber1 = 0xFA90;
    char acDest1[7];
    UIntToHexStr(uiNumber1, acDest1);
    if (eCompareString(acDest1, "0xFA90") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    // zerowa cyfra
    unsigned int uiNumber2 = 0x0000;
    char acDest2[7];
    UIntToHexStr(uiNumber2, acDest2);
    if (eCompareString(acDest2, "0x0000") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

}

void TestOf_eHexStringToUInt(void){
    printf("eHexStringToUInt\n\n ");

    unsigned int uiValue;
    enum Result eResult = ERROR;

    printf("Test 1 - ");
    // cyfry z granic przedziałów
    eResult = eHexStringToUInt("0xFA90", &uiValue);
    if (uiValue == 0xFA90 && eResult == OK) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    // wejściowy string za krótki
    eResult = eHexStringToUInt("0xFF", &uiValue);
    if (uiValue == 0xFF && eResult == OK) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 3 - ");
    // wejściowy string za długi
    eResult = eHexStringToUInt("0xFFFFFF", &uiValue);
    if (uiValue == 0xFFFF && eResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 4 - ");
    // brak 0x na początku ciągu
    eResult = eHexStringToUInt("FFFFFF", &uiValue);
    if (eResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 5 - ");
    // pusty ciąg wejściowy
    eResult = eHexStringToUInt("", &uiValue);
    if (eResult == ERROR) printf("OK\n\n "); else printf("Error\n\n ");
}

void TestOf_AppendUIntToString(void){
    printf("AppendUIntToString\n\n ");

    printf("Test 1 - ");
    // poprawne użycie
    char acDest1[11] = "abcd";
    AppendUIntToString(0xFFFF, acDest1);
    if (eCompareString(acDest1, "abcd0xFFFF") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

    printf("Test 2 - ");
    // pusty ciąg
    char acDest2[7] = "";
    AppendUIntToString(0xFFFF, acDest2);
    if (eCompareString(acDest2, "0xFFFF") == EQUAL) printf("OK\n\n "); else printf("Error\n\n ");

}

void TestOf_FindTokensInString(void){
    printf("ucFindTokensInString\n\n ");

    printf("Test 1 - ");
    // trzy tokeny
    if ((ucFindTokensInString("raz dwa trzy") == 3)
        && (eCompareString(asToken[0].uValue.pcString, "raz dwa trzy") == EQUAL)
        && (eCompareString(asToken[1].uValue.pcString, "dwa trzy") == EQUAL)
        && (eCompareString(asToken[2].uValue.pcString, "trzy") == EQUAL)) printf("OK\n\n "); else printf("ERROR\n\n ");

    printf("Test 2 - ");
    //ciąg samych delimiterów
    if (ucFindTokensInString("       ") == 0) printf("OK\n\n "); else printf("ERROR\n\n ");

    printf("Test 3 - ");
    //więcej niż 1 delimiter między tokenami
    if ((ucFindTokensInString("  raz   dwa    trzy") == 3)
        && (eCompareString(asToken[0].uValue.pcString, "raz   dwa    trzy") == EQUAL)
        && (eCompareString(asToken[1].uValue.pcString, "dwa    trzy") == EQUAL)
        && (eCompareString(asToken[2].uValue.pcString, "trzy") == EQUAL)) printf("OK\n\n "); else printf("ERROR\n\n ");

    printf("Test 4 - ");
    //mniej niż max ilość tokenów
    if ((ucFindTokensInString("raz dwa") == 2)
        && (eCompareString(asToken[0].uValue.pcString, "raz dwa") == EQUAL)
        && (eCompareString(asToken[1].uValue.pcString, "dwa") == EQUAL)) printf("OK\n\n "); else printf("ERROR\n\n ");

    printf("Test 5 - ");
    //więcej niż max ilość tokenów
    if ((ucFindTokensInString("raz dwa trzy cztery") == 3)
        && (eCompareString(asToken[0].uValue.pcString, "raz dwa trzy cztery") == EQUAL)
        && (eCompareString(asToken[1].uValue.pcString, "dwa trzy cztery") == EQUAL)
        && (eCompareString(asToken[2].uValue.pcString, "trzy cztery") == EQUAL)) printf("OK\n\n "); else printf("ERROR\n\n ");
}


void TestOf_eStringToKeyword(){
    printf("eStringToKeyword\n\n ");

    enum KeywordCode eKeywordCode;

    printf("Test 1 - ");
    // poprawne użycie, istniejący keyword
    if ((eStringToKeyword("reset", &eKeywordCode) == OK)
        && (eKeywordCode == RST)) printf("OK\n\n "); else printf("ERROR\n\n ");

    printf("Test 2 - ");
    // poprawne użycie, nieistniejące słowo klucz
    if (eStringToKeyword("zresetuj", &eKeywordCode) == ERROR) printf("OK\n\n "); else printf("ERROR\n\n ");
}

void TestOf_DecodeTokens(){
    printf("DecodeTokens\n\n ");

    printf("Test 1 - ");
    //test poprawnego dekodowania wszystkich typów tokenów (string, number i keyword)
    char acInput[] = "0xFFFF AbCd load";
    asToken[0].uValue.pcString = &acInput[0];
    asToken[1].uValue.pcString = &acInput[7];
    asToken[2].uValue.pcString = &acInput[12];
    acInput[6] = NULL;
    acInput[11] = NULL;

    ucTokenNr = 3;

    DecodeTokens();

    if ((asToken[0].eType == NUMBER) && (asToken[1].eType == STRING) && (asToken[2].eType == KEYWORD)
        && (asToken[0].uValue.uiNumber == 0xFFFF) && (asToken[1].uValue.pcString == &acInput[7]) && asToken[2].uValue.eKeyword == LD) printf("OK\n\n "); else printf("ERROR\n\n ");
}

void TestOf_DecodeMsg(void){
    printf("DecodeMsg\n\n ");

    printf("Test 1 - ");
    //poprawne użycie
    char acInput[] = "0xFFFF AbCd load";

    DecodeMsg(acInput);

    if ((asToken[0].eType == NUMBER) && (asToken[1].eType == STRING) && (asToken[2].eType == KEYWORD)
        && (asToken[0].uValue.uiNumber == 0xFFFF) && (asToken[1].uValue.pcString == &acInput[7]) && asToken[2].uValue.eKeyword == LD) printf("OK\n\n "); else printf("ERROR\n\n ");
}

int main(){

    printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n ");

	TestOf_CopyString();
	TestOf_CompareString();
	TestOf_AppendString();
	TestOf_ReplaceCharactersInString();

	printf("TESTY FUNKCJI DO KONWERSJI \n\n\n ");

	TestOf_UintToHexString();
	TestOf_eHexStringToUInt();
	TestOf_AppendUIntToString();

	printf("TESTY FUNKCJI DO DEKODOWANIA TOKENÓW\n\n\n ");

	TestOf_FindTokensInString();
	TestOf_eStringToKeyword();
	TestOf_DecodeTokens();
	TestOf_DecodeMsg();
	return 0;
}
