#include <conio.h>
#include <stdio.h>
#include <string.h>
#include "inven_func.h"

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
	    //printf("\nCan open file.");
		char buffer[300];
		int column = 0;
		int row = 0;
		int k = 1;


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

void add_to_cart(char entered_prod[30])
{
    int found = 1;
	FILE* fp = fopen("CSVtest.csv", "r");
	if(!fp)
		printf("\nCan't open file.");
	else
	{
	    //printf("\nCan open file.");
		char buffer[300];
		int column = 0;
		int row = 0;
		int k = 1;


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
            while (value && column<4)
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
					    slots_used +=1;
					    printf("\nThe product added to cart is: %s",value);
						strcpy(cart[slots_used].prod_name, value);
					}
					else
                        break;
                }
                if (column == 2 && k == 0)
				{
                    int x = 0;
                    do
                    {
                        printf("\nEnter quantity less than %s ", value);
                        scanf("%d", &x);
                        //edit_pdt(row-1, x);
                    }while(!(x>0&&x<atoi(value)));

                    cart[slots_used].qty = x;
                    printf("Quantity =  %d",x);
                }
				if (column == 3 && k == 0)
				{
                    cart[slots_used].price = atoi(value);
                    printf("\t and with price =  %s",value);
                }
                value = strtok(NULL, ", ");
                column++;

            }
            if(found==0)
                break;
        }

        // Close the file
        fclose(fp);
    }
}

void display_cart()
{
    printf("\nYour cart contains: ");
    if(slots_used == -1)
        printf("\nEmpty Cart");
    else
        for(int i =1;i<=slots_used; i++)
            printf("\n%s %d %d", cart[i].prod_name ,cart[i].qty,cart[i].price);
}

void remove_from_cart(char entered_prod[30])
{
    int i, j = 0, deleted = 1, n =slots_used;

    for(i=1;i<=n;i++)
    {
        if(strcmpi(entered_prod, cart[i].prod_name))
        {
            j++;
            strcpy(cart[j].prod_name, cart[i].prod_name);
            cart[j].price = cart[i].price;
            cart[j].qty = cart[i].qty;
        }
        else if(strcmpi(entered_prod, cart[i].prod_name)==0)
        {
            slots_used --;
            printf("\nProduct removed is: %s ", cart[i].prod_name);
            deleted = 0;
        }
    }
    if(deleted)
        printf("\nEntered product does not exist in cart. ");
}

void total_bill()
{
    int sum = 0;
    for(int i =1;i<=slots_used; i++)
    {
        sum += cart[i].qty*cart[i].price;
    }
    printf("\nYour total bill is %d", sum);
}

void check_out()
{
int i, index;
for(i = 1;i<=slots_used;i++)
{
    int found = 1;
	FILE* fp3 = fopen("CSVtest.csv", "r");
	if(!fp3)
		printf("\nCan't open file.");
	else
	{
	    char entered_prod[20];
	    strcpy(entered_prod, cart[i].prod_name);
	    //printf("\nCan open file.");
		char buffer[300];
		int column = 0;
		int row = 0;
		int k = 1, q;


        while (fgets(buffer, 300, fp3))
        {
            column = 0;
            row++;
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");
            while (value)
            {
                if (column == 0)
                {
                    index = atoi(value);
                    printf("%d", index);
                    value = strtok(NULL, ", ");
                    column ++;
                }

                if (column == 1)
				{
                    k = strcmpi(entered_prod, value);
                    if(k==0)
					{
					    found  = 0;
                        fclose(fp3);
					    q = -(cart[i].qty);
					    printf("\nQUantity takemn away is %d from row %d ", q, index);
						edit_pdt(index, q);
					}
					value = strtok(NULL, ", ");
					column++;
				}
				else
                    value = strtok(NULL, ", ");
            }
            if(found==0)
                break;
        }
    }
    }
}

void edit_pdt(int slno, int added_quantity)
{
    printf("\n%d\n", added_quantity);
    int found = 1;
	FILE* fp = fopen("CSVtest.csv", "r");
	FILE* fp2 = fopen("temp.csv", "w");
	if(!fp2)
		printf("\nCan't open file.");
	else
	{
	    printf("\nCan open file.");
		char buffer[300];
		int com2, com3, numcom = 0;
        char buffer2[300], ch[5], ch2[5];
		int column = 0;
		int row = 0;
		int k = 1, l, i, j;


        while (fgets(buffer, 300, fp))
        {
            if(slno != row )
                fprintf(fp2, "%s", buffer);
            else
            {
                printf("HIHI");
                strcpy(buffer2,buffer);
                for(i =0;i<300;i++)
                {
                    //printf("comloop");
                    if(buffer2[i] == ',')
                    {
                        numcom++;
                        if(numcom == 2)
                            com2 = i;
                        else if(numcom == 3)
                            com3 = i;

                    }

                }
                printf("\n %d, %d ", com2, com3);
                for(i=0;i<(com3 - com2 - 1);i++)
                    ch2[i] = buffer[com2+1+i];
                ch2[i] = '\0';
                printf("\n%s", ch2);

                itoa(added_quantity+atoi(ch2), ch, 10);
                l = strlen(ch);
                printf("\n%d", l);
                for(i=1; i<=l;i++)
                    buffer[com2+i] = ch[i-1];
                for(i=com2+l+1, j = com3; (i<300&&j<300); i++, j++)
                    buffer[i] = buffer2[j];
                fprintf(fp2, "%s", buffer);
            }
            row++;


        }
        printf("\nEdited Successfully");
        fclose(fp);
        fclose(fp2);
        remove("CSVtest.csv");
        rename("temp.csv","CSVtest.csv");
    }
}

void add_pdt()
{
    FILE* fp = fopen("CSVtest.csv", "r");
    char buffer[300];
    char pname[20], p1[20], p2[20], p3[20];
    int qty, row = 0;
    int price;
    while (fgets(buffer, 300, fp))
        row++;
    fclose(fp);
    fp = fopen("CSVtest.csv", "a+");
    if (!fp)
    {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    }

    // Asking user input for the
    // new product to be added
    printf("\nEnter Product Name\n");
    scanf("%s", &pname);
    printf("\nEnter Quantity\n");
    scanf("%d", &qty);
    printf("\nEnter Price\n");
    scanf("%d", &price);
    printf("\nEnter Property 1: \n");
    scanf("%s", &p1);
    printf("\nEnter Property 2: \n");
    scanf("%s", &p2);
    printf("\nEnter Property 3: \n");
    scanf("%s", &p3);
    // Saving data in file
    fprintf(fp,"%d,%s,%d,%d,%s,%s,%s\n", row, pname, qty, price, p1, p2, p3);

    printf("\nNew Product added to inventory");

    fclose(fp);
}


