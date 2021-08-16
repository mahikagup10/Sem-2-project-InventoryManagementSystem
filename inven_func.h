void View_all();
void View_product(char []);
void add_to_cart(char []);
void display_cart();

struct cart_products
{
	  //int ref_id;
	  //int slots_used;
      char prod_name[20];
      int qty;
      float price;
}cart[15];

int slots_used;
