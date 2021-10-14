#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct state_tax
{
	char code[2];
	float tax_rate;
}state_tax[] =
{
	{.code = {'u', 't'}, .tax_rate = 0.0685f},
	{.code = {'n', 'v'}, .tax_rate = 0.08f},
	{.code = {'t', 'x'}, .tax_rate = 0.0625f},
	{.code = {'a', 'l'}, .tax_rate = 0.04f},
	{.code = {'c', 'a'}, .tax_rate = 0.0825f},
};

struct discount_values_s
{
	float discount_rate;
	float order_value;
}discount_values[] =
{
	{.order_value = 0.0f, .discount_rate = 0.0f},
	{.order_value = 1000.0f, .discount_rate = 0.03f},
	{.order_value = 5000.0f, .discount_rate = 0.05f},
	{.order_value = 7000.0f, .discount_rate = 0.07},
	{.order_value = 10000.0f, .discount_rate = 0.1f},
	{.order_value = 50000.0f, .discount_rate = 0.15f},
};

int main()
{
	float number_of_items; 
	float price_per_item;
	char state_code[3]; //add space for zero termination
	
    printf("Please enter number of items:\n\r");
	scanf("%f", &number_of_items); 
	printf("Please enter item price:\n\r");
	scanf("%f", &price_per_item); 
	printf("Please enter State Code:\n\r");
	scanf("%s", state_code); 
	
	float order_sum = number_of_items*price_per_item;
	
	struct discount_values_s* discount = &discount_values[0];
	for(int i = 0; i<(sizeof(discount_values)/sizeof(discount_values[0])); i++)
		if(order_sum >= discount_values[i].order_value)
			discount = &discount_values[i];
	
	float tax_rate = -1.0f;
	for(int i = 0; i<(sizeof(state_tax)/sizeof(state_tax[0])); i++)
		if(memcmp(state_tax[i].code, state_code, 2) == 0)
		{
			tax_rate = state_tax[i].tax_rate;
			break;
		}
	
	if(tax_rate < 0)
	{
		printf("Could not find state code \n\r");
		return 1;
	}
	
	order_sum = order_sum * (1-discount->discount_rate);
	order_sum =(tax_rate*order_sum)+order_sum;
	
	printf("Please give the instructor: %f $ \n\r", order_sum);
	
    return 0;
}
