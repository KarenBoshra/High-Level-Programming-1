#include "std_lib_facilities.h"

struct Date {
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

// helper functions:

Date::Date(int yy, int mm, int dd)
{
    //check that (y,m,d) is a valid date
    int yearMax = 3000, yearMin = 1700;
    if (yy < yearMin || yy > yearMax)
        cout << "Error, invalid year." << endl;
    else if (mm < 1 || mm > 12)
        cout << "Error, invalid month." << endl;
    else if (dd < 1 || dd > 31)
        cout << "Error, invalid day." << endl;
    // if it is, use to initialize dd
    else
    {
        y = yy;
        m = mm;
        d = dd;
    }

    return;
}

void Date::add_day(int n)
{
    if ((d += n) > 31)
    {
        d = 1;
        ++m;
    }
    
}

// Printing
ostream& operator<<(ostream& os, const Date& d)
{
    return os << d.d << "/" << d.m << "/" << d.y << endl;
}

int main()
{
    // set today to June 25, 1978
    Date today {1978, 6, 25};
    cout << "Today: " << today << endl;

    Date tomorrow {today};
    tomorrow.add_day(1);
    
    cout << "Tomorrow: " << tomorrow << endl;

    Date invalidDate {1300, 27, -4};

    return 0;

}
