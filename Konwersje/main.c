#define NULL '\0'
#define MAX_LENGTH 254


enum Result {OK, ERROR};

void UIntToHexStr(unsigned int uiValue, char pcString[]){
	
	char cNybbleCtr;
	char cNybble;
	
	pcString[0] = '0';
	pcString[1] = 'x';
	
	for (cNybbleCtr = 0; cNybbleCtr < 4; cNybbleCtr++){
		
		cNybble = (uiValue >> (cNybbleCtr * 4)) & 0xf;
		
		if (cNybble > 9){
			pcString[5 - cNybbleCtr] = cNybble + ('A' - 10);
		}
		else{
			pcString[5 - cNybbleCtr] = cNybble + '0';
		}
	}
	pcString[6] = NULL;
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	char cCharCtr;
	char cNybble;
	
	if (pcStr[0] != '0') { return ERROR; }
	if (pcStr[1] != 'x') { return ERROR; }
	if (pcStr[2] == NULL) { return ERROR; }

	*puiValue = 0x00;

	for (cCharCtr = 2; pcStr[cCharCtr] != NULL; cCharCtr++){
		cNybble = pcStr[cCharCtr];
		
		if (cCharCtr > 5){
			return ERROR;
		}
		
		*puiValue = *puiValue << 4;
		
		if (cNybble >= 'A'){
			*puiValue = *puiValue | (cNybble - ('A' - 10));
		}
		else{
			*puiValue = *puiValue | (cNybble - '0');
		}
	}
	return OK;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	char cStringLength;
	
	for (cStringLength = 0; pcDestinationStr[cStringLength] != NULL; cStringLength++){}
		
	UIntToHexStr(uiValue, &pcDestinationStr[cStringLength]);
}

int main(){
	
	char acStringA[] = "0xFE8DA";

	enum Result eRes = ERROR;
	
	unsigned int uiValue;
	
	eRes = eHexStringToUInt(acStringA, &uiValue);
	
	
	return 0;
}
