#include<iostream>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

/*Initialize the list of champions */
std::map<string,int> Champions = {  { "human", 100 },
                                    { "wizard", 100 },
                                    { "spirit", 100 },
                                    { "giant", 150 },
                                    { "vampire", 110 } } ;

/*
  Function: number2string
  Description: convert input number to string with the time format
*/
string number2string(int number)
{
  string str;
  if(number >= 0 && number <= 9)
  {
    str= "0" + to_string(number);
  }
  else
  {
    str=to_string(number);
  }
  return str;
}

/*
  Function: convertString2time
  Description: convert the input String(XXXX-XX-XX XX:XX) into the Time structure
*/
tm convertString2time(string str_time)
{
    time_t tStart;
    int yy, month, dd, hh, mm;
    tm tm;
    const char *zStart = str_time.c_str();

    sscanf(zStart, "%d-%d-%d %d:%d", &yy, &month, &dd, &hh, &mm);
  
    /*Checking if the input String has format XXXX-XX-XX XX:XX and X is interger*/
    string checkInputStr = number2string(yy) + "-" + number2string(month) + "-" + \
                            number2string(dd) + " " + number2string(hh) + ":" + number2string(mm) ;
  
    if(checkInputStr != str_time)
    {
      /* if the format is wrong,use the default value: 1900-01-00 00:00 */
      cout<<"The format of date_string_interval is wrong:"<<checkInputStr<<endl;
      yy=1900;
      month=1;
      dd=hh=mm=0;
    }
  
    tm.tm_year = yy - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = dd;
    tm.tm_hour = hh;
    tm.tm_min = mm;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;

    tStart = mktime(&tm);
    return tm;
}

/*
  Function: holly_day
  Description:
    Tuesdays and Thursdays are holly days.
    Days since Sunday in range:	0-6
    Tuesday is 2,Thursday is 4
    
    Function will return True if it's Tuesday or Thursday
    return False if it's not a holly day.
*/
bool holly_day(int wday)
{
  return (wday == 2 || wday == 4);
}

/*
  Function:invincible_champion
  Description: 
    Wizards, Spirits are able to deceive the guards and pass through the gate without losing any HP.
    Function will return TRUE if champion is Wizard or Spirit
    return FALSE if not.
*/
bool invincible_champion(string champion)
{
  return (champion == "wizard" || champion == "spirit");
}


/*
  Function: calculate_damage_taken
  Description:
            Function will return the damage taken based 
            on the champion type and the date
*/
int calculate_damage_taken(tm *date, string champion)
{
  if (holly_day(date->tm_wday) || invincible_champion(champion))
	{
    //cout<<"holly_day"<<endl;
    return 0 ;
  }
  else    /*calculate damage taken*/
  {
    //cout<<"tm_hour:"<<date->tm_hour<<endl;
    //cout<<"tm_min:"<<date->tm_min<<endl;
    /* "Janna" demon of Wind spawned */
		if (( date->tm_hour == 6  )
		    &&( date->tm_min  >= 0  )
		    &&( date->tm_min  <= 29 ) )
		{
	      return 7;
		}
		/* "Tiamat" goddess of Oceans spawned */
		else if ( (date->tm_hour == 6  )
        &&  ( date->tm_min  >= 30 )
        &&  ( date->tm_min  <= 59 ) )
		{
	      return 18;
		}
		/* "Mithra" goddess of sun spawned */
		else if(( date->tm_hour == 7  )
        &&  ( date->tm_min  >= 0  )
        &&  ( date->tm_min  <= 59 ))
    {
        return 25;
		}
		/* "Warwick" God of war spawned */
		else if(( date->tm_hour == 8  )
        &&  ( date->tm_min  >= 0  )
        &&  ( date->tm_min  <= 29 ))
		{
        return 18;
		}
		/* "Kalista" demon of agony spawned */
		else if(( date->tm_hour >= 8  )
            &&  ( date->tm_hour <= 14 )
            &&  ( date->tm_min  >= 30 )
            &&  ( date->tm_min  <= 59 ))
		{
        return 7;
		}
		/* "Ahri" goddess of wisdom spawned */
		else if(( date->tm_hour == 15 )
            &&  ( date->tm_min  >= 0  )
            &&  ( date->tm_min  <= 29  ))
		{
        return 13;
		}
		/* "Brand" god of fire spawned 
    -->Fix issue : Overlappinging time duration for “brand” and "Ahri" in 15:00 to 15:30*/
		else if(( date->tm_hour == 15 && date->tm_min >= 30)
	       || ( date->tm_hour == 16 && date->tm_min <= 59 ))
		{
        return 25;
		}
		/* "Rumble" god of lightning spawned */
		else if(( date->tm_hour == 17 )
            && ( date->tm_min  >= 0 )
            && ( date->tm_min  <= 59 ))
		{
        return 18;
		}
		/* "Skarner" the scorpion demon spawned */
		else if((date->tm_hour >= 18 )
            && ( date->tm_hour <= 19 )
            && ( date->tm_min  >= 0  )
            && ( date->tm_min  <= 59 ))
		{
        return 7;
		}
		/* "Luna" The goddess of the moon spawned */
		else if(( date->tm_hour == 20  )&&
            ( date->tm_min  <= 59  ))
		{
        return 13;
		}
		else
		{      
      return 0;
		}
	}
}


/*
  Function:calculate_champion_health
  Description: calculate amount of health remained for a champion at the end of day.
    @param champion - type of the champion (e.g. 'Wizard', 'human')
    @param date_string_intervals - list of date intervals strings
        when a champion passing the gate (e.g. ['XXXX-XX-XX XX:XX'])
*/

int calculate_champion_health(string champion,vector<string> *date_string_intervals)
{
  int total_damage=0,damage=0,attempt=0;
  tm tm,pre_tm;
  std::array<string, 5> listChampion = { "human", "wizard", "spirit", "giant", "vampire" };
  
  /*Sort vector date_string_intervals*/
  sort(date_string_intervals->begin(), date_string_intervals->end());
 
  //* Convert champion string to lowcase string 
  transform(champion.begin(), champion.end(), champion.begin(), ::tolower);
  
  if (find(begin(listChampion), end(listChampion), champion) != std::end(listChampion))
  {
    
    for (int i=0; i < date_string_intervals->size(); i++)
    {
        attempt++;
        tm=convertString2time(date_string_intervals->at(i));
        damage=calculate_damage_taken(&tm,champion);
        //cout<<"-------damage:----------"<<damage<<endl;
        
        if((tm.tm_year == pre_tm.tm_year)&&(tm.tm_mon == pre_tm.tm_mon)&&(tm.tm_mday == pre_tm.tm_mday))
        {
          //Check if champion should only lose HP once every hour//
          if(tm.tm_hour>pre_tm.tm_hour)
          {
            total_damage = total_damage + damage;
            //cout<<"[sameday]total_damage"<<total_damage<<endl;
          }
        }
        else
        {
          total_damage = total_damage + damage;
        }
        if(total_damage >= Champions.at(champion))
        {
          break;
        }
        pre_tm=tm;
    }
    
    cout<<"Attempts:"<<attempt<<endl;
    
    ///*Check HP of Champion
    if(total_damage >= Champions.at(champion))
    {
          Champions.at(champion) = 0;
    }
    else
    {
          Champions.at(champion) -= total_damage;
    }
    
    cout<<"Amount of health remained for a champion:"<<champion<<" is: "<<Champions.at(champion)<<endl;      
  }
  else
  {
    //* The input champion's name is not found in the list of Champions
    cout<<"Invalid champion's name:"<<champion<<endl;
  }

    return total_damage;
  }

/*========================MAIN-FUNC===========================================*/
int main()
{ 
  
  vector<string> strVec = {"2018-06-13 22:30", "2018-06-13 20:00", "2018-06-13 12:58", "2018-06-13 10:45",
                           "2018-06-14 07:45", "2018-06-15 07:45", "2018-06-16 07:45","2018-06-19 07:45",
                          "2018-06-13 07:45","2018-06-12 07:45","2018-06-20 07:45","2018-06-22 07:45" };
  
  vector<string> strVec1 = {"2018-07-xx 0x:xx"};
 
  cout<<"==========Test1============== \
         Total Damage is:"<<calculate_champion_health("humAN",&strVec)<<endl;
  cout<<"==========Test2==============  \
         Total Damage is:"<<calculate_champion_health("Zhuman",&strVec)<<endl;
  cout<<"==========Test3==============  \
         Total Damage is:"<<calculate_champion_health("wizard",&strVec1)<<endl;
  
  return 0;
}
