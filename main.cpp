#include "Main.h"

int main()
{
	char re = 'Y';
	do 
	{
		Main g("Flights.txt", "HotelCharges_perday.txt");
		cout << "File reading done\n";
		//g.showGraphStructure();
		string source = g.printMenuSource();
		cout << source << endl;
		string destination = g.printMenuDestination(source);
		cout << destination << endl;
		//Base Case Date
		int bd = 1;
		int bm = 7;
		int by = 2019;
		int days;
		int months;
		int years;
		bool direct = false;
		bool cost_price = false;
		bool travel_time = false;
		Vector<string> transit_location;
		Vector<int>transit_time;
		string flight_preferred = "";
		char Check;
		g.inputDate(bd, bm, by, days, months, years, source, destination);
		system("cls");
		g.printScreen();
		cout << "Your source is : " << source << endl;
		cout << "Your destination is : " << destination << endl;
		cout << "Date of flight is: " << days << "/" << months << "/" << years << endl;
		cout << "Do you want to see flights in order of less cost?(Y/N)" << endl;
		cin >> Check;
		if (Check == 'Y' || Check == 'y')
		{
			cost_price = true;
		}
		if (!cost_price)
		{
			cout << "Do you want to see flights in order of less travel time?(Y/N)" << endl;
			cin >> Check;
			if (Check == 'Y' || Check == 'y')
			{
				travel_time = true;
			}
		}
		char newCheck;
		cout << "Do you want direct flight?(Y/N)" << endl;
		cin >> newCheck;
		if (newCheck == 'Y' || newCheck == 'y')
		{
			direct = true;
		}
		bool more = false;
		if (!direct && !more)
		{
			cin.ignore();
			cout << "Do you want to add transit location?(Y/N)" << endl;
			cin >> Check;
			if (Check == 'Y' || Check == 'y')
			{
				more = true;
			}
		}
		if (more)
		{
			system("cls");
			g.printScreen();
			cout << "Your source is : " << source << endl;
			cout << "Your destination is : " << destination << endl;
			cout << "Date of flight is: " << days << "/" << months << "/" << years << endl;
			g.transit_loc(source, destination, transit_location, transit_time);
			cout << "Transit locations are : " << endl;
			for (register short i = 0; i < transit_location.size(); ++i)
			{
				cout << transit_location.at(i) << " " << transit_time.at(i) << endl;
			}
		}
		system("cls");
		g.printScreen();
		cout << "Your source is : " << source << endl;
		cout << "Your destination is : " << destination << endl;
		cout << "Date of flight is: " << days << "/" << months << "/" << years << endl;
		cout << "Transit locations are : " << endl;
		for (register short i = 0; i < transit_location.size(); ++i)
		{
			cout << transit_location.at(i) << "\tStay: " << transit_time.at(i) << endl;
		}
		g.flight_preference(flight_preferred, "Flights.txt");
		system("cls");
		g.printScreen();
		cout << "Your source is : " << source << endl;
		cout << "Your destination is : " << destination << endl;
		cout << "Date of flight is: " << days << "/" << months << "/" << years << endl;
		cout << "Transit locations are : " << endl;
		for (register short i = 0; i < transit_location.size(); ++i)
		{
			cout << transit_location.at(i) << "\tStay: " << transit_time.at(i) << endl;
		}
		cout << "Preferred flight is: " << flight_preferred << endl;
		int max_transit_time = 0;
		cout << endl << endl;
		g.Traverser(source, destination, days, months, years, flight_preferred, max_transit_time, transit_location, transit_time, cost_price, travel_time, direct);
		cout << "Do you want to re-run the code?(Y/N)";
		cin >> re;
	} while (re == 'y' || re == 'Y');
	
	return 0;
}