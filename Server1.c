#include <conio.h>
#include <stdio.h>
#include <string.h>

void View_all()
{
	FILE* fp = fopen("CSVtest.csv", "r");
	if(!fp)
		printf("\nCan't open file.");
	else
	{
		char buffer[300];
        int row = 0;
        int column = 0;

        while (fgets(buffer, 300, fp))
        {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    printf("Sl No :");
                }

                // Column 2
                if (column == 1)
				{
                    printf("\tName: ");
                }

                // Column 3
                if (column == 2)
				{
                    printf("\tQuantity :");
                }
				if (column == 3)
				{
                    printf("\tPrice :");
                }
				if ((column == 4) || (column == 5) | (column == 6))
				{
                    printf("\t");
                }

                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }

            printf("\n");
        }

        // Close the file
        fclose(fp);
    }
}

void View_product(char entered_prod[30])
{
    int found = 1;
	FILE* fp = fopen("CSVtest.csv", "r");
	if(!fp)
		printf("\nCan't open file.");
	else
	{
	    printf("\nCan open file.");
		char buffer[300];
		int column = 0;
		int row = 0;
		int k = 1;


        while (fgets(buffer, 3000, fp))
        {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");
            while (value)
            {
                // Column 1
                if (column == 0)
                {
                        value = strtok(NULL, ", ");
                        column ++;
                }

                // Column 2
                if (column == 1)
				{
                    k = strcmpi(entered_prod, value);
                    if(k==0)
					{
					    found  = 0;
						printf("\n%d", (row -1));
						printf(" Name: ");
					}
					else
                        break;
                }
                if (column == 2 && k == 0)
				{
                    printf("\tQuantity :");
                }
				if (column == 3 && k == 0)
				{
                    printf("\tPrice :");
                }
				if ((column == 4 && k == 0) || (column == 5 && k == 0) | (column == 6&& k == 0))
				{
                    printf("\t");
                }
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;

            }
            printf("\n");
            if(found==0)
                break;
        }

        // Close the file
        fclose(fp);
    }
}
/*
void View_one(int r)
{
	FILE* fp1 = fopen("CSVtest.csv", "r");
	if(!fp1)
		printf("\nCan't open file.");
	else
	{
		char buffer[300];
        int row = 0;
        int column = 0;

        while (fgets(buffer, 300, fp1))
        {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
			else if (row==r)
            {
                // Splitting the data
                char* value = strtok(buffer, ", ");

                while (value)
                {
                    // Column 1
                    if (column == 0)
                    {
                        printf("Sl No :");
                    }

                    // Column 2
                    if (column == 1)
                    {
                        printf("\tName: ");
                    }

                    // Column 3
                    if (column == 2)
                    {
                        printf("\tQuantity :");
                    }
                    if (column == 3)
                    {
                        printf("\tPrice :");
                    }
                    if ((column == 4) || (column == 5) | (column == 6))
                    {
                        printf("\t");
                    }

                    printf("%s", value);
                    value = strtok(NULL, ", ");
                    column++;
            }

            printf("\n");
        }
        }
        // Close the file
        fclose(fp1);
    }

}
*/
