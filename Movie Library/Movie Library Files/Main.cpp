#include "MovieStore.h"

const string INVENTORY_PATH = "data4movies.txt";
const string CUSTOMERS_PATH = "data4customers.txt";
const string TRANSACTIONS_PATH = "data4commands.txt";

int main()
{
    MovieStore movieStore;
    movieStore.Run(INVENTORY_PATH, CUSTOMERS_PATH, TRANSACTIONS_PATH);
    return 0;
}
