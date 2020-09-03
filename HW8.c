/*
	Write Records.data array to the filename.
*/
void writeRecords(Records records, char* filename) {
	FILE *file = fopen(filename,"wb");
	if(!file)
		return;
	fwrite(records.data,sizeof(Record),records.size,file);
	fclose(file);
}

/*
	Reads Record structs from file and places them to Records.data array.
	Note that the number of Record structs in the file is unkown.
*/
void readRecords(Records *records, char* filename) {
	Record rec;
	FILE *file = fopen(filename,"rb");
	if(!file)
		return;
	records->size = 0;
	while(fread(&rec,sizeof(Record),1,file))
		memcpy(&records->data[records->size++], &rec, sizeof(Record));
	fclose(file);
}

/*
	Write People.data array to the filename.
*/
void writePeople(People people, char* filename) {
	FILE *file = fopen(filename,"wb");
	if(!file)
		return;
	fwrite(people.data,sizeof(Person),people.size,file);
	fclose(file);
}

/*
	Reads Person structs from file and places them to People.data array.
	Note that the number of Person structs in the file is unkown.
*/
void readPeople(People *people, char* filename) {
	Person p;
	FILE *file = fopen(filename,"rb");
	if(!file)
		return;
	people->size = 0;
	while(fread(&p,sizeof(Person),1,file))
		memcpy(&people->data[people->size++],&p,sizeof(Person));
	fclose(file);
}


int contains(Records records, Record record) {
	int i;
	for (i = 0; i < records.size; ++i)
		if(!strcmp(records.data[i].number,record.number) &&
			records.data[i].id == record.id)
			return 1;
	return 0;
}

/**
  * Reads the input file and constructs People and Records structs.
  	Note that each Record in Records is unique (should not present multiple times).
  */
void read(char* filename, People *people, Records *records) {
	Record record;
	char name[NAMELEN], surname[NAMELEN];
	int phoneCount = 0, i, status = 1;
	char tmp;
	FILE *file;
	file = fopen(filename,"r");
	if(!file)
		return;
	if(people->size >= MAXRECORD)
		return;
	while(1) {
		status = fscanf(file,"%d %s %s %d",&people->data[people->size].id, name, surname, &phoneCount);
		if(status == EOF)
			break;
		/* concatenate name and surname and copy the people struct */
		strcat(name," ");
		strcat(name,surname);
		strcpy(people->data[people->size].name, name);
		record.id = people->data[people->size].id;
		for (i = 0; i < phoneCount; ++i) {
			fscanf(file,"%s",record.number);
			/* avoid duplicate records */
			if(!contains(*records, record)) {
				memcpy(&records->data[records->size], &record, sizeof(Record));
				++records->size;
			}
		}
		fscanf(file,"%c",&tmp);
		++people->size;
	}
	fclose(file);
}
