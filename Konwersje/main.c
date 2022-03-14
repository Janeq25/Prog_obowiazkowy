#define NULL '\0'
#define MAX_LENGTH 254


enum Result {OK, ERROR};

void UIntToHexStr(unsigned int uiValue, char pcString[]){
	
	signed char scNybbleNumber;
	char cNybble;
	
	pcString[0] = '0';
	pcString[1] = 'x';
	
	for (scNybbleNumber = 3; scNybbleNumber >= 0; scNybbleNumber--){
		
		cNybble = (uiValue >> (scNybbleNumber * 4)) & 0xF;
		
		if (cNybble > 9){
			pcString[5 - scNybbleNumber] = cNybble + ('A' - 10);
		}
		else{
			pcString[5 - scNybbleNumber] = cNybble + '0';
		}
	}
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	char cArrayElementNumber;
	char cNybble;
	
	if (pcStr[0] != '0') { return ERROR; }
	if (pcStr[1] != 'x') { return ERROR; }
	if (pcStr[2] == NULL) { return ERROR; }

	*puiValue = 0x00;

	for (cArrayElementNumber = 2; cArrayElementNumber < 6; cArrayElementNumber++){
		cNybble = pcStr[cArrayElementNumber];
		
		*puiValue = *puiValue << 4;
		
		if (cNybble == NULL){
			return OK;
		}
		if (cNybble >= 'A'){
			*puiValue = *puiValue | (cNybble-('A' - 10));
		}
		else{
			*puiValue = *puiValue | (cNybble-'0');
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
	
	char acStringA[MAX_LENGTH] = "testyoe!!!!";
	char acStringC[MAX_LENGTH];
	
	enum Result eRes = ERROR;
	
	unsigned int uiValue;
	
	UIntToHexStr(65000, acStringC);
	
	eRes = eHexStringToUInt(acStringC, &uiValue);
	
	AppendUIntToString(65000, acStringA);
	
	return 0;
}
