

#include<stdio.h>
#include<stdlib.h>
#include "inven_func.h"
#include<string.h>


int main()
{
	printf("Enter user: \n1.Customer\n2.Employee");
	int choice;
  	scanf("%d",&choice);
  	if(choice==1)
 	{
  		printf("What do you want to do? \n1.Search product \n2.Add product to cart \n3.Remove product from cart \n4.View cart\n5.Total bill");
		int c_ch1;  
   		scanf("%d", &c_ch1);
    		do{
		switch(ch1)
		{
			case 1:
				printf("\nEnter the name of the product:");
        			//char entered_prod; ---turn to string
				scanf("%s", &entered_prod);
				//if(entered_prod in s.prod_name array) ---syntax ---struct details
					View_product();
				else
				{
					printf("\nProduct not found/not available");
				}
				break;
			case 2: 
				add_to_cart();
				break;
			case 3: 
				remove_from_cart();
				break;
			case 4: 
				printf("\nDisplaying cart:");
				display_cart();
				break;
      		case 5:
      			total_bill();
       			break;
			default:
				printf("\nInvalid input"); 
		} //switch
 		printf("\nDo you want to quit the program? (Press 0): ");
		scanf("%d", &ch2);
		}while(ch2!=0);     //do while
	} //if statement
 
 	else if(choice==2)
 	{
  		printf("Enter employee login password:");
   		int emp_pass = 12345;    //change to string?
    		int entered_pass;
    		scanf("%d",&entered_pass);
    		if(entered_pass!=emp_pass)
    			printf("\nInvalid password\n");
    		else
    		{
   			int ch1, ch2, ref; 
			printf("What do you want to do? \n1.View inventory \n2.Add a product record \n3.Delete a record \n4.Edit product details\n");
                  scanf("%d", &ch1);
			do{
			switch(ch1)
			{
				case 1:
					printf("\n1.Entire inventory \n2. A particular product"); //change
					scanf("%d", &ch2);
					if(ch2 == 1)
						View_all();
					else if(ch2==2)
					{
						printf("\nEnter ref no.: ");
						scanf("%d", &ref);
						view_ref(ref);
					}
                              else
                              	printf("Invalid input");
					break;
				case 2: 
					add_pdt();
					break;
				case 3: 
					delete_pdt();
					break;
				case 4: 
					printf("\nEnter ref no. of the product: ");
					scanf("%d", &ref);
					edit_pdt(ref);
					break;
				default:
					printf("\nInvalid input"); 
			}
   		printf("\nDo you want to quit the program? (Press 0): ");
		scanf("%d", &ch2);
		}while(ch2);
    	}//else
 	}//else if
  
  else
  {
  	printf("Invalid input");
    	exit(0); 											// go back to choice
  }
  
	
  
  
  /*
  
  printf("\nDo you want to quit the program? (Press 0): ");
	scanf("%d", &ch2);
	}while(ch2);
 
 */
  
  
  
  
  return 0;
}
