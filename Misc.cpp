//Group of Functions


//Dice function
int Dice(int side)
{
    //result variable to output the result
    int result{ 0 };
    //Limit function to only allow 4, 6, 8, 10, 12, 20, 100 sided die
    switch (side)
    {
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
    case 20:
    case 100:
        result = ((rand() % side) + 1); //Add 1 to result since '0' is not a possible role
        std::cout << "Rolled " << side << "-sided die, result: " << result << std::endl;
        return result;
    default:
        return 0;
    }
}
