#include "std_lib_facilities.h"

enum class Month
{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

struct Date {
    int y; Month m; int d;
public:
    Date(int y, Month m, int d);

    void add_day(int n);

    Month month() { return m; }
    int day() { return d; }
    int year() {return y; }
};

// helper functions:

Date::Date(int yy, Month mm, int dd)
{
    //check that (y,m,d) is a valid date
    int yearMax = 3000, yearMin = 1700;
    if (yy < yearMin || yy > yearMax)
        cout << "Error, invalid year." << endl;
    else if (int(mm) < 1 || int(mm) > 12)
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
    bool lastDay = false;
    bool endYear = false;
    for (int i = 0; i < n; ++i)
    {
        if (d == 31) 
        {
            lastDay = true;
            d = 1;
        }
        else ++d;

        if (lastDay)
        {
            lastDay = false;
            if (int(m) == 12)
            {
                m = Month::jan;
                endYear = true;
            }
            m = Month(int(m) + 1);
        }
        if (endYear)
        {
            endYear = false;
            ++y;
        }
    }
    
}

// Printing
ostream& operator<<(ostream& os, const Date& d)
{
    return os << d.d << "/" << int(d.m) << "/" << d.y << endl; 
}

int main()
{
    // set today to June 25, 1978
    Date today {1978, Month::jun, 25};
    cout << "Today: " << today << endl;

    Date tomorrow {today};
    tomorrow.add_day(1);
    
    cout << "Tomorrow: " << tomorrow << endl;

    //Date invalidDate {1300, Month::dec, -4};
    Date invalidDate {3000, Month::dec, 31};
    
    return 0;

}
