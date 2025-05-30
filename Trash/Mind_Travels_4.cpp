#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int year_1,  mounth_1,  day_1,  hour_1,  min_1, sec_1;
    int year_2,  mounth_2,  day_2,  hour_2,  min_2, sec_2;
    int counter_days_1 = 0, counter_days_2 = 0;
    int counter_sec_1 = 0, counter_sec_2 = 0;
    int length_mounth[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    cin >> year_1 >> mounth_1 >> day_1 >>  hour_1 >> min_1 >> sec_1;
    cin >> year_2 >> mounth_2 >> day_2 >>  hour_2 >> min_2 >> sec_2;

    long long int mount_of_days = 0;

    for(size_t i = 0; i < mounth_1-1; ++i ) 
        counter_days_1 += length_mounth[i];
    for(size_t i = 0; i < mounth_2-1; ++i ) 
        counter_days_2 += length_mounth[i];

    counter_days_1 += day_1;
    counter_days_2 += day_2;

    if( counter_days_2 >= counter_days_1 ) {
        mount_of_days += counter_days_2 - counter_days_1;
        mount_of_days += max ( ( year_2 - year_1  ), 0) * 365;
    }
    else {
        mount_of_days +=  365 - counter_days_1 + counter_days_2;
        mount_of_days += max ( ( year_2 - year_1 -1 ), 0) * 365;
    }
    if( hour_2 < hour_1) 
        -- mount_of_days;
    else if( hour_1 == hour_2 and min_2 < min_1 )
        -- mount_of_days;
    else if ( hour_1 == hour_2 and min_2 == min_1 and sec_2 < sec_1)
        -- mount_of_days;

    long long int mount_of_sec = 0 ;               //86 400

    counter_sec_1 = hour_1 * 3600 + min_1 * 60 + sec_1;
    counter_sec_2 = hour_2 * 3600 + min_2 * 60 + sec_2;

    if( counter_sec_2 >= counter_sec_1)
        mount_of_sec += counter_sec_2 - counter_sec_1;
    else 
        mount_of_sec += 86400 - counter_sec_1 + counter_sec_2; 

    cout<< mount_of_days << " " << mount_of_sec << endl;

    return 0;
}
