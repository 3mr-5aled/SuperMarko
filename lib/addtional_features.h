#include <iostream>
#include "struct.h"
using namespace std;

ORDER applyVAT(ORDER &order, double VAT_RATE = 14)
{
    order.TotalPrice *= (1 + (VAT_RATE / 100));
    return order; // Return reference to modified order
    
}