#include <iostream>

int main ()
{
    int binaryTime1, binaryTime2; 

    // variables for the time in hours and minutes in decimal number system
    int formatOfTime1, formatOfTime2; // format of the times 
    int tensOfHour1, tensOfHour2; // tens of the hours
    int onesOfHour1, onesOfHour2; // ones of the hours
    int hour1, hour2;
    int minutes1, minutes2;

    std::cin >> binaryTime1 >> binaryTime2;
    
    bool validInput = true; // boolean variable checking the validation of the input

    // CONVERTING THE TIMES FROM BINARY FORMAT TO HOURS AND MINUTES INTO DECIMAL NUMBER SYSTEM
    // ***************************************************************************************
    // the first time
    formatOfTime1 = (binaryTime1 >> 12); // 000000000000|#; # - format in binary number system
    tensOfHour1 = ((binaryTime1 >> 10) & 3); // 0000000000|X|** & 0000000000011 --> 0000000000|X|##; ## - tens of the hour in binary number system
    onesOfHour1 = ((binaryTime1 >> 6) & 15); // 00000|X|XX|**** & 0000000001111 --> 00000|X|XX|####; #### - ones of the hour in binary number system
    hour1 = 10 * tensOfHour1 + onesOfHour1;
    minutes1 = (binaryTime1 & 63); // X|XX|XXXX|****** & 0000000111111 --> X|XX|XXXX|######; ###### - minutes in binary number system

    // the second time
    tensOfHour2 = ((binaryTime2 >> 10) & 3); 
    onesOfHour2 = ((binaryTime2 >> 6) & 15); 
    hour2 = 10 * tensOfHour2 + onesOfHour2;
    minutes2 = (binaryTime2 & 63);

    // INPUT VALIDATION 
    // ***************************
    // checking if the first time is valid
    if (((formatOfTime1 == 0) && (hour1 < 0 || hour1 > 12)) // if it's a 12-hour format and the hour is out of the range [0-12] 
        || ((formatOfTime1 == 1) && (hour1 < 0 || hour1 > 23)) //  or if it's a 24-hour format and the hour is out of the range [0-23] 
        || (minutes1 < 0 || minutes1 > 59)) // or if the minutes are out of the range [0-59]
    {
        std::cout << "The first binary time is invalid" << std::endl;
        validInput = false; // the input is invalid
    }
    // check if the second time is valid
    if (((formatOfTime2 == 0) && (hour2 < 0 || hour2 > 12)) 
        || ((formatOfTime2 == 1) && (hour2 < 0 || hour2 > 23))
        || (minutes2 < 0 || minutes2 > 59)) 
    {
        std::cout << "The second binary time is invalid" << std::endl;
        validInput = false; 
    }

    if (validInput) 
    {
        std::cout << hour1 << ":";

        // adding '0' if the minutes are one-digit
        if (minutes1 < 10) 
        {
            std::cout << "0" << minutes1 << std::endl;  
        }
        else
        {
            std::cout << minutes1 << std::endl;
        }

        std::cout << hour2 << ":";

        if (minutes2 < 10)
        {
            std::cout << "0" << minutes2 << std::endl;
        }
        else
        {
            std::cout << minutes2 << std::endl; 
        }

        int time1InMinutes, time2InMinutes; 
        int timeDifferenceInMinutes; 
        int hourDifference, minutesDifference;

        // converting the two times into minutes
        time1InMinutes = 60 * hour1 + minutes1; 
        time2InMinutes = 60 * hour2 + minutes2;

        // calculating the absolute difference
        if (time1InMinutes > time2InMinutes)
        {
            timeDifferenceInMinutes = time1InMinutes - time2InMinutes;
        }
        else
        {
            timeDifferenceInMinutes = time2InMinutes - time1InMinutes;
        }
        
        // converting the difference in minutes into hours and minutes
        hourDifference = timeDifferenceInMinutes / 60;
        minutesDifference = timeDifferenceInMinutes % 60;

        std::cout << "diff " << hourDifference << ":";

        // adding '0' if the minutes of the difference are one-digit
        if (minutesDifference < 10)
        {
            std::cout << "0" << minutesDifference << std::endl;
        }
        else 
        {
            std::cout << minutesDifference << std::endl;
        }
        
    }

    return 0;
}