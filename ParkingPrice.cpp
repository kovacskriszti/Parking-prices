#include"functions.h"
int main()
{
    // sunt apelate functiile definite pentru citirea pretului parcarii, a bancnotelor introduse, este calculat restul si apelata functia care arata restul si bancnotele returnate
    int price = ReadPrice();
    int input = ReadInputBanknotes();
    int remaining = input - price;
    ShowRemaining(remaining);
    return 0;
}
