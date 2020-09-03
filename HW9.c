int getNumCount(Person p) {
	int count = 0;
	Record *rec = p.numbers;
	while(rec) {
		++count;
		rec = rec->next;
	}
	return count;
}

/*
	Write People.data array to the filename.
*/
void writePeople(People people, char* filename) {
	int i, numCount;
	Record *rec;
	FILE *file = fopen(filename,"wb");
	if(!file)
		return;
	for (i = 0; i < people.size; ++i) {
		fwrite(&people.data[i].id,sizeof(int),1,file);
		fwrite(people.data[i].name,sizeof(char)*NAMELEN,1,file);
		fwrite(&people.data[i].expenditure,sizeof(double),1,file);
		numCount = getNumCount(people.data[i]);
		fwrite(&numCount,sizeof(int),1,file);
		rec = people.data[i].numbers;
		while(rec) {
			fwrite(rec->number,sizeof(char)*NAMELEN,1,file);
			rec = rec->next;
		}
	}
	fclose(file);
}

/*
	Reads Person structs from file and places them to People.data array.
	Note that the number of Person structs in the file is unkown.
*/
void readPeople(People *people, char* filename) {
	Person p;
	int i,numCount;
	Record *rec;
	FILE *file = fopen(filename,"rb");
	if(!file)
		return;
	people->size = 0;
	while(fread(&p.id,sizeof(int),1,file)) {
		fread(p.name,sizeof(char)*NAMELEN,1,file);
		fread(&p.expenditure,sizeof(double),1,file);
		memcpy(&people->data[people->size],&p,sizeof(Person));
		fread(&numCount,sizeof(int),1,file);
		people->data[people->size].numbers = NULL;
		rec = NULL;
		for (i = 0; i < numCount; ++i) {
			if(rec) {
				rec->next = (Record *) malloc(sizeof(Record));
				rec = rec->next;
			} else {
				rec = (Record *) malloc(sizeof(Record));
				people->data[people->size].numbers = rec;
			}
			rec->next = NULL;
			fread(rec->number,sizeof(char)*NAMELEN,1,file);
		}
		++people->size;
	}
	fclose(file);
}

#define EPSILON 0.0001
int doubleEq(double d1, double d2) {
	return d2 < (d1+EPSILON) && d2 > (d1-EPSILON);
}

void imputation(People *people) {
	int i, totalPhoneCount = 0, phoneCount;
	Record *rec;
	double totalExpenditures = 0, expenditure, avgExpenditure;

	for (i = 0; i < people->size; ++i) {
		rec = people->data[i].numbers;
		expenditure = people->data[i].expenditure;
		if(!doubleEq(expenditure,-1)) {
			totalExpenditures += expenditure;
			while(rec) {
				++totalPhoneCount;
				rec = rec->next;
			}
		}
	}

	avgExpenditure = totalExpenditures / totalPhoneCount;

	for (i = 0; i < people->size; ++i) {
		rec = people->data[i].numbers;
		expenditure = people->data[i].expenditure;
		phoneCount = 0;
		if(doubleEq(expenditure,-1)) {
			while(rec) {
				++phoneCount;
				rec = rec->next;
			}
			people->data[i].expenditure = phoneCount * avgExpenditure;
		}
	}


}

/**
  * Reads the input file and constructs People struct.
  	Note that the number of phone numbers in file is unknown unlike your
  	previous homework. You should keep phone numbers in the linked list
  	(numbers field)
  */
void read(char* filename, People *people) {
	Record *record = NULL;
	char name[NAMELEN], surname[NAMELEN], number[NAMELEN];
	int status = 1;
	FILE *file;
	file = fopen(filename,"r");
	if(!file)
		return;
	if(people->size >= MAXRECORD)
		return;
	while(1) {
		status = fscanf(file,"%d %s %s %lf",&people->data[people->size].id, name, surname, &people->data[people->size].expenditure);
		if(status == EOF)
			break;
		/* concatenate name and surname and copy the people struct */
		strcat(name," ");
		strcat(name,surname);
		strcpy(people->data[people->size].name, name);
		record = NULL;
		while(fscanf(file,"%s",number) == 1) {
			if(record == NULL) {
				record = (Record *) malloc(sizeof(Record));
				people->data[people->size].numbers = record;
			}
			else {
				record->next = (Record *) malloc(sizeof(Record));
				record = record->next;
			}
			strcpy(record->number, number);
			record->id = people->data[people->size].id;
			record->next = NULL;
			if(fgetc(file) == '\n')
				break;
		}

		++people->size;
	}
	fclose(file);
}
