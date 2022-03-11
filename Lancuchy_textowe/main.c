#define NULL '\0'
#define MAX_LENGTH 254
#define CAPITAL_LETTER_ASCI_OFFSET	55
#define NUMBER_ASCI_OFFSET 48


enum CompResult {DIFFRENT, EQUAL};

void CopyString(char pcSource[], char pcDestination[]){
	char cCounter;
	
	for (cCounter = 0; pcSource[cCounter] != NULL; cCounter++){
		pcDestination[cCounter] = pcSource[cCounter];
	}
	
	pcDestination[cCounter] = NULL;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	char cCounter;
	
	for (cCounter = 0; pcStr1[cCounter] != NULL; cCounter++){
		if (pcStr1[cCounter] != pcStr2[cCounter]){
			return DIFFRENT;
		}
	}
	if (pcStr2[cCounter] != NULL){
		return DIFFRENT;
	}
	return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	char cCounter;
	
	for (cCounter = 0; pcDestinationStr[cCounter] != NULL; cCounter++){}
		
	CopyString(pcSourceStr, (pcDestinationStr + cCounter));
}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	char cCounter;
	
	for (cCounter = 0; pcString[cCounter] != NULL; cCounter++){
		if (pcString[cCounter] == cOldChar){
			pcString[cCounter] = cNewChar;
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
