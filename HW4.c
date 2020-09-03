void zeroPadding(double outputArr[], int outputArrSize, int paddingWidth){
    int i = 0;

    for(i = 0; i<paddingWidth; ++i){
        outputArr[i]=0; 
    }

    for(i = outputArrSize-paddingWidth; i<outputArrSize; ++i){
        outputArr[i]=0;     
    }
}

void halfPadding(double outputArr[], int outputArrSize, int paddingWidth){
    int i = 0;

    for(i = 0; i<paddingWidth; ++i){
        outputArr[i]=outputArr[paddingWidth]/2; 
    }

    for(i = outputArrSize-paddingWidth; i<outputArrSize; ++i){
        outputArr[i]=outputArr[outputArrSize-paddingWidth-1]/2;
    }
}

void samePadding(double outputArr[], int outputArrSize, int paddingWidth){
    int i = 0;

    for(i = 0; i<paddingWidth; ++i){
        outputArr[i]=outputArr[paddingWidth];   
    }

    for(i = outputArrSize-paddingWidth; i<outputArrSize; ++i){
        outputArr[i]=outputArr[outputArrSize-paddingWidth-1];
    }
}

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int *outputArraySize, int paddingWidth, void paddingMethod(double[], int, int)){
    int i = 0;

    *outputArraySize = inputArraySize + 2*paddingWidth;
    for(i = 0; i<inputArraySize; ++i){
        outputArr[i+paddingWidth]=inputArr[i];
    }

    paddingMethod(outputArr, *outputArraySize, paddingWidth);
}



