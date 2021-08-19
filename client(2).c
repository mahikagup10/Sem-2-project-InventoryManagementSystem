    #include<stdio.h>
    #include<stdlib.h>
    #include<conio.h>
    #include "inven_func.h"
    #include<string.h>



    int main()
    {
        printf("Enter user: \n1.Customer\n2.Employee\n");
        int choice, ch2, newQty;
        char pname[30];
        int pid;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("What do you want to do? \n1.Search product \n2.Add product to cart \n3.Remove product from cart \n4.View cart\n5.Total bill\n");
            int ch1;
            scanf("%d", &ch1);
                do{
            switch(ch1)
            {
                case 1:

                    printf("\nEnter the name of the product:");
                    scanf("%s", &pname);
                    View_product(pname);

                    break;


                case 2:
                    printf("\nEnter the name of the product to be added to cart:");
                    scanf("%s", &pname);
                    add_to_cart(pname);
                    break;

                case 3:
                    printf("\nEnter the name of the product to be deleted from cart:");
                    scanf("%s", &pname);
                    remove_from_cart(pname);
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
            printf("\nDo you want to check-out? (Press 0 to check-out, 1 to continue): ");
            scanf("%d", &ch2);
            if(ch2!=0)
            {
                printf("What do you want to do? \n1.Search product \n2.Add product to cart \n3.Remove product from cart \n4.View cart\n5.Total bill\n");
                scanf("%d", &ch1);
            }
            else if(ch2 == 0)
                check_out();
            }while(ch2!=0);     //do while
        } //if statement

        else if(choice==2)
        {
                char password[100], ch;
                char correct_pass[] = "inventory";
                int i = 0;
                printf("Enter Password : ");
                // 13 is ASCII value of Enter key
                while((ch = getch()) != 13)
                {
                    if(i < 0)
                        i = 0;
                        // 8 is ASCII value of BACKSPACE character
                    if(ch == 8)
                    {
                            putch('\b');
                            putch(NULL);
                            putch('\b');
                            i--;
                            continue;
                    }
                    password[i++] = ch;
                    putch('*');
                }
                password[i] = '\0';

                int check = strcmpi(password,correct_pass);
                if(check!= 0)
                    printf("\nInvalid password\n");
                else
                {
                printf("\nEntered password is correct. ");
                int ch1, ch2, ref;
                printf("\nWhat do you want to do? \n1.View inventory \n2.Add a product record \n3.Edit product details\n");
                      scanf("%d", &ch1);
                do{
                switch(ch1)
                {
                    case 1:
                        printf("\n1.Entire inventory \n2. A particular product\n"); //change
                        scanf("%d", &ch2);
                        if(ch2 == 1)
                            View_all();
                        else if(ch2==2)
                        {
                            printf("\nEnter product name.: ");
                            scanf("%s", &pname);
                            View_product(pname);
                        }
                        else
                            printf("Invalid input");
                        break;
                    case 2:
                        add_pdt();
                        break;
                    case 3:
                        printf("\nEnter id of the product: ");
                        scanf("%d", &pid);
                        printf("\nEnter the quantity to be added (positive number) or removed (negative): ");
                        scanf("%d", &newQty);
                        edit_pdt(pid, newQty);
                        break;

                    default:
                        printf("\nInvalid input");
                }
            printf("\nDo you want to quit the program? (Press 0 to quit, 1 to continue): ");
            scanf("%d", &ch2);
            if(ch2!=0)
            {
                printf("What do you want to do? \n1.View Products \n2.Add product to inventory \n3.Edit Product details\n");
                scanf("%d", &ch1);
            }
            }while(ch2);
            }//else
        }//else if

      else
      {
        printf("Invalid input");
            exit(0); 											// go back to choice
      }


      return 0;
    }
