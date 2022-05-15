#define NULL '\0'
#define MAX_LENGTH 254

enum CompResult {DIFFRENT, EQUAL};

void CopyString(char pcSource[], char pcDestination[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcSource[cCharCounter] != NULL; cCharCounter++){
		pcDestination[cCharCounter] = pcSource[cCharCounter];
	}
	
	pcDestination[cCharCounter] = NULL;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcStr1[cCharCounter] != NULL; cCharCounter++){
		if (pcStr1[cCharCounter] != pcStr2[cCharCounter]){
			return DIFFRENT;
		}
	}
	if (pcStr2[cCharCounter] != NULL){
		return DIFFRENT;
	}
	return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	char cCharCounter;
	
	for (cCharCounter = 0; pcDestinationStr[cCharCounter] != NULL; cCharCounter++){}
		
	CopyString(pcSourceStr, (pcDestinationStr + cCharCounter));
}


void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	char cCharCounter;
	
	for (cCharCounter = 0; pcString[cCharCounter] != NULL; cCharCounter++){
		if (pcString[cCharCounter] == cOldChar){
			pcString[cCharCounter] = cNewChar;
		}
	}
}

int main(){
	char acStringA[MAX_LENGTH] = "StringA";
	char acStringB[MAX_LENGTH] = "StringB";
	
	AppendString(acStringA, acStringB);
	
	return 0;
}
