#define NULL '\0'
#define MAX_LENGTH 254

enum CompResult {DIFFRENT, EQUAL};

void CopyString(char pcSource[], char pcDestination[]){
	char cCurrentCharIndex;
	
	for (cCurrentCharIndex = 0; pcSource[cCurrentCharIndex] != NULL; cCurrentCharIndex++){
		pcDestination[cCurrentCharIndex] = pcSource[cCurrentCharIndex];
	}
	
	pcDestination[cCurrentCharIndex] = NULL;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	char cCurrentCharIndex;
	
	for (cCurrentCharIndex = 0; pcStr1[cCurrentCharIndex] != NULL; cCurrentCharIndex++){
		if (pcStr1[cCurrentCharIndex] != pcStr2[cCurrentCharIndex]){
			return DIFFRENT;
		}
	}
	if (pcStr2[cCurrentCharIndex] != NULL){
		return DIFFRENT;
	}
	return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	char cCurrentCharIndex;
	
	for (cCurrentCharIndex = 0; pcDestinationStr[cCurrentCharIndex] != NULL; cCurrentCharIndex++){}
		
	CopyString(pcSourceStr, (pcDestinationStr + cCurrentCharIndex));
}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	char cCurrentCharIndex;
	
	for (cCurrentCharIndex = 0; pcString[cCurrentCharIndex] != NULL; cCurrentCharIndex++){
		if (pcString[cCurrentCharIndex] == cOldChar){
			pcString[cCurrentCharIndex] = cNewChar;
		}
	}
}

int main(){
	char acStringA[] = "testyyyyyyyyyyyyyoneone!!!!";
	char acStringB[MAX_LENGTH] = "testyyz";
	char acStringC[MAX_LENGTH];
	
	enum CompResult eResult = DIFFRENT;
	
	
	CopyString(acStringA, acStringB);
	
	eResult = eCompareString(acStringA, acStringB);
	
	AppendString(acStringA, acStringB);
	
	ReplaceCharactersInString(acStringA, 'y', 'z');
	return 0;
}
