#include <iostream>
#include <struct.h>
using namespace std;

ORDER &applyVAT(ORDER &order)
{
    const double VAT_RATE = 0.14;
    order.TotalPrice *= (1 + VAT_RATE);
    return order; // Return reference to modified order
}