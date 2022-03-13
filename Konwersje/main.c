#define NULL '\0'
#define MAX_LENGTH 254
#define CAPITAL_LETTER_ASCI_OFFSET	55
#define NUMBER_ASCI_OFFSET 48


enum Result {OK, ERROR};

void UIntToHexStr(unsigned int uiValue, char pcString[]){
	
	char cCounter;
	unsigned int uiTempValue;
	
	pcString[0] = '0';
	pcString[1] = 'x';
	
	for (cCounter = 3; cCounter >= 0 && cCounter < 4; cCounter--){
		uiTempValue = uiValue >> (cCounter * 4);
		uiTempValue = uiTempValue & 0xF;
		
		if (uiTempValue > 9){
			uiTempValue = uiTempValue + CAPITAL_LETTER_ASCI_OFFSET;
		}
		else{
			uiTempValue = uiTempValue + NUMBER_ASCI_OFFSET;
		}
		
		pcString[5 - cCounter] = (char)uiTempValue;
	}
}

int pointer = 10;

int * pointer_to_pointer;


enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	char cCounter;
	char cTempChar;
	
	if (pcStr[0] != '0') { return ERROR; }
	if (pcStr[1] != 'x') { return ERROR; }
	if (pcStr[2] == NULL) { return ERROR; }

	
	for (cCounter = 0; cCounter < 4; cCounter++){
		cTempChar = pcStr[cCounter + 2];
		
		if (cTempChar == NULL){
			return OK;
		}
		if (cTempChar > 64){
			cTempChar = cTempChar - CAPITAL_LETTER_ASCI_OFFSET;
		}
		else{
				cTempChar = cTempChar - NUMBER_ASCI_OFFSET;
		}
		
		*puiValue = *puiValue << 4;
		*puiValue = *puiValue | (unsigned int)cTempChar;
	}
	return OK;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	char cCounter;
	
	for (cCounter = 0; pcDestinationStr[cCounter] != NULL; cCounter++){}
	UIntToHexStr(uiValue, &pcDestinationStr[cCounter]);
}

int main(){
	
	char acStringA[] = "testyyyyyyyyyyyyyoneone!!!!";
	char acStringC[MAX_LENGTH];
	
	enum Result eRes = ERROR;
	
	unsigned int uiValue;
	
	UIntToHexStr(65000, acStringC);
	
	eRes = eHexStringToUInt(acStringC, &uiValue);
	
	AppendUIntToString(65000, acStringA);
	
	pointer_to_pointer = &pointer;
	
	return 0;
}
