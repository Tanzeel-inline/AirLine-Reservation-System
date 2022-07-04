#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include "Vector.h"
using namespace std;


long p_checker = 0;
class AdjList
{
public:
	//From where flight will fly
	string oirgin;
	//cost at staying this airport
	int hotel_price;
	//From this node information to for reaching the specific destination will be contained
	node* head;
};
class Main
{
	AdjList* root;
	short total_airport;
public:
	Vector<int>prize;
	Vector<string> airport_name;
	Main(const char* flights, const char* hotelrent)//Initializing the adjancey list
	{
		ifstream datafile(flights);
		if (!datafile.is_open())
		{
			cout << "Error opening file" << endl;
		}
		total_airport = 0;
		if (datafile.is_open()) //&& a_datafile.is_open())
		{
			while (!datafile.eof())
			{
				string name;
				string name1;
				datafile >> name;
				datafile >> name1;
				bool not_found = true;
				bool not_found1 = true;
				for (register short i = 0; i < airport_name.size(); ++i)
				{
					if (name == airport_name.at(i))
					{
						not_found = false;
					}
					if (name1 == airport_name.at(i))
					{
						not_found1 = false;
					}
				}
				if (not_found)
				{
					airport_name.push_back(name);
					prize.push_back(0);
					++total_airport;
				}
				if (not_found1)
				{
					airport_name.push_back(name1);
					prize.push_back(0);
					++total_airport;
				}
				getline(datafile, name);
			}
		}
		datafile.close();
		ifstream hotelfile(hotelrent);
		if (!hotelfile.is_open())
		{
			cout << "Error opening file" << endl;
		}
		while (!hotelfile.eof())
		{
			string name;
			int prize1;
			hotelfile >> name;
			hotelfile >> prize1;
			for (register short i = 0; i < airport_name.size(); ++i)
			{
				if (name == airport_name.at(i))
				{
					prize.set(i,prize1);
				}
			}
		}

		hotelfile.close();
		cout << "Total Airports are " << airport_name.size() << endl;

		total_airport = airport_name.size();
		root = new AdjList[airport_name.size()];
		for (register short i = 0; i < total_airport; ++i)
		{
			root[i].oirgin = airport_name.at(i);
			root[i].hotel_price = prize.at(i);
			root[i].head = NULL;
			cout << root[i].oirgin << " " << root[i].hotel_price << endl;
		}
		cout << "Inserting edges" << endl;
		insertEdge(flights,airport_name);
	}
	void insertEdge(const char* flights,Vector<string>airport_name)//Inserting the data into adjancey list
	{
		ifstream datafile(flights);
		if (datafile.is_open())
		{
			string start;
			string dest;
			char charignore;
			int day;
			int month;
			int year;
			int fh_time;
			int fm_time;
			int lh_time;
			int lm_time;
			int prize;
			string f_name;
			while (!datafile.eof())
			{
				datafile >> start;
				//system("pause");

				for (register short i = 0; i < total_airport; ++i)
				{
					if (root[i].oirgin == start)
					{
						datafile >> dest;
						datafile >> day;
						datafile.get(charignore);
						datafile >> month;
						datafile.get(charignore);
						datafile >> year;
						datafile >> fh_time;
						datafile.get(charignore);
						datafile >> fm_time;
						datafile >> lh_time;
						datafile.get(charignore);
						datafile >> lm_time;
						datafile >> prize;
						datafile >> f_name;
						if (root[i].head == NULL)
						{
							root[i].head = new node();
							root[i].head->destination = dest;
							root[i].head->dest_index = airport_name.find(dest);
							root[i].head->t.set(day, month, year, fh_time, fm_time, lh_time, lm_time);
							root[i].head->ticket_price = prize;
							root[i].head->airline_name = f_name;
							break;
						}
						else
						{
							bool no_flight = true;
							//system("pause");
							node* temp = root[i].head;
							while (temp->next != NULL)
							{
								if (temp->destination == dest && temp->t.day == day && temp->t.month == month && temp->t.year == year 
									&& temp->t.fh_time == fh_time && temp->t.fm_time == fm_time &&
									temp->t.lh_time == lh_time && temp->t.lm_time == lm_time &&
									temp->airline_name == f_name && temp->ticket_price == prize)
								{
									no_flight = false;
									break;
								}
								//system("pause");
								temp = temp->next;
							}
							if (no_flight)
							{
								if (temp->destination == dest && temp->t.day == day && temp->t.month == month && temp->t.year == year
									&& temp->t.fh_time == fh_time && temp->t.fm_time == fm_time &&
									temp->t.lh_time == lh_time && temp->t.lm_time == lm_time &&
									temp->airline_name == f_name && temp->ticket_price == prize)
								{
									break;
								}
								temp->next = new node;
								temp->next->destination = dest;
								temp->next->dest_index = airport_name.find(dest);
								temp->next->t.set(day, month, year, fh_time, fm_time, lh_time, lm_time);
								temp->next->ticket_price = prize;
								temp->next->airline_name = f_name;
								break;

							}
							else
							{
								break;
							}
						}
						//cout << "Node inserted at " << i << endl;
						break;
					}

				}
			}
			datafile.close();
		}
		else
		{
			cout << "Error opening the file at line 150\n";
			system("pause");
		}
	}
	void showGraphStructure()//Prints all the graph on the screen
	{
		cout << "\n\nPrinting graphs value\n";
		for (register int i = 0; i < total_airport; ++i)
		{
			cout << "From node " << root[i].oirgin << " flight is connecting to : " << endl;
			if (root[i].head != NULL)
			{
				node* temp = root[i].head;
				while (temp)
				{
					cout << temp->dest_index << " ";
					cout << temp->destination << " ";
					temp->t.display();
					cout << temp->ticket_price << " ";
					cout << temp->airline_name << " ";
					cout << temp->t.total_hoursf << " " << temp->t.total_hoursl << " ";
					temp = temp->next;
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	bool isEmpty()
	{
		for (register int i = 0; i < total_airport; ++i)
		{
			if (root[i].head != NULL)
			{
				return false;
			}
		}
		return true;
	}
	void Traverser(string source, string destination,int d, int m , int y,string flight_preferred,int max_transit_time,Vector<string> transit_location,Vector<int>transit_time,bool cost_price , bool travel_time,bool direct)
	//Recieves all the input from user and stat traversing the graph 
	{
		system("cls");
		bool* path = new bool[total_airport];
		for (int i = 0; i < total_airport; ++i)
		{
			path[i] = false;
		}
		int src = -1;
		int dest = -1;
		for (register short i = 0; i < total_airport; ++i)//Checks whether the source and destination are valid input(Two factor authentication :))
		{
			if (root[i].oirgin == source)
			{
				src = i;
			}
			if (root[i].oirgin == destination)
			{
				dest = i;
			}
			if (src != -1 && dest != -1)
			{
				break;
			}
		}
		PathSaver p;
		FinalPath M_I;
		p.addSource(root[src].oirgin,src,d,m,y);//Adds the source to path since our starting point wil remain same
		cout << "Checking availibles flights\n";
		int date_check = 0;
		while (M_I.root == NULL || date_check == -1 )//Check whether the flgiht was found on given date or not if not then it goes to check flight on previous and incoming date
		{
			if (!direct)//Checks if user want direct flight or not
			{//If not direct flight
				if (date_check == -1)
				{
					date_check = -2;
				}
				OptimalDFS(src, dest, path, p, flight_preferred, M_I, max_transit_time, transit_location, transit_time, cost_price, travel_time);
			}
			else
			{//If direct flight
				if (date_check == -1)
				{
					date_check = -2;
				}
				connecting_flights(src, dest, p, flight_preferred, M_I, max_transit_time, cost_price, travel_time);
			}
			if (M_I.root == NULL && date_check == 0)//Checking flights on next date
			{
				date_check = 1;
				cout << "\n\n\n\nChecking on next date\n";
				dateAddition(d, m, y, 1);
				p.setSourceDate( d, m, y);
			}
			else if (date_check == 1)//Checking flight on previous date
			{
				cout << "\n\n\n\nChecking on previous date\n";
				date_check = -1;
				dateSubtraction(d, m, y, 1);
				dateSubtraction(d, m, y, 1);
				p.setSourceDate(d, m, y);
			}
			else if ( M_I.root == NULL )
			{
				cout << "\n\n\n\nNo path found\n" << endl;
				break;
			}
		}
		if (M_I.root != NULL)
		{
			cout << "\n\n\nAvailible flights are:" << endl;
		}	
		M_I.display(prize);
		cout << p_checker << endl;
		p_checker = 0;
	}
	void OptimalDFS(int src, int dest, bool path[], PathSaver p,string flight_preferred,FinalPath &M_I,int max_transit_time,Vector<string> transit_location, Vector<int>transit_time, bool cost_price, bool travel_time)
	{
		//we start with our source node already present in the path and then starting from head of our starting point we traverse down the whole graph by checking the conditions
		//DFS is better than other because it goes into the depth of first node and then goes on forward keeping the conditions in mind we cant use some pre defined algo as one give shortest path and we have multiple from a single node 
		//Once we have found the one specific path we will never to go traverse it again we will save it in final path and then go to some other node from our starting point
		++p_checker;
		path[src] = true;
		if (src == dest)
		{
			//Checking if user want connected flight from specific place and wid specific stay
			bool checking = true;
			if (!transit_location.isEmpty())
			{
				for (register short i = 0; i < transit_location.Size(); ++i)
				{
					checking = p.getTransitLocationTime(transit_location.at(i), transit_time.at(i));
					if (checking == false)
					{
						break;
					}
				}
			}
			//If satisfied checking travel_time and cost_prrice preference
			if (checking && !cost_price && !travel_time)
			{
				M_I.addPath(p, prize);
			}
			else if (checking && !cost_price && travel_time)
			{
				M_I.addPathT(p, prize);//This sortation on basis of of time
			}
			else if (checking && cost_price && !travel_time)
			{
				M_I.addPathC(p, prize);//This sortation on basis of of cost
			}
		}
		else
		{
			node* temp = root[src].head;
			while (temp)
			{
				if (!path[temp->dest_index])
				{
					//Checking if the first flight from source flys on a given date if givcen date is 1/12/2019 then first flight must fly on 1/12/2019
					bool first_flight = true;
					if (p.getSourceDest() == src)
					{
						if (temp->t.getTotal_hoursf() - p.getSourceTime() >= 0 && temp->t.getTotal_hoursf() - p.getSourceTime() <= 24)
						{

						}
						else
						{
							first_flight = false;
						}
					}
					//Checking if the next flight flies after the previous flight , we can face the problem that our algo might add such flight after previous that fly before the previous //Overcoming that fact	
					if (p.last_land_time() <= temp->t.getTotal_hoursf() && first_flight)
					{
						//Checking if user has preferred some airline or not
						if ( temp->airline_name == flight_preferred || flight_preferred == "" )
						{
							p.newPath(temp->destination, temp->dest_index, temp->ticket_price, temp->airline_name, temp->t);
							//Checking if user want to reach below some maximum time
							if ( (max_transit_time != 0 && p.Calculate_TotalTime() <= max_transit_time) || max_transit_time == 0 )
							{
								OptimalDFS(temp->dest_index, dest, path, p, flight_preferred, M_I,max_transit_time, transit_location, transit_time, cost_price, travel_time);
							}
							else
							{
								p.pop();
							}
							
						}	
					}		
				}
				temp = temp->next;
			}

		}
		p.pop();
		path[src] = false;
	}
	void connecting_flights(int src, int dest, PathSaver p, string flight_preferred, FinalPath& M_I, int max_transit_time, bool cost_price, bool travel_time)
	{
		node* temp = root[src].head;
		while (temp)
		{
			++p_checker;
			if (temp->dest_index == dest)
			{
				//Checking if the first flight from source flys on a given date if given date is 1/12/2019 then first flight must fly on 1/12/2019
				bool first_flight = true;
				if (temp->t.getTotal_hoursf() - p.getSourceTime() >= 0 && temp->t.getTotal_hoursf() - p.getSourceTime() <= 24)
				{

				}
				else
				{
					first_flight = false;
				}
				//Checking if the next flight flies after the previous flight , we can face the problem that our algo might add such flight after previous that fly before the previous //Overcoming that fact	
				if (p.last_land_time() <= temp->t.getTotal_hoursf() && first_flight)
				{
					//Checking if user has preferred some airline or not
					if (temp->airline_name == flight_preferred || flight_preferred == "")
					{
						p.newPath(temp->destination, temp->dest_index, temp->ticket_price, temp->airline_name, temp->t);
						//Checking if user want to reach below some maximum time
						if ((max_transit_time != 0 && p.Calculate_TotalTime() <= max_transit_time) || max_transit_time == 0)
						{
							//If satisfied checking travel_time and cost_prrice preference
							if (!cost_price && !travel_time)
							{
								M_I.addPath(p, prize);
							}
							else if (!cost_price && travel_time)
							{
								M_I.addPathT(p, prize);
							}
							else if (cost_price && !travel_time)
							{
								M_I.addPathC(p, prize);//This sortation on basis of of cost
							}
						}
						else
						{
							p.pop();
						}

					}
				}
			}	
			temp = temp->next;
		}
	}
	void printScreen()
	{
		cout << endl << endl;
		cout << "                                              FAST Airline Reservation System" << endl << endl;
		cout << "Welcome to FAST Airline reservation system." << endl << endl;
	}
	string printMenuSource()
	{
		if (total_airport == 0)
		{
			cout << "Nothing avalible now " << endl;
			exit(-10);
		}
		bool input_done = false;
		int j;
		while (!input_done)
		{
			system("cls");
			printScreen();
			cout << "Enter the source\n";
			for (register short i = 0; i < total_airport; ++i)
			{
				cout << i + 1 << ". " << airport_name.at(i) << endl;
			}
			cin >> j;
			if (j - 1 >= 0 && j - 1 < total_airport)
			{
				input_done = true;
			}
		}
		return airport_name.at(j - 1);
	}
	string printMenuDestination(string source)
	{
		bool input_done = false;
		int j;
		while (!input_done)
		{
			system("cls");
			printScreen();
			cout << "Your source is : " << source << endl;
			cout << "Enter the destination\n";
			for (register short i = 0; i < total_airport; ++i)
			{
				if (airport_name.at(i) != source)
				{
					cout << i + 1 << ". " << airport_name.at(i) << endl;
				}
				
			}
			cin >> j;
			if (j - 1 >= 0 && j - 1 < total_airport && airport_name.at(j-1) != source)
			{
				input_done = true;
			}
		}
		return airport_name.at(j - 1);
	}
	int getDays(int months, int years)
	{
		//leap year condition, if month is 2
		if (months == 2)
		{
			if ((years % 400 == 0) || (years % 4 == 0 && years % 100 != 0))
				return 29;
			else
				return 28;
		}
		//months which has 31 days
		else if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8
			|| months == 10 || months == 12)
			return 31;
		else
			return 30;
	}
	void inputDate(int bd, int bm, int by , int&days ,int &months , int &years,string source ,string destination)
	{
		bool input_done = false;
		int j;
		while (!input_done)
		{
			input_done = true;
			system("cls");
			printScreen();
			cout << "Your source is : " << source << endl;
			cout << "Your destination is : " << destination << endl;
			cout << "Enter the date\n";
			cout << "Days: ";
			cin >> days;
			cout << "Months: ";
			cin >> months;
			cout << "Years: ";
			cin >> years;
			cout << endl;
			if (years < by)
			{
				input_done = false;
			}
			else if (years == by && months < bm)
			{
				input_done = false;
			}
			else if (years == by && months == bm && days < bd)
			{
				input_done = false;
			}
			else if (months < 1 || months > 12)
			{
				input_done = false;
			}
			else
			{
				int matcher = getDays(months, years);
				if (days < 1 || days > matcher)
				{
					input_done = false;
				}
			}
		}
		
	}
	void transit_loc(string source, string destination, Vector<string>&transit_location, Vector<int>&transit_time)
	{
		int total_transit_loc;
		cout << "How many transit location you want to add:" << endl;
		cin >> total_transit_loc;
		while (total_transit_loc > total_airport - 2)
		{
			cout << "This many transit locations are not avalible\nKindly redefine the transit locations\n";
			cin >> total_transit_loc;
		}
		while (total_transit_loc--)
		{
			bool right_input = false;
			int j;
			while (!right_input)
			{
				right_input = true;
				cout << "Enter the Transit Location\n";
				for (register short i = 0; i < total_airport; ++i)
				{
					cout << i + 1 << ". " << airport_name.at(i) << endl;
				}
				cin >> j;
				if (j - 1 <= 0 || j - 1 >= total_airport)
				{
					cout << "Re-Enter the input!False\n";
					right_input = false;
					continue;
				}
				if (airport_name.at(j - 1) == source || airport_name.at(j - 1) == destination )
				{
					cout << "This one " << endl;
					transit_location.pop();
					cout << "Re-Enter the input!False\n";
					right_input = false;
				}
				for (int i = 0; i < transit_location.size(); ++i)
				{
					if (transit_location.at(i) == airport_name.at(j - 1))
					{
						cout << "Re-Enter the input!False";
						right_input = false;
						break;
					}
				}
				transit_location.push_back(airport_name.at(j - 1));
				bool transit_checker = false;
				while (!transit_checker)
				{
					transit_checker = true;
					cout << "Enter the stay at transit location" << endl;
					cin >> j;
					if (j < 0 || j > 100)
					{
						cout << "Sorry we don't provide this service!Re-Enter the transit hours\n";
						transit_checker = false;
					}
					if (transit_checker == true)
					{
						transit_time.push_back(j);
					}
				}
				
			}
		}
	}
	void flight_preference(string& flight_preferred,const char* filename)
	{
		ifstream datafile(filename);
		if (!datafile.is_open())
		{
			cout << "File not opened\n";
			exit(-10);
		}
		Vector<string> flightsname;
		string ignore;
		string airlines;
		while (!datafile.eof())
		{
			datafile >> ignore;
			datafile >> ignore;
			datafile >> ignore;
			datafile >> ignore;
			datafile >> ignore;
			datafile >> ignore;
			datafile >> airlines;
			bool finder = false;
			for (register short i = 0; i < flightsname.size(); ++i)
			{
				if (airlines == flightsname.at(i))
				{
					finder = true;
					break;
				}
			}
			if (!finder)
			{
				flightsname.push_back(airlines);
			}
		}
		datafile.close();
		if (flightsname.size() == 0)
		{
			cout << "Nothing avalible now " << endl;
			exit(-10);
		}
		bool input_done = false;
		int j;
		while (!input_done)
		{
			system("cls");
			printScreen();
			cout << "Enter the Preferred Flight\n";
			cout << "0" << ". " << "None" << endl;
			for (register short i = 0; i < flightsname.size(); ++i)
			{
				cout << i + 1 << ". " << flightsname.at(i) << endl;
			}
			cin >> j;
			if (j - 1 == -1)
			{
				flight_preferred = "";
				return;
			}
			if (j - 1 >= 0 && j - 1 < flightsname.size())
			{
				input_done = true;
			}
		}
		flight_preferred = flightsname.at(j);
	}
	~Main()
	{
		for (register short i = 0; i < airport_name.Size(); ++i)
		{
			node* current = root[i].head;
			node* next;

			while (current != NULL)
			{
				next = current->next;
				delete current;
				current = next;
			}
		}
	}
};

