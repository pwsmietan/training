#include <iostream>

int main()
{
    int today = 0;
    std::cout << "Which day is today (1:Monday ..., 7: Sunday): " << std::endl;
    std::cin >> today;

    if (today >= 1 && today <= 7)
    {
        // We've got a valid starting day:
        const char* dow[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        
        // Loop back through time n-days:
        int daysBack = 0;
        std::cout << "How many days prior do you want to go?" << std::endl;
        std::cin >> daysBack;

        std::cout << "Today is " << dow[today - 1] << std::endl;
        std::cout << "If we went " << daysBack << " in the past we would hit a ";

        // Use today's day of week as our origin:
        int lastDay = 0;
        for(int dayCount = daysBack, dayIdx = today - 1; dayCount >= 0; dayCount--)
        {
            //std::cout << dow[dayIdx] << std::endl;
            if(dayCount == 0)
            {
                //std::cout << "Last day is " << dayIdx << std::endl;
                lastDay = dayIdx;
            }

            if(dayIdx > 0) 
                dayIdx--;
            else
                dayIdx = 6;
        }

        std::cout << dow[lastDay] << std::endl;
    }
    else
    {
        std::cout << "Sorry, " << today << " is not a valid day. Bye!" << std::endl;
    }

    return 0;
}