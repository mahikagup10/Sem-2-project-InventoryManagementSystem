void View_all();
void View_product(char []);
void add_to_cart(char []);
void display_cart();
void remove_from_cart(char []);
void total_bill();
void check_out();

void edit_pdt(int, int );
void add_pdt();

struct cart_products
{
	  //int ref_id;
	  //int slots_used;
      char prod_name[20];
      int qty;
      int price;
}cart[15];

int slots_used ;
