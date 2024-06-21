#include "unit.h"


void LoadUnitFromFile(struct unit* myunit)
{
	// open file
	char buffer[50] = { '\0' };
	sprintf_s(buffer, 50, "Units\\%d.unit", myunit->type);
	FILE* unitinfo = fopen(buffer, "r");

	//check file is correct
	if (unitinfo == NULL)
	{
		return;
	}

	// read file and  store data
	fscanf_s(unitinfo, "%d", &myunit->originalatt);
	myunit->att = myunit->originalatt;
	fscanf_s(unitinfo, "%d", &myunit->Maxhp);
	myunit->life = myunit->Maxhp;
	myunit->Maxtime = 1;



	// close file
	fclose(unitinfo);
}