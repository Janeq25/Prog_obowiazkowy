#include <stdio.h>
#include "string_conversion.h"
#include "tokens.h"

void TestOf_CopyString(void){
	printf("bCopyString\n\n ");

	printf("Test 1 - ");
	// poprawne użycie
	char acStr1[] = "abcd";
	char acStr2[4];
	if (eCompareString(acStr1, acStr2) == EQUAL) printf("ON\n\n "); else printf("Error\n\n ");

}





int main(){

	TestOf_CopyString();
	return 0;
}