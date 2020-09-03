#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_NUM_WORDS 500
#define WORD_LENGTH 50
void myTest();
int getAndFilterWord(char * w);
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *
word_count);
void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int
word_count);
 void myTest()
{
	char a[WORD_LENGTH];
	char words[MAX_NUM_WORDS][WORD_LENGTH];
	int occur[MAX_NUM_WORDS],wordCount=0;
	int i;
	

	printf("yazi giriniz ");
	scanf("%s",a);
	

	for(i=0; i<MAX_NUM_WORDS; ++i){
		words[i][0] = '\0';
		occur[i] = 0;
	}
	getAndFilterWord(a);
	i=0;
	while(strcmp(a,"end") != 0){
		addWord(a,words,occur,&wordCount);
		printf("Word[%d]: %s ",i,words[i]);
		printf("occur[%d]: %d word_count= %d\n",i,occur[i],wordCount);
		printf("\n");
		scanf("%s",a);
		getAndFilterWord(a);
		++i;
	}
	
	for(i=0; i<wordCount; ++i){
		printf("Word[%d]: %s ",i,words[i]);
		printf("occur[%d]: %d word_count= %d\n",i,occur[i],wordCount);
	}
	
	sortWords(words,occur,wordCount);
	for(i=0; i<wordCount; ++i){
		printf(" %d ",occur[i]);
	}
	for(i=0; i<wordCount; ++i){
		printf("words[%d] %s ",i,words[i]);
	}
	
	

}
int getAndFilterWord(char * w)
{
    int i = 0;
    int p = 0,result=1;
    int len = strlen(w);
    for (i = 0; i <= len; i++) {
        if (! ispunct(w[i]) && ! isdigit(w[i])) {
            w[p] = tolower(w[i]);
            p++;
        }
        else
        	result = 0;
    }
    return result;
}
void addWord(char * w, char words[MAX_NUM_WORDS][WORD_LENGTH],int occur[MAX_NUM_WORDS], int *
word_count){
	
	int i;
	for(i=0;i<*word_count ;++i)
	{
		printf("girilen input: %s - words array input: %s\n",w,words[i]);
		if(strcmp(words[i],w) == 0){
			occur[i]++;
			printf("ayni kelime geldi\n");
			
		}
		
	}
	
	if(*word_count==i)
	{
		
 		strcpy(words[i],w);
 		(*word_count)++;
 		occur[i]=1;
	}
	
	
}
void sortWords(char words[MAX_NUM_WORDS][WORD_LENGTH], int occur[MAX_NUM_WORDS],int
word_count){
	int i,temp_int,max,j;
	char temp_char[WORD_LENGTH];
	
	for (i = 0; i < word_count; i++)
    {
        max = i;
        for (j = i+1; j < word_count; j++)
          if (occur[j] > occur[max])
            max = j;
 
        
		temp_int=occur[i];
		occur[i] = occur[max];
		occur[max] = temp_int;
		
		strcpy(temp_char,words[i]);
		strcpy(words[i],words[max]);
		strcpy(words[max],temp_char);
    }
	
	
}

